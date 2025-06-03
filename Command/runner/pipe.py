import os
import contextlib
from typing import Generator, TextIO


@contextlib.contextmanager
def ospipe() -> Generator[tuple[TextIO, TextIO], None, None]:
    fd_in, fd_out = os.pipe()
    fobj_in = os.fdopen(fd_in, "r")
    fobj_out = os.fdopen(fd_out, "w")
    try:
        yield fobj_in, fobj_out
    finally:
        fobj_out.close()
        fobj_in.close()
