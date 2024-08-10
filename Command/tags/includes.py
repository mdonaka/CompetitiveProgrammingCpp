import dataclasses
from collections import deque
from pathlib import Path
from typing import Callable, Optional

from tags.interface import TagsInterface


def open_src(filepath: Path) -> list[str]:
    with open(filepath, "r") as f:
        return [row for row in f]


@dataclasses.dataclass
class Graph:
    size: int = 0
    itop: list[Path] = dataclasses.field(default_factory=list)
    ptoi: dict[Path, int] = dataclasses.field(default_factory=dict)
    edge: list[list[int]] = dataclasses.field(default_factory=list)

    def __add_node(self, u: Path) -> None:
        if u not in self.ptoi:
            self.itop.append(u)
            self.ptoi[u] = self.size
            self.edge.append([])
            self.size += 1

    def add_edge(self, u: Path, v: Path) -> None:
        self.__add_node(u)
        self.__add_node(v)
        self.edge[self.ptoi[u]].append(self.ptoi[v])

    def topological_lambda(self, f: Callable[[Path], None], *refs) -> None:
        use = [0 for _ in range(self.size)]
        for u in range(self.size):
            for v in self.edge[u]:
                use[v] += 1

        queue: deque = deque()
        for u, c in enumerate(use):
            if c == 0:
                queue.append(u)

        while queue:
            u = queue.popleft()
            f(self.itop[u], *refs)
            for v in self.edge[u]:
                use[v] -= 1
                if use[v] == 0:
                    queue.append(v)


@dataclasses.dataclass
class Source:
    filepath: Path
    includes: list[Path] = dataclasses.field(default_factory=list, init=False)

    def __post_init__(self) -> None:
        root = self.filepath.parent
        for line in open_src(self.filepath):
            if "#include" in line and "Library/Debug/" not in line:
                sp = line.split('"')
                if len(sp) > 1:
                    filepath = root / sp[1]
                    self.includes.append(filepath.resolve())

    def get_includes_graph(self, graph_: Optional[Graph] = None) -> Graph:
        graph = graph_ if graph_ else Graph()
        for include_path in self.includes:
            graph.add_edge(include_path, self.filepath)
            src = Source(include_path)
            src.get_includes_graph(graph)
        return graph


@dataclasses.dataclass(frozen=True)
class TagsIncludes(TagsInterface):
    tag = "includes"

    def replace(self, lst: list[str], filepath: Path) -> list[str]:
        source = Source(filepath)
        graph = source.get_includes_graph()
        ret: list[str] = []

        def f(filepath: Path, replace_source: list):
            if "main.cpp" not in str(filepath):
                exclude_words = [
                    "#pragma once",
                    "#include",
                ]
                add_line = ""
                for line in open_src(filepath):
                    if all([ex not in line for ex in exclude_words]):
                        add_line += line[:-1].split("//")[0]
                replace_source.append(add_line)

        graph.topological_lambda(lambda filepath: f(filepath, ret))
        return ret + ["\n"]
