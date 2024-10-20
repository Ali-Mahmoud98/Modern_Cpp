# Numeric Algorithms

## `std::accumulate`
`std::accumulate` is a function in C++ that belongs to the `<numeric>` header. It is primarily used to compute the sum or some other accumulation (e.g., product) of elements in a range. 

**Read more:** https://en.cppreference.com/w/cpp/numeric/accumulate

### Syntax
```cpp
#include <numeric>

T accumulate(InputIterator first, InputIterator last, T init);
T accumulate(InputIterator first, InputIterator last, T init, BinaryOperation op);
```

### Parameters

1. **`first`** and **`last`**: These define the range of elements over which the accumulation is performed. `first` is the starting iterator, and `last` is the ending iterator (non-inclusive).

2. **`init`**: This is the initial value of the accumulation. The type of this value (`T`) determines the type of the result as well.

3. **`BinaryOperation op`** (optional): This is a binary operation (usually a function or a lambda) that can be used to specify how to combine the elements. If this is not provided, the default operation is `+` (i.e., addition).

### Return Value

- The function returns the accumulated result starting from `init` and applying the `BinaryOperation` (or addition by default) to the elements in the range `[first, last)`.

### Example 1: Basic Accumulation (Sum)

```cpp
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    
    std::cout << "Sum: " << sum << std::endl;  // Output: Sum: 15
    return 0;
}
```

In this example:
- We use `std::accumulate` to compute the sum of the elements in the vector.
- `numbers.begin()` and `numbers.end()` define the range, and `0` is the initial value (starting point of the sum).

### Example 2: Custom Binary Operation (Multiplication)

```cpp
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    int product = std::accumulate(numbers.begin(), numbers.end(), 1, std::multiplies<int>());
    
    std::cout << "Product: " << product << std::endl;  // Output: Product: 120
    return 0;
}
```

In this example:
- Instead of summing the elements, we use a custom binary operation: `std::multiplies<int>()`, which multiplies the elements together.
- The initial value is `1` because multiplication with `0` would result in `0`.

### Example 3: Using Lambda for Custom Operation

```cpp
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    
    // Custom operation using a lambda: subtract each element from the previous one.
    int result = std::accumulate(numbers.begin(), numbers.end(), 0, [](int x, int y) {
        return x - y;
    });
    
    std::cout << "Result: " << result << std::endl;  // Output: Result: -15
    return 0;
}
```

Here:
- We use a lambda function to define a custom binary operation that subtracts each element from the previous one.

### Key Points:
- **Default behavior**: `std::accumulate` adds elements together if no custom operation is provided.
- **Custom operations**: By providing a binary function (like `std::multiplies` or a lambda), you can change how the accumulation is performed (e.g., multiply, subtract).
- **Initial value**: The initial value (`init`) is crucial because it sets the starting point of the accumulation. For example, in multiplication, the initial value should be `1`.

## `std::partial_sum`
`std::partial_sum` is a function in C++ from the `<numeric>` header that computes the partial sums (or any other operation) of elements in a range. It is used to generate a sequence where each element is the result of accumulating all previous elements up to that point. Essentially, it’s like performing `std::accumulate`, but at each step, you store the result in a new range.

**Read more:** https://en.cppreference.com/w/cpp/numeric/partial_sum

### Syntax
```cpp
#include <numeric>

template <class InputIterator, class OutputIterator>
OutputIterator partial_sum(InputIterator first, InputIterator last, OutputIterator result);

template <class InputIterator, class OutputIterator, class BinaryOperation>
OutputIterator partial_sum(InputIterator first, InputIterator last, OutputIterator result, BinaryOperation op);
```

### Parameters

1. **`first`** and **`last`**: These iterators define the range `[first, last)` over which the partial sums are computed. `first` is the starting iterator, and `last` is the ending iterator (non-inclusive).

2. **`result`**: This is the output iterator where the partial sums (or results of the custom binary operation) are stored.

3. **`BinaryOperation op`** (optional): This is a binary operation used to combine the elements, like in `std::accumulate`. If this is not provided, the default operation is `+` (addition).

### Return Value

- The function returns an iterator to the element past the last element written in the `result` range.

### Example 1: Basic Partial Sum (Addition)

```cpp
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::vector<int> result(numbers.size());
    
    std::partial_sum(numbers.begin(), numbers.end(), result.begin());
    
    std::cout << "Partial sums: ";
    for (int n : result) {
        std::cout << n << " ";  // Output: 1 3 6 10 15
    }
    std::cout << std::endl;
    
    return 0;
}
```

