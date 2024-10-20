#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    std::cout << "Sum: " << sum << std::endl << std::endl;  // Output: Sum: 15 = 1+2+3+4+5
    
    int sum2 = std::accumulate(numbers.begin(), numbers.end(), 1);
    std::cout << "Sum: " << sum2 << std::endl << std::endl; // Output: Sum: 16 = 1+1+2+3+4+5

    int product = std::accumulate(numbers.begin(), numbers.end(), 1, std::multiplies<int>());
    std::cout << "Product: " << product << std::endl << std::endl;  // Output: Product: 120 = 1*1*2*3*4*5

    int sum3 = std::accumulate(numbers.begin(), numbers.end(), 0, [](int a, int b) {
        std::cout << a << " + " << b << " = " << a + b << std::endl;
        return a + b;
    });
    std::cout << "Sum: " << sum3 << std::endl << std::endl;  // Output: Sum: 15 = 1+2+3+4+5

    std::vector<int> result(numbers.size());
    std::partial_sum(numbers.begin(), numbers.end(), result.begin());
    std::cout << "Partial sums: ";
    for (int n : result) {
        std::cout << n << " ";  // Output: 1 3 6 10 15
    }
    std::cout << std::endl << std::endl;

    std::partial_sum(numbers.begin(), numbers.end(), result.begin(), [](int a, int b) {
        std::cout << a << " + " << b << " = " << a + b << std::endl;
        return a + b;
    });
    std::cout << "Partial sums: ";
    for (int n : result) {
        std::cout << n << " ";  // Output: 1 3 6 10 15
    }
    std::cout << std::endl << std::endl;

    std::vector<int> numbers2 = {1, 4, 9, 16, 25};
    std::vector<int> result2(numbers2.size());
    std::adjacent_difference(numbers2.begin(), numbers2.end(), result2.begin());
    std::cout << "Adjacent differences: ";
    for (int n : result2) {
        std::cout << n << " ";  // Output: 1 3 5 7 9
    }
    std::cout << std::endl << std::endl;
    return 0;
}
