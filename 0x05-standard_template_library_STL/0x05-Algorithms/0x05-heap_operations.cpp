#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Define a vector of integers
    std::vector<int> vec = {20, 10, 30, 5, 15, 25};

    // 1. Create a heap from the vector
    std::make_heap(vec.begin(), vec.end());
    std::cout << "Initial heap: ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // 2. Push a new element into the heap
    vec.push_back(35);
    std::push_heap(vec.begin(), vec.end());  // Maintain heap property
    std::cout << "After pushing 35: ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // 3. Pop the top element from the heap
    std::pop_heap(vec.begin(), vec.end());  // Move top to end
    vec.pop_back();  // Remove the top element
    std::cout << "After popping the top element: ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // 4. Sort the heap
    std::sort_heap(vec.begin(), vec.end());
    std::cout << "After sorting the heap: ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
