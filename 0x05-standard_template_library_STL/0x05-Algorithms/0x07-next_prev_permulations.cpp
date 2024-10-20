#include <iostream>
#include <vector>
#include <algorithm>  // For std::next_permutation and std::prev_permutation

int main() {
    std::vector<int> vec = {1, 2, 3};

    // 1. Basic usage of std::next_permutation
    std::cout << "Next permutations of {1, 2, 3}:\n";
    do {
        for (int i : vec) std::cout << i << " ";  // Output each permutation
        std::cout << std::endl;
    } while (std::next_permutation(vec.begin(), vec.end()));

    // 2. Resetting the vector and using std::prev_permutation
    std::vector<int> vec2 = {3, 2, 1};

    std::cout << "\nPrevious permutations of {3, 2, 1}:\n";
    do {
        for (int i : vec2) std::cout << i << " ";  // Output each permutation
        std::cout << std::endl;
    } while (std::prev_permutation(vec2.begin(), vec2.end()));

    // 3. Using std::next_permutation for a specific subset of permutations
    std::vector<int> vec3 = {1, 1, 2};
    std::cout << "\nPermutations of {1, 1, 2} (handling duplicates):\n";
    do {
        for (int i : vec3) std::cout << i << " ";
        std::cout << std::endl;
    } while (std::next_permutation(vec3.begin(), vec3.end()));

    // 4. Reverse vector to explore previous permutations in descending order
    std::vector<int> vec4 = {4, 3, 2, 1};
    std::cout << "\nPermutations of {4, 3, 2, 1} in descending order:\n";
    do {
        for (int i : vec4) std::cout << i << " ";
        std::cout << std::endl;
    } while (std::prev_permutation(vec4.begin(), vec4.end()));

    return 0;
}
