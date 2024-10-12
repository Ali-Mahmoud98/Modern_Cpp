#include <iostream>
#include <array>

int main() {
    std::array<int, 5> arr = { 1, 2, 3, 4, 5 };
    
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << std::endl;
    }
    
    std::cout << "---------------" << std::endl;
    std::cout << std::endl;
    
    for (auto elem : arr) {
        std::cout << elem << std::endl;
    }

    std::cout << "---------------" << std::endl;
    std::cout << std::endl;

    std::cout << "arr.at(0) = " << arr.at(0) << std::endl;
    std::cout << "arr.front() = " << arr.front() << std::endl;
    std::cout << "arr.back() = " << arr.back() << std::endl;

    arr.fill(0);

    for (auto elem : arr) {
        std::cout << elem << std::endl;
    }

    std::cout << "---------------" << std::endl;
    std::cout << std::endl;

    std::cout << "arr.size() = " << arr.size() << std::endl;

    std::cout << "---------------" << std::endl;
    std::cout << std::endl;

    std::cout << "arr.data() = " << arr.data() << std::endl;

    std::cout << "---------------" << std::endl;
    std::cout << std::endl;

    arr.at(0) = 10;
    arr[2] = 5;
    std::cout << "arr.at(0) = " << arr.at(0) << std::endl;
    return 0;
}