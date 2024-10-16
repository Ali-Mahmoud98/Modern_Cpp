# Set vs. Unordered Set
Here's a comparison table between `std::set` and `std::unordered_set` in C++, highlighting their key features, performance characteristics, and Big O notation for common operations:

| Feature                       | `std::set`                          | `std::unordered_set`                |
|-------------------------------|-------------------------------------|-------------------------------------|
| **Definition**                | An ordered collection of unique elements. | An unordered collection of unique elements. |
| **Underlying Data Structure** | Typically implemented as a balanced binary search tree (e.g., Red-Black Tree). | Typically implemented as a hash table. |
| **Ordering**                  | Elements are stored in sorted order based on the comparator (default is `std::less`). | Elements are not stored in any specific order. |
| **Time Complexity**           |                                     |                                     |
| - Insertion                   | O(log n)                            | O(1) average, O(n) worst-case (due to rehashing) |
| - Deletion                    | O(log n)                            | O(1) average, O(n) worst-case (due to rehashing) |
| - Search (Find)              | O(log n)                            | O(1) average, O(n) worst-case (due to rehashing) |
| **Memory Overhead**           | Generally lower memory overhead per element than `unordered_set`. | Higher memory overhead due to hash table implementation and potential rehashing. |
| **Iterators**                 | Iterators are valid even after insertions and deletions (but the order is based on the sorted nature of the set). | Iterators may be invalidated after rehashing. The order of elements is not guaranteed. |
| **Key Type**                  | Requires a key type that supports comparison operators (e.g., `operator<`). | Requires a key type that is hashable (supports `std::hash`) and equality comparable (`operator==`). |
| **Use Cases**                 | Useful when order matters, such as maintaining a sorted collection. | Useful when fast access and insertion are more important than order. |

### Summary of Big O Notation

- **Insertion**:
  - `std::set`: O(log n)
  - `std::unordered_set`: O(1) average, O(n) worst-case

- **Deletion**:
  - `std::set`: O(log n)
  - `std::unordered_set`: O(1) average, O(n) worst-case

- **Search (Find)**:
  - `std::set`: O(log n)
  - `std::unordered_set`: O(1) average, O(n) worst-case

### Conclusion
- Use `std::set` when you need elements to be stored in a specific order and when you are performing many search, insert, or delete operations where performance is acceptable at O(log n).
- Use `std::unordered_set` when you prioritize fast insertion and lookup times, and when the order of elements does not matter, keeping in mind that performance can degrade in worst-case scenarios due to hash collisions or rehashing.

### set and unordered_set element access methods
Certainly! In C++, both `std::set` and `std::unordered_set` provide several methods for accessing elements. Below are the key methods for both containers, including how to check for the presence of an element and how to iterate over their contents.

#### Accessing Elements in `std::set`

1. **Find an Element**:
   - **Method**: `find(const Key& key)`
   - **Description**: Searches for an element with the specified key. Returns an iterator to the found element or `end()` if not found.
   - **Example**:
     ```cpp
     std::set<int> mySet = {1, 2, 3};
     auto it = mySet.find(2);
     if (it != mySet.end()) {
         std::cout << "Found: " << *it << std::endl;  // Output: Found: 2
     }
     ```

2. **Count Occurrences**:
   - **Method**: `count(const Key& key)`
   - **Description**: Returns the number of occurrences of the specified key (will be 0 or 1 for `set` since it only contains unique elements).
   - **Example**:
     ```cpp
     int count = mySet.count(2);  // count will be 1 if found, 0 otherwise
     ```

3. **Iterating**:
   - **Method**: `begin()`, `end()`
   - **Description**: Returns iterators to the beginning and end of the set.
   - **Example**:
     ```cpp
     for (const auto& elem : mySet) {
         std::cout << elem << " ";  // Output: 1 2 3
     }
     ```

4. **Lower Bound**:
   - **Method**: `lower_bound(const Key& key)`
   - **Description**: Returns an iterator pointing to the first element not less than `key`.
   - **Example**:
     ```cpp
     auto it = mySet.lower_bound(2);  // it points to 2
     ```

