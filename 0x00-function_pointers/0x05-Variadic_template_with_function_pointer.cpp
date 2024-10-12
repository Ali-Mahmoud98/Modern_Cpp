#include <iostream>

// Base case for the variadic template recursion
template <typename ReturnType, typename... Args>
ReturnType callFunctionPointer(ReturnType (*func)(Args...), Args&&... args) {
    return func(std::forward<Args>(args)...);
}

// Recursive case for the variadic template
template <typename ReturnType, typename Arg, typename... Args>
ReturnType callFunctionPointer(ReturnType (*func)(Arg, Args...), Arg&& arg, Args&&... args) {
    return func(std::forward<Arg>(arg), callFunctionPointer(func, std::forward<Args>(args)...));
}

// Example function: Multiply any number of integers
template <typename... Args>
int multiply(Args... args) {
    return (args * ...);
}

int main() {
    // Function pointer for the multiply function
    int (*multiplyFunc)(int, int, int) = multiply;

    // Call the function using variadic templates and function pointer
    int result = callFunctionPointer(multiplyFunc, 2, 3, 4);

    std::cout << "Result: " << result << std::endl;  // Output: Result: 24

    return 0;
}
