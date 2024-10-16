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
    // 1. Basic Usage: Creating and inserting elements into a multiset
    std::multiset<int> myMultiSet = {5, 1, 9, 3, 7, 1, 5};

    // Elements are automatically sorted in ascending order, and duplicates are allowed
    std::cout << "Elements in the multiset (sorted): ";
    for (const int &x : myMultiSet) {
        std::cout << x << " ";  // Output: 1 1 3 5 5 7 9
    }
    std::cout << std::endl;

    // Inserting a new element
    myMultiSet.insert(4);  // Insert 4 into the multiset
    std::cout << "After inserting 4: ";
    for (const int &x : myMultiSet) {
        std::cout << x << " ";  // Output: 1 1 3 4 5 5 7 9
    }
    std::cout << std::endl;

    // Inserting a duplicate element
    myMultiSet.insert(5);  // Insert another 5
    std::cout << "After inserting duplicate 5: ";
    for (const int &x : myMultiSet) {
        std::cout << x << " ";  // Output: 1 1 3 4 5 5 5 7 9
    }
    std::cout << std::endl;

    // 2. Deleting elements
    myMultiSet.erase(5);  // Erase all elements with value 5
    std::cout << "After erasing 5: ";
    for (const int &x : myMultiSet) {
        std::cout << x << " ";  // Output: 1 1 3 4 7 9
    }
    std::cout << std::endl;

    // 3. Counting elements
    int count5 = myMultiSet.count(5);  // Count occurrences of 5 (after erasing, it's 0)
    std::cout << "Number of 5's in the multiset: " << count5 << std::endl;

    int count1 = myMultiSet.count(1);  // Count occurrences of 1
    std::cout << "Number of 1's in the multiset: " << count1 << std::endl;  // Output: 2

    // 4. Range-based operations
    // Lower bound returns the first element that is not less than the given key
    auto it = myMultiSet.lower_bound(4);
    std::cout << "Lower bound of 4: " << *it << std::endl;  // Output: 4

    // Upper bound returns the first element that is greater than the given key
    it = myMultiSet.upper_bound(4);
    std::cout << "Upper bound of 4: " << *it << std::endl;  // Output: 7

    // 5. Using custom comparator (multiset with descending order)
    std::multiset<int, CustomComparator> myMultiSetDesc = {5, 1, 9, 3, 7, 1, 5};
    std::cout << "Elements in the multiset (descending): ";
    for (const int &x : myMultiSetDesc) {
        std::cout << x << " ";  // Output: 9 7 5 5 3 1 1
    }
    std::cout << std::endl;

    // 6. Multiset Operations (Union, Intersection, Difference)
    std::multiset<int> setA = {1, 3, 5, 7, 7, 9};
    std::multiset<int> setB = {3, 6, 7, 7, 8, 10};

    std::multiset<int> setUnion, setIntersection, setDifference;

    // Union
    std::set_union(setA.begin(), setA.end(), setB.begin(), setB.end(),
                   std::inserter(setUnion, setUnion.begin()));
    std::cout << "Union of setA and setB: ";
    for (const int &x : setUnion) {
        std::cout << x << " ";  // Output: 1 3 5 6 7 7 8 9 10
    }
    std::cout << std::endl;

    // Intersection
    std::set_intersection(setA.begin(), setA.end(), setB.begin(), setB.end(),
                          std::inserter(setIntersection, setIntersection.begin()));
    std::cout << "Intersection of setA and setB: ";
    for (const int &x : setIntersection) {
        std::cout << x << " ";  // Output: 3 7 7
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
