#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

int main() {
    // Define two sets of integers
    std::set<int> setA = {1, 2, 3, 4, 5};
    std::set<int> setB = {4, 5, 6, 7, 8};

    // Set for results
    std::set<int> resultSet;

    // 1. Set Union
    std::cout << "Set Union (A ∪ B): ";
    std::set_union(setA.begin(), setA.end(), setB.begin(), setB.end(),
                   std::inserter(resultSet, resultSet.begin()));
    for (const auto& elem : resultSet) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Clear the result set for the next operation
    resultSet.clear();

    // 2. Set Intersection
    std::cout << "Set Intersection (A ∩ B): ";
    std::set_intersection(setA.begin(), setA.end(), setB.begin(), setB.end(),
                          std::inserter(resultSet, resultSet.begin()));
    for (const auto& elem : resultSet) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Clear the result set for the next operation
    resultSet.clear();

    // 3. Set Difference
    std::cout << "Set Difference (A - B): ";
    std::set_difference(setA.begin(), setA.end(), setB.begin(), setB.end(),
                        std::inserter(resultSet, resultSet.begin()));
    for (const auto& elem : resultSet) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Clear the result set for the next operation
    resultSet.clear();

    // 4. Set Symmetric Difference
    std::cout << "Set Symmetric Difference (A Δ B): ";
    std::set_symmetric_difference(setA.begin(), setA.end(), setB.begin(), setB.end(),
                                   std::inserter(resultSet, resultSet.begin()));
    for (const auto& elem : resultSet) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
