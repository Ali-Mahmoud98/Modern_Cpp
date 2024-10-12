#include <iostream>
#include <utility>

class MyString {
public:
    // Constructor with move semantics
    MyString(std::string&& str) : data(std::move(str)) {
        std::cout << "Constructed with Move: " << data << std::endl;
    }

private:
    std::string data;
};

int main() {
    std::string original = "Hello, World!";

    // Move semantics in action
    MyString movedString = std::move(original);

    // movedString will steal the original value
    std::cout << "Original String: " << original << std::endl;  // the origional will be empty string

    return 0;
}
