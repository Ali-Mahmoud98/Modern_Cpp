# Smart Pointers

In modern C++ programming, the Standard Library includes smart pointers, which are used to help ensure that programs are free of memory and resource leaks and are exception-safe.

Smart pointers are defined in the std namespace in the `<memory>` header file. They are crucial to the **RAII or Resource Acquisition Is Initialization programming idiom**.  The main goal of this idiom is to ensure that resource acquisition occurs at the same time that the object is initialized, so that all resources for the object are created and made ready in one line of code.

**READ More:**
* [Smart Pointers in C++ - GFG](https://www.geeksforgeeks.org/smart-pointers-cpp/)
* [Smart pointers (Modern C++) - Microsoft](https://learn.microsoft.com/en-us/cpp/cpp/smart-pointers-modern-cpp?view=msvc-170)

## Problems with Normal Pointers
Some Issues with normal pointers in C++ are as follows:
* **Memory Leaks:** This occurs when memory is repeatedly allocated by a program but never freed. This leads to excessive memory consumption and eventually leads to a system crash. 
* **Dangling Pointers:** A [dangling pointer](https://www.geeksforgeeks.org/difference-between-dangling-pointer-and-void-pointer/) is a pointer that occurs at the time when the object is de-allocated from memory without modifying the value of the pointer.
* **Wild Pointers:** Wild pointers are pointers that are declared and allocated memory but the pointer is never initialized to point to any valid object or address.
* **Data Inconsistency:** Data inconsistency occurs when some data is stored in memory but is not updated in a consistent manner.
* **Buffer Overflow:** When a pointer is used to write data to a memory address that is outside of the allocated memory block. This leads to the corruption of data which can be exploited by malicious attackers.

### Types of Smart Pointers
C++ libraries provide implementations of smart pointers in the following types:
* **auto_ptr:** An `auto_ptr` was a smart pointer class in C++ that provided basic resource management, similar to what modern smart pointers like `std::unique_ptr` do today. However, `auto_ptr` is now deprecated and has been removed from the C++11 standard onward because of several design flaws that led to unsafe behavior in certain situations.
* **unique_ptr:** `std::unique_ptr` is a smart pointer in C++ that provides **exclusive ownership** of a dynamically allocated object. This means that at any time, only one `std::unique_ptr` can own a given object, and when the `std::unique_ptr` is destroyed or goes out of scope, the object it points to is automatically deleted.
* **shared_ptr:** 
* **weak_ptr**

## Unique Pointer

A **`std::unique_ptr`** is another type of smart pointer in C++ that provides automatic memory management. Unlike `std::shared_ptr`, which allows multiple ownership of a resource, a `std::unique_ptr` is designed for **exclusive ownership** of a dynamically allocated object. This means that at any given time, only one `unique_ptr` instance can own the object, ensuring that no two `unique_ptr`s can point to the same resource.

It is part of the C++11 standard, found in the `<memory>` header, and it's a great alternative to manual memory management when you know that an object will have a single owner.

### Key Features of `std::unique_ptr`:

1. **Exclusive Ownership**:  
   A `std::unique_ptr` guarantees that there is only one owner of the object it manages. If a `unique_ptr` is destroyed, goes out of scope, or is reset, the object it manages is automatically deleted, preventing memory leaks.

2. **Non-Copyable**:  
   A unique pointer cannot be copied. This prevents more than one pointer from owning the same resource. Attempting to copy a `unique_ptr` will result in a compile-time error:
   
   ```cpp
   std::unique_ptr<int> ptr1 = std::make_unique<int>(10);
   std::unique_ptr<int> ptr2 = ptr1;  // ERROR: unique_ptr cannot be copied
   ```

3. **Move Semantics**:  
   Although a `unique_ptr` cannot be copied, it can be **moved**. This means ownership of the managed object can be transferred from one `unique_ptr` to another using C++ move semantics (via `std::move`):
   
   ```cpp
   std::unique_ptr<int> ptr1 = std::make_unique<int>(10);
   std::unique_ptr<int> ptr2 = std::move(ptr1);  // Ownership is transferred to ptr2, ptr1 becomes null
   ```

4. **Automatic Resource Management**:  
   When a `unique_ptr` goes out of scope, it automatically deletes the object it owns. This eliminates the need to manually call `delete` and reduces the chance of memory leaks.

5. **Custom Deleters**:  
   A `unique_ptr` allows the use of custom deleters. This can be useful when you need to clean up resources in a specific way (e.g., closing file handles, freeing memory from custom allocators, etc.).

6. **Lightweight and Efficient**:  
   Since `unique_ptr` does not need to manage reference counts like `shared_ptr`, it is more lightweight and offers better performance in situations where only a single owner is needed.

### Syntax and Usage:

- **Creating a `unique_ptr`**:
  The preferred way to create a `unique_ptr` is to use `std::make_unique`, which simplifies memory allocation and prevents potential errors with manual `new`:

  ```cpp
  std::unique_ptr<int> ptr = std::make_unique<int>(42);  // Creates a unique_ptr managing an int
  ```

  You can also initialize a `unique_ptr` directly:

  ```cpp
  std::unique_ptr<int> ptr(new int(42));  // Not preferred due to possible exceptions before the assignment
  ```

- **Accessing the Managed Object**:
  You can access the object pointed to by `unique_ptr` using the `*` and `->` operators:

  ```cpp
  std::cout << *ptr << std::endl;  // Dereferences the unique_ptr
  ```

- **Transferring Ownership (Move Semantics)**:
  As mentioned earlier, ownership can be transferred from one `unique_ptr` to another using `std::move`:

  ```cpp
  std::unique_ptr<int> ptr1 = std::make_unique<int>(10);
  std::unique_ptr<int> ptr2 = std::move(ptr1);  // ptr1 is now null
  ```

  After the move, `ptr1` no longer owns the object and is null. You can check this:

  ```cpp
  if (ptr1 == nullptr) {
      std::cout << "ptr1 is empty" << std::endl;
  }
  ```

- **Releasing Ownership**:
  You can release the ownership of the object without deleting it using the `release()` method. This returns the raw pointer to the object and sets the `unique_ptr` to null:

  ```cpp
  std::unique_ptr<int> ptr = std::make_unique<int>(10);
  int* rawPtr = ptr.release();  // Releases ownership, ptr is now null
  delete rawPtr;  // Manually delete the object
  ```

  Note: Once the object is released, you are responsible for manually deleting it, as the `unique_ptr` no longer manages it.

- **Resetting the `unique_ptr`**:
  You can reset a `unique_ptr`, which either deletes the currently managed object (if any) or points it to a new object:

  ```cpp
  ptr.reset(new int(20));  // Deletes the current object and manages the new one
  ptr.reset();  // Deletes the current object and makes the unique_ptr null
  ```

- **Custom Deleters**:
  You can provide a custom deleter for `unique_ptr` if you need special cleanup logic:

  ```cpp
  std::unique_ptr<FILE, decltype(&fclose)> filePtr(fopen("file.txt", "r"), fclose);
  ```

  In this case, the `unique_ptr` is managing a `FILE*` pointer and will use `fclose` as the deleter when the `unique_ptr` goes out of scope.

### Example:

Here’s a basic example of `unique_ptr` in action:

```cpp
#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() { std::cout << "MyClass created\n"; }
    ~MyClass() { std::cout << "MyClass destroyed\n"; }
    void display() { std::cout << "Hello from MyClass\n"; }
};

int main() {
    std::unique_ptr<MyClass> ptr = std::make_unique<MyClass>();  // Object created
    ptr->display();  // Access the object using the unique_ptr

    // Transferring ownership
    std::unique_ptr<MyClass> ptr2 = std::move(ptr);  // ptr now holds no object
    if (!ptr) {
        std::cout << "ptr is null\n";
    }

    // ptr2 still owns the object
    ptr2->display();

    // ptr2 goes out of scope, and the object is automatically deleted
    return 0;
}
```

### Benefits of `std::unique_ptr`:

1. **No Overhead**:  
   Unlike `shared_ptr`, `unique_ptr` has no reference counting overhead, making it more efficient when exclusive ownership is required.

2. **Memory Safety**:  
   Since it automatically deletes the managed object when it goes out of scope, `unique_ptr` helps prevent memory leaks.

3. **Move Semantics**:  
   `unique_ptr` supports move semantics, making it possible to transfer ownership without risking memory corruption or undefined behavior.

4. **Custom Deleters**:  
   It allows the use of custom deleters, making it flexible for managing resources other than just dynamically allocated memory (e.g., file handles, sockets, etc.).

### When to Use `std::unique_ptr`:

- **Single Ownership**:  
  Use `std::unique_ptr` when you know that an object will have only one owner throughout its lifetime. It's perfect for cases where an object is created, used, and then automatically destroyed without sharing ownership with other parts of the program.

- **Performance Critical Code**:  
  If you want the benefits of automatic memory management without the overhead of reference counting (as in `shared_ptr`), `unique_ptr` is an ideal choice.

- **Resource Management**:  
  It is excellent for managing resources like dynamically allocated memory, file handles, or other system resources that need deterministic destruction.

### difference between using **`std::make_unique`** and **direct initialization with `new`**

`std::make_unique` was introduced in C++14 and is the preferred way to create a `std::unique_ptr` because of the following benefits:
1. **Exception Safety**:
   - `std::make_unique` ensures that memory is allocated and the constructor is called in a single step. This eliminates the risk of memory leaks in case an exception occurs during the object's creation.
   - With direct use of `new`, if an exception is thrown between the allocation of the object and the assignment to the smart pointer, the allocated memory will not be properly cleaned up, leading to a memory leak.
   
   **Example**:
   ```cpp
   std::unique_ptr<MyClass> ptr = std::make_unique<MyClass>(constructor_args);  // Safe
   ```

   In this case, the resource allocation and pointer creation happen atomically, so exceptions are handled cleanly.

2. **Cleaner Syntax**:
   - `std::make_unique` provides a cleaner and more readable syntax compared to directly using `new`. The `std::make_unique` function deduces the type automatically, which reduces the possibility of errors and makes the code more concise.
   
   **Example**:
   ```cpp
   std::unique_ptr<int> ptr = std::make_unique<int>(10);  // Cleaner, no need for new
   ```

   Compare this to the direct `new` version:
   ```cpp
   std::unique_ptr<int> ptr(new int(10));  // More verbose
   ```

3. **Performance**:
   - `std::make_unique` can avoid some unnecessary memory allocations. When you call `new`, the allocation happens first, followed by the `unique_ptr` constructor, which may involve a second memory operation (depending on the compiler). `std::make_unique` can optimize this into a single operation, making it potentially more efficient.

4. **No Redundant Type Specification**:
   - With `std::make_unique`, you don’t need to specify the type twice, which is required when using `new`.
   
   **Example**:
   ```cpp
   std::unique_ptr<MyClass> ptr = std::make_unique<MyClass>(arg1, arg2);  // No need to repeat the type
   ```

   Whereas in direct initialization:
   ```cpp
   std::unique_ptr<MyClass> ptr(new MyClass(arg1, arg2));  // MyClass type repeated twice
   ```

**Direct Initialization with `new` (Less Preferred)**. Directly initializing a `std::unique_ptr` by passing a raw pointer (using `new`) was commonly used in C++98 and earlier, but it’s now considered **less safe** and **less efficient** for a number of reasons:
1. **Risk of Memory Leaks in Case of Exceptions**:
   - If an exception is thrown between the memory allocation (with `new`) and assigning the pointer to the `unique_ptr`, the memory will be leaked since the `unique_ptr` never takes ownership of the resource.
   
   **Example**:
   ```cpp
   std::unique_ptr<MyClass> ptr(new MyClass(arg1, arg2));  // If an exception occurs, memory could be leaked
   ```

   If an exception occurs between `new MyClass(arg1, arg2)` and the assignment to `ptr`, the allocated memory could be lost because the `unique_ptr` does not yet manage the resource.

2. **Verbose and Error-Prone**:
   - Direct initialization requires you to manually use the `new` keyword and specify the type explicitly. This is both more verbose and increases the likelihood of mistakes (like mismatched types).

   **Example**:
   ```cpp
   std::unique_ptr<MyClass> ptr(new MyClass(arg1, arg2));  // Must manually use new
   ```

3. **No Optimizations for Memory Allocation**:
   - With `new`, memory is first allocated, then the object is constructed, and then the `unique_ptr` takes ownership of it. This introduces extra steps that may not be optimized, whereas `std::make_unique` can perform optimizations in a single operation.

#### **Example of Exception Problem with `new`:**

Here’s a more detailed example showing how direct use of `new` can lead to a memory leak if an exception is thrown during object creation:

```cpp
// Bad Example: Using new directly
void createObject() {
    std::unique_ptr<int> ptr(new int(10));
    // Imagine something here throws an exception before assignment to ptr completes
    throw std::runtime_error("Exception occurred");
}
```

In this example, if the exception is thrown before `ptr` takes ownership of the resource, the memory allocated by `new int(10)` will not be freed, resulting in a **memory leak**.

In contrast, with `std::make_unique`, the exception safety is handled internally:

```cpp
// Good Example: Using std::make_unique
void createObject() {
    std::unique_ptr<int> ptr = std::make_unique<int>(10);  // Safe, no leak possible
    throw std::runtime_error("Exception occurred");
}
```

Here, even if an exception is thrown, the memory will still be safely managed by the `std::unique_ptr`, and no leak will occur.

#### Summary of Key Differences:

| **Aspect**                    | **`std::make_unique`** (Recommended) | **Direct Initialization with `new`** (Less Preferred) |
|-------------------------------|--------------------------------------|-------------------------------------------------------|
| **Exception Safety**           | Safe (prevents memory leaks in case of exceptions) | Risk of memory leaks if exception occurs before ownership is taken |
| **Syntax**                     | Cleaner and more concise            | More verbose (requires manually using `new`)           |
| **Performance**                | More efficient (fewer memory operations) | Potentially less efficient                            |
| **Type Deduction**             | Automatically deduces the type      | Requires manually specifying the type twice           |
| **Memory Management**          | Managed in one step, safer          | Two-step memory management with potential for errors  |

## Shared Pointer
A **shared pointer** is a type of smart pointer in C++ that provides automatic memory management, ensuring that dynamically allocated memory is properly deallocated when no longer needed. Shared pointers are part of the C++ Standard Library, introduced in C++11 as part of the `<memory>` header. They address common issues with manual memory management, such as memory leaks and dangling pointers.

### Key Concepts of Shared Pointer:

1. **Reference Counting**:  
   A shared pointer keeps a reference count of how many shared pointers currently point to a given resource (usually a dynamically allocated object). This reference count is maintained in a control block, which is separate from the managed object. Every time a new shared pointer is created (either via copy or assignment), the reference count is incremented. When a shared pointer is destroyed (goes out of scope or is explicitly reset), the reference count is decremented. Once the reference count drops to zero, the managed object is automatically destroyed.

2. **Control Block**:  
   The control block holds important metadata about the shared pointer, including:
   - The **reference count** (number of shared pointers managing the object).
   - The **weak count** (number of weak pointers, which I'll explain later).
   - A **pointer** to the managed object.
   The control block ensures that even when there are multiple shared pointers referring to the same object, they share the same control information.

3. **Thread Safety**:  
   The reference count in a shared pointer is typically implemented in a thread-safe way. This means that you can safely share a `std::shared_ptr` between threads without needing additional synchronization mechanisms, as the reference count updates are atomic operations.

4. **Automatic Deletion**:  
   Once the reference count reaches zero, the object is automatically deleted, freeing the allocated memory. This automatic memory management greatly reduces the chances of memory leaks.

5. **Ownership Semantics**:  
   With a shared pointer, **multiple owners** can manage a single object. Each owner holds a reference to the object, and the object will only be destroyed when the last owner releases their reference.

### Syntax and Usage:

- **Creating a shared pointer**:
  You can create a shared pointer in various ways:
  
  ```cpp
  std::shared_ptr<int> sp1 = std::make_shared<int>(10);  // Preferable way (avoids extra allocations)
  std::shared_ptr<int> sp2(new int(20));                 // Direct initialization (less efficient)
  ```

  - `std::make_shared` is preferred because it combines the allocation of the control block and the object into one step, which is more efficient.

- **Copying and Assigning**:
  When you copy or assign a `std::shared_ptr`, the reference count is incremented:

  ```cpp
  std::shared_ptr<int> sp3 = sp1;  // sp3 and sp1 now share ownership
  ```

- **Accessing the Managed Object**:
  Use the `*` or `->` operators to access the underlying object:

  ```cpp
  int value = *sp1;
  ```

- **Resetting a shared pointer**:
  You can reset a shared pointer, which will decrement the reference count and optionally assign it a new object:

  ```cpp
  sp1.reset();                     // sp1 no longer points to the object, and the object may be destroyed if no other shared_ptr is referencing it.
  sp1.reset(new int(30));           // sp1 now points to a new object.
  ```

- **Getting the raw pointer**:
  If needed, you can retrieve the raw pointer, though this is discouraged unless necessary:

  ```cpp
  int* rawPtr = sp1.get();
  ```

### Weak Pointers (`std::weak_ptr`):

A `std::weak_ptr` is a smart pointer that holds a *non-owning* reference to an object managed by a `std::shared_ptr`. This means that a `weak_ptr` does not affect the reference count. You can think of it as a way to break circular references (which can cause memory leaks) by allowing objects to be referenced without taking ownership.

- **Creating a weak pointer**:

  ```cpp
  std::shared_ptr<int> sp = std::make_shared<int>(100);
  std::weak_ptr<int> wp = sp;  // wp does not increase the reference count
  ```

- **Accessing the object**:
  Before accessing the object, you must check if the `shared_ptr` is still valid (i.e., the object hasn’t been destroyed) by converting the `weak_ptr` into a `shared_ptr` using `lock()`:

  ```cpp
  if (std::shared_ptr<int> spLock = wp.lock()) {
      // The object is still alive, and spLock is now a shared_ptr to it
      std::cout << *spLock << std::endl;
  } else {
      // The object has been destroyed
  }
  ```

### Example:

Here’s an example illustrating basic usage:

```cpp
#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() { std::cout << "MyClass created\n"; }
    ~MyClass() { std::cout << "MyClass destroyed\n"; }
};

int main() {
    std::shared_ptr<MyClass> sp1 = std::make_shared<MyClass>();  // Object created, ref count = 1
    {
        std::shared_ptr<MyClass> sp2 = sp1;  // ref count = 2
        std::cout << "Inside scope, ref count = " << sp1.use_count() << "\n";
    }  // sp2 goes out of scope, ref count = 1

    std::cout << "Outside scope, ref count = " << sp1.use_count() << "\n";
    return 0;
}  // sp1 goes out of scope, object is destroyed
```

### Circular Reference Problem:

A common issue with `std::shared_ptr` is **circular references**, where two objects reference each other through `shared_ptr`, preventing their destruction because the reference count never drops to zero. Using `std::weak_ptr` can help resolve this issue by breaking the ownership cycle.

```cpp
class B;  // Forward declaration

class A {
public:
    std::shared_ptr<B> ptrB;
    ~A() { std::cout << "A destroyed\n"; }
};

class B {
public:
    std::shared_ptr<A> ptrA;  // Creates a circular reference
    ~B() { std::cout << "B destroyed\n"; }
};
```

In this scenario, neither `A` nor `B` will be destroyed because both reference counts remain non-zero. To solve this, replace one of the `std::shared_ptr` members with a `std::weak_ptr`.

## Weak Pointer
A **`std::weak_ptr`** is a smart pointer in C++ that provides a **non-owning** or **weak reference** to an object managed by a `std::shared_ptr`. This means that a `weak_ptr` does not affect the reference count of the `shared_ptr`, but it allows you to observe or access the object if it still exists. The key use case for `std::weak_ptr` is to **break circular references** in programs that use `shared_ptr`, which can otherwise lead to memory leaks.

### Key Characteristics of `std::weak_ptr`:

1. **Non-Owning Reference**:  
   Unlike `std::shared_ptr`, a `std::weak_ptr` does not "own" the object it points to. It simply points to an object managed by a `std::shared_ptr`, without contributing to the object's reference count. This means that if all `shared_ptr` instances that own the object are destroyed, the object will be deleted even if there are `weak_ptr` instances pointing to it.

2. **Breaking Circular Dependencies**:  
   One of the main reasons to use a `weak_ptr` is to avoid circular dependencies between objects. Circular references happen when two objects hold `shared_ptr` references to each other, creating a cycle that prevents either object from being destroyed because their reference counts never reach zero. By replacing one of these `shared_ptr` instances with a `weak_ptr`, the cycle is broken.

3. **No Direct Access**:  
   A `weak_ptr` cannot directly access the object it refers to. Before using the object, you must convert the `weak_ptr` to a `shared_ptr` using the `lock()` method. This operation checks whether the object is still alive (i.e., not destroyed) and returns a `shared_ptr` if it is. If the object has already been destroyed, the `lock()` method returns an empty `shared_ptr`.

4. **Thread Safety**:  
   Like `shared_ptr`, `weak_ptr` is designed to be thread-safe. You can safely share a `weak_ptr` between threads, but care must be taken when locking or modifying shared objects.

### Common Use Cases:

1. **Avoiding Circular References**:  
   Consider two objects that reference each other using `shared_ptr`, leading to a circular dependency:
   
   ```cpp
   class A;
   class B;

   class A {
   public:
       std::shared_ptr<B> b_ptr;
       ~A() { std::cout << "A destroyed\n"; }
   };

   class B {
   public:
       std::shared_ptr<A> a_ptr;
       ~B() { std::cout << "B destroyed\n"; }
   };
   ```

   In this example, `A` holds a `shared_ptr` to `B`, and `B` holds a `shared_ptr` to `A`. When the program ends, neither `A` nor `B` will be destroyed because their reference counts will never reach zero (since each object keeps the other alive). To solve this, you can replace one of the `shared_ptr`s with a `weak_ptr`:

   ```cpp
   class A {
   public:
       std::weak_ptr<B> b_ptr;  // Weak pointer breaks the circular reference
       ~A() { std::cout << "A destroyed\n"; }
   };

   class B {
   public:
       std::shared_ptr<A> a_ptr;
       ~B() { std::cout << "B destroyed\n"; }
   };
   ```

   Now, when the `shared_ptr` to `B` is destroyed, the object `B` will be destroyed, and since `B` only holds a weak reference to `A`, `A` will also be destroyed when its reference count reaches zero.

2. **Caching and Observing Objects**:  
   `weak_ptr` is also useful when you want to cache or observe an object but don’t want to extend its lifetime. For example, if you have a cache of objects managed by `shared_ptr`, you can keep `weak_ptr` references to those objects so that they can be cleaned up when no other code is using them.

### Syntax and Usage:

- **Creating a `weak_ptr`**:
  A `weak_ptr` must be initialized from a `shared_ptr`. It cannot directly manage an object by itself.

  ```cpp
  std::shared_ptr<int> sp = std::make_shared<int>(42);
  std::weak_ptr<int> wp = sp;  // wp is now a weak pointer to the same object
  ```

- **Checking Object Validity**:
  Before accessing the object, you should check if it still exists by converting the `weak_ptr` to a `shared_ptr` using `lock()`:

  ```cpp
  if (std::shared_ptr<int> locked = wp.lock()) {
      // Object is still alive, safe to use it
      std::cout << *locked << std::endl;
  } else {
      // Object has been destroyed
      std::cout << "Object no longer exists\n";
  }
  ```

  The `lock()` method returns a `shared_ptr` that either points to the object (if it is still valid) or is empty (if the object has been destroyed). This pattern helps avoid dereferencing a pointer to a destroyed object, which would otherwise lead to undefined behavior.

- **Resetting a `weak_ptr`**:
  You can reset a `weak_ptr` to make it stop pointing to any object:

  ```cpp
  wp.reset();  // Now wp no longer points to any object
  ```

- **Getting the Raw Pointer**:
  If needed, you can check the raw pointer using the `expired()` method or `lock()`:

  ```cpp
  if (wp.expired()) {
      std::cout << "The object has already been destroyed\n";
  }
  ```

  `expired()` returns `true` if the object has been destroyed (i.e., the reference count in the associated `shared_ptr` is zero).

### Example:

Here’s an example demonstrating how `std::weak_ptr` is used to break a circular reference:

```cpp
#include <iostream>
#include <memory>

class B;  // Forward declaration of B

class A {
public:
    std::shared_ptr<B> b_ptr;
    ~A() { std::cout << "A destroyed\n"; }
};

class B {
public:
    std::weak_ptr<A> a_ptr;  // weak_ptr breaks the circular reference
    ~B() { std::cout << "B destroyed\n"; }
};

int main() {
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();

    a->b_ptr = b;  // A holds shared ownership of B
    b->a_ptr = a;  // B holds a weak reference to A

    // When main ends, both objects will be correctly destroyed.
    return 0;
}
```

### How `std::weak_ptr` Solves the Circular Reference Problem:

In the example above, class `A` holds a `shared_ptr` to `B`, but class `B` holds a `weak_ptr` to `A`. This weak reference prevents the circular reference problem because `weak_ptr` does not increase the reference count of `A`. When `main` ends, `a` and `b` go out of scope, and their reference counts drop to zero. First, `b` is destroyed, and since `b` has only a weak reference to `a`, `a` can be destroyed as well.

### Benefits of `std::weak_ptr`:

1. **Breaking Circular References**:  
   The primary advantage of `weak_ptr` is its ability to break reference cycles in programs that use `shared_ptr`, which prevents memory leaks.

2. **Efficient Memory Management**:  
   By allowing non-owning references, `weak_ptr` lets you observe or cache objects without extending their lifetime unnecessarily.

3. **Safe Access**:  
   `weak_ptr` ensures that you can only access the object if it still exists by using the `lock()` function, avoiding potential issues like dereferencing a dangling pointer.

## Smart Pointers Comparison

| **Smart Pointer** | **Description** | **Usage Scenario** | **Ownership** | **Thread-Safety** |
|-------------------|-----------------|--------------------|---------------|-------------------|
| **`std::unique_ptr`** | Exclusive ownership of a resource, no other smart pointer can own the resource. | Use when you need sole ownership of an object. Ideal for dynamic memory management where transfer of ownership is needed. | Single owner at any time. Ownership can be transferred using `std::move`. | Not inherently thread-safe. Only one thread should access the `unique_ptr` at a time. |
| **`std::shared_ptr`** | Shared ownership of a resource. Multiple smart pointers can point to the same resource. Reference counting is used to track ownership. | Use when multiple parts of the program need to share ownership of an object. Automatically deallocates when the last reference is destroyed. | Multiple owners. Deallocated when all `shared_ptr` instances pointing to the resource are destroyed. | Reference counting is thread-safe, but modifying the underlying object requires additional synchronization. |
| **`std::weak_ptr`** | A weak reference to an object managed by `std::shared_ptr`. Does not participate in reference counting. | Use to avoid circular references in `std::shared_ptr` ownership chains (e.g., in observer patterns). It allows access to an object without owning it. | No ownership. It references but does not manage the lifetime of the resource. | Not thread-safe by itself. Accessing the underlying object via `lock()` must be handled carefully in multithreaded contexts. |
| **`std::auto_ptr`** (deprecated) | Provides exclusive ownership but has unsafe copy semantics (ownership transfers on copy). Deprecated since C++11 in favor of `std::unique_ptr`. | Avoid using, as it is deprecated. Use `std::unique_ptr` instead for exclusive ownership. | Single owner. Ownership transfers on copy. | Not thread-safe and should be avoided. |

### Key Points:
- **`std::unique_ptr`** is best for sole ownership and efficient resource management without reference counting overhead.
- **`std::shared_ptr`** is appropriate for shared ownership, but it comes with the cost of reference counting.
- **`std::weak_ptr`** is useful to prevent circular dependencies that could occur with `shared_ptr`.
