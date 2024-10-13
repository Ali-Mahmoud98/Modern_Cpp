# Deque in C++ Standard Template Library (STL)

**Double-ended queues** are sequence containers with the feature of expansion and contraction on both ends. They are **similar to vectors, but are more efficient in case of insertion and deletion of elements**. Unlike vectors, contiguous storage allocation may not be guaranteed. 

Double Ended Queues are basically an implementation of the data structure double-ended queue. A queue data structure allows insertion only at the end and deletion from the front. This is like a queue in real life, wherein people are removed from the front and added at the back. Double-ended queues are a special case of queues where insertion and deletion operations are possible at both the ends.

**The time complexities for doing various operations on deques are:**
* Accessing Elements- `O(1)`
* Insertion or removal of elements- `O(N)`
* Insertion or removal of elements at start or end- `O(1)`

### Key Features of `std::deque`:

1. **Dynamic Sizing**:
   - Like `std::vector`, a `deque` can dynamically resize to accommodate more elements as needed. However, instead of being backed by a contiguous memory block like `std::vector`, a `deque` is implemented as a sequence of fixed-size arrays (or blocks), which allows efficient memory management for both front and back insertions.

2. **Fast Access**:
   - Provides **random access** to elements, similar to `std::vector`. You can access any element in constant time `O(1)` using `operator[]` or `at()`.
   
3. **Efficient Insertion/Deletion**:
   - Supports fast insertion and deletion at both the **front** and **back** (`O(1)` for both). This is a key advantage over `std::vector`, which only has `O(1)` insertion and deletion at the back.
   
4. **No Memory Reallocation**:
   - Unlike `std::vector`, `std::deque` does not invalidate pointers and references after adding elements to the front or back unless the entire container is restructured. This makes it more stable in some scenarios where `std::vector` might reallocate its entire block of memory.
   
5. **Non-contiguous Memory**:
   - Unlike `std::vector`, which stores all its elements in contiguous memory, `std::deque` divides its elements across multiple chunks of memory. This makes it less cache-friendly than `std::vector` but more efficient when it comes to insertion at both ends.

6. **Iterators**:
   - `std::deque` supports iterators that allow traversal and manipulation of elements. Random access iterators can be used, just like with `std::vector`, allowing easy integration with STL algorithms (like `std::sort`, `std::find`, etc.).

### Use Cases for `std::deque`:
- **Bidirectional Queue**: When you need a double-ended queue where elements can be added or removed from both ends efficiently.
- **Sliding Window Algorithms**: `std::deque` is commonly used in sliding window problems where you need to access and update the front and back efficiently.
- **Undo/Redo Functionality**: `std::deque` can be used to store history where operations are pushed and popped from either the front or back, depending on the current state.

### Performance Characteristics:

| Operation               | `std::deque` Complexity | `std::vector` Complexity |
|-------------------------|-------------------------|--------------------------|
| Random Access           | `O(1)`                  | `O(1)`                   |
| Insertion at Back       | `O(1)`                  | `O(1)`                   |
| Insertion at Front      | `O(1)`                  | `O(n)`                   |
| Insertion in Middle     | `O(n)`                  | `O(n)`                   |
| Deletion at Back        | `O(1)`                  | `O(1)`                   |
| Deletion at Front       | `O(1)`                  | `O(n)`                   |
| Deletion in Middle      | `O(n)`                  | `O(n)`                   |

### Deque Fucnctions:

| **Function**                      | **Description**                                                                                      |
|-----------------------------------|------------------------------------------------------------------------------------------------------|
| **`push_back(const T& value)`**   | Adds an element to the **back** of the deque.                                                         |
| **`push_front(const T& value)`**  | Adds an element to the **front** of the deque.                                                        |
| **`pop_back()`**                  | Removes the last element from the deque.                                                              |
| **`pop_front()`**                 | Removes the first element from the deque.                                                             |
| **`size()`**                      | Returns the number of elements in the deque.                                                          |
| **`operator[](size_type pos)`**   | Provides access to the element at position `pos` (no bounds checking).                               |
| **`at(size_type pos)`**           | Provides access to the element at position `pos`, with bounds checking. Throws `out_of_range` if invalid. |
| **`front()`**                     | Returns a reference to the first element in the deque.                                                |
| **`back()`**                      | Returns a reference to the last element in the deque.                                                 |
| **`clear()`**                     | Removes all elements from the deque.                                                                  |
| **`empty()`**                     | Checks if the deque is empty, returns `true` if there are no elements.                                |
| **`insert(iterator pos, const T& value)`** | Inserts an element at the specified position, shifting subsequent elements.                         |
| **`erase(iterator pos)`**         | Removes the element at the specified position, shifting subsequent elements.                          |
| **`swap(std::deque<T>& other)`**  | Swaps the contents of this deque with another deque.                                                  |
| **`begin()`**                     | Returns an iterator to the first element of the deque.                                                |
| **`end()`**                       | Returns an iterator to the element **past the last** element of the deque.                            |
| **`rbegin()`**                    | Returns a reverse iterator to the last element of the deque.                                          |
| **`rend()`**                      | Returns a reverse iterator to the element **before the first** element of the deque.                  |
| **`emplace_back(args...)`**       | Constructs an element in-place at the back of the deque, without extra copying or moving.             |
| **`emplace_front(args...)`**      | Constructs an element in-place at the front of the deque, without extra copying or moving.            |
| **`emplace(iterator pos, args...)`** | Constructs an element in-place at the specified position.                                          |
| **`resize(size_type count)`**     | Resizes the deque to contain `count` elements. If the new size is larger, new elements are added with default values. |
| **`shrink_to_fit()`**             | Reduces the capacity of the deque to fit its size, freeing any excess memory.                         |
| **`assign(size_type count, const T& value)`** | Assigns `count` copies of `value` to the deque, replacing its current contents.                  |
| **`reserve(size_type new_cap)`**  | Requests a change in capacity to at least `new_cap`.                                                  |


### References:
* [Deque in C++ STL - GeeksforGeeks](https://www.geeksforgeeks.org/deque-cpp-stl/)
* [Deque in C++ STL - C++ Reference](https://en.cppreference.com/w/cpp/container/deque)
