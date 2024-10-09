#include <iostream>
#include <vector>

template <typename T>
void addToVector(std::vector<T>& vec, T arg) {
    vec.push_back(arg);  // Add the single argument to the vector
}

template <typename T, typename... Types>
void addToVector(std::vector<T>& vec, T first, Types... rest) {
    vec.push_back(first);         // Add the first argument to the vector
    addToVector(vec, rest...);    // Recursively add the rest of the arguments
}

template <typename... Types>
void addToVector(std::vector<std::string>& vec, Types... args) {
    (vec.push_back(std::string(args)), ...);  // Expanding the parameter pack and converting each to std::string
}

int main() {
    std::vector<int> intVec;
    addToVector(intVec, 1, 2, 3, 4, 5);  // Add multiple integers to the vector

    std::cout << "Contents of intVec: ";
    for (int num : intVec) {
        std::cout << num << " ";  // Print each element in the vector
    }
    std::cout << std::endl;

    std::vector<std::string> strVec;
    addToVector(strVec, "Hello", "World", "from", "variadic", "templates");

    std::cout << "Contents of strVec: ";
    for (const std::string& str : strVec) {
        std::cout << str << " ";  // Print each string in the vector
    }
    std::cout << std::endl;

    return 0;
}
