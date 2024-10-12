#include <iostream>

class MyClass
{
    //var2 is private by default
    int var2;
public:
    int publicVar;
    void publicFunction() {
        // the "::"" is called access resolution operator
        std::cout << "Public function in class" << std::endl;
    }
};

// Structure with public members (explicit, though not necessary)
struct MyStruct {
    int publicVar1; // struct members are public by default
    void publicFunction() {
        // the "::"" is called access resolution operator
        std::cout << "Public function in class" << std::endl;
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
