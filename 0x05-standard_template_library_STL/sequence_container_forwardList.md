# Forward List

**For Reference:** [Forward List - C++ Reference](https://en.cppreference.com/w/cpp/container/forward_list)

`std::forward_list` is a sequence container in C++ that implements a **singly linked list**. Unlike `std::list`, which is a doubly linked list, `std::forward_list` is optimized for memory efficiency and offers **faster insertions** and deletions but only supports forward traversal.

Here's a detailed breakdown of `std::forward_list`, its characteristics, and how it compares to other containers like `std::list`.

### Key Characteristics of `std::forward_list`:

1. **Singly Linked List**:
   - `std::forward_list` is implemented as a **singly linked list**, meaning each element contains a reference to the **next** element but not to the previous one. This makes it lighter than `std::list`, which maintains both forward and backward references (doubly linked).

2. **Forward Traversal Only**:
   - Since `std::forward_list` is a singly linked list, it supports only **forward traversal**. There is no direct access to the previous elements, and you cannot move backward through the list like you can in `std::list`.

3. **Memory Efficiency**:
   - Due to its simpler structure (storing only one pointer per node), `std::forward_list` consumes less memory compared to `std::list`, which stores two pointers (next and previous) for each node.

4. **No Size Information**:
   - `std::forward_list` does **not store its size** internally. This means that operations like `size()` are not available, and if you need the size of the list, you would have to traverse it to count the elements manually, which makes checking the size an `O(n)` operation (linear complexity).

5. **Efficient Insertions and Deletions**:
   - Insertions and deletions at the beginning and middle of the list are very efficient, typically done in constant time `O(1)` if the position is known (with a pointer or iterator). However, like other linked list containers, random access to elements (e.g., accessing the nth element) is slow (`O(n)`).

6. **No Random Access**:
   - `std::forward_list` does not provide random access, so operations like indexing with `operator[]` or `at()` are unavailable. The only way to access elements is by traversing the list from the start.

7. **Single-Iterator Operations**:
   - Due to the singly linked structure, most operations in `std::forward_list` require only a single iterator to perform modifications (inserting, deleting, etc.), unlike `std::list`, which requires bidirectional iterators.

8. **Frequent Insertions/Deletions**:
   - `std::forward_list` is ideal for applications where frequent insertions or deletions are required, particularly at the front of the container or at known positions within the list.

### Example of `std::forward_list`:

```cpp
#include <iostream>
#include <forward_list>

int main() {
    std::forward_list<int> flist = {10, 20, 30};

    // Insert an element at the front
    flist.push_front(5);

    // Traverse and print the elements
    for (int x : flist) {
        std::cout << x << " ";  // Output: 5 10 20 30
    }

    // Insert an element after the first element
    auto it = flist.begin();
    flist.insert_after(it, 15);  // Insert 15 after the first element (5)

    std::cout << "\nAfter insert: ";
    for (int x : flist) {
        std::cout << x << " ";  // Output: 5 15 10 20 30
    }

    return 0;
}
```

### Common Member Functions of `std::forward_list`:

#### 1. **`push_front(const T& value)`**:
   - Inserts a new element at the **front** of the forward list.

   ```cpp
   std::forward_list<int> flist;
   flist.push_front(10);  // Adds 10 to the front
   ```

#### 2. **`pop_front()`**:
   - Removes the first element from the forward list.

   ```cpp
   flist.pop_front();  // Removes the first element
   ```

#### 3. **`insert_after(iterator pos, const T& value)`**:
   - Inserts an element **after** the position pointed to by the iterator.

   ```cpp
   auto it = flist.begin();
   flist.insert_after(it, 20);  // Inserts 20 after the first element
   ```

#### 4. **`erase_after(iterator pos)`**:
   - Removes the element that is located **after** the given position.

   ```cpp
   flist.erase_after(it);  // Erases the element after the first one
   ```

#### 5. **`emplace_after(iterator pos, Args&&... args)`**:
   - Constructs an element in-place **after** the specified position.

   ```cpp
   flist.emplace_after(it, 25);  // Constructs 25 in place after the first element
   ```

#### 6. **`before_begin()`**:
   - Returns an iterator to the **before the first element** of the forward list. This is useful for certain operations like `insert_after()` or `emplace_after()` where you need to modify the very first element.

   ```cpp
   auto it = flist.before_begin();  // Points to a position before the first element
   ```

#### 7. **`clear()`**:
   - Removes all elements from the forward list.

   ```cpp
   flist.clear();  // Clears the list
   ```

#### 8. **`empty()`**:
   - Checks if the forward list is empty.

   ```cpp
   if (flist.empty()) {
       std::cout << "List is empty";
   }
   ```

#### 9. **`merge(std::forward_list& other)`**:
   - Merges another sorted `std::forward_list` into the current list, maintaining the sort order.

   ```cpp
   flist.merge(other_flist);  // Merges two sorted lists
   ```

#### 10. **`sort()`**:
   - Sorts the elements of the list in ascending order.

   ```cpp
   flist.sort();  // Sorts the list
   ```

#### 11. **`reverse()`**:
   - Reverses the order of the elements in the forward list.

   ```cpp
   flist.reverse();  // Reverses the list
   ```

#### 12. **`unique()`**:
   - Removes consecutive duplicate elements from the list. This operation only works if the list is sorted.

   ```cpp
   flist.unique();  // Removes consecutive duplicates
   ```

#### 13. **`splice_after(iterator pos, std::forward_list& other)`**:
   - Transfers elements from another forward list to the current list **after** the specified position.

   ```cpp
   flist.splice_after(flist.begin(), other_flist);  // Splices elements after the first element
   ```

#### 14. **`remove(const T& value)`**:
   - Removes all elements with the specified value from the forward list.

   ```cpp
   flist.remove(10);  // Removes all occurrences of 10 from the list
   ```

#### 15. **`remove_if(Predicate pred)`**:
   - Removes all elements that satisfy a given predicate.

   ```cpp
   flist.remove_if([](int x) { return x % 2 == 0; });  // Removes all even numbers
   ```

### Performance Characteristics:

| **Operation**           | **Complexity**   |
|-------------------------|------------------|
| Insertion/Deletion (front)  | `O(1)`           |
| Insertion/Deletion (middle) | `O(1)` after finding the position |
| Accessing nth element    | `O(n)`           |
| Traversal               | `O(n)`           |
| Memory overhead         | Lower than `std::list` |

### Example Usage of `std::forward_list`:

```cpp
#include <iostream>
#include <forward_list>

int main() {
    std::forward_list<int> flist = {1, 2, 3, 4};

    // Insert at front
    flist.push_front(0);

    // Insert after the first element
    auto it = flist.begin();
    flist.insert_after(it, 5);

    // Print the list
    for (const auto& val : flist) {
        std::cout << val << " ";  // Output: 0 5 1 2 3 4
    }

    return 0;
}
```

### When to Use `std::forward_list`:
- **Memory Efficiency**: Use `std::forward_list` when you need a memory-efficient singly linked list and don't require bidirectional traversal.
- **Insertions/Deletions at Known Positions**: Ideal for cases where you frequently insert or delete elements at known positions or at the front.
- **No Need for Random Access**: If your application does not require random access, `std::forward_list` is an excellent option.

### Differences Between `std::forward_list` and `std::list`:

| **Feature**                    | **`std::forward_list`**              | **`std::list`**                     |
|---------------------------------|--------------------------------------|-------------------------------------|
| Type of Linked List             | Singly Linked

                        | Doubly Linked                       |
| Memory Overhead                 | Lower                                | Higher                              |
| Access Direction                | Forward only                         | Bidirectional                       |
| Size Information                | No (size has to be computed)         | Yes (size is stored)                |
| Random Access                   | Not supported                        | Not supported                       |
| Use Case                        | Memory efficiency and forward traversal | When bidirectional traversal is needed |
| Iterators                       | Forward iterators only               | Bidirectional iterators             |

`std::forward_list` is a great choice for efficient insertions, deletions, and lightweight memory usage, while `std::list` is better when you need bidirectional traversal.