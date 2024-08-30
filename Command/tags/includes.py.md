---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import dataclasses\nfrom collections import deque\nfrom pathlib import Path\n\
    from typing import Callable, Optional\n\nfrom tags.interface import TagsInterface\n\
    \n\ndef open_src(filepath: Path) -> list[str]:\n    with open(filepath, \"r\"\
    ) as f:\n        return [row for row in f]\n\n\n@dataclasses.dataclass\nclass\
    \ Graph:\n    size: int = 0\n    itop: list[Path] = dataclasses.field(default_factory=list)\n\
    \    ptoi: dict[Path, int] = dataclasses.field(default_factory=dict)\n    edge:\
    \ list[list[int]] = dataclasses.field(default_factory=list)\n\n    def __add_node(self,\
    \ u: Path) -> None:\n        if u not in self.ptoi:\n            self.itop.append(u)\n\
    \            self.ptoi[u] = self.size\n            self.edge.append([])\n    \
    \        self.size += 1\n\n    def add_edge(self, u: Path, v: Path) -> None:\n\
    \        self.__add_node(u)\n        self.__add_node(v)\n        self.edge[self.ptoi[u]].append(self.ptoi[v])\n\
    \n    def topological_lambda(self, f: Callable[[Path], None], *refs) -> None:\n\
    \        use = [0 for _ in range(self.size)]\n        for u in range(self.size):\n\
    \            for v in self.edge[u]:\n                use[v] += 1\n\n        queue:\
    \ deque = deque()\n        for u, c in enumerate(use):\n            if c == 0:\n\
    \                queue.append(u)\n\n        while queue:\n            u = queue.popleft()\n\
    \            f(self.itop[u], *refs)\n            for v in self.edge[u]:\n    \
    \            use[v] -= 1\n                if use[v] == 0:\n                  \
    \  queue.append(v)\n\n\n@dataclasses.dataclass\nclass Source:\n    filepath: Path\n\
    \    includes: list[Path] = dataclasses.field(default_factory=list, init=False)\n\
    \n    def __post_init__(self) -> None:\n        root = self.filepath.parent\n\
    \        for line in open_src(self.filepath):\n            if \"#include\" in\
    \ line and \"Library/Debug/\" not in line:\n                sp = line.split('\"\
    ')\n                if len(sp) > 1:\n                    filepath = root / sp[1]\n\
    \                    self.includes.append(filepath.resolve())\n\n    def get_includes_graph(self,\
    \ graph_: Optional[Graph] = None) -> Graph:\n        graph = graph_ if graph_\
    \ else Graph()\n        for include_path in self.includes:\n            graph.add_edge(include_path,\
    \ self.filepath)\n            src = Source(include_path)\n            src.get_includes_graph(graph)\n\
    \        return graph\n\n\n@dataclasses.dataclass(frozen=True)\nclass TagsIncludes(TagsInterface):\n\
    \    tag = \"includes\"\n\n    def replace(self, lst: list[str], filepath: Path)\
    \ -> list[str]:\n        source = Source(filepath)\n        graph = source.get_includes_graph()\n\
    \        ret: list[str] = []\n\n        def f(filepath: Path, replace_source:\
    \ list):\n            if \".cpp\" not in str(filepath):\n                exclude_words\
    \ = [\n                    \"#pragma once\",\n                    '#include \"\
    ',\n                ]\n                add_line = \"\"\n                for line\
    \ in open_src(filepath):\n                    if all([ex not in line for ex in\
    \ exclude_words]):\n                        add_line += line[:-1].split(\"//\"\
    )[0]\n                        if \"#include <\" in line:\n                   \
    \         add_line += \"\\n\"\n                replace_source.append(add_line\
    \ + \"\\n\")\n\n        graph.topological_lambda(lambda filepath: f(filepath,\
    \ ret))\n        return ret\n"
  dependsOn: []
  isVerificationFile: false
  path: Command/tags/includes.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Command/tags/includes.py
layout: document
redirect_from:
- /library/Command/tags/includes.py
- /library/Command/tags/includes.py.html
title: Command/tags/includes.py
---
