### `std::stable_sort` in C++

The `std::stable_sort` function is similar to `std::sort`, but it guarantees that the relative order of equivalent elements is **preserved**. This makes it a **stable sort**, which is useful when you want to maintain the order of elements that compare as equal according to the comparison function.

### Syntax:

```cpp
template <class RandomIt>
void stable_sort(RandomIt first, RandomIt last);

template <class RandomIt, class Compare>
void stable_sort(RandomIt first, RandomIt last, Compare comp);
```

### Parameters:
1. **`first`**: Iterator to the beginning of the range to be sorted.
2. **`last`**: Iterator to the end of the range (exclusive).
3. **`comp`**: A custom comparison function (optional). By default, it sorts in ascending order using the `<` operator.

### How It Works:
- **Stable Sort**: When two elements compare as equal (i.e., `a == b`), the relative order of these elements in the original sequence is preserved after sorting.
  
- **Time Complexity**: The time complexity is O(N log² N), slightly worse than `std::sort`, which is O(N log N). This is because `std::stable_sort` usually uses **merge sort** instead of quicksort or introsort.

### Example of Stability:
Stability is important in cases where objects have multiple fields, and you want to sort by one field while maintaining the order of another.

For example, if you're sorting a list of people by their age, and there are people with the same age, the stable sort will ensure that people with the same age retain their original order (e.g., by name) in the sorted sequence.

### Example:

#### Example 1: Demonstrating Stability

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
        {"Charlie", 25},
        {"David", 35}
    };

    // Sorting people by age using stable_sort
    std::stable_sort(people.begin(), people.end(), compareByAge);

    // Output the sorted list
    std::cout << "People sorted by age (stable):\n";
    for (const Person& p : people) {
        std::cout << p.name << " (" << p.age << ")\n";
    }
    return 0;
}
```

**Output:**
```
People sorted by age (stable):
Bob (25)
Charlie (25)
Alice (30)
David (35)
```

In this case, `Bob` and `Charlie` both have the same age (25), but since `std::stable_sort` is used, their original relative order is preserved (i.e., `Bob` appears before `Charlie` in the sorted list).

#### Example 2: Sorting in Descending Order (Custom Comparator)
You can still sort using a custom comparison function in `std::stable_sort` just like `std::sort`.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {5, 3, 8, 6, 2, 7, 4, 1};

    // Stable sorting in descending order using a lambda expression
    std::stable_sort(vec.begin(), vec.end(), [](int a, int b) {
        return a > b;
    });

    // Output the sorted vector
    std::cout << "Stable sorted vector in descending order: ";
    for (int i : vec) {
        std::cout << i << " ";
    }
    return 0;
}
```

**Output:**
```
Stable sorted vector in descending order: 8 7 6 5 4 3 2 1
```

### Stability and `std::sort` vs. `std::stable_sort`:
- **`std::sort`**: Faster (O(N log N)) but not guaranteed to be stable. If you don't care about the relative order of equivalent elements, use `std::sort`.
- **`std::stable_sort`**: Guarantees stability, but at the cost of slightly worse performance (O(N log² N)). Use this when the order of equivalent elements matters.

### Key Points:
- **Random Access Iterators**: Like `std::sort`, `std::stable_sort` requires random access iterators, so it works with containers like `std::vector`, `std::array`, but not `std::list`.
- **When to Use**: Use `std::stable_sort` when you need to sort based on multiple criteria, and you want to maintain the order of elements that are considered "equal" according to your primary sort criterion.