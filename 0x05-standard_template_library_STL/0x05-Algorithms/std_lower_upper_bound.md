# **`std::lower_bound`** and **`std::upper_bound`**.

Both of these algorithms are used for searching in **sorted ranges** (like arrays or vectors) and work efficiently in logarithmic time (O(log N)). They are useful for finding the positions where a value can be inserted or where a range of values starts and ends.

### 1. **`std::lower_bound`**

#### Purpose:
- **`std::lower_bound`** returns an iterator to the **first element** in the sorted range that is **not less than** (i.e., greater than or equal to) the given value.
  
#### Syntax:
```cpp
template< class ForwardIt, class T >
ForwardIt lower_bound( ForwardIt first, ForwardIt last, const T& value );

template< class ForwardIt, class T, class Compare >
ForwardIt lower_bound( ForwardIt first, ForwardIt last, const T& value, Compare comp );
```

#### Parameters:
1. **`first`**: Iterator to the beginning of the range.
2. **`last`**: Iterator to the end of the range (exclusive).
3. **`value`**: The value to search for.
4. **`comp`**: (Optional) A custom comparison function.

#### Return Value:
- It returns an iterator pointing to the **first element that is not less than the given value**.
- If all elements are smaller than `value`, it returns `last` (i.e., the end of the range).

#### Example 1: Simple Use of `std::lower_bound`
Let’s take a simple example of how `std::lower_bound` works.

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 4, 4, 5, 6, 8, 9};

    // Find the first element >= 4
    auto it = std::lower_bound(vec.begin(), vec.end(), 4);

    if (it != vec.end()) {
        std::cout << "First element >= 4: " << *it << std::endl;
    } else {
        std::cout << "Element not found." << std::endl;
    }

    return 0;
}
```

**Output:**
```
First element >= 4: 4
```

### How It Works:
- The array is `{1, 2, 4, 4, 5, 6, 8, 9}`.
- `std::lower_bound` searches for the first element **not less than `4`**. It finds that `4` is the first element that satisfies this condition and returns an iterator to it.

#### Example 2: Inserting with `std::lower_bound`
A common use case is to find the correct place to **insert** an element in a sorted container, while keeping it sorted:

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 4, 4, 5, 6, 8, 9};

    // Insert 3 into the correct position
    auto it = std::lower_bound(vec.begin(), vec.end(), 3);
    vec.insert(it, 3);  // Insert 3 at the found position

    // Output the modified vector
    for (int i : vec) {
        std::cout << i << " ";
    }

    return 0;
}
```

**Output:**
```
1 2 3 4 4 5 6 8 9
```

### 2. **`std::upper_bound`**

#### Purpose:
- **`std::upper_bound`** returns an iterator to the **first element that is greater than** the given value.

#### Syntax:
```cpp
template< class ForwardIt, class T >
ForwardIt upper_bound( ForwardIt first, ForwardIt last, const T& value );

template< class ForwardIt, class T, class Compare >
ForwardIt upper_bound( ForwardIt first, ForwardIt last, const T& value, Compare comp );
```

#### Parameters:
1. **`first`**: Iterator to the beginning of the range.
2. **`last`**: Iterator to the end of the range (exclusive).
3. **`value`**: The value to search for.
4. **`comp`**: (Optional) A custom comparison function.

#### Return Value:
- It returns an iterator pointing to the **first element greater than** the given value.
- If no such element exists (i.e., all elements are less than or equal to `value`), it returns `last`.

#### Example 1: Simple Use of `std::upper_bound`
```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 4, 4, 5, 6, 8, 9};

    // Find the first element > 4
    auto it = std::upper_bound(vec.begin(), vec.end(), 4);

    if (it != vec.end()) {
        std::cout << "First element > 4: " << *it << std::endl;
    } else {
        std::cout << "Element not found." << std::endl;
    }

    return 0;
}
```

**Output:**
```
First element > 4: 5
```

### How It Works:
- The array is `{1, 2, 4, 4, 5, 6, 8, 9}`.
- `std::upper_bound` searches for the **first element greater than `4`**. It skips the two `4`s and finds that `5` is the first element greater than `4`.

#### Example 2: Using `std::upper_bound` for Range Queries
You can use `std::upper_bound` to find the **end of a range of elements** that are equal to a given value:

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 4, 4, 5, 6, 8, 9};

    // Find the first element greater than 4
    auto it = std::upper_bound(vec.begin(), vec.end(), 4);

    // Output the elements after the range of 4's
    std::cout << "Elements greater than 4: ";
    for (; it != vec.end(); ++it) {
        std::cout << *it << " ";
    }

    return 0;
}
```

**Output:**
```
Elements greater than 4: 5 6 8 9
```

### Difference Between `std::lower_bound` and `std::upper_bound`:
- **`std::lower_bound`**: Finds the **first element that is greater than or equal to** the value.
- **`std::upper_bound`**: Finds the **first element that is strictly greater than** the value.

### When to Use:
- **Use `std::lower_bound`** if you want to find the **first element that is not less than** (i.e., >=) a value.
- **Use `std::upper_bound`** if you want to find the **first element that is strictly greater than** a value.

### Combining `lower_bound` and `upper_bound`:
You can use both together to find a **range of elements** equal to a specific value:
```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 4, 4, 5, 6, 8, 9};

    auto lower = std::lower_bound(vec.begin(), vec.end(), 4);
    auto upper = std::upper_bound(vec.begin(), vec.end(), 4);

    // Print all elements equal to 4
    std::cout << "Elements equal to 4: ";
    for (auto it = lower; it != upper; ++it) {
        std::cout << *it << " ";
    }

    return 0;
}
```

**Output:**
```
Elements equal to 4: 4 4
```