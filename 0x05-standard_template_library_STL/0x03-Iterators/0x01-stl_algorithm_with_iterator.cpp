#include <iostream>
#include <vector>
#include <algorithm>  // for sort and find

int main() {
    std::vector<int> vec = {4, 2, 5, 1, 3};

    // Using iterators with std::sort to sort the vector
    std::sort(vec.begin(), vec.end());

    std::cout << "Sorted vector: ";
    for (const auto& val : vec) {
        std::cout << val << " ";  // Using range-based for loop with iterators
    }
    std::cout << std::endl;

    // Using std::find with iterators
    auto it = std::find(vec.begin(), vec.end(), 3);
    if (it != vec.end()) {
        std::cout << "Element 3 found at position: " << (it - vec.begin()) << std::endl;
    } else {
        std::cout << "Element 3 not found" << std::endl;
    }

    // std::distance
    it = std::find(vec.begin(), vec.end(), 3);
    if (it != vec.end()) {
        std::cout << "Element 3 found at position: " << std::distance(vec.begin(), it) << std::endl;
    } else {
        std::cout << "Element 3 not found" << std::endl;
    }

    // Binary search
    if (std::binary_search(vec.begin(), vec.end(), 3)) {
        std::cout << "Element 3 found in the vector" << std::endl;
    } else {
        std::cout << "Element 3 not found in the vector" << std::endl;
    }

    return 0;
}
