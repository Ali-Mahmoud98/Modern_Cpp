### `std::sort` in C++

The `std::sort` algorithm is one of the most commonly used algorithms in the C++ Standard Template Library (STL) for sorting a range of elements. It efficiently sorts elements using a combination of sorting techniques, often a quicksort or introsort (a hybrid of quicksort, heapsort, and insertion sort). It's a highly optimized, general-purpose sorting function.

**Read more:** https://en.cppreference.com/w/cpp/algorithm/sort

### Syntax:
```cpp
template <class RandomIt>
void sort(RandomIt first, RandomIt last);

template <class RandomIt, class Compare>
void sort(RandomIt first, RandomIt last, Compare comp);
```

### Parameters:
1. **`first`**: Iterator to the beginning of the range to be sorted.
2. **`last`**: Iterator to the end of the range (exclusive).
3. **`comp`**: A custom comparison function (optional). By default, it sorts in **ascending order** using the `<` operator.

### How It Works:
- The `std::sort` algorithm rearranges the elements in the range `[first, last)` into non-decreasing order (i.e., ascending order by default).
- If you provide a custom comparison function, it will sort according to the logic provided in the function.

### Time Complexity:
- **Worst case**: O(N log N), where N is the number of elements in the range.
- **Average case**: O(N log N).

It is generally faster than other sorting algorithms like bubble sort or insertion sort for large datasets because it is typically implemented using quicksort with optimizations like switching to heapsort when the recursion depth becomes too large.

### Examples:

#### Example 1: Basic Sorting in Ascending Order
```cpp
#include <iostream>
#include <vector>
#include <algorithm>  // for std::sort

int main() {
    std::vector<int> vec = {5, 3, 8, 6, 2, 7, 4, 1};

    // Sorting the vector in ascending order
    std::sort(vec.begin(), vec.end());

    // Output the sorted vector
    std::cout << "Sorted vector: ";
    for (int i : vec) {
        std::cout << i << " ";
    }
    return 0;
}
```

**Output:**
```
Sorted vector: 1 2 3 4 5 6 7 8
```

#### Example 2: Sorting in Descending Order (Using a Custom Comparator)
You can sort in descending order by passing a custom comparison function.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {5, 3, 8, 6, 2, 7, 4, 1};

    // Sorting in descending order using a custom comparator (lambda)
    std::sort(vec.begin(), vec.end(), [](int a, int b) {
        return a > b;  // Compare such that larger elements come first
    });

    // Output the sorted vector
    std::cout << "Sorted vector in descending order: ";
    for (int i : vec) {
        std::cout << i << " ";
    }
    return 0;
}
```

**Output:**
```
Sorted vector in descending order: 8 7 6 5 4 3 2 1
```

### Sorting with Custom Objects:
If you're sorting objects, you can provide a custom comparator function that defines how the objects should be compared.

#### Example 3: Sorting Custom Objects (e.g., sorting people by age)

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Person {
    std::string name;
    int age;
};

// Comparator function to sort by age
bool compareByAge(const Person& a, const Person& b) {
    return a.age < b.age;
}

int main() {
    std::vector<Person> people = {
        {"Alice", 30},
        {"Bob", 25},
        {"Charlie", 35}
    };

    // Sorting people by age
    std::sort(people.begin(), people.end(), compareByAge);

    // Output the sorted list
    std::cout << "People sorted by age:\n";
    for (const Person& p : people) {
        std::cout << p.name << " (" << p.age << ")\n";
    }
    return 0;
}
```

**Output:**
```
People sorted by age:
Bob (25)
Alice (30)
Charlie (35)
```

### Sorting Specific Ranges:
You don't need to sort the entire container; you can sort a specific portion of it.

#### Example 4: Sorting a Subsection of a Container
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {10, 2, 8, 6, 1, 9, 3, 7, 5, 4};

    // Sorting only a subsection of the vector (first 5 elements)
    std::sort(vec.begin(), vec.begin() + 5);

    // Output the partially sorted vector
    std::cout << "Partially sorted vector: ";
    for (int i : vec) {
        std::cout << i << " ";
    }
    return 0;
}
```

**Output:**
```
Partially sorted vector: 1 2 6 8 10 9 3 7 5 4
```

### Edge Cases:
- **Empty range:** If `first == last`, the function does nothing.
- **Single element range:** Sorting a single element or an empty container also does nothing, as they are already "sorted."

### Key Points:
- **Stable vs Unstable Sort**: `std::sort` is not guaranteed to be stable. This means that if two elements are equal, their relative order may not be preserved. If you need stable sorting, you should use `std::stable_sort`.
  
- **Random Access Iterators Required**: The `std::sort` function requires **random access iterators**, which means it works with containers like `std::vector` or `std::array` but **not** with linked lists like `std::list`.