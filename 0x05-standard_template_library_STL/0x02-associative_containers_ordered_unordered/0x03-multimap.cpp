#include <iostream>
#include <map>
#include <string>

int main() {
    // 1. Basic Usage: Creating and inserting elements into a multimap
    std::multimap<std::string, int> myMultiMap;

    // Inserting elements into the multimap
    myMultiMap.insert({"Apple", 1});
    myMultiMap.insert({"Banana", 2});
    myMultiMap.insert({"Orange", 3});
    myMultiMap.insert({"Apple", 4});  // Inserting a duplicate key
    myMultiMap.insert({"Banana", 5}); // Inserting another duplicate key

    // Display elements in the multimap
    std::cout << "Elements in the multimap (sorted by key):\n";
    for (const auto &pair : myMultiMap) {
        std::cout << pair.first << " => " << pair.second << std::endl;
        // Output: Apple => 1, Apple => 4, Banana => 2, Banana => 5, Orange => 3
    }

    // 2. Accessing elements by key
    std::cout << "\nValues associated with 'Apple':\n";
    auto range = myMultiMap.equal_range("Apple"); // Get range of elements with key "Apple"
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << it->first << " => " << it->second << std::endl; // Output: Apple => 1, Apple => 4
    }

    // 3. Deleting elements
    myMultiMap.erase("Banana");  // Removes all elements with key "Banana"
    std::cout << "\nAfter erasing all elements with key 'Banana':\n";
    for (const auto &pair : myMultiMap) {
        std::cout << pair.first << " => " << pair.second << std::endl;
        // Output: Apple => 1, Apple => 4, Orange => 3
    }

    // 4. Finding elements
    auto it = myMultiMap.find("Orange");
    if (it != myMultiMap.end()) {
        std::cout << "\nFound Orange: " << it->second << std::endl;  // Output: Found Orange: 3
    } else {
        std::cout << "\nOrange not found." << std::endl;
    }

    // 5. Counting occurrences of keys
    int count = myMultiMap.count("Apple");
    std::cout << "\nNumber of Apples in the multimap: " << count << std::endl;  // Output: 2

    // 6. Using a custom comparator (optional)
    // In this example, we'll just sort by length of the key (ascending)
    std::multimap<std::string, int, std::less<>> customMultiMap; // Default comparator
    customMultiMap.insert({"Pear", 1});
    customMultiMap.insert({"Kiwi", 2});
    customMultiMap.insert({"Strawberry", 3});
    customMultiMap.insert({"Lemon", 4});
    
    std::cout << "\nElements in the custom multimap (sorted by key):\n";
    for (const auto &pair : customMultiMap) {
        std::cout << pair.first << " => " << pair.second << std::endl;
    }

    return 0;
}