5. **Upper Bound**:
   - **Method**: `upper_bound(const Key& key)`
   - **Description**: Returns an iterator pointing to the first element greater than `key`.
   - **Example**:
     ```cpp
     auto it = mySet.upper_bound(2);  // it points to 3
     ```

#### Accessing Elements in `std::unordered_set`

1. **Find an Element**:
   - **Method**: `find(const Key& key)`
   - **Description**: Searches for an element with the specified key. Returns an iterator to the found element or `end()` if not found.
   - **Example**:
     ```cpp
     std::unordered_set<int> myUnorderedSet = {1, 2, 3};
     auto it = myUnorderedSet.find(2);
     if (it != myUnorderedSet.end()) {
         std::cout << "Found: " << *it << std::endl;  // Output: Found: 2
     }
     ```

2. **Count Occurrences**:
   - **Method**: `count(const Key& key)`
   - **Description**: Returns the number of occurrences of the specified key (will be 0 or 1 for `unordered_set` since it only contains unique elements).
   - **Example**:
     ```cpp
     int count = myUnorderedSet.count(2);  // count will be 1 if found, 0 otherwise
     ```

3. **Iterating**:
   - **Method**: `begin()`, `end()`
   - **Description**: Returns iterators to the beginning and end of the unordered set.
   - **Example**:
     ```cpp
     for (const auto& elem : myUnorderedSet) {
         std::cout << elem << " ";  // Output order is not guaranteed
     }
     ```

4. **Bucket Interface**:
   - **Method**: `bucket_count()`, `bucket_size(size_t n)`
   - **Description**: Returns the number of buckets in the unordered set and the number of elements in the specified bucket, respectively.
   - **Example**:
     ```cpp
     std::cout << "Number of buckets: " << myUnorderedSet.bucket_count() << std::endl;
     ```

5. **Load Factor**:
   - **Method**: `load_factor()`
   - **Description**: Returns the average number of elements per bucket.
   - **Example**:
     ```cpp
     std::cout << "Load factor: " << myUnorderedSet.load_factor() << std::endl;
     ```

#### Summary of Access Methods

| Method                     | `std::set`                                | `std::unordered_set`                    |
|----------------------------|-------------------------------------------|-----------------------------------------|
| **Find Element**           | `find(const Key& key)`                   | `find(const Key& key)`                 |
| **Count Occurrences**      | `count(const Key& key)`                  | `count(const Key& key)`                |
| **Iterate**                | `begin()`, `end()`                       | `begin()`, `end()`                     |
| **Lower Bound**            | `lower_bound(const Key& key)`            | Not applicable                          |
| **Upper Bound**            | `upper_bound(const Key& key)`            | Not applicable                          |
| **Bucket Count**           | Not applicable                            | `bucket_count()`                        |
| **Bucket Size**            | Not applicable                            | `bucket_size(size_t n)`                |
| **Load Factor**            | Not applicable                            | `load_factor()`                         |

Both `std::set` and `std::unordered_set` provide similar interfaces for basic operations like finding and counting elements, but they differ in additional functionalities and performance characteristics due to their underlying implementations.

#### Accessing Elements Methods Big O Notation
Big O notation for common operations in `std::set` and `std::unordered_set` in C++:

| Operation              | `std::set`                      | `std::unordered_set`               |
|------------------------|----------------------------------|-------------------------------------|
| **Insertion**          | O(log n)                        | O(1) average, O(n) worst-case       |
| **Deletion**           | O(log n)                        | O(1) average, O(n) worst-case       |
| **Search (Find)**      | O(log n)                        | O(1) average, O(n) worst-case       |
| **Count**              | O(log n)                        | O(1) average, O(n) worst-case       |
| **Iteration**          | O(n)                            | O(n)                                 |
| **Lower Bound**        | O(log n)                        | Not applicable                       |
| **Upper Bound**        | O(log n)                        | Not applicable                       |
| **Bucket Count**       | Not applicable                  | O(1)                                 |
| **Bucket Size**        | Not applicable                  | O(1)                                 |
| **Load Factor**        | Not applicable                  | O(1)                                 |

