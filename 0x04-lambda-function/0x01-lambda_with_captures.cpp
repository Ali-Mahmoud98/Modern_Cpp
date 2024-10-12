#include <iostream>

int main() {
    std::cout << "Hello from lambda with captures!" << std::endl;
    int x = 10;
    int y = 5;

    std::cout << "x = " << x << ", y = " << y << std::endl;
    // [x, &y] means that x is captured by value and y is captured by reference
    // capture means that external variables can be accessed from the surrounding scope in a lambda
    auto multiply = [x, &y](int z) {
        y = y + z;
        //x = 3; // this line will cause an error
        //variables captured by value in a lambda are immutable, meaning they cannot be modified inside the lambda function.
        return x * y;
    };
    // [x, &y] is called a capture list or capture closure
    std::cout << "the fuction multiply(z) = (y=y+z)*x" << std::endl;
    std::cout << "multiply(5) = (y=5+5)*10 = " << multiply(5) << std::endl;

    std::cout << "x = " << x << ", y = " << y << std::endl;

    return 0;
}
