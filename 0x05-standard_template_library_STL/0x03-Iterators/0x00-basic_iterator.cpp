#include <iostream>
#include <vector>

/**
 * Basic usage of iterators:
 * 1. Basic usage of iterators to traverse a vector
 * 2. Using a const iterator to ensure elements are not modified
 * 3. Using reverse iterator to iterate in reverse order
 */

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Basic usage of iterators to traverse a vector
    std::cout << "Vector elements: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";  // Dereference the iterator to get the value
        if (*it == 5) {
            *it = 10;  // Modify the value using the iterator
        }
    }
    std::cout << std::endl;

    // Using a const iterator to ensure elements are not modified
    std::cout << "Vector elements (const iterator): ";
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";  // We can't modify *it since it's a const iterator
        // So the following lines will cause error if you uncomment them
        // if (*it == 3) {
        //     *it = 10;  // Modify the value using the iterator
        // }
    }
    std::cout << std::endl;

    // Using reverse iterator
    std::cout << "Vector elements in reverse: ";
    for (std::vector<int>::reverse_iterator rit = vec.rbegin(); rit != vec.rend(); ++rit) {
        std::cout << *rit << " ";  // Access the element using reverse iterator
    }
    std::cout << std::endl;

    // auto
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";  // Access the element using auto
    }
    std::cout << std::endl;

    // Range-based for loop
    for (const auto &val : vec) {
        std::cout << val << " ";  // Access the element using range-based for loop
    }
    std::cout << std::endl;

    // auto it = begin(vec); is equivalent to auto it = vec.begin()
    for (auto it = begin(vec); it != end(vec); ++it) {
        std::cout << *it << " ";  // Access the element using auto
    }
    std::cout << std::endl;

    /**
     * Important Notes:
     * 1. auto is a C++11 feature
     * 2. begin() and end() return a non-const iterator
     * 3. auto it = begin(vec); is equivalent to auto it = vec.begin()
     * 4. cbegin() and cend() return a const iterator, so you cannot modify elements
     * 5. the iterator function which starts with 'c' returns a const iterator
     * 6. you can find the iterator functions of the container in the cpp reference documentation under:
     *      - Member functions -> Iterators  
     */

    return 0;
}
