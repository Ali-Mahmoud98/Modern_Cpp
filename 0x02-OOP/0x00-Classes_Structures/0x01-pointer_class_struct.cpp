#include <iostream>

class MyClass {
public:
    int data;
    void display() {
        std::cout << "Data: " << data << std::endl;
    }
};

struct MyStruct {
    int data;
    void display() {
        std::cout << "Data: " << data << std::endl;
    }
};


int main() {
    // Pointer to class object
    MyClass* myClassPtr = nullptr;  // Setting to nullptr is equivalent to NULL for pointers

    // Accessing members through the pointer
    // This would lead to undefined behavior, as myClassPtr is not pointing to a valid object
    // Uncommenting the line below might result in a segmentation fault or other issues.
    // myClassPtr->display();

    // Pointer to structure object
    MyStruct* myStructPtr = nullptr;  // Setting to nullptr is equivalent to NULL for pointers

    // Accessing members through the pointer
    // This would lead to undefined behavior, as myStructPtr is not pointing to a valid object
    // Uncommenting the line below might result in unexpected behavior.
    // the next line will cause segmentation fault because myStructPtr is not pointing to a valid object
    // std::cout << "Data: " << myStructPtr->data << std::endl;
    return 0;
}
