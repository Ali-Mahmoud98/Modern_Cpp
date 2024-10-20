# More STL
1. **`std::pair`**: A container for storing two values of different types.
    - Example: `std::pair<int, std::string> myPair;`

2. **`std::tuple`**: Like `std::pair`, but it can store an arbitrary number of elements of different types.
   - Example: `std::tuple<int, double, std::string> myTuple;`

3. **`std::optional`**: Represents an object that may or may not contain a value. It's useful for indicating optional parameters.
   - Example: `std::optional<int> opt;`

4. **`std::variant`**: A type-safe union that can hold one of several types. It's useful when a variable can hold multiple types.
   - Example: `std::variant<int, std::string> var;`

5. **`std::span`**: Represents a non-owning view over a contiguous sequence of objects (like an array or vector). This allows you to pass around arrays without copying them. (Since C++20)
   - Example: `std::span<int> mySpan(arr, size);`

### **`std::pair`**:
`std::pair` is a simple but powerful utility that can hold two heterogeneous values as a single object. It's part of the Standard Template Library (STL) and is defined in the `<utility>` header. Here's a detailed breakdown of its features and usage:

#### Definition

A `std::pair` is a class template that is defined as follows:

```cpp
template <class T1, class T2>
struct pair {
    T1 first;  // The first value
    T2 second; // The second value

    // Constructors
    pair();
    pair(const T1& a, const T2& b);
    template <class U1, class U2>
    pair(const pair<U1, U2>& p);
    
    // Other member functions can be defined as well
};
```

#### Key Features

1. **Storage for Two Values**: `std::pair` can store two values of potentially different types. The types are specified as template parameters `T1` and `T2`.

2. **Access Members**: You can access the values using the `first` and `second` public members. For example:
   ```cpp
   std::pair<int, std::string> myPair(1, "Hello");
   std::cout << myPair.first;  // Outputs: 1
   std::cout << myPair.second; // Outputs: Hello
   ```

3. **Constructors**: It provides constructors for easy initialization. You can create a pair using either default values or by passing in the two values directly.

4. **Comparison Operators**: `std::pair` supports comparison operators, including `==`, `!=`, `<`, `>`, `<=`, and `>=`, which compare pairs lexicographically. For example, comparing pairs is done based on the first element, and if those are equal, then the second element is compared.

5. **Standard Usage**: It’s commonly used in associative containers like `std::map`, where a pair can represent a key-value association.

#### Example Usage

Here’s a simple example of how to use `std::pair`:

```cpp
#include <iostream>
#include <utility> // for std::pair
#include <string>

int main() {
    // Creating a pair
    std::pair<int, std::string> p1(1, "Apple");
    std::pair<int, std::string> p2(2, "Banana");

    // Accessing elements
    std::cout << "First: " << p1.first << ", Second: " << p1.second << std::endl;

    // Using comparison
    if (p1 < p2) {
        std::cout << p1.second << " is less than " << p2.second << std::endl;
    }

    // Swapping pairs
    std::swap(p1, p2);
    std::cout << "After swap - p1: " << p1.first << ", p2: " << p2.first << std::endl;

    return 0;
}
```

#### Practical Applications

- **Returning Multiple Values**: Functions can return a `std::pair` to give back two related values without needing to create a custom struct or class.
- **Storing Key-Value Pairs**: In STL containers like `std::map`, which use pairs to associate keys with values.
