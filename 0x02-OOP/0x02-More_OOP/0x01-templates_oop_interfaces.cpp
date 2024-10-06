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

// Base class: ArrayStack
template<typename T>
class ArrayStack : virtual public IStack<T> {
protected:
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

// PrintableStack Interface (extends IStack and adds a print function)
template<typename T>
class PrintableStack : virtual public IStack<T> {
public:
    virtual void print() const = 0;  // Pure virtual function to print the stack
};

// PrintableArrayStack class that inherits from both ArrayStack and PrintableStack
template<typename T>
class PrintableArrayStack : public ArrayStack<T>, public PrintableStack<T> {
public:
    // Implement the print function to print the stack's contents
    void print() const override {
        std::cout << "Stack contents: ";
        for (const T& elem : this->stack) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
};

// Main function demonstrating the use of templates and OOP
int main() {
    // Stack of integers
    PrintableArrayStack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    std::cout << "Integer stack:" << std::endl;
    intStack.print(); // Prints the stack
    intStack.pop();
    std::cout << "After popping one element:" << std::endl;
    intStack.print(); // Prints the stack after pop

    // Stack of strings
    PrintableArrayStack<std::string> stringStack;
    stringStack.push("Hello");
    stringStack.push("World");

    std::cout << "\nString stack:" << std::endl;
    stringStack.print(); // Prints the stack
    stringStack.pop();
    std::cout << "After popping one element:" << std::endl;
    stringStack.print(); // Prints the stack after pop

    return 0;
}
