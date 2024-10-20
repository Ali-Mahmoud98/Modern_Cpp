#include <iostream>
#include <vector>
#include <algorithm>  // For std::reverse and std::rotate

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};

    // 1. Basic usage of std::reverse
    std::reverse(vec.begin(), vec.end());
    std::cout << "After reverse: ";
    for (int i : vec) std::cout << i << " ";  // Output: 6 5 4 3 2 1
    std::cout << std::endl;

    // 2. Reversing a sub-range
    std::reverse(vec.begin() + 1, vec.end() - 1);
    std::cout << "After reversing sub-range: ";
    for (int i : vec) std::cout << i << " ";  // Output: 6 3 4 5 2 1
    std::cout << std::endl;

    // 3. Basic usage of std::rotate
    // Rotating the entire vector, making 4 the first element
    std::rotate(vec.begin(), vec.begin() + 3, vec.end());
    std::cout << "After rotate (making 4 the first element): ";
    for (int i : vec) std::cout << i << " ";  // Output: 4 5 2 1 6 3
    std::cout << std::endl;

    // 4. Rotating a sub-range
    // Rotating the first 5 elements so that 2 becomes the first
    std::rotate(vec.begin(), vec.begin() + 2, vec.begin() + 5);
    std::cout << "After rotating first 5 elements: ";
    for (int i : vec) std::cout << i << " ";  // Output: 2 1 4 5 6 3
    std::cout << std::endl;

    return 0;
}
