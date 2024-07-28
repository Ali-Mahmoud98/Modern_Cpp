#include <iostream>

// EXAMPLE 1:
// class Base {
// public:
//     // removing virtual keyword from function in the base class will cause error
//     // if the function in the drived class use override keyword
//     virtual void show() {
//         std::cout << "Base show" << std::endl;
//     }
// };

// class Derived : public Base {
// public:
//     // override keyword tells the compiler to use the override version of the function
//     // if you don't use override, the compiler will use the version from the base class
//     // if you removed virtual keyword from function in the base class it will cause error
//     void show() override {
//         std::cout << "Derived show" << std::endl;
//     }
// };

// EXAMPLE 2:
// to see the effect of the override keyword and virtual keyword
// class Base {
// public:
//     virtual void show() {
//         std::cout << "Base show" << std::endl;
//     }
// };

// class Derived : public Base {
// public:
//     void show() {
//         std::cout << "Derived show" << std::endl;
//     }
// };

// EXAMPLE 3:
class Base {
public:
    void show() {
        std::cout << "Base show" << std::endl;
    }
};

class Derived : public Base {
public:
    void show() {
        std::cout << "Derived show" << std::endl;
    }
};

// EXAMPLE 4:
// this example will cause error
// class Base {
// public:
//     void show() {
//         std::cout << "Base show" << std::endl;
//     }
// };

// class Derived : public Base {
// public:
//     void show() override{
//         std::cout << "Derived show" << std::endl;
//     }
// };


// use all examples and see the output
int main() {
    Base* b = new Derived();
    b->show(); // see the output
    delete b;

    std::cout << "---------------- " << std::endl;
    Base b2;
    b2.show(); // see the output
    Derived d;
    d.show(); // see the output

    return 0;
}
