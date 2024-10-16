# STANDARD TEMPLATE LIBRARY: std::pair
In C++, a **pair** is a simple data structure provided by the Standard Template Library (STL) that encapsulates two heterogeneous objects into a single unit. This structure is defined in the `<utility>` header and can be particularly useful when you want to return multiple values from a function or when working with data that logically forms a pair (like a key and value in maps).

### Key Features of `std::pair`

1. **Template Structure**:
   - `std::pair` is a template class that can hold two values of potentially different types. It is defined as `std::pair<T1, T2>`, where `T1` and `T2` are the types of the first and second elements, respectively.

2. **Members**:
   - A `pair` has two public data members:
     - `first`: This member holds the first element of the pair.
     - `second`: This member holds the second element of the pair.

3. **Construction**:
   - You can create a `pair` using its constructor, or you can use the `std::make_pair` function for convenience, which automatically deduces the types of the elements.

4. **Use Cases**:
   - Commonly used in associative containers like `std::map` and `std::unordered_map`, where each element consists of a key-value pair.
   - Useful for returning multiple values from functions without needing to define a custom structure.

### Example Usage

Here’s a simple example that demonstrates how to use `std::pair`:

```cpp
#include <iostream>
#include <utility> // for std::pair and std::make_pair

int main() {
    // Creating a pair using constructor
    std::pair<int, std::string> myPair(1, "One");
    
    // Accessing pair elements
    std::cout << "First: " << myPair.first << std::endl;   // Output: First: 1
    std::cout << "Second: " << myPair.second << std::endl; // Output: Second: One

    // Creating a pair using std::make_pair
    auto anotherPair = std::make_pair(2, "Two");
    
    std::cout << "First: " << anotherPair.first << std::endl;   // Output: First: 2
    std::cout << "Second: " << anotherPair.second << std::endl; // Output: Second: Two

    return 0;
}
```

### Output

```
First: 1
Second: One
First: 2
Second: Two
```

### Summary

- **`std::pair`**: A simple and versatile data structure that holds two values, which can be of different types.
- **Key Members**: Contains two public members: `first` and `second`.
- **Construction**: Can be created using the constructor or the `std::make_pair` function.
- **Common Use Cases**: Often used in maps, returning multiple values from functions, and other scenarios where a simple two-element structure is needed.

The `std::pair` class is a convenient way to group two related values together, making it easier to handle operations that involve pairs of data.