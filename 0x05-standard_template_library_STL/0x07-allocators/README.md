# Allocators

### What is an Allocator?

An **allocator** in C++ is an object responsible for handling the allocation and deallocation of memory. It abstracts away the memory management process, allowing developers to control how memory is allocated and released for objects, especially in data structures like containers. The primary goal of an allocator is to provide a mechanism for memory management that can be customized or optimized according to specific needs. 

### Default Allocator: `std::allocator`

The default allocator in C++ is provided by the Standard Library and is called `std::allocator`. This allocator performs basic memory management using the following methods:

- **Allocate**: It allocates a specified number of objects of a given type.
- **Deallocate**: It deallocates memory previously allocated.
- **Construct**: It constructs an object in the allocated memory.
- **Destroy**: It destroys an object, calling its destructor.

Here’s a simple example of how `std::allocator` works:

```cpp
#include <memory>

int main() {
    std::allocator<int> alloc; // Create an allocator for ints
    int* p = alloc.allocate(5); // Allocate memory for 5 ints

    for (int i = 0; i < 5; ++i) {
        alloc.construct(p + i, i); // Construct the integers
    }

    for (int i = 0; i < 5; ++i) {
        std::cout << p[i] << " "; // Output the integers
    }

    for (int i = 0; i < 5; ++i) {
        alloc.destroy(p + i); // Destroy the integers
    }

    alloc.deallocate(p, 5); // Deallocate memory

    return 0;
}
```

**READ More:** https://en.cppreference.com/w/cpp/memory/allocator

### Creating Custom Allocators

Creating a custom allocator involves defining a class that conforms to the allocator requirements specified in the C++ Standard. This class must define several types and member functions, including:

- `value_type`: The type of objects allocated.
- `pointer`: A pointer type that points to `value_type`.
- `allocate(size_t n)`: Allocates memory for `n` objects.
- `deallocate(pointer p, size_t n)`: Deallocates memory for `n` objects pointed to by `p`.
- `construct(pointer p, Args&&... args)`: Constructs an object at pointer `p`.
- `destroy(pointer p)`: Destroys the object at pointer `p`.

Here’s an example of a simple custom allocator:

```cpp
#include <iostream>
#include <memory>

template <typename T>
class MyAllocator {
public:
    using value_type = T;

    MyAllocator() = default;

    template <typename U>
    MyAllocator(const MyAllocator<U>&) {}

    T* allocate(std::size_t n) {
        if (n > std::size_t(-1) / sizeof(T)) {
            throw std::bad_alloc();
        }
        T* p = static_cast<T*>(::operator new(n * sizeof(T)));
        return p;
    }

    void deallocate(T* p, std::size_t) {
        ::operator delete(p);
    }

    void construct(T* p, const T& value) {
        new(p) T(value);
    }

    void destroy(T* p) {
        p->~T();
    }
};

template <typename T, typename U>
bool operator==(const MyAllocator<T>&, const MyAllocator<U>&) { return true; }

template <typename T, typename U>
bool operator!=(const MyAllocator<T>&, const MyAllocator<U>&) { return false; }
```

### Allocators in Containers: Custom Memory Management

C++ Standard Library containers like `std::vector`, `std::list`, and `std::map` allow the user to specify a custom allocator as a template argument. This enables the containers to manage memory in a way that fits specific performance or memory usage needs.

For example, if you want to use `MyAllocator` with `std::vector`, you can specify it like this:

```cpp
#include <vector>

int main() {
    std::vector<int, MyAllocator<int>> vec; // Vector using custom allocator
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    // Custom memory management is applied here
    return 0;
}
```

### Use Cases of Custom Allocators in High-Performance Scenarios

Custom allocators are particularly beneficial in high-performance scenarios, where memory allocation and deallocation can become bottlenecks. Here are a few use cases:

1. **Pool Allocators**: These allocators manage a large block of memory and serve small chunks to avoid the overhead of frequent allocations. This is useful in scenarios where many small objects are frequently created and destroyed.

2. **Memory Tracking**: Custom allocators can be designed to track memory usage for debugging purposes or to implement features like memory leaks detection.

3. **Optimized Performance**: In performance-critical applications, such as game engines or real-time systems, custom allocators can be optimized for specific patterns of memory usage, reducing fragmentation and improving cache locality.

4. **Specialized Storage**: Custom allocators can manage memory on special hardware or in specific environments, like GPUs or embedded systems, where standard allocation methods are inadequate.

5. **Alignment Control**: Allocators can be created to ensure that memory is allocated with specific alignment requirements, which is crucial for performance on certain hardware architectures.

In summary, allocators in C++ are a powerful feature that provides flexibility in memory management, enabling developers to optimize their applications for performance and memory usage. The ability to create custom allocators allows for tailored solutions in various high-performance scenarios.

### References

1. C++ Standard Library: Allocators - https://en.cppreference.com/w/cpp/memory/allocator
2. Custom Allocators in C++ - https://www.learncpp.com/cpp-tutorial/custom-memory-allocators-in-c/
3. High-Performance Memory Management - https://www.oreilly.com/library/view/high-performance-c/9780134923218/ch03.xhtml