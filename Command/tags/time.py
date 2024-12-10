import dataclasses
from pathlib import Path
import datetime

from tags.interface import TagsInterface


@dataclasses.dataclass(frozen=True)
class TagsTime(TagsInterface):
    tag = "time"

    def replace(self, lst: list[str], filepath: Path) -> list[str]:
        now = datetime.datetime.now(datetime.timezone(datetime.timedelta(hours=9)))
        now = now.strftime("%Y-%m-%d %H:%M:%S %Z")

        return [
            "/*\n",
            " * Author:  cutmdo\n",
            " * Created: " + str(now) + "\n",
            " */\n",
        ]
