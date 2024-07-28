#include <iostream>

class Example {
private:
    int x;
public:
    Example(int val) : x(val) {}
    friend void showX(const Example& e);
    // friend void perintX() {
    //     std::cout << "print x = " << x << std::endl; // error
    //     std::cout << "print x = " << this.x << std::endl; // error
    // }
};

class Derived : public Example {
public:
    Derived(int val) : Example(val) {}
};

void showX(const Example& e) {
    std::cout << "X: " << e.x << std::endl;
}

int main() {
    Example ex(10);
    showX(ex); // Output: X: 10

    Derived d(20);
    showX(d); // Output: X: 20
    return 0;
}
