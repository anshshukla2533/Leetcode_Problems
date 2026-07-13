#!/usr/bin/env python3
"""
organize_by_topic.py

Scans the repo root for LeetHub/LeetSync problem folders (folders named
like "1212-sequential-digits"), fetches each problem's topic tags from
LeetCode's public GraphQL API, and copies the solution files directly
into a topic folder at the repo root, e.g.:

    Array/1212-sequential-digits.py
    Enumeration/1212-sequential-digits.py

No "topics/" wrapper folder, no per-problem subfolder -- files sit flat
inside their topic folder, same name as in the original problem folder.

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
# Using this pattern (instead of a hardcoded exclude list) means topic
# folders like "Array/" or "Enumeration/" are automatically skipped when
# scanning for problems, since they don't match this shape.
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
    """
    Strip the leading numeric id + separator to get the LeetCode titleSlug.
    "1212-sequential-digits" -> "sequential-digits"
    """
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


def cleanup_old_symlink(tag_dir: str, entry: str) -> None:
    """Remove leftovers from an older version of this script that used
    symlinks and a topics/ wrapper folder, if present."""
    old_symlink_path = os.path.join(tag_dir, entry)
    if os.path.islink(old_symlink_path):
        os.unlink(old_symlink_path)
    old_topics_dir = os.path.join(REPO_ROOT, "topics")
    if os.path.isdir(old_topics_dir):
        shutil.rmtree(old_topics_dir, ignore_errors=True)


def main() -> bool:
    changed = False

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

        source_dir = os.path.join(REPO_ROOT, entry)
        source_files = [
            f for f in os.listdir(source_dir)
            if os.path.isfile(os.path.join(source_dir, f))
        ]

        if not source_files:
            print(f"  ! no files found in {entry}, skipping")
            time.sleep(0.3)
            continue

        for tag in tags:
            tag_dir_name = tag.replace(" ", "-")
            tag_dir = os.path.join(REPO_ROOT, tag_dir_name)
            os.makedirs(tag_dir, exist_ok=True)

            cleanup_old_symlink(tag_dir, entry)

            for filename in source_files:
                src_file = os.path.join(source_dir, filename)
                dest_file = os.path.join(tag_dir, filename)
                shutil.copyfile(src_file, dest_file)
                changed = True
                print(f"  + copied {filename} -> {tag_dir_name}/")

        time.sleep(0.3)  # be polite to LeetCode's API

    return changed


if __name__ == "__main__":
    did_change = main()
    with open(".topic_sync_changed", "w") as f:
        f.write("1" if did_change else "0")
    print("Done. Changes made:", did_change)
