
# 🚀 LeetCode Solutions: Segment Tree Deep Dive

## Short Description
Dive deep into the world of Segment Trees with this comprehensive repository, featuring highly optimized C++ implementations for a variety of challenging problems found on platforms like LeetCode. This collection is your go-to resource for mastering efficient range queries, updates, and complex problem-solving using one of competitive programming's most powerful data structures. Whether you're tackling sum, min, or max queries, or solving intricate real-world scenarios, this project provides robust, performant solutions designed for peak efficiency.

## ✨ Key Features
*   **Fundamental Segment Tree Operations:** Core implementations for building, querying, and updating Segment Trees.
*   **Range Sum Queries:** Efficiently calculate sums over specified ranges, including mutable array support.
*   **Range Minimum/Maximum Queries:** Quickly find the minimum or maximum element within any given range.
*   **Advanced Problem Solutions:** Tackle complex problems like finding meeting points in buildings (`FindBuildingWhereAlice_and_BobCanMeet.cpp`) or counting good triplets (`count_good_triplets_in_array.cpp`) with Segment Tree optimizations.
*   **C++ Optimized:** Crafted for performance using modern C++ best practices, ideal for competitive programming environments.

## Who is this for?
This repository is tailor-made for:
*   **Competitive Programmers:** Looking to hone their skills in advanced data structures and algorithms.
*   **Algorithm Enthusiasts:** Eager to understand and implement Segment Trees for various applications.
*   **Students & Learners:** Seeking practical, well-structured examples to grasp the nuances of range query problems.
*   **Interview Preparation:** A valuable resource for practicing common data structure problems often encountered in technical interviews.

## Technology Stack & Architecture
This project is built primarily with:
*   **Language:** C++
*   **Core Data Structure:** Segment Tree
*   **Environment:** Designed for standard C++ compilers (e.g., g++)

The architecture centers around the Segment Tree itself, a binary tree used for storing information about intervals or segments. It allows querying for information about any range (e.g., sum, min, max) in `O(logN)` time and updating an element in `O(logN)` time, making it exceptionally efficient for problems involving large datasets and frequent range operations.

## 📊 Architecture & Database Schema
While this project doesn't feature a traditional database, the core architectural flow revolves around the Segment Tree data structure. Here’s a conceptual diagram illustrating its operational flow:

```mermaid
graph TD
    A["Input Data Array (e.g., Numbers, Elements)"] --> B["Build Segment Tree (O(N) Time)"];
    B -- "Recursive Division" --> C["Leaf Nodes Represent Single Elements"];
    C -- "Merge Upwards" --> D["Internal Nodes Store Aggregates (Sum, Min, Max)"];
    D --> E1["Query Operation (e.g., "Range Sum", "Min", "Max")"];
    D --> E2["Update Operation (e.g., "Modify Element at Index")"];
    E1 -- "Traverse Tree" --> F1["Return Range Query Result (O(logN) Time)"];
    E2 -- "Update Path to Root" --> F2["Segment Tree Updated (O(logN) Time)"];
    F2 --> E1;
    F1 --> G["Problem Solution / Application"];
    F2 --> G["Problem Solution / Application"];
```

## ⚡ Quick Start Guide
To get started with these Segment Tree implementations:

1.  **Clone the Repository:**
    ```bash
    git clone https://github.com/grewal16/leetcode.git
    cd leetcode/segmentTree
    ```

2.  **Compile a Specific Solution:**
    Choose any `.cpp` file (e.g., `buildTree.cpp` or `query_sum.cpp`).
    ```bash
    g++ -std=c++17 -Wall -O2 buildTree.cpp -o buildTree
    ```

3.  **Run the Executable:**
    ```bash
    ./buildTree
    ```

4.  **Experiment:**
    Modify the C++ files to test different inputs or integrate the Segment Tree logic into your own projects. Each file is self-contained and demonstrates a specific aspect or application of the Segment Tree.
