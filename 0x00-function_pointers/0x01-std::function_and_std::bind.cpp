#include <iostream>
#include <functional>

int add(int a, int b) {
    return a + b;
}

int main() {
    // Using std::function for flexibility
    // std::function<ret_type(params_type)
    // params_type: is separated by comma (example)=> ret_type(int, int, float, ...)
    std::function<int(int, int)> funcPointer = add;

    std::cout << funcPointer(3, 4) << std::endl;

    // Using std::bind to bind arguments
    auto addFive = std::bind(add, std::placeholders::_1, 5);
    std::cout << addFive(10) << std::endl;

    return 0;
}
