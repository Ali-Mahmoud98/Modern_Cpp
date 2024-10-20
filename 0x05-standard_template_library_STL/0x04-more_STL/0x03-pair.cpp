// To compile: g++ -std=c++11 -o pair pair.cpp
// std::pair (Since C++11)
#include <iostream>
#include <utility> // for std::pair and std::make_pair
#include <vector>
#include <algorithm> // for std::sort

// Function to print a vector of pairs
void printPairs(const std::vector<std::pair<int, std::string>>& pairs) {
    for (const auto& p : pairs) {
        std::cout << "(" << p.first << ", " << p.second << ") ";
    }
    std::cout << std::endl;
}

// Function to modify a pair by reference
void modifyPair(std::pair<int, std::string>& p) {
    p.first *= 2; // Double the first element
    p.second += " Modified"; // Append " Modified" to the second element
}

// Comparison function for sorting pairs by the first element
bool comparePairs(const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {
    return a.first < b.first; // Sort by the first element
}

int main() {
    // Basic usage: Creating pairs
    std::pair<int, std::string> p1(1, "Apple");
    std::pair<int, std::string> p2 = std::make_pair(2, "Banana");

    // Accessing pair members
    std::cout << "Pair 1: (" << p1.first << ", " << p1.second << ")" << std::endl;
    std::cout << "Pair 2: (" << p2.first << ", " << p2.second << ")" << std::endl;

    // Modifying a pair
    modifyPair(p1);
    std::cout << "Modified Pair 1: (" << p1.first << ", " << p1.second << ")" << std::endl;

    // Using pairs in a vector
    std::vector<std::pair<int, std::string>> pairVector = {
        {3, "Orange"},
        {1, "Grape"},
        {2, "Kiwi"}
    };

    std::cout << "Original Vector of Pairs: ";
    printPairs(pairVector);

    // Sorting the vector of pairs
    std::sort(pairVector.begin(), pairVector.end(), comparePairs);
    std::cout << "Sorted Vector of Pairs: ";
    printPairs(pairVector);

    // Creating a pair from multiple values
    auto newPair = std::make_pair(4, "Cherry");
    pairVector.push_back(newPair); // Adding a new pair to the vector
    std::cout << "After adding a new Pair: ";
    printPairs(pairVector);

    // Accessing and modifying elements of the sorted vector
    for (auto& p : pairVector) {
        modifyPair(p); // Modify each pair in the vector
    }
    std::cout << "After modifying all pairs: ";
    printPairs(pairVector);

    return 0;
}
