#include <iostream>
#include <map>
#include <string>

// Custom comparator to sort map in descending order based on keys
struct CustomComparator {
    bool operator()(const int &a, const int &b) const {
        return a > b;  // Reverse order (descending)
    }
};

int main() {
    // 1. Basic Usage: Creating and inserting elements into a map
    std::map<int, std::string> myMap;

    // Inserting elements into the map
    myMap[1] = "Apple";
    myMap[3] = "Banana";
    myMap[2] = "Orange";

    // Map stores elements as key-value pairs, automatically sorted by keys (ascending order)
    std::cout << "Elements in the map (sorted by key):\n";
    for (const auto &pair : myMap) {
        std::cout << pair.first << " => " << pair.second << std::endl;
        // Output: 1 => Apple, 2 => Orange, 3 => Banana
    }

    // 2. Inserting elements using insert() method
    myMap.insert({4, "Grapes"});
    myMap.insert({5, "Pineapple"});

    std::cout << "After inserting more elements:\n";
    for (const auto &pair : myMap) {
        std::cout << pair.first << " => " << pair.second << std::endl;
        // Output: 1 => Apple, 2 => Orange, 3 => Banana, 4 => Grapes, 5 => Pineapple
    }

    // 3. Accessing elements using the key
    std::cout << "Element with key 3: " << myMap[3] << std::endl;  // Output: Banana

    // 4. Modifying elements
    myMap[2] = "Strawberry";  // Modifying value for key 2
    std::cout << "Modified value for key 2: " << myMap[2] << std::endl;  // Output: Strawberry

    // 5. Deleting elements
    myMap.erase(4);  // Removes the element with key 4 (Grapes)
    std::cout << "After erasing key 4:\n";
    for (const auto &pair : myMap) {
        std::cout << pair.first << " => " << pair.second << std::endl;
        // Output: 1 => Apple, 2 => Strawberry, 3 => Banana, 5 => Pineapple
    }

    // 6. Finding elements
    if (myMap.find(5) != myMap.end()) {
        std::cout << "Key 5 is found: " << myMap[5] << std::endl;  // Output: Pineapple
    }

    // 7. Using lower_bound and upper_bound
    auto itLow = myMap.lower_bound(2);  // First element not less than 2
    auto itUp = myMap.upper_bound(3);   // First element greater than 3
    std::cout << "Lower bound for key 2: " << itLow->first << " => " << itLow->second << std::endl;
    std::cout << "Upper bound for key 3: " << itUp->first << " => " << itUp->second << std::endl;

    // 8. Using custom comparator for sorting keys in descending order
    std::map<int, std::string, CustomComparator> myMapDesc;
    myMapDesc[1] = "Apple";
    myMapDesc[2] = "Strawberry";
    myMapDesc[3] = "Banana";
    myMapDesc[5] = "Pineapple";

    std::cout << "Elements in the map (sorted in descending order by key):\n";
    for (const auto &pair : myMapDesc) {
        std::cout << pair.first << " => " << pair.second << std::endl;
        // Output: 5 => Pineapple, 3 => Banana, 2 => Strawberry, 1 => Apple
    }

    return 0;
}
