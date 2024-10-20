// O(log N), where N is the number of elements in the range.
#include <iostream>
#include <algorithm>
#include <vector>

struct Person {
    int id;
    std::string name;
};

bool compareById(const Person& a, const Person& b) {
    return a.id < b.id;  // Custom comparison based on 'id'
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  // Sorted vector

    // Check if 5 exists in the vector
    if (std::binary_search(vec.begin(), vec.end(), 5)) {
        std::cout << "Element 5 found." << std::endl;
    } else {
        std::cout << "Element 5 not found." << std::endl;
    }

    // Check if 15 exists in the vector
    if (std::binary_search(vec.begin(), vec.end(), 15)) {
        std::cout << "Element 15 found." << std::endl;
    } else {
        std::cout << "Element 15 not found." << std::endl;
    }

    // Binary search with custom comparison
    std::vector<Person> people = {
        {1, "Alice"}, {2, "Bob"}, {3, "Charlie"}, {4, "David"}
    };

    Person target = {3, "Unknown"};  // We only care about the 'id'

    // The vector must be sorted by 'id' for binary_search to work
    if (std::binary_search(people.begin(), people.end(), target, compareById)) {
        std::cout << "Person with ID 3 found." << std::endl;
    } else {
        std::cout << "Person with ID 3 not found." << std::endl;
    }

    return 0;
}
