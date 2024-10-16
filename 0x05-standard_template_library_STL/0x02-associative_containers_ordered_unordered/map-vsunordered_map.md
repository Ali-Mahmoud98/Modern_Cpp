# Map vs Unordered Map
Here's a comparison table summarizing the key features, performance characteristics, and Big O notation for common operations in `std::map` and `std::unordered_map` in C++.

| Feature                     | `std::map`                            | `std::unordered_map`                |
|-----------------------------|---------------------------------------|-------------------------------------|
| **Definition**              | An ordered collection of key-value pairs. | An unordered collection of key-value pairs. |
| **Underlying Data Structure** | Typically implemented as a balanced binary search tree (e.g., Red-Black Tree). | Typically implemented as a hash table. |
| **Ordering**                | Keys are stored in sorted order based on the comparator (default is `std::less`). | Keys are not stored in any specific order. |
| **Time Complexity**         |                                       |                                     |
| - Insertion                 | O(log n)                              | O(1) average, O(n) worst-case (due to rehashing) |
| - Deletion                  | O(log n)                              | O(1) average, O(n) worst-case (due to rehashing) |
| - Search (Find)             | O(log n)                              | O(1) average, O(n) worst-case (due to rehashing) |
| - Count                     | O(log n)                              | O(1) average, O(n) worst-case (due to rehashing) |
| **Memory Overhead**         | Generally lower memory overhead per element compared to `unordered_map`. | Higher memory overhead due to hash table implementation and potential rehashing. |
| **Iterators**               | Iterators are valid and maintain order (in sorted order) even after insertions and deletions. | Iterators may be invalidated after rehashing. The order of elements is not guaranteed. |
| **Key Type**                | Requires a key type that supports comparison operators (e.g., `operator<`). | Requires a key type that is hashable (supports `std::hash`) and equality comparable (`operator==`). |
| **Use Cases**               | Useful when order matters, such as maintaining a sorted collection of key-value pairs. | Useful when fast access and insertion are more important than order. |

### Summary of Big O Notation

- **Insertion**:
  - `std::map`: O(log n)
  - `std::unordered_map`: O(1) average, O(n) worst-case

- **Deletion**:
  - `std::map`: O(log n)
  - `std::unordered_map`: O(1) average, O(n) worst-case

- **Search (Find)**:
  - `std::map`: O(log n)
  - `std::unordered_map`: O(1) average, O(n) worst-case

- **Count**:
  - `std::map`: O(log n)
  - `std::unordered_map`: O(1) average, O(n) worst-case

### Conclusion
- Use `std::map` when you need key-value pairs to be stored in a specific order and when performance at O(log n) is acceptable for insertions and lookups.
- Use `std::unordered_map` when you prioritize fast insertion and lookup times, and when the order of key-value pairs does not matter, keeping in mind that performance can degrade in worst-case scenarios due to hash collisions or rehashing.


Both `std::map` and `std::unordered_map` in C++ provide several methods for accessing elements. Below are the key methods for both containers, including how to check for the presence of an element and how to iterate over their contents.

### Accessing Elements in `std::map`

1. **Element Access**:
   - **Method**: `operator[]`
   - **Description**: Returns a reference to the value associated with the specified key. If the key does not exist, it will insert a new element with a default value.
   - **Example**:
     ```cpp
     std::map<int, std::string> myMap;
     myMap[1] = "One"; // Inserts (1, "One")
     std::cout << myMap[1]; // Output: One
     ```

2. **Find an Element**:
   - **Method**: `find(const Key& key)`
   - **Description**: Searches for an element with the specified key. Returns an iterator to the found element or `end()` if not found.
   - **Example**:
     ```cpp
     auto it = myMap.find(1);
     if (it != myMap.end()) {
         std::cout << "Found: " << it->second; // Output: Found: One
     }
     ```

3. **Count Occurrences**:
   - **Method**: `count(const Key& key)`
   - **Description**: Returns the number of occurrences of the specified key (will be 0 or 1 for `map` since it only contains unique keys).
   - **Example**:
     ```cpp
     int count = myMap.count(1); // count will be 1 if found, 0 otherwise
     ```

4. **Iterating**:
   - **Method**: `begin()`, `end()`
   - **Description**: Returns iterators to the beginning and end of the map.
   - **Example**:
     ```cpp
     for (const auto& pair : myMap) {
         std::cout << pair.first << ": " << pair.second << " "; // Output: 1: One
     }
     ```

5. **Lower Bound**:
   - **Method**: `lower_bound(const Key& key)`
   - **Description**: Returns an iterator pointing to the first element not less than `key`.
   - **Example**:
     ```cpp
     auto it = myMap.lower_bound(1); // it points to the element with key 1
     ```

6. **Upper Bound**:
   - **Method**: `upper_bound(const Key& key)`
   - **Description**: Returns an iterator pointing to the first element greater than `key`.
   - **Example**:
     ```cpp
     auto it = myMap.upper_bound(1); // it points to the next element after key 1
     ```

### Accessing Elements in `std::unordered_map`

