#!/usr/bin/env python3
"""
organize_by_topic.py

Scans the repo root for LeetHub/LeetSync problem folders, fetches each
problem's topic tags from LeetCode's public GraphQL API, and creates
symlinks under topics/<Tag-Name>/<problem-folder> pointing back to the
original solution folder.

Designed to run inside a GitHub Action right after LeetHub/LeetSync
pushes a new solution commit.
"""

import json
import os
import re
import time
import urllib.request
import urllib.error

REPO_ROOT = os.getcwd()

# Folders that should never be treated as "problem folders"
EXCLUDE_DIRS = {".git", ".github", "topics", "scripts", "node_modules", ".venv", "venv"}

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
    LeetHub/LeetSync folder names are often like "0322-coin-change".
    Strip a leading numeric id + separator to get the LeetCode titleSlug.
    Falls back to the raw folder name if no numeric prefix is found.
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


def main() -> bool:
    changed = False

    entries = sorted(
        e for e in os.listdir(REPO_ROOT)
        if os.path.isdir(os.path.join(REPO_ROOT, e))
        and e not in EXCLUDE_DIRS
        and not e.startswith(".")
    )

    for entry in entries:
        slug = slug_from_folder(entry)
        print(f"Checking '{entry}' -> slug '{slug}'")

        tags = get_tags(slug)
        if not tags:
            time.sleep(0.3)
            continue

        for tag in tags:
            tag_dir_name = tag.replace(" ", "-")
            tag_dir = os.path.join(REPO_ROOT, "topics", tag_dir_name)
            os.makedirs(tag_dir, exist_ok=True)

            link_path = os.path.join(tag_dir, entry)
            if not os.path.exists(link_path):
                # relative path from topics/<Tag>/ back to the repo-root problem folder
                target = os.path.join("..", "..", entry)
                os.symlink(target, link_path)
                changed = True
                print(f"  + linked into topics/{tag_dir_name}/")

        time.sleep(0.3)  # be polite to LeetCode's API

    return changed


if __name__ == "__main__":
    did_change = main()
    with open(".topic_sync_changed", "w") as f:
        f.write("1" if did_change else "0")
    print("Done. Changes made:" , did_change)
