#include <iostream>

class Example {
private:
    int x;
public:
    Example(int val) : x(val) {}
    friend class FriendClass;
};

class FriendClass {
public:
    void showX(const Example& e) {
        std::cout << "X: " << e.x << std::endl;
    }
};

class Derived : public Example {
    int x;
public:
    Derived(int val) : Example(val) {}
};

int main() {
    Example ex(10);
    FriendClass fc;
    fc.showX(ex); // Output: X: 10

    Derived d(20);
    fc.showX(d); // Output: X: 20
    fc.showX(ex);
    return 0;
}
