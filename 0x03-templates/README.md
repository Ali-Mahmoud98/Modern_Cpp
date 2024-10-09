# C++ Templates

## Contents:
* [1. Introduction to Templates](#1-introduction-to-templates)
    * [1.1 Full Specialization](#11-full-specialization)
        * [1.1.1 Example](#111-example)
        * [1.1.2 Explanation](#112-explanation)
        * [1.1.3 How It Works](#113-how-it-works)
    * [1.2 Partial Specialization](#12-partial-specialization)
        * [1.2.1 Example](#121-example)
        * [1.2.2 Explanation](#122-explanation)
        * [1.2.3 How It Works](#123-how-it-works)
    * [1.3 Function Template Specialization](#13-function-template-specialization)
        * [1.3.1 Example](#131-example)
        * [1.3.2 Explanation](#132-explanation)
    * [1.4 Summary of Template Specialization](#14-summary-of-template-specialization)
    * [1.5 Advantages of Specialization](#15-advantages-of-specialization)
* [2. Function Templates](#2-function-templates)
    * [2.1 Key Concepts](#21-key-concepts)
    * [2.2 Why Use Function Templates](#22-why-use-function-templates)
    * [2.3 Explaining multiply Function in Details](#23-explaining-multiply-function-in-details)
        * [2.3.1 Template Declaration](#231-template-declaration)
        * [2.3.2 Function Signature](#232-function-signature)
        * [2.3.3 Why Use decltype(a * b)](#233-why-use-decltypea--b)
        * [2.3.4 Function Body](#234-function-body)
        * [2.3.5 Example 1: Multiplying int and double](#235-example-1-multiplying-int-and-double)
        * [2.3.6 Example 2: Multiplying two ints](#235-example-1-multiplying-int-and-double)
        * [2.3.7 Example 3: Multiplying float and double](#236-example-2-multiplying-two-ints)
        * [2.3.8 Advantages of This Template](#237-example-3-multiplying-float-and-double)
* [3. Class Templates](#3-class-templates)
    * [3.1 Key Concepts of Class Templates](#31-key-concepts-of-class-templates)
    * [3.2 Example of a Class Template in Action](#32-example-of-a-class-template-in-action)
    * [3.3 Explanation](#33-explanation)
    * [3.4 Advantages of Class Templates](#34-advantages-of-class-templates)
* [4. Template Specialization](#4-template-specialization)
* [5. Separating Template Declaration and Definition in C++](#5-separating-template-declaration-and-definition-in-c)
    * [5.1 Solution 1: Define Everything in the Header File Example](#51-solution-1-define-everything-in-the-header-file-example)
    * [5.2 Solution 2: Explicit Template Instantiation (Advanced Example)](#52-solution-2-explicit-template-instantiation-advanced-example)

<br>

Another Topics:
* [Non-Type Template Parameters](./non-type-template-params.md)
* [Variadic Templates](./variadic-templates.md)

### 1. Introduction to Templates
Templates are the basis for generic programming in C++. As a **strongly-typed language**, C++ requires **all variables to have a specific type**, either **explicitly declared by the programmer or deduced by the compiler**. However, many data structures and algorithms look the same no matter what type they are operating on. Templates enable you to define the operations of a class or function, and let the user specify what concrete types those operations should work on.

A template is a simple yet very powerful tool in C++. The simple idea is to pass the data type as a parameter so that we don’t need to write the same code for different data types. For example, a software company may need to `sort()` for different data types. Rather than writing and maintaining multiple codes, we can write one `sort()` and pass the datatype as a parameter. 

C++ adds two new keywords to support templates: `template` and `typename`. The second keyword can always be replaced by the keyword `class`.

**Templates are expanded at compiler time**. This is like macros. The difference is, that the compiler does type-checking before template expansion. The idea is simple, source code contains only function/class, but compiled code may contain multiple copies of the same function/class. 

A template is a construct that generates an ordinary type or function at compile time based on arguments the user supplies for the template parameters.


### 2. Function Templates
Function templates in C++ are a powerful feature that allows you to create generic functions that work with any data type. Instead of writing separate functions for each data type (e.g., `int`, `float`, `double`), you can write a single function template that can be used for multiple types, reducing code duplication and improving maintainability.

#### 2.1. Key Concepts:
1. **Template Declaration**: A function template is declared using the `template` keyword followed by a parameter list in angle brackets (`<>`). This parameter list typically contains one or more type parameters (commonly named `T`, but it can be any valid identifier).
   
   Example:
   ```cpp
   template <typename T>
   T add(T a, T b) {
       return a + b;
   }
   ```

   Here, `T` is a placeholder for any data type. When you call the `add` function, the compiler automatically determines the type based on the arguments.

2. **Type Deduction**: The compiler automatically deduces the type of the template parameter based on the types of the arguments passed to the function.

   Example usage:
   ```cpp
   int x = add(5, 10);         // T is deduced as int
   double y = add(2.5, 3.7);   // T is deduced as double
   ```

3. **Explicit Type Specification**: If needed, you can explicitly specify the type when calling the template function.
   
   Example:
   ```cpp
   int result = add<int>(5, 10);  // explicitly specifying T as int
   ```

4. **Multiple Template Parameters**: You can also define function templates with multiple type parameters.

   Example:
   ```cpp
   template <typename T, typename U>
   auto multiply(T a, U b) -> decltype(a * b) {
       return a * b;
   }
   ```

   In this case, the function takes two arguments of different types (`T` and `U`), and `decltype` is used to deduce the return type based on the multiplication of `a` and `b`.

   **NOTE:** If you removed `decltype(a * b)`, you'd have to specify the return type explicitly.

5. **Template Specialization**: In some cases, you may want to provide a specialized implementation of a template for a specific type. This is called **template specialization**.

   Example:
   ```cpp
   template <>
   std::string add<std::string>(std::string a, std::string b) {
       return a + " " + b;
   }
   ```

   Here, we specialize the `add` function for `std::string` to concatenate strings with a space in between.

#### 2.2. Why Use Function Templates?
- **Code Reusability**: Function templates allow you to write a single function that works with any data type.
- **Type Safety**: The compiler checks that the operations within the template are valid for the types used when the function is instantiated.
- **Flexibility**: You can write more generic code that works with custom types and built-in types alike.

In summary, function templates are a cornerstone of generic programming in C++, providing both flexibility and efficiency in handling multiple data types with a single piece of code.

#### 2.3. Explaining multiply function in details
The function is:
```bash
template <typename T, typename U>
auto multiply(T a, U b) -> decltype(a * b) {
    return a * b;
}
```
Sure! Let's break down the `multiply` function template you provided and explain each part in detail:

##### 2.3.1. **Template Declaration**:
```cpp
template <typename T, typename U>
```
- The `template` keyword declares that this is a function template.
- `<typename T, typename U>` defines two template type parameters, `T` and `U`. These placeholders can represent any data type (like `int`, `float`, or even user-defined types like classes).
- The function template is designed to accept arguments of **two potentially different types** (`T` and `U`). For example, you might call it with an `int` and a `double`, or two `int`s, or any other combination of types.

##### 2.3.2. **Function Signature**:
```cpp
auto multiply(T a, U b) -> decltype(a * b)
```
- **`auto`**: The use of `auto` here indicates that the return type will be deduced by the compiler. However, unlike simple type deduction, here it's followed by a **trailing return type** (`-> decltype(...)`), which we'll explain next.
  
- **`decltype(a * b)`**: 
  - `decltype` is a C++ feature that determines the type of an expression at compile-time. In this case, `decltype(a * b)` tells the compiler to deduce the return type of the function based on the result of multiplying `a` and `b`.
  - So, if you multiply an `int` and a `double`, `decltype(a * b)` will result in `double`, because the result of multiplying an `int` and a `double` is a `double`.
  - This ensures that the return type is correctly deduced based on the types of `a` and `b`, allowing for flexibility in handling different types (like `float`, `int`, `double`, etc.).

##### 2.3.3. Why Use `decltype(a * b)`?
Using `decltype(a * b)` allows the function to automatically adapt to the types of its arguments and return the correct type. If `a` is an `int` and `b` is a `double`, the result of `a * b` is a `double`, and the function will return a `double`. If both are `int`, it returns an `int`, and so on. This provides flexibility, as the function doesn't need to explicitly define the return type — it is deduced automatically.

##### 2.3.4. **Function Body**:
```cpp
return a * b;
```
- This is a straightforward return statement that returns the result of multiplying `a` and `b`.
- The type of the result is determined at runtime based on the types of `a` and `b`. Thanks to `decltype`, the compiler already knows what type this result will be.


#### 2.3.5. Example 1: Multiplying `int` and `double`
```cpp
int x = 4;
double y = 3.5;
auto result = multiply(x, y);
```
- Here, `x` is an `int` and `y` is a `double`. The expression `x * y` yields a `double` result. The function will return a `double` in this case.
- `decltype(x * y)` evaluates to `double`, so the return type of `multiply(x, y)` is `double`.

#### 2.3.6. Example 2: Multiplying Two `int`s
```cpp
int a = 10;
int b = 5;
auto result = multiply(a, b);
```
- Both `a` and `b` are `int`, so the result of `a * b` is also an `int`.
- `decltype(a * b)` evaluates to `int`, and the function returns an `int`.

#### 2.3.7. Example 3: Multiplying `float` and `double`
```cpp
float p = 2.5f;
double q = 4.7;
auto result = multiply(p, q);
```
- Here, `p` is a `float` and `q` is a `double`. The result of `p * q` will be a `double` (since multiplying a `float` by a `double` results in a `double`).
- `decltype(p * q)` evaluates to `double`, and the function returns a `double`.

#### 2.3.8. Advantages of This Template:
1. **Generic**: It works with any types (`int`, `float`, `double`, etc.), as long as they support the `*` operator.
2. **Type Safety**: The compiler ensures that the multiplication is valid for the given types. For example, trying to multiply incompatible types (like a `std::string` and an `int`) would result in a compile-time error.
3. **Flexibility**: The use of `decltype` ensures that the function can return the correct type based on the operation. This is especially useful when working with mixed types (e.g., multiplying `int` and `double`).
4. **Modern C++**: This leverages modern C++ features like `auto` and `decltype`, which reduce boilerplate code and enhance code readability.

### 3. Class Templates
A **class template** in C++ allows you to create generic classes that work with any data type. Like function templates, class templates make it possible to write code that can operate on various types without duplicating code for each specific type. Instead of writing separate classes for different data types (e.g., `int`, `float`, `double`), you can write a single class template that can handle them all, improving code reusability and maintainability.

#### 3.1. Key Concepts of Class Templates

1. **Template Declaration**: A class template is declared using the `template` keyword followed by a list of template parameters in angle brackets (`<>`). These parameters are typically types (e.g., `typename T`), but they can also be non-type parameters (like integers).

   Example:
   ```cpp
   template <typename T>
   class Box {
       T value;
   public:
       Box(T v) : value(v) {}
       T getValue() { return value; }
   };
   ```

   In this example:
   - `template <typename T>` declares that `T` is a placeholder for any data type.
   - The `Box` class now works for any type `T`, such as `int`, `double`, `std::string`, or custom types.
   - The member function `getValue()` returns the value stored in the `Box`.

2. **Instantiating a Class Template**: When you use a class template, you need to **instantiate** it by providing a specific type for `T`.

   Example instantiations:
   ```cpp
   Box<int> intBox(42);          // T is int
   Box<double> doubleBox(3.14);  // T is double
   Box<std::string> strBox("Hello!"); // T is std::string
   ```

   Each of these instances will use the same `Box` template, but the type `T` will be substituted with `int`, `double`, or `std::string`, respectively.

3. **Member Functions**: Member functions of the template class can use the template parameter `T` in their return types, arguments, and inside the function body.

   Example:
   ```cpp
   template <typename T>
   class Box {
       T value;
   public:
       Box(T v) : value(v) {}      // Constructor accepts type T
       T getValue() { return value; }  // Function returns type T
       void setValue(T v) { value = v; }  // Function accepts type T
   };
   ```

   This class allows you to store, retrieve, and modify values of any type `T`.

4. **Multiple Template Parameters**: You can define class templates with multiple template parameters.

   Example:
   ```cpp
   template <typename T, typename U>
   class Pair {
       T first;
       U second;
   public:
       Pair(T f, U s) : first(f), second(s) {}
       T getFirst() { return first; }
       U getSecond() { return second; }
   };
   ```

   - Here, `Pair` is a class template that accepts two different types, `T` and `U`.
   - It can be instantiated with different types for `T` and `U`:
     ```cpp
     Pair<int, double> p1(42, 3.14);  // T = int, U = double
     Pair<std::string, int> p2("Age", 30);  // T = std::string, U = int
     ```

5. **Specialization**: Like function templates, class templates can also be **specialized** for specific types. This is useful when you need a custom implementation for certain types.

   Example:
   ```cpp
   template <typename T>
   class Box {
       T value;
   public:
       Box(T v) : value(v) {}
       T getValue() { return value; }
   };

   // Specialization for type char
   template <>
   class Box<char> {
       char value;
   public:
       Box(char v) : value(v) {}
       char getValue() { return toupper(value); }  // Special behavior for char
   };
   ```

   - In this case, we’ve specialized the `Box` template for `char` type. Instead of simply returning the value, it converts it to uppercase using `toupper()`.

6. **Default Template Arguments**: You can also provide default values for template parameters.

   Example:
   ```cpp
   template <typename T = int>
   class Box {
       T value;
   public:
       Box(T v) : value(v) {}
       T getValue() { return value; }
   };
   ```

   - Here, the default type for `T` is `int`. So, if you instantiate `Box` without specifying a type, it will use `int`:
     ```cpp
     Box<> defaultBox(42);  // T is int by default
     ```

#### 3.2. Example of a Class Template in Action:

Here’s a more complete example of how a class template might be used:

```cpp
#include <iostream>
#include <string>

// Template for a generic Box
template <typename T>
class Box {
    T value;
public:
    Box(T v) : value(v) {}
    
    void setValue(T v) {
        value = v;
    }

    T getValue() const {
        return value;
    }

    void print() const {
        std::cout << "Box contains: " << value << std::endl;
    }
};

int main() {
    Box<int> intBox(42);
    intBox.print();  // Output: Box contains: 42

    Box<double> doubleBox(3.14159);
    doubleBox.print();  // Output: Box contains: 3.14159

    Box<std::string> strBox("Hello, world!");
    strBox.print();  // Output: Box contains: Hello, world!

    return 0;
}
```

#### 3.3. Explanation:
- We define a generic class `Box` that can hold a value of any type `T`.
- The class has a constructor, a setter method (`setValue()`), a getter method (`getValue()`), and a method to print the value (`print()`).
- In the `main()` function, we create `Box` objects of different types (`int`, `double`, `std::string`) and call their `print()` method to display their contents.

#### 3.4. Advantages of Class Templates:
1. **Code Reusability**: Class templates let you write one generic class that can work with multiple types. This reduces code duplication and simplifies maintenance.
2. **Type Safety**: The compiler ensures that the operations within the class are valid for the types used. For example, you cannot call an operation on a type that doesn’t support it (like adding two `std::string` objects as if they were numbers).
3. **Flexibility**: You can handle different data types without rewriting the class for each one.
4. **Efficiency**: Since the class is instantiated at compile-time for each type, there is no overhead associated with templates at runtime.

### 4. Template specialization

**Template specialization** in C++ allows you to provide a custom implementation of a template for specific types or conditions. This feature is particularly useful when a general template needs to behave differently for a specific type or set of types. C++ offers two forms of specialization:

1. **Full Specialization**: Specializing a template for a particular type.
2. **Partial Specialization**: Specializing a template for a subset of types or for specific template parameters. (Note: This applies only to class templates, as function templates do not support partial specialization.)

Let’s explore both types of specialization in detail.

---

#### 1.1. **Full Specialization**

Full specialization means that you are providing a completely different implementation of a template for a specific type.

##### 1.1.1. Example:

Consider a template class `Box` that stores a value of any type `T`. For most types, the default implementation is used, but you want to provide a special behavior when the type is `char`.

```cpp
#include <iostream>
#include <cctype> // for toupper

// General template
template <typename T>
class Box {
    T value;
public:
    Box(T v) : value(v) {}
    T getValue() { return value; }
    void print() { std::cout << "Box contains: " << value << std::endl; }
};

// Full specialization for char
template <>
class Box<char> {
    char value;
public:
    Box(char v) : value(v) {}
    char getValue() { return toupper(value); } // Special behavior for char
    void print() { std::cout << "Box contains (uppercase): " << getValue() << std::endl; }
};

int main() {
    Box<int> intBox(42);
    intBox.print(); // Box contains: 42

    Box<char> charBox('a'); // Uses the specialized version for char
    charBox.print(); // Box contains (uppercase): A

    return 0;
}
```

##### 1.1.2. Explanation:
- **General Template**: The generic `Box<T>` class works for any type `T` and simply stores a value and prints it.
- **Specialized Template for `char`**: The template specialization for `char` provides a custom implementation. Instead of printing the value directly, it converts the character to uppercase using `toupper()` before printing.
  
##### 1.1.3. How It Works:
- When you instantiate `Box<int>`, the general template is used.
- When you instantiate `Box<char>`, the specialized version for `char` is used.

---

#### 1.2. **Partial Specialization**

Partial specialization is allowed only for **class templates**, and it lets you specialize a template based on part of its template parameters. This is useful when you want to handle specific combinations of types differently.

##### 1.2.1. Example:

Let’s create a `Pair` class that holds two values of types `T1` and `T2`. We can partially specialize the class when both `T1` and `T2` are of the same type.

```cpp
#include <iostream>

// General template
template <typename T1, typename T2>
class Pair {
    T1 first;
    T2 second;
public:
    Pair(T1 f, T2 s) : first(f), second(s) {}
    void print() {
        std::cout << "Pair: " << first << ", " << second << std::endl;
    }
};

// Partial specialization when both T1 and T2 are the same
template <typename T>
class Pair<T, T> {  // Special case when both template parameters are the same type
    T first;
    T second;
public:
    Pair(T f, T s) : first(f), second(s) {}
    void print() {
        std::cout << "Pair (same type): " << first << ", " << second << std::endl;
    }
};

int main() {
    Pair<int, double> p1(42, 3.14);  // General template
    p1.print(); // Output: Pair: 42, 3.14

    Pair<int, int> p2(10, 20);       // Partial specialization for same types
    p2.print(); // Output: Pair (same type): 10, 20

    return 0;
}
```

##### 1.2.2. Explanation:
- **General Template**: `Pair<T1, T2>` is a generic class that can hold values of different types `T1` and `T2`. 
- **Partial Specialization for Same Types**: The partial specialization `Pair<T, T>` applies when both `T1` and `T2` are of the same type (`T`). In this case, we can define a custom behavior or optimizations specific to this scenario (e.g., a different print method).
  
##### 1.2.3. How It Works:
- When you create `Pair<int, double>`, the general template is instantiated because `T1` and `T2` are different types.
- When you create `Pair<int, int>`, the partial specialization is instantiated because both template parameters are of the same type.

---

#### 1.3. **Function Template Specialization**

While function templates do not support **partial specialization**, you can fully specialize a function template for a specific type.

##### 1.3.1. Example:

Consider a function template `max()` that finds the maximum of two values. You want to provide a specialized version for `const char*` (C-style strings) to perform string comparison instead of pointer comparison.

```cpp
#include <iostream>
#include <cstring>  // For strcmp

// General template
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

// Full specialization for const char*
template <>
const char* max<const char*>(const char* a, const char* b) {
    return (strcmp(a, b) > 0) ? a : b;
}

int main() {
    std::cout << max(10, 20) << std::endl;          // Uses general template: Output: 20
    std::cout << max(3.14, 2.71) << std::endl;      // Uses general template: Output: 3.14
    std::cout << max("apple", "banana") << std::endl;  // Uses specialized version for const char*: Output: banana

    return 0;
}
```

##### 1.3.2. Explanation:
- **General Template**: The generic `max()` function works for any type where the `>` operator is defined.
- **Specialization for `const char*`**: C-style strings need a different comparison logic (using `strcmp`), so we specialize the `max()` function for `const char*`. This specialized version compares strings lexicographically instead of comparing the pointers.

---

#### 1.4. Summary of Template Specialization:
1. **Full Specialization**: 
   - Provides a completely different implementation of a template for a specific type.
   - Applicable to both **function** and **class** templates.
   - Use cases: Handling special types (like `char` or `const char*`) that require different behavior.

2. **Partial Specialization**: 
   - Allows specialization of a template for specific combinations of template parameters.
   - Only available for **class templates**, not function templates.
   - Use cases: Providing custom behavior when multiple template parameters meet certain conditions (like both being the same type).

3. **Function Template Specialization**: 
   - You can fully specialize a function template for specific types, but partial specialization is not supported.
   - Use cases: Implementing different logic for certain types (like handling `const char*` differently from other types).

#### 1.5. Advantages of Specialization:
- **Custom Behavior**: Specialization allows you to customize how templates work for specific types or combinations of types.
- **Efficiency**: In some cases, you may need optimized or specialized behavior for particular types (e.g., handling arrays, pointers, or strings differently).
- **Flexibility**: By leveraging specialization, you can make your templates more versatile without sacrificing performance or correctness for specific cases.

Template specialization is a powerful tool for tailoring generic code to meet the needs of specific types or conditions, making C++ templates both flexible and efficient.

### 5. Separating Template Declaration and Definition in C++
When you want to use templates in C++ with separate files (`example.h` for declarations and `example.cpp` for definitions), you need to be mindful of the way templates are handled by the compiler. Unlike non-template classes and functions, **template definitions cannot be compiled separately**. Instead, both the declaration and the definition of templates must be available to the compiler at the point of instantiation.

<br>

**Problem with Templates in Separate Files:**

**Templates are a compile-time feature**, and the **compiler needs access to the full template definition** to generate the code for each instantiation. If you define a template function or class in a `.cpp` file, it won’t be available during template instantiation in another file (such as `main.cpp`), **leading to linker errors**.


**Two Common Solutions:**
* Inline the template definition in the header file. This is the most common and simple approach when working with templates. You place both the declaration and definition in the header file
* Use an explicit instantiation in the `.cpp` file. 

#### 5.1. Solution 1: Define Everything in the Header File Example
example.h:
```c++
// example.h
#ifndef EXAMPLE_H
#define EXAMPLE_H

// Template class definition
template <typename T>
class Example {
private:
    T value;
public:
    Example(T v);         // Constructor declaration
    void printValue();     // Method declaration
};

// Constructor definition (inline)
template <typename T>
Example<T>::Example(T v) : value(v) {}

// Method definition (inline)
template <typename T>
void Example<T>::printValue() {
    std::cout << "Value: " << value << std::endl;
}

// Template function declaration and definition in the header
template <typename T>
T add(T a, T b) {
    return a + b;
}

#endif // EXAMPLE_H
```
main.cpp (File that uses the template):
```c++
// main.cpp
#include <iostream>
#include "example.h"  // Include the header file with the template

int main() {
    Example<int> exampleInt(42);
    exampleInt.printValue();  // Output: Value: 42

    Example<double> exampleDouble(3.14);
    exampleDouble.printValue();  // Output: Value: 3.14

    int result1 = add(10, 20);  // Calls add<int>
    double result2 = add(3.14, 2.71);  // Calls add<double>

    std::cout << "Result1: " << result1 << std::endl;  // Output: Result1: 30
    std::cout << "Result2: " << result2 << std::endl;  // Output: Result2: 5.85

    return 0;
}
```

#### 5.2. Solution 2: Explicit Template Instantiation (Advanced) Example
example.h:
```c++
// example.h
#ifndef EXAMPLE_H
#define EXAMPLE_H

template <typename T>
class Example {
private:
    T value;
public:
    Example(T v);         // Constructor declaration
    void printValue();     // Method declaration
};

// Template function declaration
template <typename T>
T add(T a, T b);

#endif // EXAMPLE_H
```
example.cpp:
```cpp
// example.cpp
#include <iostream>
#include "example.h"

// Constructor definition
template <typename T>
Example<T>::Example(T v) : value(v) {}

// Method definition
template <typename T>
void Example<T>::printValue() {
    std::cout << "Value: " << value << std::endl;
}

// Explicit instantiation of the template for specific types
template class Example<int>;
template class Example<double>;

// Template function definition
template <typename T>
T add(T a, T b) {
    return a + b;
}

// Explicit instantiation of the function template for specific types
template int add<int>(int a, int b);          // Instantiate add for int
template double add<double>(double a, double b);  // Instantiate add for double
```
main.cpp:
```cpp
// main.cpp
#include <iostream>
#include "example.h"  // Include the header file with the function template declaration

int main() {
    Example<int> exampleInt(42);
    exampleInt.printValue();  // Output: Value: 42

    Example<double> exampleDouble(3.14);
    exampleDouble.printValue();  // Output: Value: 3.14
    ///////////////////////////////////////////////////
    int result1 = add(10, 20);  // Calls add<int>
    double result2 = add(3.14, 2.71);  // Calls add<double>

    std::cout << "Result1: " << result1 << std::endl;  // Output: Result1: 30
    std::cout << "Result2: " << result2 << std::endl;  // Output: Result2: 5.85

    return 0;
}
```
