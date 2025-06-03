from runner.run import compile_file, popen_cpp, process_pipe_communication
from runner.pipe import ospipe
import pytest
from contextlib import contextmanager
import subprocess
import os
import hashlib


@contextmanager
def mock_file(src: str):
    file_name = "./" + hashlib.md5(src.encode()).hexdigest() + ".cpp"
    with open(f"{file_name}", "w") as f:
        f.write(src)
    try:
        yield file_name
    finally:
        if os.path.exists(file_name):
            os.remove(file_name)
        if os.path.exists(file_name.replace(".cpp", ".o")):
            os.remove(file_name.replace(".cpp", ".o"))


@pytest.mark.parametrize(
    "src",
    [
        # simple hello world
        """
#include <iostream>
int main() {
std::cout << "Hello, World!" << std::endl;
}
        """,
    ],
)
def test_compile(src: str):
    with mock_file(src) as file_name:
        obj_name = file_name.replace(".cpp", ".o")
        compile_file(file_name, obj_name)
        assert os.path.exists(obj_name), f"Compiled object {obj_name} does not exist."
        with open(obj_name, "rb") as f:
            content = f.read()
            assert content, "Compiled object is empty."


@pytest.mark.parametrize(
    ["src", "expected_exception"],
    [
        # empty source code
        (
            """
            """,
            RuntimeError,
        ),
        # syntax error
        (
            """
#include <iostream>
int main() {
std::cout << "Hello, World!" << std::endl;
            """,
            RuntimeError,
        ),
    ],
)
def test_compile_failure(src: str, expected_exception: Exception):
    with mock_file(src) as file_name:
        obj_name = file_name.replace(".cpp", ".o")
        with pytest.raises(expected_exception):
            compile_file(file_name, obj_name)


@pytest.mark.parametrize(
    ["src", "expected"],
    [
        # simple hello world
        (
            """
#include <iostream>
int main() {
std::cout << "Hello, World!" << std::endl;
}""",
            "Hello, World!\n",
        ),
    ],
)
def test_popen_cpp(src: str, expected: str):
    with mock_file(src) as file_name, ospipe() as (fobj_in, fobj_out):
        process = popen_cpp(file_name, subprocess.PIPE, fobj_out)
        process.communicate()
        fobj_out.close()
        output = "".join(fobj_in.readlines())
        assert output == expected, f"Expected '{expected}', but got '{output}'"


@pytest.mark.parametrize(
    ["src1", "src2"],
    [
        # simple pipe communication
        (
            """
#include <iostream>
#include <cassert>
int main() {
    std::cout << 2 << std::endl;
    int n;
    std::cin >> n;
    assert(n == 4);
}""",
            """
#include <iostream>
int main() {
    int n;
    std::cin >> n;
    std::cout << 4 << std::endl;
}""",
        ),
    ],
)
def test_process_pipe_communication(src1: str, src2: str):
    with mock_file(src1) as file_name1, mock_file(src2) as file_name2:
        with ospipe() as (fobj_in1, fobj_out1), ospipe() as (fobj_in2, fobj_out2):
            process_pipe_communication(
                file_name1, fobj_in2, fobj_out1, file_name2, fobj_in1, fobj_out2
            )


@pytest.mark.parametrize(
    ["src1", "src2", "expected_exception"],
    [
        # failure in pipe communication
        (
            """
#include <iostream>
#include <cassert>
int main() {
    std::cout << 2 << std::endl;
    int n;
    std::cin >> n;
    assert(n == 4);
}""",
            """
#include <iostream>
int main() {
    int n;
    std::cin >> n;
    std::cout << 10 << std::endl;
}""",
            RuntimeError,
        ),
    ],
)
def test_process_pipe_communication_failure(
    src1: str, src2: str, expected_exception: Exception
):
    with mock_file(src1) as file_name1, mock_file(src2) as file_name2:
        with ospipe() as (fobj_in1, fobj_out1), ospipe() as (fobj_in2, fobj_out2):
            with pytest.raises(expected_exception):
                process_pipe_communication(
                    file_name1, fobj_in2, fobj_out1, file_name2, fobj_in1, fobj_out2
                )
