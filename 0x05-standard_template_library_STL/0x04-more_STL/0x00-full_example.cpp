#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>  // for std::accumulate

int main() {
    // 1. Basic Lambda Usage with std::for_each
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    std::cout << "Doubling the numbers using std::for_each and a lambda:\n";
    std::for_each(numbers.begin(), numbers.end(), [](int n) {
        std::cout << n * 2 << " ";  // Doubles each element
    });
    std::cout << "\n\n";

    // 2. Using std::find_if with a lambda to find the first even number
    auto is_even = [](int n) { return n % 2 == 0; };
    auto even_it = std::find_if(numbers.begin(), numbers.end(), is_even);

    if (even_it != numbers.end()) {
        std::cout << "First even number found: " << *even_it << "\n\n";
    } else {
        std::cout << "No even numbers found!\n\n";
    }

    // 3. Capturing variables by value and reference
    int factor = 3;
    std::cout << "Multiplying numbers by factor (captured by value):\n";
    std::for_each(numbers.begin(), numbers.end(), [factor](int n) {
        std::cout << n * factor << " ";  // Captures factor by value
    });
    std::cout << "\n\n";

    int total_sum = 0;
    std::cout << "Accumulating sum (capturing by reference):\n";
    std::for_each(numbers.begin(), numbers.end(), [&total_sum](int n) {
        total_sum += n;  // Captures total_sum by reference to accumulate
    });
    std::cout << "Total Sum: " << total_sum << "\n\n";

    // 4. Using std::transform to square each element
    std::vector<int> squares(numbers.size());
    std::transform(numbers.begin(), numbers.end(), squares.begin(), [](int n) {
        return n * n;  // Squares each element
    });

    std::cout << "Squared numbers using std::transform:\n";
    for (int sq : squares) {
        std::cout << sq << " ";
    }
    std::cout << "\n\n";

    // 5. Using std::sort with a custom comparator (lambda)
    std::vector<int> random_numbers = {10, 30, 20, 50, 40};
    std::cout << "Sorting random numbers in descending order:\n";
    std::sort(random_numbers.begin(), random_numbers.end(), [](int a, int b) {
        return a > b;  // Custom comparator for descending order
    });

    for (int num : random_numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n\n";

    // 6. Capturing multiple variables (mixed capture) in a lambda
    int multiplier = 2;
    int offset = 5;
    std::vector<int> results(numbers.size());
    
    std::transform(numbers.begin(), numbers.end(), results.begin(), [=](int n) {
        return n * multiplier + offset;  // Captures multiplier by value and uses it
    });

    std::cout << "Transformed numbers with multiplier and offset:\n";
    for (int res : results) {
        std::cout << res << " ";
    }
    std::cout << "\n\n";

    // 7. Using std::accumulate with a lambda
    int sum_of_squares = std::accumulate(squares.begin(), squares.end(), 0, [](int total, int sq) {
        return total + sq;  // Sum the squares of numbers
    });

    std::cout << "Sum of squares using std::accumulate: " << sum_of_squares << "\n\n";

    // 8. Advanced: Filtering numbers using std::remove_if with a lambda
    std::cout << "Removing all odd numbers from the vector:\n";
    auto new_end = std::remove_if(numbers.begin(), numbers.end(), [](int n) {
        return n % 2 != 0;  // Remove odd numbers
    });

    // Erase the removed elements from the vector
    numbers.erase(new_end, numbers.end());

    std::cout << "Numbers after removing odd values:\n";
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << "\n";

    return 0;
}
