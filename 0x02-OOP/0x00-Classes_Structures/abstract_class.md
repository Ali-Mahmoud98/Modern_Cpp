# Abstract Class
An abstract class in C++ is a class that cannot be instantiated on its own and is designed to be a base class for other classes. **An abstract class is defined by having at least one pure virtual function**. A pure virtual function is a virtual function that is declared by assigning `0` to it within the class declaration. Abstract classes are used to define interfaces in C++ and to create a foundation for other classes to build upon.

### Characteristics of Abstract Classes:
1. **Cannot be instantiated**: You cannot create an object of an abstract class.
2. **Contain pure virtual functions**: These functions must be implemented by derived classes.
3. **Used as base classes**: Abstract classes serve as templates for other classes.

### Example of an Abstract Class in C++:
```cpp
// Abstract class
class Shape {
public:
    // Pure virtual function
    virtual void draw() = 0;
    // Regular member function
    void setColor(string col) {
        color = col;
    }
    string getColor() {
        return color;
    }
private:
    string color;
};
```
### Summary:
Abstract classes are a key feature in C++ that help in designing flexible and scalable systems by providing a common interface and enforcing the implementation of specific methods in derived classes. They are essential for achieving polymorphism and creating robust class hierarchies.