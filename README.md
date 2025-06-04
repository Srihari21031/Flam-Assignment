# Flam-Assignment


This repository provides implementations for four different problems in C++. Each solution is optimized for performance and clarity.

---

## 📚 Contents

1. [LRU Cache](#1-lru-cache)
2. [Custom HashMap (Without STL)](#2-custom-hashmap-without-stl)
3. [N-Queens Puzzle](#3-n-queens-puzzle)
4. [Cycle Detection in Directed Graph](#4-cycle-detection-in-directed-graph)

---
## 1. LRU Cache

**Problem Statement:**  
Design and implement a Least Recently Used (LRU) Cache. A cache has a fixed capacity, and when it exceeds that capacity, it must evict the least recently used item to make space for the new one.

Implement the following operations:
- `get(key)`: Return the value of the key if it exists in the cache, otherwise return -1.
- `put(key, value)`: Update or insert the value. If the cache is full, remove the least recently used item before inserting.

**Constraints:**
- 1 <= capacity <= 3000  
- 0 <= key, value <= 10^4  
- Maximum operations: 10^5  
- All operations must be done in O(1) time complexity.

---

## 2. Custom HashMap

**Problem Statement:**  
You are required to implement a simplified version of a HashMap without using built-in hash table libraries like `unordered_map`, `map`, `dict`, etc.

Implement the following operations:
- `put(key, value)`: Insert or update the value by key.
- `get(key)`: Return the value associated with the key. If not found, return -1.
- `remove(key)`: Remove the key from the map.

**Constraints:**
- 0 <= key, value <= 10^6  
- Keys are unique within the map  
- Maximum operations: 10^5  
- Do not use built-in hash maps or dictionaries.

---

## 3. N-Queens Puzzle

**Problem Statement:**  
The n-queens puzzle is the problem of placing `n` queens on an `n x n` chessboard such that no two queens attack each other.

Given an integer `n`, return all distinct solutions to the n-queens puzzle. You may return the answer in any order. Each solution contains a distinct board configuration of the queen’s placement, where `'Q'` and `'.'` indicate a queen and an empty space respectively.

**Constraints:**
- 1 <= n <= 9

**Example (n = 4):**
[
[".Q..","...Q","Q...","..Q."],
["..Q.","Q...","...Q",".Q.."]
]

---

## 4. Cycle Detection in Directed Graph

**Problem Statement:**  
You are building a module loader for a large software system. Each module may depend on one or more other modules. Before loading, you must ensure that the dependencies do not contain any circular dependency, as that would lead to infinite loading loops.

Given a list of `n` modules and their dependency relationships, determine if the dependency graph contains a cycle.

**Function Signature:**
```cpp
bool hasCircularDependency(int n, vector<vector<int>>& edges);
Constraints:

1 <= n <= 10^4

0 <= edges.length <= 10^5

Self-dependencies like {a, a} are valid and considered a cycle

The graph can have multiple disconnected components

Example:
Input: n = 4, edges = {{0, 1}, {1, 2}, {2, 0}}
Output: true


## 1. LRU Cache

**Problem Statement:**  
Design and implement a Least Recently Used (LRU) Cache. A cache has a fixed capacity, and when it exceeds that capacity, it must evict the least recently used item to make space for the new one.

Implement the following operations:
- `get(key)`: Return the value of the key if it exists in the cache, otherwise return -1.
- `put(key, value)`: Update or insert the value. If the cache is full, remove the least recently used item before inserting.

**Constraints:**
- 1 <= capacity <= 3000  
- 0 <= key, value <= 10^4  
- Maximum operations: 10^5  
- All operations must be done in O(1) time complexity.

---








