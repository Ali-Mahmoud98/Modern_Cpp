#include <iostream>

class Calculator {
public:
    using Operation = int (*)(int, int);

    Calculator(Operation op) : operation(op) {}

    int calculate(int a, int b) {
        return operation(a, b);
    }

private:
    Operation operation;
};

int add(int a, int b) {
    return a + b;
}

int main() {
    Calculator calculator(add);
    std::cout << calculator.calculate(5, 3) << std::endl;

    return 0;
}
