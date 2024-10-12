# OOP Concepts
* Encapsulation
* Abstraction
* Polymorphism
* [Inheritance](./0-inheritance.md)
* [Dynamic Binding](./1-dynamic_binding.md)
* [Message Passing](./2-message_passing.md)
* [Enum and Enum Class](./3-enum_enumClass.md)
* [Nested Class](./4-nested_class.md)
* [Shallow Copy and Deep Copy](./5-shallow_deep_copy.md)

## Contents
* [Encapsulation](#1-encapsulation)
    * [Explanation](#11-explanation)
* [Abstraction](#2-abstraction)
* [Polymorphism](#3-polymorphism)
    * [Types of Polymorphism](#31-types-of-polymorphism)
    * [Example of Compile-time Polymorphism](#32-example-of-compile-time-polymorphism)
        * [Function Overloading](#321-function-overloading)
        * [Operator Overloading](#322-operator-overloading)
    * [Example of Run-time Polymorphism](#33-example-of-run-time-polymorphism)
        * [Virtual Functions](#331-virtual-functions)
    * [Use Cases of Polymorphism](#34-use-cases-of-polymorphism)

## 1. Encapsulation
Encapsulation is one of the fundamental principles of object-oriented programming (OOP). It refers to the bundling of data (variables) and methods (functions) that operate on the data into a single unit, typically a class. Encapsulation also involves restricting direct access to some of an object's components, which is a means of preventing accidental interference and misuse of the data.

In simple terms, encapsulation is like a protective shield that keeps the data safe within the object and only allows access to it through well-defined interfaces (methods).

Let's consider a simple example of a class `Person` that encapsulates the details of a person.
```c++
class Person {
private:
    // Private data members
    std::string name;
    int age;
public:
    // Constructor to initialize the object
    Person(std::string n, int a) : name(n), age(a) {}
    // Public method to set the name
    void setName(std::string n) {
        name = n;
    }
    // Public method to get the name
    std::string getName() {
        return name;
    }
    // Public method to set the age
    void setAge(int a) {
        if (a > 0) { // Simple validation
            age = a;
        }
    }
    // Public method to get the age
    intAge() {
        return age;
    }
    // Public method to display the person's details
    void display() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

```
### 1.1. Explanation
1. **Private Data Members:** The `name` and `age` are private, meaning they cannot be accessed directly from outside the class. This ensures that the internal state of the object is protected from unintended modifications.
2. **Public Methods:** The class provides public methods (`setName`, `getName`, `setAge`, `getAge`, and `display`) to interact with the private data. These methods act as an interface to the outside world, allowing controlled access to the data.
3. **Validation**: The `setAge` method includes a simple validation to ensure that the age is positive. This is an example of how encapsulation can help maintain the integrity of the data.

By using encapsulation, we ensure that the internal state of the `Person` object can only modified in a controlled manner, reducing the risk of errors and making the code easier to maintain and understand.

## 2. Abstraction
Abstraction is another fundamental principle of object-oriented programming (OOP). It involves hiding the complex implementation details of a system and exposing only the necessary and relevant parts to the user. The main goal of abstraction is to reduce complexity and allow the programmer to focus on interactions at a higher level.

In simple terms, abstraction is like using a car without needing to understand the intricate details of how the engine works. You just need to know how to drive it.

Let's consider an example of a simple `Shape` class hierarchy to illustrate abstraction.
```c++
#include <iostream>
#include <cmath>
// Abstract base class
class Shape {
public:
    // Pure virtual function providing interface framework.
    double area() const = 0;
    virtual double perimeter() const = 0;

    // Virtual destructor
    virtual ~Shape() {}
};
// Derived class for Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // Implementing the pure virtual functions
    double area() const override {
        return M_PI * radius * radius;
    }

    double perimeter() const override {
        return 2 * M_PI * radius;
    }
};
// Derived class for Rectangle
class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    // Implement the pure virtual functions
    double area() const override {
        return width * height;
    }

    double perimeter() const override {
        return 2 * (width + height);
    }
};
int main() {
    // Creating objects of derived classes
    Shape* circle = new Circle(5.0);
    Shape* rectangle = new Rectangle(4.0, 6.0);
    // Using the abstract interface to interact with the objects
    std::cout << "Circle Area: " << circle->area() << std::endl;
    std::cout << "Circle Perimeter: " << circle->perimeter() << std::endl;
    std::cout << "Rectangle Area: " <<->area() << std::endl;
    std::cout << "Rectangle Perimeter: " << rectangle->perimeter() << std::endl;
    // Cleaning up
    delete circle;
    delete rectangle;

    return 0;
}
```
**NOTE:** The Abstract class explained in section [0x00-Classes_Structures](../0x00-Classes_Structures/) with example.


## 3. Polymorphism
Polymorphism is one of the core concepts of object-oriented programming (OOP) and it refers to the ability of different classes to be treated as instances of the same class through a common interface. The most common use of polymorphism in C++ is through inheritance and virtual functions. Polymorphism allows for methods to be defined in a base class and overridden in derived classes, enabling objects of different types to be manipulated through a common interface.

### 3.1. Types of Polymorphism
1. **Compile-time Polymorphism (Static Polymorphism)**:
   - **Function Overloading**: Multiple functions with the same name but different parameters.
   - **Operator Overloading**: Giving special meaning to an existing operator in the context of a user-defined data type.
   
2. **Run-time Polymorphism (Dynamic Polymorphism)**:
   - **Virtual Functions**: Functions declared in a base class and overridden in a derived class. The decision about which function to invoke is made at runtime.

### 3.2. Example of Compile-time Polymorphism

#### 3.2.1. Function Overloading
```cpp
#include <iostream>
using namespace std;

class Print {
public:
    void display(int i) {
        cout << "Displaying int: " << i << endl;
    }
    void display(double d) {
        cout << "Displaying double: " << d << endl;
    }
    void display(string str) {
        cout << "Displaying string: " << str << endl;
    }
};
```
#### 3.2.2. Operator Overloading
```cpp
class Complex {
private:
    int x;
public:
    //member initialization list
    Complex() : x(0) {}
    Complex(int num) : x(num) {}
    // overloading the '+' operator
    Complex operator + (const Complex &obj) {
        Complex temp;
        temp.x = x + obj.x;
        return temp;
    }
};
```

### 3.3. Example of Run-time Polymorphism
#### 3.3.1. Virtual Functions
```cpp
class Base {
public:
    virtual void show() {
        cout << "Base class show function" << endl;
    }
    void display() {
        cout << "Base class display function" << endl;
    }
};
class Derived : public Base {
public:
    // function overriding
    void show() override {
        cout << "Derived class show function" << endl;
    }

    void display() {
        cout << "Derived class display function" << endl;
    }
};
int main() {
    Base *basePtr;
    Derived derivedObj;
    basePtr = &derivedObj;
    // Run-time polymorphism
    basePtr->show(); // Calls Derived class show function
    basePtr->display(); // Calls Base class display function
    return 0;
}
```

In this example:
- The `show` function is a virtual function. The call to `basePtr->show()` will invoke the `show` function in the `Derived` class because the `Derived` class overrides the `show` function and the function is marked as virtual.
- The `display` function is not virtual. The call to `basePtr->display()` will invoke the `display` function in the `Base` class because it is not virtual and therefore does not exhibit polymorphic behavior.

### 3.4. Use Cases of Polymorphism

1. **Flexible System Design**:
   Polymorphism allows for designing systems that can be easily extended with new classes without modifying existing code.

2. **Code Reusability**:
   Polymorphism enables the reuse of code by allowing functions to use objects of different types through a common interface.

3. **Implementation Hiding**:
   By using polymorphism, the implementation details of derived classes can be hidden from the users, exposing only the interface.

4. **Extensibility**:
   New derived classes can be added without changing the existing code that uses the base class interface, making the system more maintainable and scalable.

Polymorphism is a powerful feature in C++ that enhances the flexibility and maintainability of code, making it a fundamental concept in OOP.
