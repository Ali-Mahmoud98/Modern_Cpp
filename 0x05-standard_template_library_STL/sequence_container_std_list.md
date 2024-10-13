# List in C++ Standard Template Library (STL)

* Doubly Linked List === `std::list`
* Singly Linked List === `std::forward_list`

**Lists** are sequence containers that allow non-contiguous memory allocation. As compared to the vector, the list has slow traversal, but once a position has been found, insertion and deletion are quick (constant time). Normally, **when we say a List, we talk about a doubly linked list**. For implementing a **singly linked list, we use a forward_list**.

`std::list` is the class of the List container. It is the part of C++ Standard Template Library (STL) and is defined inside `<list>` header file.

Syntax:
```cpp
std::list <data-type> name_of_list;
```

`std::list` is a sequence container in C++ that implements a doubly linked list. It allows for efficient insertion and deletion of elements at any position within the list, unlike `std::vector` and `std::deque`, which are optimized for contiguous storage and fast access but can suffer performance penalties when inserting or removing elements from the middle. `std::list` is particularly useful in scenarios where frequent insertions or deletions in the middle of the container are necessary.

### Key Characteristics of `std::list`:

1. **Doubly Linked List**:
   - `std::list` is implemented as a **doubly linked list**, meaning each element contains a reference to both its previous and next elements. This structure allows for constant-time (`O(1)`) insertions and deletions at any position in the list, making it ideal for use cases that require such operations frequently.

2. **Non-contiguous Memory**:
   - Unlike `std::vector` and `std::deque`, which store elements in contiguous memory, `std::list` elements are distributed across different memory locations. This means that random access (e.g., accessing the nth element) is slower (`O(n)`), as it requires traversing the list from the beginning or the end.

3. **Bidirectional Iterators**:
   - The iterators provided by `std::list` are **bidirectional**, allowing traversal from the beginning to the end and vice versa. However, they do not support random access like the iterators of `std::vector` and `std::deque`.

4. **Efficient Insertions and Deletions**:
   - Insertions and deletions are efficient for `std::list` regardless of whether they occur at the front, back, or middle of the list. These operations are `O(1)` when performed at a specific position.

5. **No Invalidations**:
   - In `std::list`, inserting or erasing elements does not invalidate existing iterators pointing to other elements, which is a significant advantage when compared to `std::vector` or `std::deque`, where iterators can be invalidated during reallocation.

6. **Flexible Size**:
   - The size of `std::list` can dynamically change during runtime, just like other STL containers. There is no need to manually manage its capacity.

### Common Member Functions of `std::list`:

#### 1. **`push_back(const T& value)`**
   - Adds a new element to the **end** of the list.

   ```cpp
   std::list<int> lst;
   lst.push_back(10);  // Adds 10 to the end of the list
   ```

#### 2. **`push_front(const T& value)`**
   - Adds a new element to the **front** of the list.

   ```cpp
   lst.push_front(5);  // Adds 5 to the front of the list
   ```

#### 3. **`pop_back()`**
   - Removes the last element from the list.

   ```cpp
   lst.pop_back();  // Removes the last element
   ```

#### 4. **`pop_front()`**
   - Removes the first element from the list.

   ```cpp
   lst.pop_front();  // Removes the first element
   ```

#### 5. **`size()`**
   - Returns the number of elements in the list.

   ```cpp
   std::cout << lst.size();  // Outputs the size of the list
   ```

#### 6. **`empty()`**
   - Checks whether the list is empty.

   ```cpp
   if (lst.empty()) {
       std::cout << "List is empty";
   }
   ```

#### 7. **`front()`**
   - Returns a reference to the first element in the list.

   ```cpp
   lst.front();  // Access the first element
   ```

#### 8. **`back()`**
   - Returns a reference to the last element in the list.

   ```cpp
   lst.back();  // Access the last element
   ```

#### 9. **`clear()`**
   - Removes all elements from the list.

   ```cpp
   lst.clear();  // Clears the list, making it empty
   ```

#### 10. **`insert(iterator pos, const T& value)`**
   - Inserts an element at the specified position in the list.

   ```cpp
   lst.insert(lst.begin(), 20);  // Inserts 20 at the beginning of the list
   ```

#### 11. **`erase(iterator pos)`**
   - Removes the element at the specified position.

   ```cpp
   lst.erase(lst.begin());  // Removes the first element from the list
   ```

#### 12. **`swap(std::list<T>& other)`**
   - Swaps the contents of the list with another list in constant time.

   ```cpp
   std::list<int> lst2 = {7, 8, 9};
   lst.swap(lst2);  // Swap contents of lst and lst2
   ```

#### 13. **`splice(iterator pos, std::list& other)`**
   - Transfers elements from another list to the list at the specified position. This operation is constant time and does not require any copying.

   ```cpp
   lst.splice(lst.begin(), lst2);  // Moves all elements from lst2 to the beginning of lst
   ```

#### 14. **`sort()`**
   - Sorts the elements of the list in ascending order. This is done using the list’s internal structure, which is more efficient than sorting for `std::vector` due to fewer element shifts.

   ```cpp
   lst.sort();  // Sorts the list in ascending order
   ```

