Certainly! Let's explore how **templates** interact with **object-oriented programming (OOP)** in C++ by examining a full example that demonstrates the core principles of both. Templates allow you to write generic code that works with any data type, while OOP allows you to define relationships between objects and use polymorphism, inheritance, and encapsulation.

We'll look at how templates and OOP can be combined, what their limitations are, and how template-based polymorphism differs from inheritance-based polymorphism.

### Full Example: A Generic Stack with Both Template and OOP Features

Let's create a **generic stack** class using C++ templates. The stack should be able to handle different data types and adhere to OOP principles. We'll also show how template-based polymorphism can be used and contrasted with OOP-based polymorphism.

#### Step 1: Defining the Interface (Abstract Class)
First, let's define an interface (using an abstract class) that describes the behavior of a stack. We'll declare the basic stack operations as pure virtual functions.

```cpp
#include <iostream>
#include <vector>

// Interface for a stack (using abstract class)
template<typename T>
class IStack {
public:
    virtual ~IStack() = default; // Virtual destructor for proper cleanup
    virtual void push(T value) = 0;  // Pure virtual function
    virtual T pop() = 0;             // Pure virtual function
    virtual T peek() const = 0;      // Pure virtual function
    virtual bool isEmpty() const = 0;// Pure virtual function
};
```

In this interface:
- We use **pure virtual functions** to define the essential operations for any stack (push, pop, peek, and checking if the stack is empty).
- The interface is **generic** because it’s defined as a **template class** (`IStack<T>`), meaning that any stack implementing this interface can work with any data type `T`.

#### Step 2: Implementing the Stack using a Template

Now, we'll implement the `IStack` interface using a template class called `ArrayStack` that uses a `std::vector` to manage the stack elements.

```cpp
template<typename T>
class ArrayStack : public IStack<T> {
private:
    std::vector<T> stack; // Use a vector to store the stack elements

public:
    // Push element onto the stack
    void push(T value) override {
        stack.push_back(value);
    }

    // Pop element from the stack
    T pop() override {
        if (!isEmpty()) {
            T top = stack.back();
            stack.pop_back();
            return top;
        } else {
            throw std::out_of_range("Stack is empty!");
        }
    }

    // Peek at the top element
    T peek() const override {
        if (!isEmpty()) {
            return stack.back();
        } else {
            throw std::out_of_range("Stack is empty!");
        }
    }

    // Check if the stack is empty
    bool isEmpty() const override {
        return stack.empty();
    }
};
```

In this class:
- We implement the generic `ArrayStack` class by inheriting from the abstract `IStack` interface.
- The stack is internally managed using a `std::vector`, and we provide definitions for the stack operations (push, pop, peek, and isEmpty).
- Since the class is templated (`template<typename T>`), we can create stacks for any data type (`int`, `float`, `std::string`, etc.).

#### Step 3: Using the Stack with Different Data Types

Let's create stacks of different data types (e.g., `int` and `std::string`) and demonstrate how the same generic class can handle both.

```cpp
int main() {
    // Stack of integers
    ArrayStack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    
    std::cout << "Top of intStack: " << intStack.peek() << std::endl;
    intStack.pop();
    std::cout << "Top of intStack after pop: " << intStack.peek() << std::endl;

    // Stack of strings
    ArrayStack<std::string> stringStack;
    stringStack.push("Hello");
    stringStack.push("World");

    std::cout << "Top of stringStack: " << stringStack.peek() << std::endl;
    stringStack.pop();
    std::cout << "Top of stringStack after pop: " << stringStack.peek() << std::endl;

    return 0;
}
```

In the `main()` function:
- We create an `ArrayStack<int>` to hold integers and perform stack operations like `push()`, `pop()`, and `peek()`.
- Similarly, we create an `ArrayStack<std::string>` to hold strings and demonstrate the same operations.
- The key point is that the `ArrayStack` works with **any data type** because it is templated.

#### Output:
```
Top of intStack: 30
Top of intStack after pop: 20
Top of stringStack: World
Top of stringStack after pop: Hello
```

### Templates vs Inheritance-Based Polymorphism

Templates allow **compile-time polymorphism**, which means that the type is determined when the code is compiled. This is different from **runtime polymorphism**, which is achieved using inheritance and virtual functions.

1. **Templates (Compile-Time Polymorphism)**:
   - With templates, the compiler generates code for each specific type that the template is instantiated with. This is **fast** and **type-safe** since the type is resolved at compile time.
   - However, templates do not support **true polymorphism** in the OOP sense, as they cannot substitute different types at runtime.

2. **Inheritance-Based Polymorphism (Runtime Polymorphism)**:
   - With inheritance and virtual functions, you can have **runtime polymorphism**, where a base class pointer or reference can refer to objects of different derived classes.
   - This allows you to create flexible systems where objects can be substituted dynamically at runtime based on their actual type.

#### Combining Both: A Hybrid Example

You can also combine templates and OOP by creating generic base classes that can be extended using inheritance and virtual functions.

```cpp
template<typename T>
class PrintableStack : public IStack<T> {
public:
    // Virtual function to print the stack (for demonstration)
    virtual void print() const = 0;
};

template<typename T>
class PrintableArrayStack : public ArrayStack<T>, public PrintableStack<T> {
public:
    void print() const override {
        std::cout << "Stack contents: ";
        for (int i = 0; i < this->stack.size(); ++i) {
            std::cout << this->stack[i] << " ";
        }
        std::cout << std::endl;
    }
};
```

In this hybrid example:
- We create a **PrintableStack** interface that extends `IStack` with a `print()` function.
- We then create a **PrintableArrayStack** class that inherits both from the `ArrayStack` template class and from the `PrintableStack` interface, allowing it to provide both the generic stack functionality and a custom `print()` method.
