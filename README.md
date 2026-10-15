# Custom C++ Dynamic Array Container (`Vector<T>`)

A lightweight, header-only, low-latency dynamic array implementation in modern C++17. Designed with custom memory management, strict exception safety, and standard-compliant move semantics.

---

## Key Technical Features

* **Generic Template Interface**: Supports arbitrary datatypes using C++ Templates (`Vector<T>`).
* **Zero-Allocation Default Construction**: Avoids dynamic memory allocation until necessary.
* **Amortized $O(1)$ Growth Rate**: Dynamic reallocation strategy with a $2\times$ growth factor upon capacity exhaustion.
* **Modern C++ Move Semantics (Rule of 5)**: Implements resource stealing via rvalue references (`T&&`) and `std::move` to bypass redundant heap allocations.
* **Bounds Checking & Exception Handling**: Safe element access through `.at()` with `std::out_of_range` exception throwing, alongside fast unchecked `operator[]`.
* **Const Correctness & Exception Guarantees**: Non-throwing getter interfaces marked with `noexcept`.

---

## Performance & Complexity

| Operation | Complexity | Description |
| :--- | :--- | :--- |
| `operator[]` | $O(1)$ | Direct unchecked access |
| `at()` | $O(1)$ | Bounds-checked element access |
| `push_back()` | $O(1)$ amortized | $O(N)$ during capacity reallocation |
| `pop_back()` | $O(1)$ | Decrements size without reallocating |
| `Move Constructor` | $O(1)$ | Steals raw memory pointer from source |
| `Copy Constructor` | $O(N)$ | Deep copy allocation and element assignment |

---

## Getting Started

### Prerequisites

* C++17 compatible compiler (`g++` >= 8.0 or `clang++` >= 7.0)

### Building and Running

```bash
clang++ -std=c++17 main.cpp -o main
./main