In this example:
- `std::partial_sum` computes the cumulative sum of the elements.
- The `result` vector stores the intermediate results.
    - First element: `1`
    - Second element: `1 + 2 = 3`
    - Third element: `1 + 2 + 3 = 6`
    - And so on, resulting in: `1, 3, 6, 10, 15`.

### Example 2: Partial Product (Custom Binary Operation)

```cpp
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::vector<int> result(numbers.size());
    
    std::partial_sum(numbers.begin(), numbers.end(), result.begin(), std::multiplies<int>());
    
    std::cout << "Partial products: ";
    for (int n : result) {
        std::cout << n << " ";  // Output: 1 2 6 24 120
    }
    std::cout << std::endl;
    
    return 0;
}
```

In this case:
- The custom binary operation `std::multiplies<int>()` is used instead of the default addition.
- The result vector stores the partial products.
    - First element: `1`
    - Second element: `1 * 2 = 2`
    - Third element: `1 * 2 * 3 = 6`
    - And so on, resulting in: `1, 2, 6, 24, 120`.

### Example 3: Using a Lambda for Custom Operation

```cpp
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::vector<int> result(numbers.size());
    
    // Custom operation using a lambda: sum of squares of the elements
    std::partial_sum(numbers.begin(), numbers.end(), result.begin(), [](int x, int y) {
        return x + y * y;
    });
    
    std::cout << "Partial sum of squares: ";
    for (int n : result) {
        std::cout << n << " ";  // Output: 1 5 14 30 55
    }
    std::cout << std::endl;
    
    return 0;
}
```

In this example:
- A lambda function is used to compute a custom operation: the sum of the squares of the elements.
    - First element: `1`
    - Second element: `1 + 2^2 = 5`
    - Third element: `5 + 3^2 = 14`
    - And so on, resulting in: `1, 5, 14, 30, 55`.

### Key Points
- **Default behavior**: If no custom operation is provided, `std::partial_sum` computes the cumulative sum of the elements.
- **Custom operations**: Like `std::accumulate`, you can provide any binary operation (e.g., product, difference, or even more complex operations using lambdas).
- **Output range**: The results of each intermediate step are stored in the output iterator (such as a vector or array).
- **Efficiency**: `std::partial_sum` performs a single pass over the input range, making it quite efficient for computing running totals or products.

`std::partial_sum` is useful in scenarios where you need cumulative results, such as running totals, partial products, or complex custom accumulations.

## `std::adjacent_difference`
`std::adjacent_difference` is a function in C++ from the `<numeric>` header, which computes the difference (or another operation) between each adjacent pair of elements in a given range. It’s used to generate a new sequence where each element is the result of an operation (typically subtraction) between an element and the one preceding it.

**Read more:** https://en.cppreference.com/w/cpp/numeric/adjacent_difference

### Syntax
```cpp
#include <numeric>

template <class InputIterator, class OutputIterator>
OutputIterator adjacent_difference(InputIterator first, InputIterator last, OutputIterator result);

template <class InputIterator, class OutputIterator, class BinaryOperation>
OutputIterator adjacent_difference(InputIterator first, InputIterator last, OutputIterator result, BinaryOperation op);
```

### Parameters

1. **`first`** and **`last`**: These define the range `[first, last)` over which the adjacent differences are computed. `first` is the starting iterator, and `last` is the ending iterator (non-inclusive).

2. **`result`**: This is the output iterator where the adjacent differences (or results of the custom operation) are stored.

3. **`BinaryOperation op`** (optional): This is a binary operation used to combine adjacent elements. If no operation is provided, the default operation is subtraction (`-`).

### Return Value

- The function returns an iterator pointing to the element past the last element written in the result range.

### How It Works

- The first element of the result sequence is always a copy of the first element of the input sequence.
- Each subsequent element in the result is obtained by applying the binary operation (or subtraction by default) between consecutive elements in the input range.

### Example 1: Basic Adjacent Difference (Subtraction)

```cpp
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 4, 9, 16, 25};
    std::vector<int> result(numbers.size());
    
    std::adjacent_difference(numbers.begin(), numbers.end(), result.begin());
    
    std::cout << "Adjacent differences: ";
    for (int n : result) {
        std::cout << n << " ";  // Output: 1 3 5 7 9
    }
    std::cout << std::endl;
    
    return 0;
}
```

