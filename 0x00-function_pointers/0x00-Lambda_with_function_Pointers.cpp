#include <iostream>

typedef int (*myFuncPtr)(int, int);

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int operate(int x, int y, int (*operation)(int, int)) {
    return operation(x, y);
}

int operate2(int x, int y, myFuncPtr op) {
    return op(x, y);
}

int main() {
    auto addLambda = [](int a, int b) { return a + b; };
    myFuncPtr fptr = add;
    using func_ptr = int (*)(int, int); // define a function pointer type alias
    func_ptr fptr2 = subtract; 

    std::cout << operate(5, 3, add) << std::endl;        // Using function pointer
    std::cout << operate(7, 2, subtract) << std::endl;   // Using function pointer
    std::cout << operate(4, 6, addLambda) << std::endl;  // Using lambda function
    std::cout << operate2(5, 3, add) << std::endl;        // Using function pointer
    std::cout << operate2(7, 2, subtract) << std::endl;   // Using function pointer
    std::cout << operate2(4, 6, addLambda) << std::endl;  // Using lambda function
    std::cout << fptr(4, 6) << std::endl;  // Using fuction pointer typedef
    std::cout << fptr2(7, 2) << std::endl;

    return 0;
}
