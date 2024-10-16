#include <iostream>
#include <set>
#include <algorithm>  // For set operations like std::set_union, std::set_intersection
#include <iterator>   // For std::inserter

// Custom comparator for sorting in descending order
struct CustomComparator {
    bool operator()(const int &a, const int &b) const {
        return a > b;  // Reverse order (descending)
    }
};

int main() {
    // 1. Basic Usage: Creating and inserting elements into a set
    std::set<int> mySet = {5, 1, 9, 3, 7};

    // Elements are automatically sorted in ascending order
    std::cout << "Elements in the set (sorted): ";
    for (const int &x : mySet) {
        std::cout << x << " ";  // Output: 1 3 5 7 9
    }
    std::cout << std::endl;

    // Inserting a new element
    mySet.insert(4);  // Insert 4 into the set
    std::cout << "After inserting 4: ";
    for (const int &x : mySet) {
        std::cout << x << " ";  // Output: 1 3 4 5 7 9
    }
    std::cout << std::endl;

    // Attempting to insert a duplicate element
    auto result = mySet.insert(3);
    if (!result.second) {
        std::cout << "3 is already present in the set!" << std::endl;
    }

    // 2. Deleting elements
    mySet.erase(5);  // Erase element with value 5
    std::cout << "After erasing 5: ";
    for (const int &x : mySet) {
        std::cout << x << " ";  // Output: 1 3 4 7 9
    }
    std::cout << std::endl;

    // 3. Finding elements in the set
    if (mySet.find(7) != mySet.end()) {
        std::cout << "7 is found in the set." << std::endl;  // Output: 7 is found in the set.
    }

    // 4. Range-based operations
    // Lower bound returns the first element that is not less than the given key
    auto it = mySet.lower_bound(4);
    std::cout << "Lower bound of 4: " << *it << std::endl;  // Output: 4

    // Upper bound returns the first element that is greater than the given key
    it = mySet.upper_bound(4);
    std::cout << "Upper bound of 4: " << *it << std::endl;  // Output: 7

    // 5. Using custom comparator (set with descending order)
    std::set<int, CustomComparator> mySetDesc = {5, 1, 9, 3, 7};
    std::cout << "Elements in the set (descending): ";
    for (const int &x : mySetDesc) {
        std::cout << x << " ";  // Output: 9 7 5 3 1
    }
    std::cout << std::endl;

    // 6. Set Operations (Union, Intersection, Difference)
    std::set<int> setA = {1, 3, 5, 7, 9};
    std::set<int> setB = {3, 6, 7, 8, 10};

    std::set<int> setUnion, setIntersection, setDifference;

    // Union
    std::set_union(setA.begin(), setA.end(), setB.begin(), setB.end(),
                   std::inserter(setUnion, setUnion.begin()));
    std::cout << "Union of setA and setB: ";
    for (const int &x : setUnion) {
        std::cout << x << " ";  // Output: 1 3 5 6 7 8 9 10
    }
    std::cout << std::endl;

    // Intersection
    std::set_intersection(setA.begin(), setA.end(), setB.begin(), setB.end(),
                          std::inserter(setIntersection, setIntersection.begin()));
    std::cout << "Intersection of setA and setB: ";
    for (const int &x : setIntersection) {
        std::cout << x << " ";  // Output: 3 7
    }
    std::cout << std::endl;

    // Difference (setA - setB)
    std::set_difference(setA.begin(), setA.end(), setB.begin(), setB.end(),
                        std::inserter(setDifference, setDifference.begin()));
    std::cout << "Difference of setA - setB: ";
    for (const int &x : setDifference) {
        std::cout << x << " ";  // Output: 1 5 9
    }
    std::cout << std::endl;

    return 0;
}
