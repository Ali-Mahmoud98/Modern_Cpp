#include <iostream>
/**
 * Private Destructor:
 * Destructors with the access modifier as private are known as Private Destructors.
 * Whenever we want to prevent the destruction of an object, we can make the destructor
 * as private.
 * What is the use of private destructor?
 * Whenever we want to control the destruction of objects of a class, we make the
 * destructor private. For dynamically created objects, it may happen that you pass
 * a pointer to the object to a function and the function deletes the object. If the
 * object is referred after the function call, the reference will become dangling.
 */

class Example {
public:
    Example() {
        std::cout << "Entered Example" << std::endl;
    }
    void deleteMe() {
        delete this;
    }
private:
    ~Example() {
        std::cout << "Exited Example" << std::endl;
    }
    friend void destructExample(Example*);
};

void destructExample(Example* ptr) { delete ptr; }
int main() {
    // Example e; // error: Example::~Example() noexcept" (declared at line 20) is inaccessible
    Example* e = new Example();
    // delete e;// error: Example::~Example() noexcept" (declared at line 20) is inaccessible
    destructExample(e);
    Example* e2 = new Example();
    e2->deleteMe();
    return 0;
}
