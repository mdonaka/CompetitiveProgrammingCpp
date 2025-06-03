import sys
from pathlib import Path
import subprocess
import os
from runner import process_pipe_communication, popen_cpp
from runner.pipe import ospipe


def reset(src: Path) -> None:
    if os.path.exists(src.as_posix().replace(".cpp", ".o")):
        os.remove(src.as_posix().replace(".cpp", ".o"))


def compare(src: str, correct: str, testcases: str) -> bool:
    with ospipe() as (fobj_in, fobj_out):
        try:
            testcases_process = popen_cpp(testcases, None, fobj_out)
            testcases_process.communicate()
            fobj_out.close()
            testcases_output = "".join(fobj_in.readlines())
        except RuntimeError as e:
            print(f"Error during testcases execution: {e}", file=sys.stderr)
            return False

    with ospipe() as (fobj_in, fobj_out):
        try:
            fobj_out.write(testcases_output)
            fobj_out.close()
            src_process = popen_cpp(src, fobj_in, subprocess.PIPE)
            src_output, _ = src_process.communicate()
            src_output = src_output.strip()
        except RuntimeError as e:
            print(f"Error during source execution: {e}", file=sys.stderr)
            return False

    with ospipe() as (fobj_in, fobj_out):
        try:
            fobj_out.write(testcases_output)
            fobj_out.close()
            correct_process = popen_cpp(correct, fobj_in, subprocess.PIPE)
            correct_output, _ = correct_process.communicate()
            correct_output = correct_output.strip()
        except RuntimeError as e:
            print(f"Error during correct source execution: {e}", file=sys.stderr)
            return False

    if src_output != correct_output:
        print(testcases_output)
        print(f"Expected: {correct_output}\nGot: {src_output}")
        return False
    return True


if __name__ == "__main__":
    args = sys.argv
    if len(args) != 4:
        raise RuntimeError(
            "USAGE: python {this file} {main src file} {correct src file} {testcases file}"
        )

    main_src = Path.cwd() / args[1]
    correct_src = Path.cwd() / args[2]
    testcases_src = Path.cwd() / args[3]

    reset(main_src)
    reset(correct_src)
    reset(testcases_src)

    ok = True
    repeat = 10**3
    for cnt in range(repeat):
        if cnt % 100 == 0:
            print(f"Running test {cnt}...", file=sys.stderr)
        if not compare(
            main_src.as_posix(), correct_src.as_posix(), testcases_src.as_posix()
        ):
            print(f"Test {cnt} failed", file=sys.stderr)
            ok = False
            break
    if ok:
        print("All tests passed!", file=sys.stderr)

    reset(main_src)
    reset(correct_src)
    reset(testcases_src)
