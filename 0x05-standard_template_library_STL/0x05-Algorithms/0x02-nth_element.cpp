#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    // std::cout << *(vec.begin() + 4) << std::endl; // output: 5

    // Finding the 4th element (0-based index, so it would be the 5th element if sorted)
    std::nth_element(vec.begin(), vec.begin() + 4, vec.end());
    // We want the element that would be the 4th smallest to in its correct position(index 2 if the array were sorted))
    // std::nth_element chooses a "pivot" (a number) and starts partitioning
    // Elements less than or equal to the pivot go to the left.
    // Elements greater than or equal to the pivot go to the right.

    // Output the element at the 4th position
    std::cout << "Element at the 4th position (sorted order): " << vec[4] << std::endl;

    // Output the vector after nth_element
    std::cout << "Vector after nth_element: ";
    for (int i : vec) {
        std::cout << i << " ";
    }

    std::cout << std::endl;
    std::cout << std::endl;

    std::vector<int> vec1 = {3, 1, 4, 1, 5, 9, 2, 6, 5};

    // Finding the 3rd largest element (descending order)
    std::nth_element(vec1.begin(), vec1.begin() + 2, vec1.end(), std::greater<int>());

    // Output the element at the 3rd position (in descending order)
    std::cout << "3rd largest element: " << vec1[2] << std::endl;

    // Output the vector after nth_element
    std::cout << "Vector after nth_element: ";
    for (int i : vec1) {
        std::cout << i << " ";
    }

    std::cout << std::endl;
    return 0;
}
