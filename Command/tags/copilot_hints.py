import dataclasses
from pathlib import Path

from tags.interface import TagsInterface


@dataclasses.dataclass(frozen=True)
class TagsCopilotHints(TagsInterface):
    tag = "copilot_hints"

    def replace(self, lst: list[str], filepath: Path) -> list[str]:
        return []
