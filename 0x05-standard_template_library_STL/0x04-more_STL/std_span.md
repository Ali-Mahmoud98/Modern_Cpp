# std::span (C++20)
`std::span` is a new feature introduced in C++20 that provides a **view** over a contiguous sequence of elements (like arrays, `std::vector`, or raw pointers) without owning the underlying data. It offers a safe and efficient way to access a block of data, but it does **not manage** the lifetime of the data itself, meaning the user is responsible for ensuring that the data remains valid for the span's lifetime.

### **Key Features of `std::span`:**
1. **Non-owning View**: `std::span` does not own the data it points to. It just provides access to a contiguous range of elements.
2. **Works with Various Containers**: It can be created from arrays, `std::vector`, raw arrays, or pointers and size.
3. **Bounds Checking**: Like `std::vector`, `std::span` provides bounds-checked access with functions like `.at()` to avoid accessing out-of-bounds elements.
4. **Lightweight and Efficient**: Since it doesn’t manage the memory, it is very lightweight (typically just two members: a pointer to the data and a size).
5. **Simplifies Function Interfaces**: You can use `std::span` in function arguments instead of passing raw pointers and sizes separately, leading to clearer, safer code.

### **How `std::span` Works:**
A span is basically a lightweight wrapper that stores:
- A pointer to the first element of the sequence.
- The number of elements in the sequence (the "extent").

### **Usage Examples:**

#### **1. Creating `std::span` from an Array:**
```cpp
#include <iostream>
#include <span>

int main() {
    int arr[] = {1, 2, 3, 4, 5};

    // Create a span from the array
    std::span<int> s(arr);

    // Iterate through the span
    for (int elem : s) {
        std::cout << elem << " ";  // Output: 1 2 3 4 5
    }

    return 0;
}
```

#### **2. Creating `std::span` from a `std::vector`:**
```cpp
#include <iostream>
#include <span>
#include <vector>

int main() {
    std::vector<int> vec = {10, 20, 30, 40, 50};

    // Create a span from the vector
    std::span<int> s(vec);

    // Access elements through the span
    std::cout << "Element at index 2: " << s[2] << std::endl;  // Output: 30

    return 0;
}
```

#### **3. Passing `std::span` to a Function:**
```cpp
#include <iostream>
#include <span>

// Function that accepts std::span
void printSpan(std::span<int> s) {
    for (int elem : s) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {100, 200, 300, 400};

    // Pass a span to a function
    printSpan(arr);  // Output: 100 200 300 400

    return 0;
}
```

#### **4. Creating a Subspan:**
You can create subviews or "subspans" to work with a subset of elements.

```cpp
#include <iostream>
#include <span>

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};

    // Create a span over the whole array
    std::span<int> s(arr);

    // Create a subspan (starting at index 2, length 3)
    std::span<int> sub = s.subspan(2, 3);

    // Output: 3 4 5
    for (int elem : sub) {
        std::cout << elem << " ";
    }

    return 0;
}
```

### **Key Benefits of `std::span`:**

1. **Simplifies Function Interfaces**: Instead of passing separate pointers and sizes, you can pass a `std::span`, which carries both the pointer and the size.
2. **Safety**: It avoids potential bugs with pointer arithmetic and makes code more readable and robust by providing range-checked access (like `.at()`).
3. **Non-Allocating**: Since it doesn’t manage memory, you don’t incur any allocation or copying overhead when creating a span.

### **Comparison with Other Containers:**

- **std::vector**: `std::vector` manages its own memory and can grow or shrink, while `std::span` simply provides a view over existing memory without managing it.
- **Raw Pointers and Sizes**: `std::span` is a safer and more convenient alternative to using raw pointers and separate sizes. It reduces the risk of errors like buffer overflows or invalid pointer accesses.
- **std::array**: `std::array` is a fixed-size container, whereas `std::span` just provides a view over any contiguous block of memory, regardless of its source (array, `std::vector`, or raw pointer).

### **Caveats:**
- `std::span` is a lightweight view, but it doesn’t own the memory. So you need to be careful that the data it points to remains valid for the lifetime of the span.

### **Conclusion:**
`std::span` is a powerful and flexible tool introduced in C++20 to make handling contiguous sequences of data safer, more expressive, and more efficient without the burden of memory management. It is particularly useful when you want to pass arrays or subarrays to functions in a concise and safer way.
