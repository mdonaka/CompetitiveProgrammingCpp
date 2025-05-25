import contextlib
import os
import subprocess
import sys
from typing import Generator, TextIO


@contextlib.contextmanager
def pipe() -> Generator[tuple[TextIO, TextIO], None, None]:
    fd_in, fd_out = os.pipe()
    fobj_in = os.fdopen(fd_in, "r")
    fobj_out = os.fdopen(fd_out, "w")
    try:
        yield fobj_in, fobj_out
    finally:
        fobj_out.close()
        fobj_in.close()


def run(command: str, judge: str) -> bool:
    with pipe() as (fobj_in1, fobj_out1):
        with pipe() as (fobj_in2, fobj_out2):
            proc1 = subprocess.Popen(
                command, shell=True, stdin=fobj_in2, stdout=fobj_out1, stderr=sys.stderr
            )
            proc2 = subprocess.Popen(
                judge,
                shell=True,
                stdin=fobj_in1,
                stdout=fobj_out2,
                stderr=subprocess.PIPE,
                text=True,
            )
            proc1.communicate()
            [_, err] = proc2.communicate()

            if proc1.returncode == 0 and proc2.returncode == 0:
                return True

            print("--- input ---", file=sys.stderr)
            print(err)
            print("-------------", file=sys.stderr, flush=True)
            if proc1.returncode != 0:
                print("RE", file=sys.stderr)
            else:
                print("WA", file=sys.stderr)
            return False


if __name__ == "__main__":
    args = sys.argv
    if len(args) != 3:
        raise RuntimeError("USAGE: python {this file} {bin file} {correct bin file}")

    main_bin = args[1]
    correct_bin = args[2]

    for cnt in range(10**3):
        if cnt % 100 == 0:
            print(f"Running test {cnt}...", file=sys.stderr)
        if not run(main_bin, correct_bin):
            print(f"Test {cnt} failed", file=sys.stderr)
            break
    print("All tests passed!", file=sys.stderr)