In this example:
- `std::adjacent_difference` computes the differences between each consecutive pair of numbers in the input vector.
    - First element: `1` (copied as is from the input)
    - Second element: `4 - 1 = 3`
    - Third element: `9 - 4 = 5`
    - And so on, resulting in: `1, 3, 5, 7, 9`.

### Example 2: Custom Binary Operation (Multiplication)

```cpp
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::vector<int> result(numbers.size());
    
    // Custom operation: multiply adjacent elements
    std::adjacent_difference(numbers.begin(), numbers.end(), result.begin(), std::multiplies<int>());
    
    std::cout << "Adjacent products: ";
    for (int n : result) {
        std::cout << n << " ";  // Output: 1 2 6 12 20
    }
    std::cout << std::endl;
    
    return 0;
}
```

Here:
- A custom binary operation `std::multiplies<int>()` is used instead of subtraction.
    - First element: `1` (copied from the input)
    - Second element: `1 * 2 = 2`
    - Third element: `2 * 3 = 6`
    - And so on, resulting in: `1, 2, 6, 12, 20`.

### Example 3: Using Lambda for Custom Operation

```cpp
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> numbers = {10, 20, 30, 40, 50};
    std::vector<int> result(numbers.size());
    
    // Custom operation using a lambda: sum of squares of adjacent differences
    std::adjacent_difference(numbers.begin(), numbers.end(), result.begin(), [](int x, int y) {
        return (x - y) * (x - y);
    });
    
    std::cout << "Adjacent squared differences: ";
    for (int n : result) {
        std::cout << n << " ";  // Output: 10 100 100 100 100
    }
    std::cout << std::endl;
    
    return 0;
}
```

In this example:
- A lambda function is used to compute the square of the difference between adjacent elements.
    - First element: `10` (copied from the input)
    - Second element: `(20 - 10)^2 = 100`
    - Third element: `(30 - 20)^2 = 100`
    - And so on, resulting in: `10, 100, 100, 100, 100`.

### Example 4: Generating Cumulative Sum

You can also use `std::adjacent_difference` to reverse a cumulative sum (i.e., to get the original values from a cumulative sum).

```cpp
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> cumulative_sum = {1, 3, 6, 10, 15};
    std::vector<int> result(cumulative_sum.size());
    
    std::adjacent_difference(cumulative_sum.begin(), cumulative_sum.end(), result.begin());
    
    std::cout << "Original sequence from cumulative sum: ";
    for (int n : result) {
        std::cout << n << " ";  // Output: 1 2 3 4 5
    }
    std::cout << std::endl;
    
    return 0;
}
```

In this case:
- `std::adjacent_difference` helps retrieve the original values from a cumulative sum.

### Key Points:
- **Default behavior**: By default, `std::adjacent_difference` subtracts consecutive elements.
- **Custom operations**: You can pass any binary operation (like addition, multiplication, or even more complex operations using a lambda) to `std::adjacent_difference`.
- **First element**: The first element of the result sequence is always a copy of the first element from the input range.
- **Applications**: It is useful for tasks like computing differences between consecutive elements, cumulative sum reversals, and applying custom operations on adjacent elements.

`std::adjacent_difference` is a versatile tool when you need to process differences or operations between neighboring elements in a sequence.

## `std::inner_product`
`std::inner_product` is a function in C++ from the `<numeric>` header used to compute the inner product (dot product) of two ranges of elements. By default, it multiplies corresponding elements of two ranges and then sums them up, but you can also provide custom binary operations for the multiplication and addition steps. 

