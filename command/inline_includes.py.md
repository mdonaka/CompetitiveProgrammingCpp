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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import dataclasses\nimport sys\nfrom collections import deque\nfrom pathlib\
    \ import Path\nfrom typing import Callable, Optional\n\n\ndef open_src(filepath:\
    \ Path) -> list[str]:\n    with open(filepath, \"r\") as f:\n        return [row\
    \ for row in f]\n\n\n@dataclasses.dataclass\nclass Graph:\n    size: int = 0\n\
    \    itop: list[Path] = dataclasses.field(default_factory=list)\n    ptoi: dict[Path,\
    \ int] = dataclasses.field(default_factory=dict)\n    edge: list[list[int]] =\
    \ dataclasses.field(default_factory=list)\n\n    def __add_node(self, u: Path)\
    \ -> None:\n        if u not in self.ptoi:\n            self.itop.append(u)\n\
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
    \ line and \"Utils/\" not in line:\n                sp = line.split('\"')\n  \
    \              if len(sp) > 1:\n                    filepath = root / sp[1]\n\
    \                    self.includes.append(filepath.resolve())\n\n    def get_includes_graph(self,\
    \ graph_: Optional[Graph] = None) -> Graph:\n        graph = graph_ if graph_\
    \ else Graph()\n        for include_path in self.includes:\n            graph.add_edge(include_path,\
    \ self.filepath)\n            src = Source(include_path)\n            src.get_includes_graph(graph)\n\
    \        return graph\n\n\ndef replace(filepath: Path) -> str:\n    exclude_words\
    \ = [\n        \"#pragma once\",\n        \"#include\",\n    ]\n    ret = \"\"\
    \n    for line in open_src(filepath):\n        if all([ex not in line for ex in\
    \ exclude_words]):\n            ret += line\n    return ret\n\n\nif __name__ ==\
    \ \"__main__\":\n    args = sys.argv\n    if len(args) != 2:\n        raise RuntimeError(\"\
    USAGE: python {this file} {src file}\")\n\n    filepath = Path(args[1]).resolve()\n\
    \n    source = Source(filepath)\n    graph = source.get_includes_graph()\n\n \
    \   flag = 0\n    source_lst: list[str] = []\n    for line in open_src(filepath):\n\
    \        if \"tag:includes begin\" in line or \"tag:includes end\" in line:\n\
    \            flag += 1\n        elif flag == 1:\n\n            def f(filepath:\
    \ Path, replace_source: list):\n                if \"main.cpp\" not in str(filepath):\n\
    \                    replace_source.append(replace(filepath))\n\n            graph.topological_lambda(lambda\
    \ filepath: f(filepath, source_lst))\n            flag += 1\n        elif flag\
    \ == 0 or flag == 3:\n            source_lst.append(line)\n\n    print(\"\".join(source_lst))\n"
  dependsOn: []
  isVerificationFile: false
  path: command/inline_includes.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: command/inline_includes.py
layout: document
redirect_from:
- /library/command/inline_includes.py
- /library/command/inline_includes.py.html
title: command/inline_includes.py
---
