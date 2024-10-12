# Enum Classes and Enum DataType
Enums or Enumerated type (enumeration) is a user-defined data type that can be assigned some limited values. These values are defined by the programmer at the time of declaring the enumerated type.

In C++, enumerations (enums) are a powerful tool for creating named sets of integer constants. They help improve code readability and maintainability by providing meaningful names to numeric values. However, C++ offers two ways to define enums: the traditional enum and the more modern enum class.

## Traditional enum
The traditional enum in C++ allows you to define a set of named integer constants without restricting their underlying type. This means the values are not encapsulated within a specific scope, leading to potential namespace clashes.
```c++
#include <iostream>

enum Color {
    Red,
    Green,
    Blue
};

int main() {
    Color myColor = Red;
    // ...
    return 0;
}
```
Two enumerations cannot share the same names in the same scope.

Enumerators declared using the traditional enum are in the same scope as the surrounding code. This can potentially lead to naming conflicts if similar names exist elsewhere in your program. the following will cause error
```c++
enum Color {
    Red,
    Green,
    Blue,
    White = 10,
    Black,
    Yellow,
    Orange = 0,
    Purple
};

enum Color2 {
    Red, // this will cause error because Red is already defined
    Green2,
    Blue2
};
int Red = 5;// this will cause error because Red is already defined
```
if the same entity defined in different scopes this will not cause error:
```c++
enum Color {
    Red,
    Green,
    Blue,
};
namespace Color2{
    enum Color2 {
        Red,
        Green2,
        Blue2
    };
}
namespace Color3{
    int Red = 5;
}
```
By default, traditional enums have an underlying integral type, usually int. You can explicitly specify the underlying type, but it’s not mandatory.
``` c++
#include <iostream>

enum Color {
    Red,
    Green,
    Blue
};

int main() {
    std::cout << sizeof(Color) << std::endl; // Size is implementation-dependent.
    return 0;
}
```

## Enum Class
C++11 has introduced enum classes (also called scoped enumerations), that makes enumerations both strongly typed and strongly scoped. Class enum doesn’t allow implicit conversion to int, and also doesn’t compare enumerators from different enumerations.
To define enum class we use class keyword after enum keyword.

Example:
```c++
#include <iostream>

// Enum class
enum class Color {
    Red,
    Green,
    Blue
};

int main() {
    Color favoriteColor = Color::Green;
    
    switch (favoriteColor) {
        case Color::Red:
            std::cout << "Red" << std::endl;
            break;
        case Color::Green:
            std::cout << "Green" << std::endl;
            break;
        case Color::Blue:
            std::cout << "Blue" << std::endl;
            break;
    }

    return 0;
}
```
Enum classes offer strong type safety. They do not allow implicit type conversions, helping to prevent unintended assignments or comparisons between different enum types.
```c++
#include <iostream>

enum class Color {
    Red,
    Green,
    Blue
};

int main() {
    Color myColor = Color::Red;
    int myInt = 1;

    if (myColor == myInt) {  // Error: no match for 'operator=='
        std::cout << "Colors match!" << std::endl;
    }

    return 0;
}
```
Enum classes require you to specify the underlying type explicitly. This promotes clarity and consistency in your code.
```c++
#include <iostream>

enum class Color : char {
    Red,
    Green,
    Blue
};

int main() {
    std::cout << sizeof(Color) << std::endl; // Size is guaranteed to be 1 byte (char).
    return 0;
}
```

## Differences Between Traditional Enums and Enum Classes

1. **Scope:**
   - **Traditional Enum:** Enum values are in the same scope as the enum type itself.
   - **Enum Class:** Enum values are scoped within the enum class.

2. **Type Safety:**
   - **Traditional Enum:** Enum values can be implicitly converted to `int`, which can lead to errors.
   - **Enum Class:** Enum values cannot be implicitly converted to `int` and require explicit casting if needed.

3. **Namespace Pollution:**
   - **Traditional Enum:** Enum values are injected into the enclosing scope, which can cause naming conflicts.
   - **Enum Class:** Enum values are confined to the enum class, avoiding conflicts with other names.

4. **Default Underlying Type:**
   - **Traditional Enum:** The underlying type is usually `int`, but it can be changed.
   - **Enum Class:** The underlying type can be specified, but defaults to `int` if not specified.



## Resources:
* [Enum vs Enum Class in C++](https://agrawalsuneet.github.io/blogs/enum-vs-enum-class-in-c++/)