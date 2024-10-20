#include <iostream>
#include <vector>
#include <algorithm>  // for std::for_each
#include <execution>  // for std::execution

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::cout << "Printing the numbers\n";
    for (int n : numbers) {
        std::cout << n << " ";  // Prints each element
    }
    std::cout << "\n\n";

    std::cout << "Doubling the numbers using std::for_each and a lambda:\n";
    std::for_each(numbers.begin(), numbers.end(), [](int n) {
        std::cout << n * 2 << " ";  // Doubles each element
    });
    std::cout << "\n\n";

    std::cout << "Printing the numbers\n";
    for (int n : numbers) {
        std::cout << n << " ";  // Prints each element
    }
    std::cout << "\n\n";

    std::cout << "Multiplying the numbers by 2 using std::for_each and a lambda:\n";
    std::for_each(numbers.begin(), numbers.end(), [](int& n) { // if you removed the '&' the values in numbers will not change
        // try [](int n) and compile then see the difference
        n *= 2;
    });

    std::cout << "Printing the numbers\n";
    for (int n : numbers) {
        std::cout << n << " ";  // Prints each element
    }
    std::cout << "\n\n";

    // void for_each( ExecutionPolicy&& policy, ForwardIt first, ForwardIt last, UnaryFunc f ); -> C++17 and later
    // UnaryFunc for_each( ExecutionPolicy&& policy, ForwardIt first, ForwardIt last, UnaryFunc f );

    // the following syntax is C++17 and beyond
    std::cout << "Multiplying the numbers by 2 using std::for_each and a lambda:\n";
    std::for_each(std::execution::par, numbers.begin(), numbers.end(), [](int& x) {
        // std::execution::seq is default
        // std::execution::par enables concurrent processing of elements
        x *= 2;  // Double each element in parallel
    });
    return 0;
}
