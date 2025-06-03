import sys
from pathlib import Path
import os
from runner import process_pipe_communication
from runner.pipe import ospipe


def reset(src: Path) -> None:
    if os.path.exists(src.as_posix().replace(".cpp", ".o")):
        os.remove(src.as_posix().replace(".cpp", ".o"))


def run(src: str, judge: str) -> bool:
    with ospipe() as (fobj_in1, fobj_out1), ospipe() as (fobj_in2, fobj_out2):
        try:
            process_pipe_communication(
                src,
                fobj_in2,
                fobj_out1,
                judge,
                fobj_in1,
                fobj_out2,
            )
        except RuntimeError as e:
            print(f"Error during process communication: {e}", file=sys.stderr)
            return False
        return True


if __name__ == "__main__":
    args = sys.argv
    if len(args) != 3:
        raise RuntimeError("USAGE: python {this file} {src file} {judge file}")

    main_src = Path.cwd() / args[1]
    judge_src = Path.cwd() / args[2]

    reset(main_src)
    reset(judge_src)

    repeat = 10**3
    for cnt in range(1, repeat + 1):
        if cnt == 1 or cnt % 100 == 0:
            print(f"Running test {cnt}...", file=sys.stderr)
        if not run(main_src.as_posix(), judge_src.as_posix()):
            print(f"Test {cnt} failed", file=sys.stderr)
            break
    print("All tests passed!", file=sys.stderr)

    reset(main_src)
    reset(judge_src)
