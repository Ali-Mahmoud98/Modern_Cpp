#include <iostream>

int main() {
    // Lvalues: Variables with identifiable memory locations
    int x = 5;  // x is an lvalue
    int* ptr = &x;  // Address of x is taken, making it an lvalue

    // Rvalues: Temporary values without identifiable memory locations
    int result = 2 + 3;  // 2 + 3 is an rvalue
    // int* tempPtr = &(x + result); // This line will cause error. value after '&' should be lvalue 
    // Expression (x + result) is an rvalue

    std::cout << "Lvalues and Rvalues Example:" << std::endl;
    std::cout << "x: " << x << ", result: " << result << std::endl;

    return 0;
}
