//  Basic std::shared_ptr Usage
#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() { std::cout << "MyClass constructed\n"; }
    ~MyClass() { std::cout << "MyClass destructed\n"; }
};

int main() {
    std::shared_ptr<MyClass> ptr1(new MyClass()); // Create a shared pointer
    {
        std::shared_ptr<MyClass> ptr2 = ptr1; // Share ownership
        std::cout << "Reference count: " << ptr1.use_count() << "\n"; // Should be 2
    } // ptr2 goes out of scope, reference count decreases
    std::cout << "Reference count: " << ptr1.use_count() << "\n"; // Should be 1
    return 0;
}
