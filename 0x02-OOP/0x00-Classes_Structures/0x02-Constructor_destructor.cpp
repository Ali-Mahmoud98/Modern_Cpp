#include <iostream>

class MyClass
{
    //var2 is private by default
    int var2;
public:
    int publicVar;
    // Constructor: is a member function that is called every time
    //+ we create a new instance of the class.
    // default constructor
    MyClass()
    {
        std::cout<<"default constructor of MyClass called\n";
    }
    void publicFunction() {
        // the "::"" is called access resolution operator
        std::cout << "Public function in class" << std::endl;
    }
    // destructor: is a member function that is called every time
    //+ the instance or object of the class is destroyed or leaves scope.
    // destructor is a function 
    ~MyClass()
    {
        std::cout<<"MyClass destructor called\n";
    }
    // Note: constructor and destructor are special member functions
};

// Structure with public members (explicit, though not necessary)
struct MyStruct {
    int publicVar1;
    void publicFunction() {
        // the "::"" is called access resolution operator
        std::cout << "Public function in class" << std::endl;
    }
    // default constructor
    MyStruct()
    {
        std::cout<<"default constructor called\n";
    }
    ~MyStruct()
    {
        std::cout<<"default constructor called\n";
    }
// to make publicVar2 private replace public with private
public:
    int publicVar2;
};

int main()
{
    MyClass cl;
    MyStruct st;

    cl.publicVar = 5;
    cl.publicFunction();
    // cl.var2 = 30; // member "MyClass::var2" (declared at line 5) is inaccessible

    st.publicVar1 = 50;
    st.publicVar2 = 20;
    st.publicFunction();

    return 0;
}
