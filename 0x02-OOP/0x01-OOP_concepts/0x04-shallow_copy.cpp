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

// Run the following code and see the output
// NOTE: It is not good to use lvalue reference in class attributes

class Shallow {
    int x; // lvalue
    int& y; // lvalue reference -> it is not good to make lvalue reference in class attributes
    int* z; // lvalue
public:
    Shallow(int val) : x(5), y(val) {
        z = new int(5);
    }
    Shallow(int val, int& val2) : x(val), y(val2) {
        // to correctly assigne value to y make int& val2
        // the y will be alias of the lvalue passed to the constructor
        // if did not use int& val2 and used int val2 then the y will get garbage value
        z = new int(5); // dyanamic memory allocation
    }
    Shallow(const Shallow& other) = default; // copy constructor
    Shallow& operator=(const Shallow& other) { // assignment operator
        std::cout << "Copy assignment operator called" << std::endl;
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }
    void print() {
        std::cout << "x = " << x << " , address = " << &x << "" << std::endl;
        // the value of y will be garbage value because it is an lvalue reference
        std::cout << "y = " << y  << " , address = " << &y << std::endl;
        std::cout << "z = " << z  << "z is pointer" << std::endl;
        std::cout << "*z = " << *z << std::endl;
    }
    void changeY(int val) {
        y = val;
    }
    void changeX(int val) {
        x = val;
    }
    ~Shallow() {
        delete z;
    }
};

class Shallow2 {
    int &y;
public:
    Shallow2(int val) : y(val) {}
    Shallow2(const Shallow2& other) = default;
    void print() {
        std::cout << "y = " << y << " , address = " << &y << std::endl;
    }
    void changeY(int val) {
        y = val;
    }
    ~Shallow2() {
        std::cout << "Shallow2 destructor called" << std::endl;
    }
};

int main() {
    int x = 17;
    Shallow obj1(10, x);
    Shallow obj2 = obj1;
    Shallow obj3(0,x);
    obj3 = obj1;
    std::cout << "obj1: " <<std::endl;
    obj1.print();
    obj1.changeY(20); // the value of y will be changed in all objects
    obj1.changeX(30); // this line will only change x in obj1
    // obj1.print();
    std::cout << "obj2: " <<std::endl;
    obj2.print();
    x = 40;
    std::cout << "obj3: " <<std::endl;
    obj3.print();
    std::cout << "----------------" << std::endl;
    Shallow obj4(10);
    Shallow obj5 = obj4;
    std::cout << "obj4: " <<std::endl;
    obj4.print();
    obj4.changeY(20);
    std::cout << "obj5: " <<std::endl;
    obj5.print();
    std::cout << "----------------" << std::endl;
    {
        Shallow2 obj6(800);
        Shallow2 obj7 = obj6;
        std::cout << "obj6: " <<std::endl;
        obj6.print();
        std::cout << "obj7: " <<std::endl;
        obj7.print();
        obj6.changeY(30);
        std::cout << "obj7: " <<std::endl;
        obj7.print();
        std::cout << "obj5: " <<std::endl;
        obj5.print();
        std::cout << "----------------" << std::endl;
    }

    // any change in y and z will be reflected in all objects created by the same class

    // there is a bug in this code because using lvalue reference in class attributes
    //+the address of y of obj5 will be the same address of y in obj6 and obj7, however
    //+the obj5 type is Shallow and obj6 and obj7 type is Shallow2
    
    // see the file 0x05-shallow_copy.cpp. it will contain a good and small code example.
    return 0;
}
