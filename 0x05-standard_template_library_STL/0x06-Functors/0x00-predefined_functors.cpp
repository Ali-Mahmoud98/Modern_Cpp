#include <iostream>
#include <vector>
#include <algorithm>  // for std::sort and std::find_if
#include <numeric>    // for std::accumulate
#include <functional> // for std::plus, std::minus, std::less, std::greater

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // 1. std::accumulate with std::plus: Calculate the sum of all elements in the vector
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0, std::plus<int>());
    std::cout << "Sum of numbers: " << sum << std::endl;  // Output: 55

    // 2. std::accumulate with std::minus: Calculate the difference by subtracting each element from a starting value
    int difference = std::accumulate(numbers.begin(), numbers.end(), 100, std::minus<int>());
    std::cout << "Difference starting from 100: " << difference << std::endl;  // Output: 45

    // 3. std::sort with std::greater: Sort the numbers in descending order
    std::sort(numbers.begin(), numbers.end(), std::greater<int>());
    std::cout << "Sorted in descending order: ";
    for (int n : numbers) {
        std::cout << n << " ";  // Output: 10 9 8 7 6 5 4 3 2 1
    }
    std::cout << std::endl;

    // 4. std::find_if with std::less: Find the first number less than 5
    auto it = std::find_if(numbers.begin(), numbers.end(), std::bind(std::less<int>(), std::placeholders::_1, 5));
    if (it != numbers.end()) {
        std::cout << "First number less than 5: " << *it << std::endl;  // Output: 4
    } else {
        std::cout << "No number found less than 5" << std::endl;
    }

    // 5. std::find_if with std::greater: Find the first number greater than 5
    it = std::find_if(numbers.begin(), numbers.end(), std::bind(std::greater<int>(), std::placeholders::_1, 5));
    if (it != numbers.end()) {
        std::cout << "First number greater than 5: " << *it << std::endl;  // Output: 10
    } else {
        std::cout << "No number found greater than 5" << std::endl;
    }

    // 6. std::find_if with std::geater: Find the last number greater than or equal to 5
    auto it2 = std::find_if(numbers.rbegin(), numbers.rend(), std::bind(std::greater<int>(), std::placeholders::_1, 5));
    if (it2 != numbers.rend()) {
        std::cout << "Last number greater than or equal to 5: " << *it2 << std::endl;  // Output: 6
    } else {
        std::cout << "No number found greater than or equal to 5" << std::endl;
    }

    return 0;
}
