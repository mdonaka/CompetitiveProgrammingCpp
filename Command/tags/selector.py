from tags.debug import TagsDebug
from tags.includes import TagsIncludes
from tags.interface import TagsInterface


def select(tag: str, *args) -> TagsInterface:
    for tag_replacer in [TagsIncludes, TagsDebug]:
        if tag == tag_replacer.tag:
            return tag_replacer(*args)
    raise RuntimeError(f"Tag:{tag} is not found.")
