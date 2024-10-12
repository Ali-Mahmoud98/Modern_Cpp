# this pointer in C++
To understand ‘this’ pointer, it is important to know how objects look at functions and data members of a class.
1. Each object gets its own copy of the data member.
2. All-access the same function definition as present in the code segment.

Meaning each object gets its own copy of data members and all objects share a single copy of member functions.

Then now question is that if only one copy of each member function exists and is used by multiple objects, how are the proper data members are accessed and updated?

The compiler supplies an implicit pointer along with the names of the functions as `this`.

The `this` pointer is **passed** as a **hidden argument to all nonstatic member function** calls and is available as a local variable within the body of all nonstatic functions.

`this` pointer **is not available in static member functions** as static member functions can be called without any object (with class name).

For a class `MyClass` the type of this pointer is `MyClass*`. Also, if a member function of `MyClass` is declared as `const`, then the type of this pointer is `const MyClass*`.

**NOTE:** the previous Explaination copied from [GFG](https://www.geeksforgeeks.org/this-pointer-in-c/)


### `this` Keyword in C++
The `this` keyword in C++ is a special pointer available inside non-static member functions of a class. It points to the object for which the member function is called. In simpler terms, `this` is a pointer to the current object instance.

- **`this`** is a pointer that refers to the current object.
- It is used to access the object’s members and to differentiate between member variables and parameters.
- **`this`** can also be used to return the current object, enabling method chaining.
  
In C++, `this` is crucial for working with classes and objects, allowing for clear and concise code, especially in complex scenarios where objects interact with themselves.

**NOTE:** READ about method chaining

#### When to Use `this`

1. **Distinguishing Between Member Variables and Parameters:**
   - When a member function has parameters with the same name as member variables, `this` is used to distinguish between the two.
  
2. **Returning the Current Object:**
   - `this` can be used to return the current object from a member function, which is useful for method chaining.

3. **Pointer to the Current Object:**
   - `this` is implicitly used when accessing member variables and functions, but can be explicitly used when needed.

### Example 1: Distinguishing Between Member Variables and Parameters

```cpp
#include <iostream>

class Rectangle {
private:
    int width, height;

public:
    // Constructor
    Rectangle(int width, int height) {
        this->width = width;  // 'this->width' refers to the member variable, 'width' refers to the parameter
        this->height = height;
    }

    void display() {
        std::cout << "Width: " << width << ", Height: " << height << std::endl;
    }
};

int main() {
    Rectangle rect(10, 20);
    rect.display();
    return 0;
}
```

**Explanation:**
- In the constructor, the `this` pointer is used to differentiate between the class members (`this->width`, `this->height`) and the constructor parameters (`width`, `height`).

### Example 2: Returning the Current Object (Method Chaining)

```cpp
#include <iostream>

class Number {
private:
    int value;

public:
    // Constructor
    Number(int value) : value(value) {}

    // Method to add a number
    Number& add(int num) {
        this->value += num;
        return *this;  // Return the current object
    }

    // Method to subtract a number
    Number& subtract(int num) {
        this->value -= num;
        return *this;  // Return the current object
    }

    void display() {
        std::cout << "Value: " << value << std::endl;
    }
};

int main() {
    Number num(10);
    num.add(5).subtract(3).display();  // Method chaining
    return 0;
}
```

**Explanation:**
- The `add` and `subtract` methods return the current object (`*this`) by reference. This allows method chaining, where multiple methods can be called on the same object in a single statement.
