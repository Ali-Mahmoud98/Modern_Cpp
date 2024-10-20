# STL - `std::optional`
`std::optional` is a utility in C++ that represents an optional value. It can either hold a value of a specified type or be empty (i.e., contain no value). This feature is particularly useful for representing scenarios where a value may be absent, helping to avoid the use of sentinel values or error codes. `std::optional` was introduced in C++17 and is part of the `<optional>` header.

### Definition

`std::optional` is defined as follows:

```cpp
template <class T>
class optional;
```

### Key Features

1. **Holds a Value or No Value**: `std::optional<T>` can either contain a value of type `T` or be in a "disengaged" state, indicating that it holds no value.

2. **Constructors**: It provides various constructors:
   - Default constructor creates an empty `optional`.
   - Copy and move constructors allow creating an `optional` that holds a value.
   - You can also construct an `optional` directly with a value.

3. **Value Access**: You can access the contained value using:
   - `value()`: Returns the value stored in the `optional`, throwing an exception (`std::bad_optional_access`) if it's empty.
   - `operator*()`: Dereferences the `optional` to get the value.
   - `operator->()`: Provides access to the value's members (if `T` is a class type).

4. **Checking State**: You can check if an `optional` contains a value using:
   - `has_value()`: Returns `true` if the `optional` contains a value, `false` otherwise.
   - The implicit conversion to `bool` can also be used.

5. **Resetting**: You can reset the `optional` to an empty state using the `reset()` method.

6. **Comparison**: `std::optional` supports comparison operators like `==`, `!=`, `<`, `>`, `<=`, and `>=`, which compare the contained values or their absence.

7. **Emplace**: The `emplace` method allows you to construct the value in-place within the `optional`, using the provided arguments.

### Example Usage

Here’s a simple example illustrating how to use `std::optional`:

```cpp
#include <iostream>
#include <optional>
#include <string>

std::optional<std::string> findUserById(int id) {
    if (id == 1) {
        return "Alice"; // Found user
    } else if (id == 2) {
        return "Bob"; // Found user
    } else {
        return std::nullopt; // User not found
    }
}

int main() {
    std::optional<std::string> user1 = findUserById(1);
    std::optional<std::string> user2 = findUserById(3); // User not found

    // Checking if user1 has a value
    if (user1.has_value()) {
        std::cout << "User 1: " << *user1 << std::endl; // Outputs: Alice
    } else {
        std::cout << "User 1 not found." << std::endl;
    }

    // Checking user2
    if (user2) { // Implicit conversion to bool
        std::cout << "User 2: " << *user2 << std::endl;
    } else {
        std::cout << "User 2 not found." << std::endl; // Outputs: User 2 not found.
    }

    // Using value() method
    try {
        std::cout << "User 1: " << user1.value() << std::endl; // Outputs: Alice
        std::cout << "User 2: " << user2.value() << std::endl; // This will throw
    } catch (const std::bad_optional_access& e) {
        std::cerr << e.what() << std::endl; // Handle the exception
    }

    return 0;
}
```

### Practical Applications

- **Returning Optional Values**: Functions can return `std::optional` to indicate that a value may or may not be present, avoiding the need for special return codes or out parameters.
  
- **Data Structures**: You can use `std::optional` in data structures where a member may not always have a value.

- **Improved Readability**: Using `std::optional` enhances code readability by clearly indicating when a value is optional.
