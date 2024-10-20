# Functors

### What are Functors?

In C++, a **functor** (function object) is an **object that can be called like a function**. It’s created by overloading the `operator()` in a class or struct, which makes an instance of that class callable like a regular function. Functors allow state to be maintained across calls, and they can encapsulate behavior in a more flexible way compared to simple functions or lambdas.

Here’s a simple example of a functor:

```cpp
#include <iostream>

// Define a functor class
class Multiply {
public:
    // Overload operator() to act as a function
    int operator()(int x, int y) const {
        return x * y;
    }
};

int main() {
    Multiply multiply;  // Create an instance of the functor
    std::cout << multiply(3, 5);  // Functor behaves like a function
    return 0;
}
```

In the example, `Multiply` is a functor that takes two integers and returns their product.

---

### How to Create a Custom Functor

To create a custom functor, you need to define a class or struct and overload the `operator()`. You can also add member variables to the class to hold state.

Here’s how to create a custom functor that adds a constant value to the input:

```cpp
#include <iostream>

// Define a custom functor
class Adder {
    int toAdd;  // Member variable to hold the constant value
public:
    Adder(int value) : toAdd(value) {}  // Constructor to initialize the value

    // Overload operator() to act as a function
    int operator()(int x) const {
        return x + toAdd;
    }
};

int main() {
    Adder addFive(5);  // Create a functor that adds 5
    std::cout << addFive(10);  // Output: 15
    return 0;
}
```

In this example, `Adder` is a custom functor that adds a constant value (in this case, 5) to the input.

---

### Functors vs Lambdas: When to Use Which

Both functors and lambdas allow you to create callable objects, but they have different use cases:

- **Functors** are preferable when:
  - You need **stateful behavior** or need to maintain a complex state across multiple invocations.
  - You require a **persistent object** with behavior that can be passed around in the code.
  - The logic is more complex or spans multiple functions.

- **Lambdas** are preferable when:
  - The functionality is **simple** and **inline**.
  - You need a quick, **anonymous function** with no need for persistent state.
  - You want to avoid the overhead of defining a full class for a simple operation.

Here’s a comparison example:

**Functor:**
```cpp
class Increment {
    int step;
public:
    Increment(int step) : step(step) {}
    int operator()(int x) const {
        return x + step;
    }
};
```

**Lambda:**
```cpp
auto increment = [](int step, int x) { return x + step; };
```

The lambda is more compact, but if you need a reusable and stateful object, a functor is more appropriate.

---

### Predefined Functors: `std::plus`, `std::minus`, `std::less`, `std::greater`

C++ Standard Library provides predefined functors in the `<functional>` header that represent common operations. These predefined functors are useful for common arithmetic, comparison, and logical operations.

- **`std::plus<T>`**: Performs addition (`T + T`).
- **`std::minus<T>`**: Performs subtraction (`T - T`).
- **`std::less<T>`**: Checks if one element is less than another (`T < T`).
- **`std::greater<T>`**: Checks if one element is greater than another (`T > T`).

Here’s how you can use these functors:

```cpp
#include <iostream>
#include <functional>  // Include for predefined functors

int main() {
    std::plus<int> add;
    std::minus<int> subtract;
    std::less<int> lessThan;

    std::cout << add(10, 5) << "\n";       // Output: 15
    std::cout << subtract(10, 5) << "\n";  // Output: 5
    std::cout << lessThan(10, 5) << "\n";  // Output: 0 (false)
    return 0;
}
```

These predefined functors are often used in STL algorithms like `std::accumulate`, `std::sort`, and `std::find_if`.

**see Example:** [0x00-predefined_functors.cpp](./0x00-predefined_functors.cpp)

---

### Use Cases for Functors in Sorting and Searching

Functors are particularly useful in algorithms like sorting and searching where custom comparison logic is needed.

1. **Sorting**:
   Functors are often used to define custom sorting orders. For example, sorting integers in descending order:

   ```cpp
   #include <iostream>
   #include <vector>
   #include <algorithm>

   // Define a functor for descending order
   struct Descending {
       bool operator()(int a, int b) const {
           return a > b;
       }
   };

   int main() {
       std::vector<int> vec = {1, 4, 2, 8, 5};
       std::sort(vec.begin(), vec.end(), Descending());  // Use functor for sorting
       for (int v : vec) {
           std::cout << v << " ";  // Output: 8 5 4 2 1
       }
       return 0;
   }
   ```

2. **Searching**:
   Functors can also be used to customize searching behavior. For example, finding an element that matches a specific condition:

   ```cpp
   #include <iostream>
   #include <vector>
   #include <algorithm>

   // Define a functor to find elements greater than a threshold
   struct GreaterThan {
       int threshold;
       GreaterThan(int t) : threshold(t) {}

       bool operator()(int x) const {
           return x > threshold;
       }
   };

   int main() {
       std::vector<int> vec = {1, 4, 2, 8, 5};
       auto it = std::find_if(vec.begin(), vec.end(), GreaterThan(4));  // Find first element > 4
       if (it != vec.end()) {
           std::cout << "Found: " << *it;  // Output: 8
       }
       return 0;
   }
   ```

In both sorting and searching, functors give you flexibility to define custom behavior that can be passed into algorithms.

---

### Summary

- **Functors** are objects that can be used like functions by overloading the `operator()`.
- You can create custom functors by defining a class with `operator()` and encapsulating state if needed.
- **Functors** are great when you need stateful behavior or complex logic, while **lambdas** are best for simple and inline operations.
- **Predefined functors** like `std::plus`, `std::minus`, `std::less`, and `std::greater` simplify common operations.
- **Functors** are especially useful in algorithms like sorting and searching where custom comparison logic is needed.

For more detailed information, you can refer to [cppreference](https://en.cppreference.com/w/cpp/utility/functional) or [cplusplus.com](http://www.cplusplus.com/reference/functional/).

