// To compile: g++ -std=c++20 -o span span.cpp
// std::span (C++20)
#include <iostream>
#include <span> // C++20
#include <vector>
#include <algorithm>

void printSpan(std::span<int> s) {
    for (int value : s) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

void modifySpan(std::span<int> s) {
    for (auto& value : s) {
        value *= 2;
    }
}

int main() {
    // Array example
    int arr[] = {1, 2, 3, 4, 5};
    std::span<int> s1(arr);

    // Vector example
    std::vector<int> vec = {6, 7, 8, 9, 10};
    std::span<int> s2(vec.data(), vec.size());

    std::cout << "Original array: ";
    printSpan(s1);

    std::cout << "Original vector: ";
    printSpan(s2);

    modifySpan(s1);
    modifySpan(s2);

    std::cout << "Modified array: ";
    printSpan(s1);

    std::cout << "Modified vector: ";
    printSpan(s2);

    // Subspan example
    std::span<int> subspan = s1.subspan(1, 3);
    std::cout << "Subspan of modified array: ";
    printSpan(subspan);

    // Sorting example
    std::sort(s2.begin(), s2.end());
    std::cout << "Sorted vector: ";
    printSpan(s2);

    return 0;
}
