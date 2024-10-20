### `std::partition` in C++

The `std::partition` algorithm rearranges elements in a range based on a predicate function. It splits the range into two groups: 
- One group that satisfies the predicate (i.e., for which the predicate returns `true`).
- Another group that does not satisfy the predicate (i.e., for which the predicate returns `false`).

It does **not guarantee** that the relative order of the elements within each group will be preserved. If you need stable behavior, you should use `std::stable_partition`.

### Syntax:

```cpp
template <class ForwardIt, class UnaryPredicate>
ForwardIt partition(ForwardIt first, ForwardIt last, UnaryPredicate p);
```

### Parameters:
1. **`first`**: Iterator to the beginning of the range.
2. **`last`**: Iterator to the end of the range (exclusive).
3. **`p`**: A predicate function that defines the condition to partition the elements. This should return `true` for elements that belong in the first group, and `false` for elements in the second group.

### Return Value:
The function returns an iterator to the first element of the second group (i.e., the first element for which the predicate returns `false`).

### How It Works:
- The elements in the range `[first, last)` are rearranged so that all elements for which the predicate `p` returns `true` come before those for which it returns `false`.
- The order of elements within each partition is not guaranteed to be preserved.

### Time Complexity:
- **Linear (O(N))**, where N is the number of elements in the range.

### Example:

#### Example 1: Partitioning Even and Odd Numbers

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Partition the vector into even and odd numbers
    auto it = std::partition(vec.begin(), vec.end(), [](int x) {
        return x % 2 == 0;  // Predicate: true for even numbers
    });

    // Output the partitioned vector
    std::cout << "Even numbers: ";
    for (auto i = vec.begin(); i != it; ++i) {
        std::cout << *i << " ";
    }

    std::cout << "\nOdd numbers: ";
    for (auto i = it; i != vec.end(); ++i) {
        std::cout << *i << " ";
    }

    return 0;
}
```

**Output:**
```
Even numbers: 2 4 6 8 10 
Odd numbers: 1 3 5 7 9 
```

In this example:
- The numbers are partitioned into two groups: even numbers come first, followed by odd numbers.
- The order within each group is not guaranteed (though it happens to be in order here).

#### Example 2: Partitioning Custom Objects

You can also partition custom objects using a predicate function that checks specific fields of the objects.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Person {
    std::string name;
    int age;
};

// Predicate: Partition people into groups of adults and minors
bool isAdult(const Person& p) {
    return p.age >= 18;
}

int main() {
    std::vector<Person> people = {
        {"Alice", 17}, {"Bob", 22}, {"Charlie", 15}, {"David", 19}, {"Eve", 12}
    };

    // Partition people into adults and minors
    auto it = std::partition(people.begin(), people.end(), isAdult);

    // Output the partitioned people
    std::cout << "Adults:\n";
    for (auto i = people.begin(); i != it; ++i) {
        std::cout << i->name << " (" << i->age << ")\n";
    }

    std::cout << "\nMinors:\n";
    for (auto i = it; i != people.end(); ++i) {
        std::cout << i->name << " (" << i->age << ")\n";
    }

    return 0;
}
```

**Output:**
```
Adults:
Bob (22)
David (19)

Minors:
Alice (17)
Charlie (15)
Eve (12)
```

Here, the people are partitioned into two groups: **adults** (age ≥ 18) and **minors** (age < 18).

### Key Points:
- **No Order Guarantee**: `std::partition` does not preserve the relative order of the elements within each group. If stability is required, use `std::stable_partition` instead.
  
- **Partition Point**: The iterator returned by `std::partition` points to the first element of the second group (i.e., the first element that does not satisfy the predicate). You can use this iterator to separate the two groups.

- **Performance**: `std::partition` is more efficient than sorting when you just need to group elements into two categories because it has a linear time complexity (O(N)).
