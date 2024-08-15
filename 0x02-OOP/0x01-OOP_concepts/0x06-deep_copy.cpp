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

class Deep {
    int y;
    int* z; 
public:
    Deep(int val) : y(val) {
        z = new int(5);
    }
    Deep(const Deep& other){
        y = other.y;
        z = new int(*other.z);
    }
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
    ~Deep() {
        delete z;
        std::cout << "Deep destructor called" << std::endl;
    }
};


int main() {
    Deep obj1(10);
    Deep obj2 = obj1;
    std::cout << "obj1: " <<std::endl;
    obj1.print();
    std::cout << "\nobj2: " <<std::endl;
    obj2.print();
    obj2.changeY(20); // the value of y will be changed in only obj2
    obj2.changeZ(30); // the value of z will be changed in only obj2
    std::cout << "\nobj1: " <<std::endl;
    obj1.print();
    std::cout << "\nobj2: " <<std::endl;
    obj2.print();
    return 0;
}

