import sys
from pathlib import Path


def open_src(filepath: Path) -> list[str]:
    with open(filepath, "r") as f:
        return [row for row in f]


def replace(root: Path, line: str) -> str:
    if "#include" not in line:
        return line
    filepath = root / line.split('"')[1]

    exclude_words = [
        "#pragma once",
        "#include",
    ]
    ret = ""
    for line in open_src(filepath):
        if all([ex not in line for ex in exclude_words]):
            ret += line
    return ret


if __name__ == "__main__":
    args = sys.argv
    if len(args) != 2:
        raise RuntimeError("USAGE: python {this file} {src file}")

    filepath = Path(args[1])
    root = filepath.parent

    rep = False
    ret = ""
    for line in open_src(filepath):
        if "tag:includes begin" in line or "tag:includes end" in line:
            rep ^= True
        ret += line if not rep else replace(root, line)

    print(ret)