#### 15. **`unique()`**
   - Removes consecutive duplicate elements from the list. This function only works if the list is sorted.

   ```cpp
   lst.unique();  // Removes consecutive duplicates
   ```

#### 16. **`reverse()`**
   - Reverses the order of the elements in the list.

   ```cpp
   lst.reverse();  // Reverses the list
   ```

#### 17. **`merge(std::list& other)`**
   - Merges another sorted list into the current list, maintaining the sort order.

   ```cpp
   lst.merge(lst2);  // Merges lst2 into lst, both of which are sorted
   ```

### Example Usage of `std::list`:

```cpp
#include <iostream>
#include <list>

int main() {
    std::list<int> lst;

    // Add elements
    lst.push_back(10);
    lst.push_front(5);
    lst.push_back(15);

    // Access elements
    std::cout << "First element: " << lst.front() << std::endl;  // Output: 5
    std::cout << "Last element: " << lst.back() << std::endl;    // Output: 15

    // Iterate over the list
    for (const auto& val : lst) {
        std::cout << val << " ";  // Output: 5 10 15
    }

    // Remove elements
    lst.pop_front();
    lst.pop_back();

    // Only one element remains
    std::cout << "\nRemaining element: " << lst.front();  // Output: 10

    return 0;
}
```

### Use Cases for `std::list`:
- **Frequent Insertions and Deletions**: `std::list` excels when you need to frequently add or remove elements from anywhere in the container.
- **No Random Access**: If you do not need random access to elements, `std::list` is a good choice. If random access is required, `std::vector` or `std::deque` are better alternatives.
- **Stable Iterators**: If you need to maintain stable references to elements while performing insertions and deletions, `std::list` is an excellent choice since these operations do not invalidate iterators (except for the ones that refer to the deleted elements).

### Performance Characteristics:

| Operation               | `std::list` Complexity | `std::vector` Complexity |
|-------------------------|------------------------|--------------------------|
| Random Access           | `O(n)`                 | `O(1)`                   |
| Insertion at Front      | `O(1)`                 | `O(n)`                   |
| Insertion at Back       | `O(1)`                 | `O(1)`                   |
| Insertion in Middle     | `O(1)` (via iterator)  | `O(n)`                   |
| Deletion at Front       | `O(1)`                 | `O(n)`                   |
| Deletion at Back        | `O(1)`                 | `O(1)`                   |
| Deletion in Middle      | `O(1)` (via iterator)  | `O(n)`                   |

### List Fucnctions:

| **Function**                              | **Description**                                                                                   |
|-------------------------------------------|---------------------------------------------------------------------------------------------------|
| **`push_back(const T& value)`**           | Adds an element to the end of the list.                                                           |
| **`push_front(const T& value)`**          | Adds an element to the front of the list.                                                         |
| **`pop_back()`**                          | Removes the last element from the list.                                                           |
| **`pop_front()`**                         | Removes the first element from the list.                                                          |
| **`size()`**                              | Returns the number of elements in the list.                                                       |
| **`empty()`**                             | Checks if the list is empty, returns `true` if there are no elements.                             |
| **`front()`**                             | Returns a reference to the first element in the list.                                              |
| **`back()`**                              | Returns a reference to the last element in the list.                                               |
| **`clear()`**                             | Removes all elements from the list, making it empty.                                              |
| **`insert(iterator pos, const T& value)`**| Inserts an element at the specified position, shifting subsequent elements.                       |
| **`erase(iterator pos)`**                 | Removes the element at the specified position.                                                    |
| **`swap(std::list<T>& other)`**           | Swaps the contents of this list with another list.                                                |
| **`splice(iterator pos, std::list& other)`** | Transfers elements from `other` list to this list at the specified position.                     |
| **`merge(std::list& other)`**             | Merges a sorted `other` list into the current list, maintaining the sort order.                   |
| **`sort()`**                              | Sorts the list in ascending order.                                                                |
| **`reverse()`**                           | Reverses the order of the elements in the list.                                                   |
| **`unique()`**                            | Removes consecutive duplicate elements from the list.                                             |
| **`resize(size_type count)`**             | Changes the number of elements in the list to `count`. If the list is enlarged, new elements are default-initialized. |
| **`assign(size_type count, const T& value)`** | Assigns `count` copies of `value` to the list, replacing its current contents.                  |
| **`emplace(iterator pos, Args&&... args)`** | Constructs an element in place at the specified position using provided arguments.               |
| **`emplace_back(Args&&... args)`**        | Constructs an element in place at the end of the list.                                            |
| **`emplace_front(Args&&... args)`**       | Constructs an element in place at the front of the list.                                          |
| **`remove(const T& value)`**              | Removes all elements with the specified value from the list.                                      |
| **`remove_if(Predicate pred)`**           | Removes all elements that satisfy the predicate `pred`.                                           |
| **`max_size()`**                          | Returns the maximum number of elements that the list can hold.                                    |
| **`begin()`**                             | Returns an iterator to the first element of the list.                                             |
| **`end()`**                               | Returns an iterator to the element following the last element of the list.                        |
| **`rbegin()`**                            | Returns a reverse iterator to the last element of the list.                                       |
| **`rend()`**                              | Returns a reverse iterator to the element preceding the first element of the list.                |

