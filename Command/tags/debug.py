import dataclasses
from pathlib import Path

from tags.interface import TagsInterface


@dataclasses.dataclass(frozen=True)
class TagsDebug(TagsInterface):
    tag = "debug"

    def replace(self, lst: list[str], filepath: Path) -> list[str]:
        # TODO: ちゃんと分岐する
        return ["#define dump(...)\n"]
