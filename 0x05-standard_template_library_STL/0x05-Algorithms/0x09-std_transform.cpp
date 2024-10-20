// example of std::transform
#include <iostream>
#include <vector>
#include <algorithm>  // for std::transform
#include <functional> // for std::plus

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::vector<int> result(numbers.size());
    
    // example1:  Unary Operation (Transforming a Single Range)
    std::transform(numbers.begin(), numbers.end(), result.begin(), [](int x) {
        return x * 2;
    });
    
    std::cout << "Transformed numbers (multiplied by 2): ";
    for (int n : result) {
        std::cout << n << " ";  // Output: 2 4 6 8 10
    }
    std::cout << std::endl << std::endl;

    // example2: Binary Operation (Transforming a two Ranges)
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    std::vector<int> v2 = {5, 4, 3, 2, 1};
    std::vector<int> res(v1.size());

    std::transform(v1.begin(), v1.end(), v2.begin(), res.begin(), std::plus<int>());
    
    std::cout << "Transformed numbers (plus 5): ";
    for (int n : res) {
        std::cout << n << " ";  // Output: 6 6 6 6 6
    }
    std::cout << std::endl << std::endl;

    // example3: Unary Operation (Transforming a Two Ranges)
    std::vector<int> vec1 = {10, 20, 30, 40, 50};
    std::vector<int> vec2 = {1, 2, 3, 4, 5};
    std::vector<int> res1(vec1.size());
    
    // Binary operation: subtract elements of vec2 from vec1
    std::transform(vec1.begin(), vec1.end(), vec2.begin(), res1.begin(), [](int a, int b) {
        return a - b;
    });
    
    std::cout << "Difference between corresponding elements: ";
    for (int n : res1) {
        std::cout << n << " ";  // Output: 9 18 27 36 45
    }
    std::cout << std::endl << std::endl;
    
    return 0;
}
