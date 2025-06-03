import subprocess
import os
from typing import TextIO
from runner.pipe import ospipe
from functools import lru_cache


def compile_file(file_name: str, obj_name: str) -> None:
    """
    Compile a C++ source file into an object file.

    Parameters
    ----------
    file_name : str
        The name of the C++ source file to compile.
        obj_name : str

    Returns
    -------
    None

    Raises
    -------
    RuntimeError
        If the compilation fails, a RuntimeError is raised with the error message.
    """
    if os.path.exists(obj_name):
        return
    options = ["-std=c++2a", "-O2"]
    command = ["g++-12", file_name, "-o", obj_name] + options
    result = subprocess.Popen(
        command,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
    )
    _, stderr = result.communicate()
    if result.returncode != 0:
        raise RuntimeError(f"Compilation failed for {file_name} with error:\n{stderr}")


def popen_cpp(file_name: str, fobj_in: TextIO, fobj_out: TextIO) -> subprocess.Popen:
    """
    Run a C++ source file as a subprocess.

    Parameters
    ----------
    file_name : str
        The name of the C++ source file to run.
    fobj_in : TextIO
        A file-like object for standard input.
    fobj_out : TextIO
        A file-like object for standard output.

    Returns
    -------
    subprocess.Popen
        A Popen object representing the running process.
    Raises

    -------
    RuntimeError
        If the compilation fails, a RuntimeError is raised.
    """
    obj_name = file_name.replace(".cpp", ".o")
    try:
        compile_file(file_name, obj_name)
    except RuntimeError:
        raise

    command = [obj_name]
    return subprocess.Popen(
        command,
        stdin=fobj_in,
        stdout=fobj_out,
        stderr=subprocess.PIPE,
        text=True,
    )


def process_pipe_communication(
    file_name1: str,
    fobj_in1: TextIO,
    fobj_out1: TextIO,
    file_name2: str,
    fobj_in2: TextIO,
    fobj_out2: TextIO,
):
    """
    Run two C++ files in a pipe communication setup.
    Each file reads from the output of the other.

    Parameters
    ----------
    file_name1 : str
        The name of the first C++ source file.
    fobj_in1 : TextIO
        A file-like object for standard input of the first process.
    fobj_out1 : TextIO
        A file-like object for standard output of the first process.
    file_name2 : str
        The name of the second C++ source file.
    fobj_in2 : TextIO
        A file-like object for standard input of the second process.
    fobj_out2 : TextIO
        A file-like object for standard output of the second process.

    Raises
    -------
    RuntimeError
        If either process fails, a RuntimeError is raised with the return code.
    """
    proc1 = popen_cpp(file_name1, fobj_in1, fobj_out1)
    proc2 = popen_cpp(file_name2, fobj_in2, fobj_out2)
    proc1.communicate()
    proc2.communicate()
    if proc1.returncode != 0:
        raise RuntimeError(f"Process 1 failed with return code {proc1.returncode}")
    if proc2.returncode != 0:
        raise RuntimeError(f"Process 2 failed with return code {proc2.returncode}")
