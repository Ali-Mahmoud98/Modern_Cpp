#include <iostream>

// Base class
class Base {
public:
    Base() {
        std::cout << "Base constructor called" << std::endl;
    }
    virtual void show() {
        std::cout << "Base class show function" << std::endl;
    }
};

// Derived class 1
class Derived1 : virtual public Base {
public:
    Derived1() {
        std::cout << "Derived1 constructor called" << std::endl;
    }
    void show() override {
        std::cout << "Derived1 class show function" << std::endl;
    }
};

// Derived class 2
class Derived2 : virtual public Base {
public:
    Derived2() {
        std::cout << "Derived2 constructor called" << std::endl;
    }
    void show() override {
        std::cout << "Derived2 class show function" << std::endl;
    }
};

// Derived class 3 inheriting from Derived1 and Derived2
class Derived3 : public Derived1, public Derived2 {
public:
    Derived3() {
        std::cout << "Derived3 constructor called" << std::endl;
    }
    void show() override {
        std::cout << "Derived3 class show function" << std::endl;
    }
};

class Derived4 : public Base {
public:
    Derived4() {
        std::cout << "Derived4 constructor called" << std::endl;
    }
    void show() override {
        std::cout << "Derived4 class show function" << std::endl;
    }
};
class Derived5 : public Base {
public:
    Derived5() {
        std::cout << "Derived5 constructor called" << std::endl;
    }
    void show() override {
        std::cout << "Derived5 class show function" << std::endl;
    }
};
class Derived6 : public Derived4, public Derived5 {
public:
    Derived6() {
        std::cout << "Derived6 constructor called" << std::endl;
    }
    void show() override {
        std::cout << "Derived6 class show function" << std::endl;
    }
};

int main() {
    Derived6 d6;
    d6.show();
    std::cout << std::endl;
    std::cout << std::endl;
    Derived3 d3;
    d3.show();

    std::cout << std::endl;
    std::cout << std::endl;
    Derived2 d2;

    return 0;
}

/**
 * How Virtual Inheritance Works
 * Single Instance: With virtual inheritance, there is only one instance of the virtual base class (Base) in any derived class,
 * regardless of how many times it is inherited.
 * 
 * Initialization: When constructing an object of class Derived6, the constructor of Base is called only once, and it’s the responsibility
 * of the most derived class (Derived6) to initialize the virtual base class.
 * 
 * Accessing Members: Since there’s only one instance of Base, there’s no ambiguity when accessing its members from an object of Derived6.
 * This means you can directly call obj.show() without worrying about which instance of Base you are referencing.
*/