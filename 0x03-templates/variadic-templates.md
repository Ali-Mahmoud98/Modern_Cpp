# Variadic Templates
Variadic templates are class or function templates, that can take any variable(zero or more) number of arguments. In C++, templates can have a fixed number of parameters only that have to be specified at the time of declaration. However, variadic templates help to overcome this issue. Douglas Gregor and Jaakko Järvi came up with this feature for C++.

Variadic arguments are very similar to [arrays](https://www.geeksforgeeks.org/c-arrays/) in C++. We can easily iterate through the arguments, find the size(length) of the template, can access the values by an index, and can slice the templates too. 

So basically, Variadic function templates are functions that can take multiple numbers of arguments.

Syntax:
```c++
template(typename arg, typename... args)
return_type function_name(arg var1, args... var2)
```

An example from GFG:
```c++
// C++ program to demonstrate working of
// Variadic function Template
#include <iostream>
using namespace std;

// To handle base case of below recursive
// Variadic function Template
void print()
{
	cout << "I am empty function and "
			"I am called at last.\n";
}

// Variadic function Template that takes
// variable number of arguments and prints
// all of them.
template <typename T, typename... Types>
void print(T var1, Types... var2)
{
	cout << var1 << endl;

	print(var2...);
}

// Driver code
int main()
{
	print(1, 2, 3.14,
		"Pass me any "
		"number of arguments",
		"I will print\n");

	return 0;
}
```

Variadic templates in C++ are a powerful feature that allows functions or classes to accept a variable number of arguments. This makes them incredibly versatile and useful in a variety of situations where the number of arguments is not known at compile-time or can vary. Here are some common **use cases** for variadic templates:

### 1. **Creating Flexible Print Functions (Logging or Debugging)**
   Variadic templates are often used to implement custom print functions that can handle an arbitrary number of arguments of different types, similar to `printf()` in C. This is useful for debugging, logging, and creating flexible output functions.
   
   **Example:**
   ```cpp
   template <typename T>
   void print(T t) {
       std::cout << t << std::endl;
   }

   template <typename T, typename... Args>
   void print(T first, Args... args) {
       std::cout << first << " ";
       print(args...);
   }

   int main() {
       print(1, 2.5, "Hello", 'A');
   }
   ```
   **Use Case:** Logging frameworks often require logging multiple types and formats of data. Variadic templates simplify this.

### 2. **Forwarding Arguments (Perfect Forwarding)**
   Variadic templates are used in combination with `std::forward` to create **perfect forwarding** functions. This is useful when writing wrapper functions that need to forward a variable number of arguments to another function while preserving the value categories of the arguments (i.e., whether they are lvalues or rvalues).
   
   **Example:**
   ```cpp
   template<typename F, typename... Args>
   void callFunction(F&& f, Args&&... args) {
       std::forward<F>(f)(std::forward<Args>(args)...);
   }

   int main() {
       auto lambda = [](int a, double b) { std::cout << a << " " << b << std::endl; };
       callFunction(lambda, 42, 3.14);  // Pass multiple arguments to lambda
   }
   ```
   **Use Case:** Wrappers around functions or constructors, like in **factory patterns** or **decorators**, where arguments need to be perfectly forwarded.

### 3. **Parameter Pack Unpacking (Building Containers)**
   Variadic templates are useful for building data structures like containers where the number of elements is not known in advance. For example, creating a `std::tuple` or initializing an `std::vector` with a variable number of arguments.

   **Example:**
   ```cpp
   template<typename... Args>
   auto createTuple(Args... args) {
       return std::make_tuple(args...);
   }

   int main() {
       auto myTuple = createTuple(1, 2.5, "Hello");
       std::cout << std::get<2>(myTuple);  // Output: Hello
   }
   ```
   **Use Case:** `std::tuple` and `std::variant` in the Standard Library are implemented using variadic templates to handle multiple types.

### 4. **Recursive Algorithms**
   Variadic templates can be used to implement recursive algorithms that need to process a variable number of arguments. This is useful in operations like **accumulation** or **folding** over a list of arguments.
   
   **Example:**
   ```cpp
   template<typename T>
   T sum(T t) {
       return t;
   }

   template<typename T, typename... Args>
   T sum(T first, Args... args) {
       return first + sum(args...);
   }

   int main() {
       std::cout << sum(1, 2, 3, 4, 5);  // Output: 15
   }
   ```
   **Use Case:** Reductions and folds (e.g., summing or accumulating a sequence of values).

### 5. **Template Metaprogramming**
   Variadic templates allow template metaprogramming techniques that operate on a list of types, such as checking if all types satisfy a certain property (e.g., if they are all integral types).

   **Example:**
   ```cpp
   template<typename T>
   constexpr bool is_integral_type() {
       return std::is_integral<T>::value;
   }

   template<typename T, typename... Args>
   constexpr bool are_all_integral() {
       return is_integral_type<T>() && (is_integral_type<Args>() && ...);
   }

   int main() {
       static_assert(are_all_integral<int, long, short>(), "Not all are integral types");
   }
   ```
   **Use Case:** Compile-time type checking, constraints, and optimizations, such as in **SFINAE** or **concepts**.

### 6. **Factory or Builder Pattern**
   Variadic templates are extremely useful for implementing the **factory pattern** or **builder pattern** where different numbers of arguments can be used to construct objects. This avoids having to overload multiple constructor signatures.

   **Example:**
   ```cpp
   template <typename T, typename... Args>
   std::unique_ptr<T> createObject(Args&&... args) {
       return std::make_unique<T>(std::forward<Args>(args)...);
   }

   class MyClass {
   public:
       MyClass(int a, double b) {
           std::cout << "MyClass created with " << a << " and " << b << std::endl;
       }
   };

   int main() {
       auto obj = createObject<MyClass>(42, 3.14);
   }
   ```
   **Use Case:** Factory methods where constructors can have different argument counts and types.

### 7. **Custom Memory Management**
   Variadic templates are useful when you want to write a **memory allocator** or **custom memory manager** that needs to allocate and initialize objects with different types of arguments.

   **Example:**
   ```cpp
   template<typename T, typename... Args>
   T* allocateAndConstruct(Args&&... args) {
       T* memory = static_cast<T*>(operator new(sizeof(T)));
       new (memory) T(std::forward<Args>(args)...);
       return memory;
   }

   int main() {
       int* p = allocateAndConstruct<int>(42);
       std::cout << *p << std::endl;  // Output: 42
       delete p;
   }
   ```
   **Use Case:** Implementing custom memory allocators and placement new operations in low-level systems programming.

### 8. **Event Handling or Delegation**
   Variadic templates are used in event systems where different types and numbers of arguments need to be passed to event handlers or delegates.

   **Example:**
   ```cpp
   template<typename... Args>
   void handleEvent(Args... args) {
       // Handle events with varying arguments
   }

   int main() {
       handleEvent(1, 2.5, "An event");
   }
   ```
   **Use Case:** Implementing callback systems or event-driven architectures where handlers receive a flexible number of parameters.

---

### 9. Summary of Use Cases:
- **Logging, Debugging, and Printing** (flexible output functions)
- **Perfect Forwarding** (argument forwarding with `std::forward`)
- **Container Construction** (building `std::tuple`, `std::vector`, etc.)
- **Recursive Algorithms** (e.g., summing or reducing)
- **Template Metaprogramming** (compile-time checks)
- **Factory or Builder Pattern** (dynamic object creation with multiple arguments)
- **Custom Memory Management** (custom allocators)
- **Event Handling** (flexible event systems)

Variadic templates allow for more concise, flexible, and efficient code in cases where the number of arguments or types is variable. They help avoid code duplication and make C++ programs more generic and reusable.
