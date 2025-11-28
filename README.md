# Simple Data Structures Visualizer

![Language](https://img.shields.io/badge/C%2B%2B-11-blue.svg)
![Build](https://img.shields.io/badge/Build-Make-green.svg)
![Platform](https://img.shields.io/badge/Platform-cross--platform-blue.svg)
![License](https://img.shields.io/badge/License-MIT-green.svg)

## Project Overview

A small C++ project that demonstrates implementations and simple visual/textual demos of classic data structures and algorithms. It provides a terminal-style visualizer for:

- Singly and doubly linked lists
- Vector (dynamic array) operations via `VectorManager`
- Sorting algorithms (Bubble, Insertion, Merge, Quick)
- Search demonstrations (Linear and Binary Search)

The demo executable prints labeled sections showing operations, results, and complexity summaries so learners can compare theoretical complexity with measured runtimes.

## 🎯 Purpose

Teach and demonstrate core data structure behaviors and algorithmic runtimes using readable C++ code and a lightweight terminal demo. This repo is suitable for beginners learning C++ and algorithmic thinking.

## ✨ Features

### Core Functionality

- Linked lists (singly/doubly): insertions, deletions, search, forward/backward display
- Vector manager: add, remove, fill random, clear, display
- Sorting algorithms: Bubble, Insertion, Merge, Quick with measured runtimes
- Searches: Linear search (vector and linked list) and Binary search (vector)
- Terminal-style demo: clear, labeled sections with Big‑O summaries and sample outputs

### Technical Highlights

- Practical C++11 code with simple classes and RAII for memory management
- Timing via `std::chrono` for empirical algorithm runtimes
- Small, readable implementations designed for teaching and extension

## 🛠️ Tech Stack

- **Language**: C++11
- **Build**: Makefile
- **Libraries**: Standard Library (vector, chrono, algorithm, iostream)
- **Platform**: Cross-platform (Linux, macOS, Windows with a compatible compiler)

## Getting Started

Clone the repo and build using `make` (the default `make` target now builds and runs the demo):

```bash
git clone <repo-url>
cd SimpleDataStructuresVisualizer
make
```

The demo binary is produced at `bin/demo` and will run automatically when you run `make` (or `make test`). To build without running:

```bash
make all
```

To clean build artifacts:

```bash
make clean
```

## Demo Sections

The demo prints the following labeled sections:

- Singly Linked List Demo — shows insert head/tail, search, delete and complexity summary
- Doubly Linked List Demo — shows forward/backward display, delete and complexity summary
- Sorting Algorithms Demo — runs Bubble/Insertion on smaller n, Merge/Quick on larger n, prints measured ms and theoretical runtimes
- Vector Manager Demo — sample vector operations and complexity summary
- Search Demo — Linear search on vector and linked list, Binary search on sorted vector, and complexity summary

## Examples (expected output snippets)

Singly Linked List Demo:
```
===== Singly Linked List Demo =====
Insert head 5
5
Insert head 3
3 -> 5
Insert tail 9
3 -> 5 -> 9
Search for 5 -> position: 2
Delete value 3
Deleted 3
5 -> 9
Complexities (Singly Linked List):
  Access: O(n) | Search: O(n) | Insert head: O(1) | Insert tail: O(n) | Delete: O(n)
```

Sorting Algorithms Demo (snippet):
```
Bubble Sort on n=2000: 14 ms
Merge Sort on n=200000: 111 ms
Quick Sort on n=200000: 25 ms
Runtimes (Sorting):
  Bubble: O(n^2) | Insertion: O(n^2) | Merge: O(n log n) | Quick: O(n log n) average, O(n^2) worst
```

Search Demo (snippet):
```
Linear search in vector for 9 -> position 5
Linear search in linked list for 1 -> position 4
Binary search for 4 in sorted vector: found
Complexities (Search):
  Linear search (vector or linked list): O(n)
  Binary search (vector only, requires sorted): O(log n)
```

## Extending the Project

- Add more data structures (stacks, queues, binary trees)
- Add visualization output (e.g., Graphviz or a small GUI) for graphical views
- Add unit tests and a `make test` integration for regression checks
- Add benchmarking targets with CSV output for plotting

## License

MIT License — see `LICENSE` file.

---

If you'd like, I can:
- Add a `LICENSE` file with MIT text
- Add unit tests (Catch2 or GoogleTest) and a `make test` target
- Produce a minimal GUI/web view for the data structure visualizations

Which would you like next?
