# Dynamic Binding
## Introduction
**Dynamic Binding**, also known as **Late Binding** or **Runtime Binding**, is a fundamental concept in object-oriented programming (OOP). It refers to the process of resolving function calls at runtime rather than at compile time. This allows the program to determine which method to invoke based on the actual object type that exists at runtime, rather than the type specified in the code.

Dynamic Binding is closely related to polymorphism and virtual functions. It enables a base class pointer or reference to call methods that are overridden in derived classes, allowing for more flexible and dynamic behavior in your programs.

Dynamic Binding enables polymorphism by resolving function calls at runtime based on the actual object type. It is essential for creating flexible, extensible, and maintainable object-oriented systems, allowing you to write generic code that can work with objects of different types in a unified way.

## Example
```cpp
#include <iostream>

// Base class
class Shape {
public:
    // Virtual function
    virtual void draw() {
        std::cout << "Drawing Shape" << std::endl;
    }
};

// Derived class 1
class Circle : public Shape {
public:
    // Overriding the draw function
    void draw() override {
        std::cout << "Drawing Circle" << std::endl;
    }
};

// Derived class 2
class Rectangle : public Shape {
public:
    // Overriding the draw function
    void draw() override {
        std::cout << "Drawing Rectangle" << std::endl;
    }
};

int main() {
    Shape* shape;

    Circle circle;
    Rectangle rectangle;

    // Dynamic binding in action
    shape = &circle;
    shape->draw();  // Calls Circle's draw() method

    shape = &rectangle;
    shape->draw();  // Calls Rectangle's draw() method

    return 0;
}
```

### Explanation:
1. **Virtual Function**: The `draw` method in the `Shape` class is declared as `virtual`. This tells the compiler to use dynamic binding for this function.
2. **Overriding in Derived Classes**: Both `Circle` and `Rectangle` classes override the `draw` method.
3. **Base Class Pointer**: A pointer of type `Shape*` is used to reference objects of `Circle` and `Rectangle`.
4. **Dynamic Binding**: When `shape->draw()` is called, the program determines at runtime which `draw` method to invoke based on the actual object type (`Circle` or `Rectangle`). This results in the correct `draw` method being called, demonstrating dynamic behavior.

## Importance of Dynamic Binding
Dynamic Binding is crucial for achieving polymorphism in C++. It allows a single piece of code (e.g., a function or method) to work with objects of different types in a flexible and extensible manner. Without dynamic binding, polymorphism would not be possible, and the ability to write generic and reusable code would be limited.

## When to Use Dynamic Binding
Dynamic Binding is typically used when:
1. **You Have a Base Class with Virtual Functions**: If a base class has virtual functions that are meant to be overridden by derived classes, dynamic binding ensures that the correct overridden function is called.
2. **You Want to Handle Different Derived Classes Uniformly**: If you have a collection of objects from different derived classes and want to treat them uniformly through a base class pointer or reference, dynamic binding allows you to do this seamlessly.
3. **You Need Flexibility and Extensibility**: Dynamic binding allows you to extend your program by adding new derived classes without modifying the existing code that uses the base class.

## Performance Considerations
While dynamic binding provides flexibility, it does come with a slight performance cost due to the runtime determination of function calls. However, this cost is usually negligible compared to the benefits of polymorphism and code extensibility it offers.
