#!/usr/bin/env python3
"""
organize_by_topic.py

Scans the repo root for LeetHub/LeetSync problem folders (folders named
like "1212-sequential-digits"), fetches each problem's topic tags from
LeetCode's public GraphQL API, and MOVES the solution files into a
single topic folder at the repo root, e.g.:

    Enumeration/1212-sequential-digits.py
    Enumeration/1212-sequential-digits.md

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


def get_question_data(slug: str) -> dict:
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
            raw = resp.read()
    except (urllib.error.URLError, TimeoutError) as e:
        # Covers HTTPError (403/429/etc.) and connection-level failures.
        print(f"  ! network error for slug '{slug}': {e}")
        return {}

    # LeetCode's anti-bot layer sometimes returns a 200 status with an
    # HTML challenge page instead of JSON (common from CI server IPs
    # with no session cookie). Never let that crash the whole run.
    try:
        data = json.loads(raw)
    except json.JSONDecodeError:
        print(f"  ! non-JSON response for slug '{slug}' (likely blocked/rate-limited) — skipping")
        return {}

    question = data.get("data", {}).get("question")
    if not question:
        print(f"  ! no question data returned for slug '{slug}' (check folder naming)")
        return {}

    return {
        "title": question.get("title") or slug,
        "tags": [tag["name"] for tag in question.get("topicTags", [])],
    }


def cleanup_old_layout() -> None:
    """Remove leftovers from older versions of this script (a topics/
    wrapper folder, or stray symlinks at repo root)."""
    old_topics_dir = os.path.join(REPO_ROOT, "topics")
    if os.path.isdir(old_topics_dir):
        shutil.rmtree(old_topics_dir, ignore_errors=True)


def dest_filename_for(filename: str, slug: str) -> str:
    """
    LeetHub/LeetSync writes each problem's writeup as a generic
    'README.md'. Since multiple problems can land in the same topic
    folder, that generic name would collide and overwrite. Give it a
    per-problem name instead. Everything else (e.g. '<slug>.cpp')
    already has a unique name from LeetHub, so it passes through as-is.
    """
    if filename.lower() == "readme.md":
        return f"{slug}.md"
    return filename


def main():
    changed = False
    processed_titles = []
    cleanup_old_layout()

    entries = sorted(
        e for e in os.listdir(REPO_ROOT)
        if os.path.isdir(os.path.join(REPO_ROOT, e))
        and PROBLEM_DIR_PATTERN.match(e)
    )

    for entry in entries:
        slug = slug_from_folder(entry)
        print(f"Checking '{entry}' -> slug '{slug}'")

        data = get_question_data(slug)
        tags = data.get("tags") or []
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
            out_name = dest_filename_for(filename, slug)
            dest_file = os.path.join(tag_dir, out_name)
            shutil.copyfile(src_file, dest_file)
            print(f"  + moved {filename} -> {primary_tag}/{out_name}")

        # Remove the original numbered folder so there's only one copy
        # of this problem's files anywhere in the repo.
        shutil.rmtree(source_dir)
        changed = True
        processed_titles.append(data.get("title", slug))

        time.sleep(0.3)  # be polite to LeetCode's API

    return changed, processed_titles


if __name__ == "__main__":
    did_change, titles = main()
    with open(".topic_sync_changed", "w") as f:
        f.write("1" if did_change else "0")

    if titles:
        if len(titles) == 1:
            commit_message = f"Added {titles[0]}"
        else:
            commit_message = "Added " + ", ".join(titles)
    else:
        commit_message = "chore: organize solutions by topic [skip ci]"

    with open(".commit_message.txt", "w") as f:
        f.write(commit_message)

    print("Done. Changes made:", did_change)
    print("Commit message will be:", commit_message)
