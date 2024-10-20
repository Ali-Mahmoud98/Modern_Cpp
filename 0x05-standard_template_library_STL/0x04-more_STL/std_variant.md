# STL - `std::variant`
`std::variant` is a powerful utility introduced in C++17 that provides a type-safe way to hold a value that can belong to one of several different types. It is a part of the `<variant>` header and is often described as a type-safe union.

### Definition

`std::variant` is defined as follows:

```cpp
template <class... Types>
class variant;
```

You can think of `std::variant` as a type that can hold a value of one of the specified types, but only one value at a time.

### Key Features

1. **Type Safety**: Unlike traditional unions, `std::variant` ensures that only the type currently held can be accessed. If you try to access a type that is not currently stored, the program will not compile.

2. **Construction and Assignment**: You can construct a `std::variant` with any of its specified types. You can assign a value of any of those types to the `std::variant`, but it can only hold one value at a time.

3. **Accessing Values**:
   - You can access the currently held value using `std::get` or `std::get_if`:
     - `std::get<T>(variant)`: Accesses the value if the variant currently holds a value of type `T`. If it does not, it throws `std::bad_variant_access`.
     - `std::get_if<T>(&variant)`: Returns a pointer to the value if it is of type `T`, or `nullptr` if it is not.

4. **Indexing**: You can check which type is currently held in the variant using `std::variant_size` and `std::variant_alternative`. You can also use `std::variant_npos` to determine if the variant is currently holding a particular type.

5. **Visitation**: The `std::visit` function allows you to apply a visitor (a callable) to the current value in the variant, which can be useful for handling different types in a unified way.

6. **Comparison Operators**: `std::variant` supports comparison operators to compare the held values.

### Example Usage

Here’s a simple example illustrating how to use `std::variant`:

```cpp
#include <iostream>
#include <variant>
#include <string>

// Function that accepts a variant type
void printVariant(const std::variant<int, double, std::string>& var) {
    // Use std::visit to handle different types
    std::visit([](auto&& arg) {
        std::cout << "Value: " << arg << std::endl;
    }, var);
}

int main() {
    // Creating variants
    std::variant<int, double, std::string> var1 = 42;             // Holds an int
    std::variant<int, double, std::string> var2 = 3.14;           // Holds a double
    std::variant<int, double, std::string> var3 = "Hello, World"; // Holds a string

    // Printing values using the printVariant function
    printVariant(var1);
    printVariant(var2);
    printVariant(var3);

    // Accessing values
    std::cout << "Using std::get: " << std::get<int>(var1) << std::endl; // Outputs: 42

    // Attempting to get a value of a different type (will throw)
    try {
        std::cout << "Trying to get double: " << std::get<double>(var1) << std::endl;
    } catch (const std::bad_variant_access& e) {
        std::cout << "Error: " << e.what() << std::endl; // Outputs an error message
    }

    // Using std::get_if
    if (auto pVal = std::get_if<double>(&var2)) {
        std::cout << "Value as double: " << *pVal << std::endl; // Outputs: 3.14
    } else {
        std::cout << "Not a double." << std::endl;
    }

    return 0;
}
```

### Practical Applications

- **Heterogeneous Collections**: `std::variant` is useful when you want to store different types in a single collection without resorting to polymorphism or base classes.

- **Type-Safe Interfaces**: You can use `std::variant` to create APIs that can handle multiple types in a type-safe manner, improving code readability and maintainability.

- **Visitor Patterns**: It can be used to implement the visitor design pattern more conveniently.

### Conclusion

`std::variant` is a powerful and flexible utility that allows you to safely manage values of multiple types. It improves type safety and reduces the chances of errors that can occur with traditional unions. For more information, you can check the C++ documentation here: [cppreference - std::variant](https://en.cppreference.com/w/cpp/utility/variant).

If you have any further questions or need additional examples, feel free to ask!
