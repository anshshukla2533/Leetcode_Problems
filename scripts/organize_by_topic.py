#!/usr/bin/env python3
"""
organize_by_topic.py

Scans the repo root for LeetHub/LeetSync problem folders (folders named
like "1212-sequential-digits"), fetches each problem's topic tags from
LeetCode's public GraphQL API, and MOVES the solution files into a
single topic folder at the repo root, e.g.:

    Enumeration/1212-sequential-digits.py
    Enumeration/README.md   (overwritten per-problem, see note below)

Each problem is filed under exactly ONE topic (its first/primary tag
from LeetCode), and the original numbered folder is deleted afterwards
so there is only ever one copy of each problem's files in the repo.

Designed to run inside a GitHub Action right after LeetHub/LeetSync
pushes a new solution commit.
"""

import json
import os
import re
import shutil
import time
import urllib.request
import urllib.error

REPO_ROOT = os.getcwd()

# A LeetHub/LeetSync problem folder always starts with the problem's
# number, e.g. "1212-sequential-digits" or "73-set-matrix-zeroes".
PROBLEM_DIR_PATTERN = re.compile(r"^\d+[-_].+")

GRAPHQL_URL = "https://leetcode.com/graphql"

QUERY = """
query questionData($titleSlug: String!) {
  question(titleSlug: $titleSlug) {
    questionId
    title
    topicTags {
      name
    }
  }
}
"""


def slug_from_folder(folder_name: str) -> str:
    match = re.match(r"^\d+[-_](.+)$", folder_name)
    return match.group(1) if match else folder_name


def get_tags(slug: str) -> list[str]:
    payload = json.dumps({"query": QUERY, "variables": {"titleSlug": slug}}).encode()
    req = urllib.request.Request(
        GRAPHQL_URL,
        data=payload,
        headers={
            "Content-Type": "application/json",
            "Referer": "https://leetcode.com",
            "User-Agent": "Mozilla/5.0 (topic-organizer script)",
        },
        method="POST",
    )
    try:
        with urllib.request.urlopen(req, timeout=10) as resp:
            data = json.loads(resp.read())
    except (urllib.error.URLError, TimeoutError) as e:
        print(f"  ! network error for slug '{slug}': {e}")
        return []

    question = data.get("data", {}).get("question")
    if not question:
        print(f"  ! no question data returned for slug '{slug}' (check folder naming)")
        return []

    return [tag["name"] for tag in question.get("topicTags", [])]


def cleanup_old_layout() -> None:
    """Remove leftovers from older versions of this script (a topics/
    wrapper folder, or stray symlinks at repo root)."""
    old_topics_dir = os.path.join(REPO_ROOT, "topics")
    if os.path.isdir(old_topics_dir):
        shutil.rmtree(old_topics_dir, ignore_errors=True)


def main() -> bool:
    changed = False
    cleanup_old_layout()

    entries = sorted(
        e for e in os.listdir(REPO_ROOT)
        if os.path.isdir(os.path.join(REPO_ROOT, e))
        and PROBLEM_DIR_PATTERN.match(e)
    )

    for entry in entries:
        slug = slug_from_folder(entry)
        print(f"Checking '{entry}' -> slug '{slug}'")

        tags = get_tags(slug)
        if not tags:
            time.sleep(0.3)
            continue

        # Only the first/primary tag -- one topic folder per problem.
        primary_tag = tags[0]

        source_dir = os.path.join(REPO_ROOT, entry)
        source_files = [
            f for f in os.listdir(source_dir)
            if os.path.isfile(os.path.join(source_dir, f))
        ]

        if not source_files:
            print(f"  ! no files found in {entry}, skipping")
            time.sleep(0.3)
            continue

        tag_dir = os.path.join(REPO_ROOT, primary_tag)
        os.makedirs(tag_dir, exist_ok=True)

        for filename in source_files:
            src_file = os.path.join(source_dir, filename)
            dest_file = os.path.join(tag_dir, filename)
            shutil.copyfile(src_file, dest_file)
            print(f"  + moved {filename} -> {primary_tag}/")

        # Remove the original numbered folder so there's only one copy
        # of this problem's files anywhere in the repo.
        shutil.rmtree(source_dir)
        changed = True

        time.sleep(0.3)  # be polite to LeetCode's API

    return changed


if __name__ == "__main__":
    did_change = main()
    with open(".topic_sync_changed", "w") as f:
        f.write("1" if did_change else "0")
    print("Done. Changes made:", did_change)
