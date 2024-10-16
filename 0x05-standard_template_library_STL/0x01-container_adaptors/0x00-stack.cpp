#include <iostream>
#include <stack>
#include <string>

int main() {
    // Create a stack of integers
    std::stack<int> intStack;

    // Pushing elements onto the stack
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    
    // Displaying the top element
    std::cout << "Top element of intStack: " << intStack.top() << std::endl;  // Output: 30

    // Popping an element from the stack
    intStack.pop();
    std::cout << "Top element after pop: " << intStack.top() << std::endl;  // Output: 20

    // Checking if the stack is empty
    if (!intStack.empty()) {
        std::cout << "Stack is not empty." << std::endl;
    }

    // Checking the size of the stack
    std::cout << "Size of intStack: " << intStack.size() << std::endl;  // Output: 2

    // Create a stack of strings
    std::stack<std::string> stringStack;

    // Pushing elements onto the string stack
    stringStack.push("Hello");
    stringStack.push("World");

    // Displaying the top element
    std::cout << "Top element of stringStack: " << stringStack.top() << std::endl;  // Output: World

    // Popping an element from the string stack
    stringStack.pop();
    std::cout << "Top element after pop: " << stringStack.top() << std::endl;  // Output: Hello

    // Demonstrate popping all elements
    while (!intStack.empty()) {
        std::cout << "Popping element: " << intStack.top() << std::endl;
        intStack.pop();  // Remove the top element
    }

    if (intStack.empty()) {
        std::cout << "intStack is now empty." << std::endl;
    }

    return 0;
}
