#include <iostream>

/**
 * Shallow Copy and Deep Copy in C++:
 * In general, creating a copy of an object means to create an exact replica of
 * the object having the same literal value, data type, and resources. There are
 * two ways that are used by C++ compiler to create a copy of objects.
 * the two ways are:
 * - Copy Constructor -> MyClass obj1(obj); OR MyClass obj1 = obj;
 * - Copy Assignment (Assignment Operator) -> MyClass obj1; obj1 = obj;
 */

// uncomment lines that uses static variable if you want to use static variable to solve double free error
class Shallow {
    // static int x;
    int y;
    int* z; 
public:
    Shallow(int val) : y(val) {
        // x++;
        z = new int(5);
    }
    Shallow(const Shallow& other) = default;
    void print() {
        std::cout << "y = " << y << " , address = " << &y << std::endl;
        std::cout << "z is pointer that points to address: " << z << std::endl;
        std::cout << "the value inside address (" << z << ") is: " << *z << std::endl;
        std::cout << "the address of z is: " << &z << std::endl;
    }
    void changeY(int val) {
        y = val;
    }
    void changeZ(int val) {
        *z = val;
    }
    ~Shallow() {
        // if (x != 0)
        // {
        //     delete z;
        //     x--;
        // }
        delete z;
        std::cout << "Shallow destructor called" << std::endl;
    }
};

// int Shallow::x = 0;

int main() {
    Shallow obj1(10);
    Shallow obj2 = obj1;
    std::cout << "obj1: " <<std::endl;
    obj1.print();
    std::cout << "\nobj2: " <<std::endl;
    obj2.print();
    obj2.changeY(20); // the value of y will be changed in only obj2
    obj2.changeZ(30); // the value of z will be changed in all objects
    std::cout << "\nobj1: " <<std::endl;
    obj1.print();
    std::cout << "\nobj2: " <<std::endl;
    obj2.print();
    // the destructor of obj2 will be called first and then obj1(double free will happen)
    // obj1 z and obj2 z will are pointing to same address -> this will lead to:
    // free(): double free detected in tcache 2
    // Aborted (core dumped)
    // this problem can be solved using static classe attribute or deep copy -> according your application
    // see the 0x06-deep_copy.cpp
    return 0;
}

