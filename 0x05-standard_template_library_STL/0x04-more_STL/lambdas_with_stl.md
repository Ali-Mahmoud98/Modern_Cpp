### Using Lambdas with STL Algorithms

Lambda expressions are frequently used with STL algorithms like `std::for_each`, `std::transform`, and many others because they provide a concise way to specify the operations to perform on elements in a container.

#### 1. **Using `std::for_each` with Lambda**

`std::for_each` is an algorithm that applies a function to every element in a range.

**Example:**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    std::for_each(vec.begin(), vec.end(), [](int x) {
        std::cout << x * 2 << " ";
    });
    
    return 0;
}
```

**Explanation:**
- `std::for_each(vec.begin(), vec.end(), lambda)` applies the lambda function to each element in the vector `vec`.
- The lambda `[](int x) { std::cout << x * 2 << " "; }` doubles each element and prints it.

#### 2. **Using `std::transform` with Lambda**

`std::transform` is used to transform elements in a range and store the results in another range.

**Example:**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::vector<int> result(vec.size());

    std::transform(vec.begin(), vec.end(), result.begin(), [](int x) {
        return x * x;  // Square each element
    });

    for (int i : result) {
        std::cout << i << " ";
    }
    
    return 0;
}
```

**Explanation:**
- `std::transform` applies the lambda function to each element in `vec` and stores the results in `result`.
- The lambda `[](int x) { return x * x; }` squares each element.

### Capturing Variables and Closures

Lambda expressions can capture variables from their surrounding scope, which allows them to use local variables without explicitly passing them as arguments.

#### Capture Modes:

1. **Capture by value (`[=]`)**: Copies the variables from the surrounding scope into the lambda.
2. **Capture by reference (`[&]`)**: Captures variables by reference, allowing the lambda to modify them.
3. **Explicit capture**: You can specify which variables to capture by value or reference (e.g., `[a, &b]` captures `a` by value and `b` by reference).

#### Example of Capture by Value:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int factor = 3;
    std::vector<int> vec = {1, 2, 3, 4, 5};

    std::for_each(vec.begin(), vec.end(), [=](int x) {
        std::cout << x * factor << " ";  // factor is captured by value
    });

    return 0;
}
```

- `factor` is captured by value (`[=]`), so its value is copied into the lambda.
- The lambda prints each element in the vector multiplied by `factor` (which remains `3` inside the lambda).

#### Example of Capture by Reference:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int sum = 0;
    std::vector<int> vec = {1, 2, 3, 4, 5};

    std::for_each(vec.begin(), vec.end(), [&sum](int x) {
        sum += x;  // sum is captured by reference
    });

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}
```

- `sum` is captured by reference (`[&sum]`), so the lambda modifies the original `sum` variable by accumulating the values of the elements in `vec`.
- The result is printed after the loop: `Sum: 15`.