Read more: [std::inner_product](https://en.cppreference.com/w/cpp/numeric/inner_product)

### Syntax
```cpp
#include <numeric>

template<class InputIterator1, class InputIterator2, class T>
T inner_product(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, T init);

template<class InputIterator1, class InputIterator2, class T, class BinaryOperation1, class BinaryOperation2>
T inner_product(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, T init, 
                BinaryOperation1 binary_op1, BinaryOperation2 binary_op2);
```

### Parameters

1. **`first1`** and **`last1`**: These define the first range `[first1, last1)` over which the operation is performed.
2. **`first2`**: This points to the beginning of the second range (which should be the same length as the first range).
3. **`init`**: This is the initial value for the accumulation. The type of this value determines the return type.
4. **`binary_op1`** (optional): The binary operation applied between corresponding elements of the two ranges (by default, multiplication).
5. **`binary_op2`** (optional): The binary operation used to combine the results of `binary_op1` (by default, addition).

### Return Value
The function returns the result of the accumulation, starting from the `init` value and applying the two binary operations.

### How It Works
- `std::inner_product` computes the result of combining corresponding elements of two ranges using `binary_op1`, and then accumulates the results using `binary_op2`.
- The default operation is multiplication for corresponding elements and addition for accumulation, which is the standard definition of an inner product (or dot product).

### Example 1: Default Inner Product (Dot Product)

```cpp
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {5, 4, 3, 2, 1};
    
    int result = std::inner_product(vec1.begin(), vec1.end(), vec2.begin(), 0);
    
    std::cout << "Dot product: " << result << std::endl;  // Output: Dot product: 35
    return 0;
}
```

In this example:
- The function computes the dot product between `vec1` and `vec2`.
    - `1 * 5 = 5`
    - `2 * 4 = 8`
    - `3 * 3 = 9`
    - `4 * 2 = 8`
    - `5 * 1 = 5`
- The sum is `5 + 8 + 9 + 8 + 5 = 35`.

### Example 2: Custom Binary Operations (Difference of Products)

```cpp
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {5, 4, 3, 2, 1};
    
    // Custom operation: multiply corresponding elements, then subtract the results
    int result = std::inner_product(vec1.begin(), vec1.end(), vec2.begin(), 0,
                                    std::minus<int>(), std::multiplies<int>());
    
    std::cout << "Custom result (difference of products): " << result << std::endl;  
    // Output: Custom result (difference of products): -35
    return 0;
}
```

In this example:
- `std::multiplies<int>()` is used to multiply the corresponding elements of the two vectors, just like in the default operation.
- Instead of summing the results, `std::minus<int>()` is used to subtract the products, giving the result `5 - 8 - 9 - 8 - 5 = -35`.

### Example 3: Accumulate with Custom Operations (Sum of Element-wise Maximums)

```cpp
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> vec1 = {1, 7, 3, 9, 5};
    std::vector<int> vec2 = {5, 4, 8, 2, 6};
    
    // Custom operation: element-wise maximum, and accumulate with addition
    int result = std::inner_product(vec1.begin(), vec1.end(), vec2.begin(), 0,
                                    std::plus<int>(), [](int a, int b) { return std::max(a, b); });
    
    std::cout << "Sum of element-wise maximums: " << result << std::endl;  
    // Output: Sum of element-wise maximums: 35
    return 0;
}
```

In this case:
- Instead of multiplying the corresponding elements, a lambda function is used to take the maximum of each pair of elements.
    - `max(1, 5) = 5`
    - `max(7, 4) = 7`
    - `max(3, 8) = 8`
    - `max(9, 2) = 9`
    - `max(5, 6) = 6`
- The result is the sum of these maximum values: `5 + 7 + 8 + 9 + 6 = 35`.

### Example 4: Computing Cosine Similarity

In machine learning and data science, `std::inner_product` can be used to compute the cosine similarity between two vectors. Cosine similarity is defined as:

\[
\text{cosine\_similarity} = \frac{\mathbf{A} \cdot \mathbf{B}}{\|\mathbf{A}\| \|\mathbf{B}\|}
\]

```cpp
#include <iostream>
#include <numeric>
#include <vector>
#include <cmath>

double magnitude(const std::vector<int>& vec) {
    return std::sqrt(std::inner_product(vec.begin(), vec.end(), vec.begin(), 0.0));
}

int main() {
    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2 = {4, 5, 6};
    
    double dot_product = std::inner_product(vec1.begin(), vec1.end(), vec2.begin(), 0.0);
    double magnitude_vec1 = magnitude(vec1);
    double magnitude_vec2 = magnitude(vec2);
    
    double cosine_similarity = dot_product / (magnitude_vec1 * magnitude_vec2);
    
    std::cout << "Cosine similarity: " << cosine_similarity << std::endl;  
    // Output: Cosine similarity: 0.974631846
    return 0;
}
```

In this example:
- The dot product of `vec1` and `vec2` is computed using `std::inner_product`.
- The magnitude (Euclidean norm) of each vector is computed.
- Cosine similarity is then calculated as the ratio of the dot product to the product of the magnitudes.

### Key Points:
- **Default behavior**: `std::inner_product` multiplies corresponding elements from two ranges and sums the results (dot product).
- **Custom operations**: You can provide custom binary operations for both the element-wise combination (default is multiplication) and accumulation (default is addition).
- **Initial value**: The initial value for the accumulation (e.g., `0` for summation) is important because it serves as the starting point for the accumulation.

`std::inner_product` is useful in various applications such as computing dot products, custom element-wise operations between two ranges, and more complex scenarios like cosine similarity in vector spaces.
