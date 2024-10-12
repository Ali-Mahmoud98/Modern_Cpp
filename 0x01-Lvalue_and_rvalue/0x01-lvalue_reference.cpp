#include <iostream>

void modifyValue(int& ref) {
    std::cout<<"Starting modifyValue function\n";
    ref *= 2;
    std::cout<<"ending modifyValue function\n";
}

int main() {
    int variable = 10;  // Declare an integer variable

    // Create an lvalue reference
    int& refVariable = variable;

    std::cout<< "address of variable = " << &variable <<std::endl;
    std::cout<< "address of refVariable = " << &variable <<std::endl;

    std::cout << "Original Value: " << variable << std::endl;

    // Modify the original value using the reference
    modifyValue(refVariable);

    std::cout << "Modified Value: " << variable << std::endl;

    return 0;
}
