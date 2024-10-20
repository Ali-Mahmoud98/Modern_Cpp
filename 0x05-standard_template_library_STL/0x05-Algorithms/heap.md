### What is a Heap?

A **heap** is a specialized tree-based data structure that satisfies the **heap property**. There are two types of heaps:

1. **Max Heap**: In a max heap, for any given node `N`, the value of `N` is greater than or equal to the values of its children. This means the largest element is always at the root of the tree.

2. **Min Heap**: In a min heap, for any given node `N`, the value of `N` is less than or equal to the values of its children. This means the smallest element is always at the root.

### Heap Structure

- A heap is typically implemented as a **binary tree**. The structure is a complete binary tree, which means all levels of the tree are fully filled except possibly the last level, which is filled from left to right.
- Heaps are often implemented using **arrays** for efficiency, where:
  - The parent of a node at index `i` can be found at index `(i-1)/2`.
  - The left child can be found at index `2*i + 1`.
  - The right child can be found at index `2*i + 2`.

### Why Use a Heap?

1. **Efficient Priority Queue**: Heaps provide an efficient way to implement priority queues. They allow for quick access to the highest (or lowest) priority element, which can be crucial in many algorithms.
  
2. **Logarithmic Complexity**: Operations such as insertion (`push`) and deletion of the maximum (or minimum) element (`pop`) can be done in O(log N) time. This is faster than other data structures like arrays or linked lists, where such operations might take O(N).

3. **Dynamic Order Statistics**: Heaps can help maintain a dynamic dataset where you frequently need to access the largest or smallest elements.

4. **Sorting**: The heap sort algorithm utilizes heaps to sort elements in O(N log N) time.

### Use Cases for Heaps

1. **Priority Queues**:
   - **Example**: Job scheduling in operating systems. Tasks with higher priority need to be executed before tasks with lower priority. A max heap can efficiently manage such a queue.

2. **Graph Algorithms**:
   - **Example**: Dijkstra’s and Prim’s algorithms use heaps to efficiently extract the minimum edge weight from a set of edges.

3. **Median Finding**:
   - Heaps can be used to maintain the median of a stream of numbers by using two heaps (a max heap for the lower half and a min heap for the upper half).

4. **Sorting**:
   - The **heap sort** algorithm sorts an array in O(N log N) time using a heap. This is useful when you want a sorting algorithm that is not based on comparisons (like merge sort) and has good worst-case performance.

5. **Dynamic Data Processing**:
   - Heaps are useful in scenarios where data is continually being added and removed, and there’s a need to always access the highest or lowest value efficiently.

### Max Heap Example

Let's say we have the following numbers: **{20, 15, 30, 10, 5, 25}**.

Here's how a max heap structure would look:

```
       30
      /  \
    20    25
   / \    /
  10  15 5
```

- **Properties**:
  - The largest element (30) is at the root.
  - Every parent node is greater than or equal to its child nodes.

### Min Heap Example

Now, let's consider the same numbers, but organized in a min heap:

```
       5
      / \
    10   15
   / \   /
  20  30 25
```

- **Properties**:
  - The smallest element (5) is at the root.
  - Every parent node is less than or equal to its child nodes.

### Array Representation

Heaps can also be represented as arrays. For the above heaps:

- **Max Heap Array Representation**: `{30, 20, 25, 10, 15, 5}`
- **Min Heap Array Representation**: `{5, 10, 15, 20, 30, 25}`

### How the Structure Works

- **For a Max Heap**:
  - The parent of the element at index `i` is found at index `(i - 1) / 2`.
  - The left child is at index `2 * i + 1`.
  - The right child is at index `2 * i + 2`.

- **For a Min Heap**, the same rules apply, but the relationship is inverted (i.e., parents are smaller than children).

### Visualizing Operations

#### Insert Operation (Max Heap)

If you were to insert **35** into the max heap:

1. Place **35** at the next available position (which is the next right-most leaf).
2. Compare with its parent (30).
3. Since 35 > 30, you swap them.

Resulting Max Heap:

```
       35
      /  \
    30    25
   / \    / \
  10  15 5
```

#### Delete Operation (Max Heap)

When you remove the maximum element (the root):

1. Move the last element (5) to the root.
2. Compare with its children (30 and 25).
3. Swap with the larger child (30).

Resulting Max Heap after adjustment:

```
       30
      /  \
    10    25
   / \
  5  15
```

### time complexities for various operations commonly associated with heaps, particularly for both **max heaps** and **min heaps**:

| **Operation**            | **Time Complexity** | **Description**                                                                 |
|--------------------------|---------------------|---------------------------------------------------------------------------------|
| **Build Heap**           | O(N)                | Constructing a heap from an unordered array using `std::make_heap`.            |
| **Insertion (Push)**     | O(log N)            | Adding a new element to the heap using `std::push_heap`.                       |
| **Deletion (Pop)**       | O(log N)            | Removing the maximum (or minimum) element from the heap using `std::pop_heap`. |
| **Find Max/Min**         | O(1)                | Accessing the root of the heap (the maximum or minimum element).               |
| **Heap Sort**            | O(N log N)          | Sorting an array using heap sort (`std::sort_heap`).                           |
| **Decrease Key**         | O(log N)            | Decreasing the value of a key in the heap (commonly used in Dijkstra's algorithm). |
| **Extract Max/Min**      | O(log N)            | Removing the root and maintaining heap properties.                              |
| **Merge Heaps**          | O(N)                | Merging two heaps efficiently (not a standard operation, typically involves building a new heap). |
