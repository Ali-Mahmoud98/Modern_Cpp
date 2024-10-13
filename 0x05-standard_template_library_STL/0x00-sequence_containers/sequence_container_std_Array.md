# STD::array in C++

In C++, `std::array` is a container introduced with C++11, and it represents a fixed-size array. Unlike a traditional C-style array, which is essentially just a raw pointer to a block of memory, `std::array` is a safer and more feature-rich wrapper around a fixed-size array. It is part of the C++ Standard Library and resides in the `<array>` header.

**READ:** [std::array - C++ Reference](https://en.cppreference.com/w/cpp/container/array)

Here's a detailed breakdown of `std::array`:

### Key Characteristics of `std::array`:
1. **Fixed Size**: The size of `std::array` is fixed at compile-time. Once defined, the size cannot be changed during runtime.
2. **Static Allocation**: The memory for the elements of `std::array` is allocated on the stack (just like a C-style array), which makes it more efficient than dynamically allocated arrays like `std::vector`.
3. **Type Safety and Features**: It provides type safety, bounds checking (via member functions like `at()`), and integrates well with STL algorithms. Unlike C-style arrays, it offers many useful member functions.
4. **Size Known at Compile-Time**: The size of the `std::array` is known at compile-time, which allows certain optimizations.
5. **STL-Compatible**: `std::array` works seamlessly with the Standard Template Library (STL) algorithms and supports iterators.

### Syntax:

```cpp
#include <array>

std::array<T, N> array_name;
```

- **T**: Data type of the elements (e.g., `int`, `float`, `double`, etc.).
- **N**: Size of the array (must be a constant expression).

For example:

```cpp
std::array<int, 5> myArray;
```

This defines an array of 5 integers.

### Key Member Functions:

1. **`size()`**: Returns the number of elements in the array.
   ```cpp
   size_t size() const noexcept;
   ```
   Example:
   ```cpp
   std::array<int, 5> arr = {1, 2, 3, 4, 5};
   std::cout << "Size: " << arr.size();  // Output: 5
   ```

2. **`at(size_t index)`**: Accesses the element at the specified position with bounds checking. Throws an exception (`std::out_of_range`) if the index is out of bounds.
   ```cpp
   T& at(size_t index);
   const T& at(size_t index) const;
   ```
   Example:
   ```cpp
   try {
       std::cout << arr.at(2);  // Output: 3
       std::cout << arr.at(5);  // Throws exception: out_of_range
   } catch (const std::out_of_range& e) {
       std::cerr << e.what() << '\n';
   }
   ```

3. **`operator[]`**: Accesses the element at the specified position without bounds checking (similar to a C-style array).
   ```cpp
   T& operator[](size_t index);
   const T& operator[](size_t index) const;
   ```
   Example:
   ```cpp
   std::cout << arr[2];  // Output: 3
   ```

4. **`front()`**: Returns a reference to the first element in the array.
   ```cpp
   T& front();
   const T& front() const;
   ```
   Example:
   ```cpp
   std::cout << arr.front();  // Output: 1
   ```

5. **`back()`**: Returns a reference to the last element in the array.
   ```cpp
   T& back();
   const T& back() const;
   ```
   Example:
   ```cpp
   std::cout << arr.back();  // Output: 5
   ```

6. **`fill(const T& value)`**: Assigns the given value to all elements in the array.
   ```cpp
   void fill(const T& value);
   ```
   Example:
   ```cpp
   arr.fill(0);  // All elements are set to 0
   ```

7. **`data()`**: Returns a pointer to the underlying array (similar to C-style arrays). This is useful if you need a raw pointer for interoperability with legacy code or APIs.
   ```cpp
   T* data() noexcept;
   const T* data() const noexcept;
   ```
   Example:
   ```cpp
   int* ptr = arr.data();
   ```

8. **`begin()` and `end()`**: Returns iterators to the beginning and end of the array, respectively, making it compatible with STL algorithms.
   ```cpp
   iterator begin() noexcept;
   const_iterator begin() const noexcept;
   iterator end() noexcept;
   const_iterator end() const noexcept;
   ```
   Example:
   ```cpp
   for (auto it = arr.begin(); it != arr.end(); ++it) {
       std::cout << *it << " ";  // Output: 1 2 3 4 5
   }
   ```

### Comparison with C-style Arrays:

| Feature                | `std::array`                        | C-style Array                   |
|------------------------|-------------------------------------|---------------------------------|
| Size Known at Compile-time | Yes                             | Yes                             |
| Bounds Checking         | Yes (`at()`), No (`[]`)             | No                              |
| Type Safety             | Yes                                 | Limited                         |
| STL Compatible          | Yes (supports iterators)            | No (requires raw pointers)      |
| Functionality           | Rich set of member functions        | Limited                         |
| Memory                  | Allocated on the stack              | Allocated on the stack          |

### Example of `std::array` Usage:

```cpp
#include <iostream>
#include <array>
#include <algorithm>  // for std::sort

int main() {
    // Declare an array of size 5 and initialize it
    std::array<int, 5> arr = {5, 2, 8, 1, 3};

    // Access elements
    std::cout << "First element: " << arr.front() << std::endl; // 5
    std::cout << "Last element: " << arr.back() << std::endl;   // 3

    // Sort the array using STL sort
    std::sort(arr.begin(), arr.end());

    // Display sorted array
    std::cout << "Sorted array: ";
    for (const auto& elem : arr) {
        std::cout << elem << " ";
    }

    return 0;
}
```

### Key Advantages of `std::array`:

- **Improved Type Safety**: Unlike C-style arrays, `std::array` ensures better type safety.
- **Standard Library Compatibility**: Since it supports iterators and a variety of useful member functions, it integrates well with STL algorithms.
- **Bounds Checking**: While the `[]` operator does not perform bounds checking, the `at()` function provides bounds-checked access, making it safer.

### Limitations:
- The size of `std::array` is fixed at compile time, meaning it cannot be resized dynamically. For dynamic sizes, you would typically use `std::vector`.

In summary, `std::array` is a powerful and safe alternative to C-style arrays, offering the convenience of a traditional array with additional features like bounds checking, iterator support, and compatibility with the STL. It is preferred when you need a fixed-size array with the safety and flexibility of modern C++.
