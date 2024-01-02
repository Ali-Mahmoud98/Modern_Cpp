#include <iostream>

// Overloaded function for lvalues
void processValue(const int& value) {
    std::cout << "Processing Lvalue: " << value << std::endl;
}

// Overloaded function for rvalues
void processValue(int&& value) {
    std::cout << "Processing Rvalue: " << value << std::endl;
}

int main() {
    int x = 42;

    // Call the appropriate overloaded function based on the nature of the argument
    processValue(x);        // Calls the lvalue overload
    processValue(3 * 7);    // Calls the rvalue overload

    return 0;
}
