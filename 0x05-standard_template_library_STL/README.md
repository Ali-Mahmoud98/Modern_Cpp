# C++ Standard Template Library (STL)

The C++ Standard Template Library (STL) is a set of template classes and functions that provides the implementation of common data structures and algorithms such as lists, stacks, arrays, sorting, searching, etc. It also provides the iterators and functors which makes it easier to work with algorithms and containers.

STL was originally designed by Alexander Stepanov and was later accepted as the part of C++ standard in C++ 98. It is a generalized library so we can use it with almost every data type without repeating the implementation code.

## RESOURCES:
* [C++ Standard Template Library (STL) - GFG](https://www.geeksforgeeks.org/the-c-standard-template-library-stl/)
* [C++ Standard Library - Microsoft](https://learn.microsoft.com/en-us/cpp/standard-library/cpp-standard-library-overview?view=msvc-170)
* [STL Containers - Microsoft](https://learn.microsoft.com/en-us/cpp/standard-library/stl-containers?view=msvc-170)
* [Iterators - Microsoft](https://learn.microsoft.com/en-us/cpp/standard-library/iterators?view=msvc-170)

### Components of STL
The components of STL are the features provided by Standard Template Library (STL) in C++ that can be classified into 4 types:
1. Containers
2. Algorithms
3. Iterators
4. Functors

These components are designed to be efficient, flexible, and reusable, making them an integral part of modern C++ programming.

The **Standard Template Library (STL)** in C++ is a powerful and flexible library that provides generic classes and functions to work with data structures and algorithms. It allows developers to write code that is more efficient, reusable, and easier to maintain. STL is divided into four main components:

### 1. **Containers**
Containers are data structures that store objects and manage collections of them. STL offers several types of containers, which can be broadly classified into three categories:

- **Sequence Containers**: These maintain elements in a linear order.
  - **`vector`**: Dynamic array that allows fast random access but slower insertion and deletion in the middle.
  - **`deque`**: Double-ended queue that allows fast insertions and deletions at both ends.
  - **`list`**: Doubly linked list that allows fast insertion and deletion but slow random access.

- **Associative Containers**: These are designed for fast retrieval of data based on keys.
  - **`set`**: Collection of unique keys, sorted by the keys.
  - **`multiset`**: Similar to `set`, but allows duplicate keys.
  - **`map`**: Stores key-value pairs, where keys are unique and sorted.
  - **`multimap`**: Similar to `map`, but allows duplicate keys.

- **Container Adapters**: These are containers with restricted interfaces, built on top of other containers.
  - **`stack`**: LIFO (Last In, First Out) structure based on `deque` or `vector`.
  - **`queue`**: FIFO (First In, First Out) structure based on `deque` or `list`.
  - **`priority_queue`**: A heap structure, where the highest priority element is served first.

### 2. **Iterators**
Iterators are used to traverse through the elements of a container. They act as an abstraction for pointers and provide a uniform interface for accessing elements in a collection. STL provides several types of iterators:

- **Input Iterator**: Can only read the values in a sequence in a single pass (e.g., `istream_iterator`).
- **Output Iterator**: Can only write values in a sequence in a single pass (e.g., `ostream_iterator`).
- **Forward Iterator**: Can read and write values, can traverse forward (e.g., `forward_list`).
- **Bidirectional Iterator**: Can traverse both forward and backward (e.g., `list`, `set`).
- **Random Access Iterator**: Provides access to elements by index and supports arithmetic operations (e.g., `vector`, `deque`).

### 3. **Algorithms**
STL provides many built-in algorithms for performing common operations on containers, like searching, sorting, and manipulating sequences of data. Some of the common algorithms are:

- **`sort`**: Sorts the elements in a range.
- **`find`**: Finds the first element in a range that matches a value.
- **`accumulate`**: Computes the sum of elements in a range.
- **`count`**: Counts the occurrences of a value in a range.
- **`binary_search`**: Checks if an element exists in a sorted range.

These algorithms can work with any container that supports iterators, making them very versatile and reusable.

### 4. **Functors (Function Objects)**
A **functor** is an object that can be called as if it were a function. STL algorithms often accept functors as arguments to customize their behavior. Functors allow you to define custom comparison logic for sorting, filtering, or other operations.

For example, a functor for custom sorting might look like this:

```cpp
struct CustomCompare {
    bool operator()(int a, int b) {
        return a > b; // Sort in descending order
    }
};
```

You can pass `CustomCompare` to the `sort` algorithm to sort in descending order:

```cpp
std::vector<int> vec = {4, 2, 7, 1, 9};
std::sort(vec.begin(), vec.end(), CustomCompare());
```

### Key Benefits of Using STL
1. **Efficiency**: STL containers and algorithms are optimized for performance.
2. **Reusability**: By using templates, STL works with any data type, reducing the need to write custom data structures.
3. **Code Clarity**: STL abstracts complex operations (like sorting or searching), making code more readable and maintainable.

### Example Usage:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {10, 5, 8, 3, 9, 2};
    
    // Sort the vector using the STL sort algorithm
    std::sort(numbers.begin(), numbers.end());

    // Display sorted numbers
    for (int n : numbers) {
        std::cout << n << " ";
    }

    return 0;
}
```

This example demonstrates the usage of the `vector` container and the `sort` algorithm to arrange the numbers in ascending order.

In summary, STL is an essential part of modern C++ programming, enabling developers to write efficient and generic code through its well-designed containers, iterators, algorithms, and functors.
