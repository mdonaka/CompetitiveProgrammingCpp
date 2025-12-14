# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Response Language

Always respond in Japanese (日本語で回答すること).

## Overview

C++20 competitive programming library with automatic verification via online-judge-verify-helper. Library documentation is published at https://mdonaka.github.io/CompetitiveProgrammingCpp/

## Build Commands

```bash
make c              # Compile main.cpp
make r              # Compile and run with input from file 'i'
make ri             # Compile and run without input
make y              # Inline includes and copy to clipboard (for submission)
make i              # Reset main.cpp from template
make t              # Run comparison test (main vs main_correct with testcases)
make ti             # Run interactive test
make clean          # Clean build artifacts
```

The compiler uses `-std=c++2b -O2 -D DEBUG -I /ac-library` with warnings enabled.

## Verification

Tests use online-judge-verify-helper with problems from Yosupo's Judge and AOJ:
```bash
pip install online-judge-verify-helper
oj-verify all       # Run all verification tests
```

Test files in `Test/` use `#define PROBLEM "url"` to specify the target problem.

## Code Architecture

### Library Structure (`Library/`)

All library code is in the `mtd` namespace.

- **Algebraic/**: Abstract algebra structures (Monoid, Group, SemiGroup) used as template parameters for data structures
- **DataStructure/**: Segment trees (normal, lazy, dynamic, Li-Chao), Convex Hull Trick, DSU, sparse tables, etc.
- **Graph/**: Graph algorithms organized by type:
  - `Normal/`: BFS, Dijkstra, Kruskal, Prim, SCC, Warshall-Floyd, Topological sort
  - `Tree/`: LCA, HLD, Euler Tour, Re-rooting DP, Auxiliary Tree
  - `Flow/`: Dinic, Ford-Fulkerson, Min-cost flow
- **Math/**: ModInt, Convolution (NTT), Matrix, Prime utilities, Zeta/Mobius transforms
- **String/**: Suffix Array, LCP Array, Z-Algorithm, Trie, Palindromic Tree, Rolling Hash
- **Algorithms/**: Binary search, Coordinate compression, Mo's algorithm
- **Range/**: Custom range utilities and views for C++20 ranges
- **Utility/**: I/O helpers (`mtd::io::in<T>()`), Y-combinator, tuple utilities

### Template System

`Library/Main/main.cpp` is the competition template. The `make y` command processes `begin:tag`/`end:tag` markers to inline includes for submission.

Input pattern examples from template:
```cpp
auto [n] = mtd::io::in<ll>();
auto [a] = mtd::io::in<std::vector<ll>>(n);
auto [n, m] = mtd::io::in<ll, ll>();
```

### Data Structure Patterns

Data structures use algebraic type parameters:
```cpp
using M = mtd::Monoid<ll, identity_value, binary_op>;
auto segtree = mtd::SegmentTree<M>(n);
```

## Code Style

Uses Google-based clang-format with modifications: namespace indentation, short statements on single lines allowed.