1. **Element Access**:
   - **Method**: `operator[]`
   - **Description**: Returns a reference to the value associated with the specified key. If the key does not exist, it will insert a new element with a default value.
   - **Example**:
     ```cpp
     std::unordered_map<int, std::string> myUnorderedMap;
     myUnorderedMap[1] = "One"; // Inserts (1, "One")
     std::cout << myUnorderedMap[1]; // Output: One
     ```

2. **Find an Element**:
   - **Method**: `find(const Key& key)`
   - **Description**: Searches for an element with the specified key. Returns an iterator to the found element or `end()` if not found.
   - **Example**:
     ```cpp
     auto it = myUnorderedMap.find(1);
     if (it != myUnorderedMap.end()) {
         std::cout << "Found: " << it->second; // Output: Found: One
     }
     ```

3. **Count Occurrences**:
   - **Method**: `count(const Key& key)`
   - **Description**: Returns the number of occurrences of the specified key (will be 0 or 1 for `unordered_map` since it only contains unique keys).
   - **Example**:
     ```cpp
     int count = myUnorderedMap.count(1); // count will be 1 if found, 0 otherwise
     ```

4. **Iterating**:
   - **Method**: `begin()`, `end()`
   - **Description**: Returns iterators to the beginning and end of the unordered map.
   - **Example**:
     ```cpp
     for (const auto& pair : myUnorderedMap) {
         std::cout << pair.first << ": " << pair.second << " "; // Output order is not guaranteed
     }
     ```

5. **Bucket Interface**:
   - **Method**: `bucket_count()`, `bucket_size(size_t n)`
   - **Description**: Returns the number of buckets in the unordered map and the number of elements in the specified bucket, respectively.
   - **Example**:
     ```cpp
     std::cout << "Number of buckets: " << myUnorderedMap.bucket_count() << std::endl;
     ```

6. **Load Factor**:
   - **Method**: `load_factor()`
   - **Description**: Returns the average number of elements per bucket.
   - **Example**:
     ```cpp
     std::cout << "Load factor: " << myUnorderedMap.load_factor() << std::endl;
     ```

### Summary of Access Methods

| Method                     | `std::map`                                 | `std::unordered_map`                     |
|----------------------------|--------------------------------------------|------------------------------------------|
| **Element Access**         | `operator[]`                               | `operator[]`                             |
| **Find Element**           | `find(const Key& key)`                    | `find(const Key& key)`                  |
| **Count Occurrences**      | `count(const Key& key)`                   | `count(const Key& key)`                 |
| **Iterate**                | `begin()`, `end()`                        | `begin()`, `end()`                       |
| **Lower Bound**            | `lower_bound(const Key& key)`             | Not applicable                           |
| **Upper Bound**            | `upper_bound(const Key& key)`             | Not applicable                           |
| **Bucket Count**           | Not applicable                             | `bucket_count()`                         |
| **Bucket Size**            | Not applicable                             | `bucket_size(size_t n)`                 |
| **Load Factor**            | Not applicable                             | `load_factor()`                          |

### Accessing Elements Methods Big O Notation
Here's a table summarizing the Big O notation for common operations in `std::map` and `std::unordered_map` in C++:

| Operation                     | `std::map`                           | `std::unordered_map`                |
|-------------------------------|--------------------------------------|-------------------------------------|
| **Insertion**                 | O(log n)                             | O(1) average, O(n) worst-case      |
| **Deletion**                  | O(log n)                             | O(1) average, O(n) worst-case      |
| **Search (Find)**             | O(log n)                             | O(1) average, O(n) worst-case      |
| **Count**                     | O(log n)                             | O(1) average, O(n) worst-case      |
| **Iteration**                 | O(n)                                 | O(n)                                 |
| **Lower Bound**               | O(log n)                             | Not applicable                      |
| **Upper Bound**               | O(log n)                             | Not applicable                      |
| **Bucket Count**              | Not applicable                       | O(1)                                |
| **Bucket Size**               | Not applicable                       | O(1)                                |
| **Load Factor**               | Not applicable                       | O(1)                                |

### Explanation of Operations:

- **Insertion**: 
  - **`std::map`**: Insertions require maintaining the order of elements, which involves traversing the tree structure, leading to O(log n) complexity.
  - **`std::unordered_map`**: Insertions are generally average O(1) due to the hash table implementation, but can degrade to O(n) in cases of hash collisions or rehashing.

- **Deletion**: 
  - **`std::map`**: Similar to insertion, deleting an element requires O(log n) as the tree structure needs to be updated.
  - **`std::unordered_map`**: Deletions are also O(1) on average, but can be O(n) in the worst case.

- **Search (Find)**: 
  - **`std::map`**: Searching for an element requires O(log n) due to the tree structure.
  - **`std::unordered_map`**: Searching is O(1) on average due to the hash table.

- **Count**: 
  - Both containers provide O(log n) and O(1) average for counting the occurrence of a specific key.

- **Iteration**: 
  - Iterating through the elements takes O(n) for both containers as each element must be accessed.

- **Lower Bound / Upper Bound**: 
  - These operations are specific to `std::map` and allow finding elements based on sorted order, requiring O(log n) time.

- **Bucket Count / Bucket Size / Load Factor**: 
  - These operations are specific to `std::unordered_map` and provide information about the hash table's organization, all performed in O(1) time.
