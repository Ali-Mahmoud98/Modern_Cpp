#include "0x03-myArray.hpp"

int main() {
    // type alias for MyArray
    using T = MyArray<int>;

    T arr(5);

    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;

    // using my custom iterator
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        std::cout << *it << " ";  // Output: 10 20 30 40 50
    }
    std::cout << std::endl;

    MyArray<std::string> arr2(4);  // Create an empty MyArray of strings>

    arr2[0] = "apple";
    arr2[1] = "banana";
    arr2[2] = "cherry";
    arr2[3] = "date";

    for (auto it = arr2.begin(); it != arr2.end(); it++) {
        std::cout << *it << " ";  // Output: apple banana cherry date
    }
    std::cout << std::endl;

    MyArray<char> arr3(3);  // Create an empty MyArray of characters
    arr3[0] = 'a';
    arr3[1] = 'b';
    arr3[2] = 'c';

    for (size_t i = 0; i < arr3.arrCapacity(); i++) {
        std::cout << arr3[i] << " ";  // Output: a b c
    }
    std::cout << std::endl;

    return 0;
}