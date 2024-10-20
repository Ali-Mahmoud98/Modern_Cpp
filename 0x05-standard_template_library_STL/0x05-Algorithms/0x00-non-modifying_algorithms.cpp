#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Sample vector to work with
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 3, 4, 5, 9};

    // 1. std::find
    // Find the first occurrence of the value '3'
    auto it_find = std::find(vec.begin(), vec.end(), 3);
    if (it_find != vec.end()) {
        std::cout << "First occurrence of 3 found at index: " 
                  << std::distance(vec.begin(), it_find) << std::endl;
    } else {
        std::cout << "3 not found!" << std::endl;
    }

    // 2. std::count
    // Count the occurrences of the value '4'
    int count_4 = std::count(vec.begin(), vec.end(), 4);
    std::cout << "Number of occurrences of 4: " << count_4 << std::endl;

    // 3. std::equal
    // Check if two vectors are equal
    std::vector<int> vec2 = {1, 2, 3, 4, 5};
    bool are_equal = std::equal(vec.begin(), vec.begin() + 5, vec2.begin());
    if (are_equal) {
        std::cout << "The first 5 elements of vec are equal to vec2" << std::endl;
    } else {
        std::cout << "The first 5 elements of vec are not equal to vec2" << std::endl;
    }

    // 4. std::mismatch
    // Find the first mismatch between two ranges
    std::vector<int> vec3 = {1, 2, 3, 6, 5};
    auto mismatch_pair = std::mismatch(vec.begin(), vec.begin() + 5, vec3.begin());
    if (mismatch_pair.first != vec.end()) {
        std::cout << "First mismatch found between vec and vec3: " 
                  << *mismatch_pair.first << " and " << *mismatch_pair.second << std::endl;
    } else {
        std::cout << "No mismatch found!" << std::endl;
    }

    // 5. std::search
    // Search for a subsequence {3, 4, 5} in the vector
    std::vector<int> subsequence = {3, 4, 5};
    auto it_search = std::search(vec.begin(), vec.end(), subsequence.begin(), subsequence.end());
    if (it_search != vec.end()) {
        std::cout << "Subsequence {3, 4, 5} found starting at index: " 
                  << std::distance(vec.begin(), it_search) << std::endl;
    } else {
        std::cout << "Subsequence {3, 4, 5} not found!" << std::endl;
    }

    return 0;
}
