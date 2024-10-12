#include <iostream>
#include <type_traits>

// Variable template for mathematical constants
template<typename T>
constexpr T pi = T(3.1415926535897932385); // Generic case for pi

// Variable template to define a zero identity
template<typename T>
constexpr T zero = T(0); // Generic zero

// Specialization of the zero variable template for pointers
template<typename T>
constexpr T* zero<T*> = nullptr; // Special case for pointer types

// Specialization of pi for float types (higher precision for float)
template<>
constexpr float pi<float> = 3.14159f; // Specialized pi for float

int main() {
    // Using pi for different types
    std::cout << "pi<double> = " << pi<double> << std::endl;
    std::cout << "pi<float>  = " << pi<float> << std::endl;
    std::cout << "pi<int>  = " << pi<int> << std::endl;

    // Using zero for different types
    std::cout << "zero<int> = " << zero<int> << std::endl;
    std::cout << "zero<double> = " << zero<double> << std::endl;

    // Using specialized zero for pointer types
    int* intPtr = zero<int*>;
    if (intPtr == nullptr) {
        std::cout << "zero<int*> is nullptr" << std::endl;
    }

    // Example of type traits with variable templates
    if constexpr (std::is_same_v<decltype(pi<float>), float>) {
        std::cout << "The type of pi<float> is indeed float" << std::endl;
    }

    return 0;
}
