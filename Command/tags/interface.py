import abc
import dataclasses
from pathlib import Path


@dataclasses.dataclass(frozen=True)
class TagsInterface(metaclass=abc.ABCMeta):
    tag = ""

    @abc.abstractmethod
    def replace(self, lst: list[str], filepath: Path) -> list[str]:
        ...
