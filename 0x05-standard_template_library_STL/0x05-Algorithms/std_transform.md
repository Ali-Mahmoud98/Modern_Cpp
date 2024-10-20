# std::transform
`std::transform` is a function in C++ from the `<algorithm>` header that applies a specified operation to elements in one or two ranges, transforming them and storing the result in an output range. It is commonly used for applying functions, modifying collections, or generating new sequences based on existing ones.

**Read more:** https://en.cppreference.com/w/cpp/algorithm/transform

### Syntax

There are two overloads of `std::transform`:

1. **Unary Operation (Transforming One Range)**
   ```cpp
   template<class InputIterator, class OutputIterator, class UnaryOperation>
   OutputIterator transform(InputIterator first1, InputIterator last1, OutputIterator result, UnaryOperation op);
   ```

   - Applies the unary operation to each element in the range `[first1, last1)` and stores the result in the `result` output iterator.

2. **Binary Operation (Transforming Two Ranges)**
   ```cpp
   template<class InputIterator1, class InputIterator2, class OutputIterator, class BinaryOperation>
   OutputIterator transform(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, OutputIterator result, BinaryOperation op);
   ```

   - Applies the binary operation to corresponding elements from two input ranges, and stores the result in the output iterator.

### Parameters

1. **`first1`** and **`last1`**: These define the range `[first1, last1)` of the first input sequence.
2. **`first2`**: For the binary version, this defines the beginning of the second input range.
3. **`result`**: This is the output iterator where the transformed results are stored.
4. **`op`**: The unary or binary operation that is applied to the elements of the input ranges. This can be a function, functor, or lambda expression.

### How It Works

- The **unary version** applies a transformation to each element of the input range and stores the result in the output iterator.
- The **binary version** applies a transformation to corresponding elements from two input ranges and stores the result.

### Example 1: Unary Operation (Transforming a Single Range)

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::vector<int> result(numbers.size());
    
    // Unary operation: multiply each element by 2
    std::transform(numbers.begin(), numbers.end(), result.begin(), [](int n) { return n * 2; });
    
    std::cout << "Transformed numbers (multiplied by 2): ";
    for (int n : result) {
        std::cout << n << " ";  // Output: 2 4 6 8 10
    }
    std::cout << std::endl;
    
    return 0;
}
```

In this example:
- A lambda function is used to multiply each element by 2.
- The result is stored in the `result` vector.

### Example 2: Binary Operation (Transforming Two Ranges)

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {5, 4, 3, 2, 1};
    std::vector<int> result(vec1.size());
    
    // Binary operation: add corresponding elements from vec1 and vec2
    std::transform(vec1.begin(), vec1.end(), vec2.begin(), result.begin(), std::plus<int>());
    
    std::cout << "Sum of corresponding elements: ";
    for (int n : result) {
        std::cout << n << " ";  // Output: 6 6 6 6 6
    }
    std::cout << std::endl;
    
    return 0;
}
```

In this example:
- The binary operation `std::plus<int>()` is used to add corresponding elements from `vec1` and `vec2`.
- The result is stored in the `result` vector.

### Example 3: Unary Transformation with a Lambda

You can also use `std::transform` with more complex operations, such as applying a function or lambda to modify the elements.

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

int main() {
    std::vector<int> numbers = {1, 4, 9, 16, 25};
    std::vector<double> result(numbers.size());
    
    // Unary operation: compute the square root of each element
    std::transform(numbers.begin(), numbers.end(), result.begin(), [](int n) { return std::sqrt(n); });
    
    std::cout << "Square roots: ";
    for (double n : result) {
        std::cout << n << " ";  // Output: 1 2 3 4 5
    }
    std::cout << std::endl;
    
    return 0;
}
```

In this example:
- A lambda function is used to compute the square root of each element in the input vector `numbers`.
- The results are stored in a `result` vector of type `double`.

### Example 4: Binary Transformation with a Custom Operation

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec1 = {10, 20, 30, 40, 50};
    std::vector<int> vec2 = {1, 2, 3, 4, 5};
    std::vector<int> result(vec1.size());
    
    // Binary operation: subtract elements of vec2 from vec1
    std::transform(vec1.begin(), vec1.end(), vec2.begin(), result.begin(), [](int a, int b) {
        return a - b;
    });
    
    std::cout << "Difference between corresponding elements: ";
    for (int n : result) {
        std::cout << n << " ";  // Output: 9 18 27 36 45
    }
    std::cout << std::endl;
    
    return 0;
}
```

In this case:
- A lambda function is used to subtract corresponding elements from two input vectors (`vec1` and `vec2`).
- The result is stored in the `result` vector.

### Key Points:
- **Unary operation**: You can use `std::transform` to modify a single range of elements by applying a transformation.
- **Binary operation**: You can use `std::transform` to combine elements from two ranges with a binary operation.
- **Custom operations**: You can pass any operation, including lambdas, functions, or functors.
- **Output**: The results of the transformation are stored in an output iterator, which can be an array, vector, or other container.

`std::transform` is versatile and commonly used for applying transformations or generating new sequences from existing data, making it useful in a wide variety of programming tasks.