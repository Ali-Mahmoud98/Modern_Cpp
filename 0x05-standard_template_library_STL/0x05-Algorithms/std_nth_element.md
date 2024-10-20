### `std::nth_element` in C++

`std::nth_element` is a partial-sorting algorithm that rearranges elements in such a way that the element at the nth position is the one that would be in that position if the entire range were sorted. Additionally:
- All elements before the nth element are less than or equal to it.
- All elements after the nth element are greater than or equal to it.
However, the elements in the two groups are not fully sorted.

This is particularly useful when you don't need the entire range sorted but only need to find the nth largest or smallest element in a sequence.

### Syntax:
```cpp
template <class RandomIt>
void nth_element(RandomIt first, RandomIt nth, RandomIt last);

template <class RandomIt, class Compare>
void nth_element(RandomIt first, RandomIt nth, RandomIt last, Compare comp);
```

### Parameters:
1. **`first`**: Iterator to the beginning of the range.
2. **`nth`**: Iterator pointing to the nth element (after the partitioning).
3. **`last`**: Iterator to the end of the range (exclusive).
4. **`comp`**: A custom comparison function (optional). By default, it uses the `<` operator to compare elements.

### How It Works:
- `std::nth_element` does not fully sort the range; it only guarantees that:
  - The element at `nth` is the one that would be at this position in a fully sorted sequence.
  - Elements before `nth` are less than or equal to it, and elements after `nth` are greater than or equal to it.
  
- It is typically implemented using the **quickselect** algorithm, which is a partial version of quicksort.

### Time Complexity:
- **Average case**: O(N), where N is the number of elements in the range.
- **Worst case**: O(N²), but this is rare due to the optimizations usually in place.

### Example:

#### Example 1: Finding the Median (nth Smallest Element)

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6, 5};

    // Finding the 4th element (0-based index, so it would be the 5th element if sorted)
    std::nth_element(vec.begin(), vec.begin() + 4, vec.end());

    // Output the element at the 4th position
    std::cout << "Element at the 4th position (sorted order): " << vec[4] << std::endl;

    // Output the vector after nth_element
    std::cout << "Vector after nth_element: ";
    for (int i : vec) {
        std::cout << i << " ";
    }
    return 0;
}
```

**Output:**
```
Element at the 4th position (sorted order): 4
Vector after nth_element: 3 1 2 1 4 9 6 5 5
```

In this example:
- After calling `std::nth_element`, the 5th element (4th index, which is `4`) is in its correct position.
- All elements before this position are smaller than or equal to 4, and all elements after it are greater than or equal to 4.
- Notice that the two groups are not fully sorted, only partitioned based on the nth element.

#### Example 2: Finding the 3rd Largest Element (Using Custom Comparator)

You can also find the nth largest element by using a custom comparison function.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6, 5};

    // Finding the 3rd largest element (descending order)
    std::nth_element(vec.begin(), vec.begin() + 2, vec.end(), std::greater<int>());

    // Output the element at the 3rd position (in descending order)
    std::cout << "3rd largest element: " << vec[2] << std::endl;

    // Output the vector after nth_element
    std::cout << "Vector after nth_element: ";
    for (int i : vec) {
        std::cout << i << " ";
    }
    return 0;
}
```

**Output:**
```
3rd largest element: 5
Vector after nth_element: 9 6 5 5 4 1 2 1 3
```

In this case:
- The 3rd largest element (index 2, value `5`) is placed at the correct position.
- All elements before the 3rd largest are greater than or equal to it, and all elements after it are less than or equal to it.
- Again, the two groups are not sorted, just partitioned around the nth element.

### Key Uses of `std::nth_element`:
1. **Finding the Median**: You can use `std::nth_element` to find the median element in an unsorted list.
2. **Top-k Elements**: It's useful for selecting the k smallest or k largest elements in a sequence without needing to fully sort the list.
3. **Quick Selection**: When you only care about one particular element's position (like the nth smallest or largest), this function can achieve that efficiently without sorting the entire sequence.

### Key Points:
- **Partitioning, Not Sorting**: Unlike `std::sort`, this function does not fully sort the range. It only ensures that the element at the nth position is in the correct spot.
  
- **Custom Comparators**: You can use a custom comparator to change the sorting criterion (e.g., finding the largest elements instead of the smallest).

- **Efficiency**: This function is very efficient for cases where you only need a single element in its sorted position (e.g., top-k problems). It is faster than sorting when only part of the sequence matters.
