#include <iostream>

template<typename Func>
void print(Func callback) {
    std::cout << "result:" << callback(5, 3) << std::endl;
}

int main() {
    // Lambda expression
    auto func = [](int a, int b) { return a + b; };

    int result = func(5, 3);

    std::cout << "result: " << result << std::endl;

    std::cout << "-----------------" << std::endl;

    // making a pointer to fuction without auto
    int (*funcPtr)(int, int) = [](int a, int b) { return a + b; };
    result = funcPtr(4, 3);
    std::cout << "result: " << result << std::endl;

    std::cout << "-----------------" << std::endl;

    // lambda expression as a function parameter
    print([](int a, int b) { return a + b; });
    print(func);
    print(funcPtr);

    return 0;
}
