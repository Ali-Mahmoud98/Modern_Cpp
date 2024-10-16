# Associative Containers
Associative containers are the type of containers that **store the elements in a sorted order** based on keys rather than their insertion order.

**Associative containers** in C++ are a group of container types that store elements in a structured way such that they can be efficiently searched, inserted, and removed. Unlike sequence containers like `std::vector` and `std::deque`, which store elements in a linear order, associative containers store data in a way that allows fast retrieval using keys.

In C++, the main associative containers are:

1. **`std::set`:** STL Set is a type of associative container in which each element has to be unique because the value of the element identifies it. By default, the values are stored in ascending order.
2. **`std::multiset`:** STL Multiset is similar to the set container except that it can store duplicate values.
3. **`std::map`:** STL Maps are associative containers that store elements in the form of a key-value pair. The keys have to be unique and the container is sorted on the basis of the values of the keys.
4. **`std::multimap`:** STL Multimap is similar to a map container but allows multiple mapped values to have same keys.

Each of these containers organizes elements according to a particular structure and provides unique features, which we'll explore in detail below.

### Resources

- [C++ Associative Containers](https://en.cppreference.com/w/cpp/container)
- [std::set](https://en.cppreference.com/w/cpp/container/set)
- [std::multiset](https://en.cppreference.com/w/cpp/container/multiset)
- [std::map](https://en.cppreference.com/w/cpp/container/map)
- [std::multimap](https://en.cppreference.com/w/cpp/container/multimap)


### 1. `std::set`

A `std::set` is an ordered collection of unique elements.

- **Key Features**:
  - **Uniqueness**: It does not allow duplicate elements.
  - **Order**: Elements are automatically sorted in increasing order (based on comparison criteria, typically `<`).
  - **Search/Insert/Delete Time Complexity**: Operations such as searching, inserting, and deleting elements take logarithmic time (O(log n)) because it is implemented as a balanced binary search tree (usually a Red-Black tree).

- **Example**:

```cpp
#include <iostream>
#include <set>

int main() {
    std::set<int> mySet = {5, 1, 3, 9, 7};

    // Elements are automatically sorted
    for (int x : mySet) {
        std::cout << x << " ";  // Output: 1 3 5 7 9
    }

    return 0;
}
```

### 2. `std::multiset`

A `std::multiset` is similar to `std::set`, but it allows **duplicate elements**.

- **Key Features**:
  - **Duplicates**: It allows duplicate values.
  - **Order**: Elements are still automatically sorted.
  - **Time Complexity**: Like `std::set`, search, insertion, and deletion operations take logarithmic time.

- **Example**:

```cpp
#include <iostream>
#include <set>

int main() {
    std::multiset<int> myMultiSet = {5, 1, 3, 9, 7, 1, 5};

    // Elements are sorted and duplicates are allowed
    for (int x : myMultiSet) {
        std::cout << x << " ";  // Output: 1 1 3 5 5 7 9
    }

    return 0;
}
```

### 3. `std::map`

A `std::map` is an ordered collection of key-value pairs, where each key is unique.

- **Key Features**:
  - **Key-Value Storage**: Stores elements as key-value pairs (`std::pair<Key, Value>`).
  - **Uniqueness**: Keys must be unique; there cannot be two elements with the same key.
  - **Order**: The elements are automatically sorted by key.
  - **Search/Insert/Delete Time Complexity**: Like `std::set`, operations take logarithmic time because it's implemented using a balanced binary search tree.

- **Example**:

```cpp
#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap;

    // Inserting key-value pairs
    myMap[1] = "One";
    myMap[2] = "Two";
    myMap[3] = "Three";

    // Accessing elements by key
    std::cout << "Key 2 has value: " << myMap[2] << std::endl;  // Output: Two

    return 0;
}
```

### 4. `std::multimap`

A `std::multimap` is similar to `std::map`, but it allows **duplicate keys**.

- **Key Features**:
  - **Duplicates**: It allows multiple key-value pairs with the same key.
  - **Order**: Like `std::map`, the elements are sorted by key.
  - **Time Complexity**: Operations take logarithmic time.

- **Example**:

```cpp
#include <iostream>
#include <map>

int main() {
    std::multimap<int, std::string> myMultiMap;

    // Inserting multiple elements with the same key
    myMultiMap.insert({1, "One"});
    myMultiMap.insert({1, "Uno"});
    myMultiMap.insert({2, "Two"});

    // Iterating through the multimap
    for (const auto& pair : myMultiMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    // Output:
    // 1: One
    // 1: Uno
    // 2: Two

    return 0;
}
```

### Key Characteristics of Associative Containers

| Feature             | `std::set`               | `std::multiset`           | `std::map`                | `std::multimap`           |
|---------------------|--------------------------|---------------------------|---------------------------|---------------------------|
| **Type of Data**     | Single elements          | Single elements            | Key-value pairs            | Key-value pairs            |
| **Uniqueness**       | Unique elements          | Duplicate elements allowed | Unique keys                | Duplicate keys allowed     |
| **Order**            | Sorted by elements       | Sorted by elements         | Sorted by keys             | Sorted by keys             |
| **Time Complexity**  | O(log n) for insert, find, and erase | O(log n) for insert, find, and erase | O(log n) for insert, find, and erase | O(log n) for insert, find, and erase |
| **Underlying Structure** | Red-Black Tree         | Red-Black Tree             | Red-Black Tree             | Red-Black Tree             |

### Comparison with Unordered Associative Containers
There are also **unordered associative containers** (`std::unordered_set`, `std::unordered_map`, `std::unordered_multiset`, `std::unordered_multimap`) which use **hash tables** for storage, resulting in faster average-time complexity (`O(1)`) for **insertions, lookups, and deletions**, but they do not maintain any ordering.

### Key Points:
- **Order**: All associative containers keep their elements sorted, while unordered associative containers do not.
- **Efficiency**: Associative containers typically have O(log n) complexity for insertions, deletions, and lookups, while unordered associative containers use hash tables and provide O(1) average complexity for the same operations.
- **Use cases**: Choose `std::set` or `std::map` when you need sorted elements or pairs, and `std::multiset` or `std::multimap` when duplicates are necessary.