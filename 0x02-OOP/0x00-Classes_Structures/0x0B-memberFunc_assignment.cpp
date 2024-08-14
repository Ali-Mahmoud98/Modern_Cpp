#include <iostream>

class MyClass1 {
    int x;
public:
    MyClass1(int val) : x(val) {}

    // MyClass1(int val)= default; // this will cause error
    /**
     * The  default syntax can only be used for special member
     * functions that the compiler can generate by default.
     * These include:
     * - Default constructor: MyClass1() = default;
     * - Copy constructor: MyClass1(const MyClass1&) = default;
     * - Move constructor: MyClass1(MyClass1&&) = default;
     * - Copy assignment operator: MyClass1& operator=(const MyClass1&) = default;
     * - Move assignment operator: MyClass1& operator=(MyClass1&&) = default;
     * - Destructor: ~MyClass1() = default;
     * 
     * MyClass1(int val) is a user-defined constructor.
     */
};

class MyClass2 {
    int x;
public:
    // MyClass2() = delete; // this line will delete the default constructor
    // and an error will be generated if you uncomment this line in the line 38
};

class MyClass3 {
    int x;
public:
    MyClass3() = default;
    MyClass3(const MyClass3&) {
        std::cout << "MyClass3 -> Copy constructor called" << std::endl;
    }
    MyClass3(MyClass3&&){
        std::cout << "MyClass3 -> Move constructor called" << std::endl;
    }
    MyClass3& operator=(const MyClass3&) = default;
    MyClass3& operator=(MyClass3&&) {
        std::cout << "MyClass3 -> Move assignment operator called" << std::endl;
        return *this;
    }
    ~MyClass3() = default;
};

class MyClass4 {
    int x;
public:
    MyClass4() = default;
    MyClass4(const MyClass4&) = default;
    MyClass4(MyClass4&&) = default;
    MyClass4& operator=(const MyClass4&) = delete;
    MyClass4& operator=(MyClass4&&) = delete;
    void operator=(const int y){
        x = y;
        std::cout << "MyClass4 -> operator=(const int y) called" << std::endl;
    }
    void print() {
        std::cout << "x = " << x << std::endl;
    }
};

int main() {
    // MyClass1 obj1; // this will cause error
    /**
     * if the user defined parametrized constructor and did not define
     * the default constructor then the compiler will not generate the default
     * constructor for the class.
     */ 
    MyClass2 obj2;// this will not cause error because the compiler will
    // generate the default constructor
    MyClass2 obj3 = obj3; // this will not cause error because the compiler will
    // generate the copy constructor

    MyClass3 class3Obj1;// default constructor is called
    MyClass3 class3Obj2;
    MyClass3 class3Obj3;
    class3Obj1 = class3Obj2; // copy constructor is called
    class3Obj3 = std::move(class3Obj2); // operator=(MyClass3&) is called
    MyClass3 class3Obj4 = std::move(class3Obj3); // move constructor is called
    MyClass3 class3Obj5(std::move(class3Obj4));// move constructor is called
    MyClass3 class3Obj6(static_cast<MyClass3&&>(class3Obj5));// move constructor is called

    MyClass4 obj4;
    obj4 = 10; // the operator overloading will be called -> operator=(const int y)
    obj4.print();

    return 0;
}