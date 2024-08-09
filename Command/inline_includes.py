import sys
from pathlib import Path

from tags import select


def open_src(filepath: Path) -> list[str]:
    with open(filepath, "r") as f:
        return [row for row in f]


if __name__ == "__main__":
    args = sys.argv
    if len(args) != 2:
        raise RuntimeError("USAGE: python {this file} {src file}")

    filepath = Path(args[1]).resolve()

    tag = ""
    tag_lst: list[str] = []
    source_lst: list[str] = []
    for line in open_src(filepath):
        if "begin:tag" in line:
            tag = line.split("begin:tag ")[1][:-1]
        elif "end:tag" in line:
            for rep_line in select(tag).replace(tag_lst, filepath):
                source_lst.append(rep_line)
            tag = ""
        elif tag:
            tag_lst.append(line)
        else:
            source_lst.append(line)

    print("".join(source_lst))
