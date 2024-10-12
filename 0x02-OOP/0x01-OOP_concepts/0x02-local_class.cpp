#include <iostream>

/** start of local class definition
 * A class declared inside a function becomes local to that function and
 * is called Local Class in C++.
 * A local class name can only be used locally i.e., inside the function
 * and not outside it. The methods of a local class must be defined inside
 * it only. A local class can have static functions but, not static data members.
 */
void foo() {
    std::cout << "Entered foo()" << std::endl;
    // Local Class
    class MyClass {
        public:
            void print() {
                std::cout << "Hello World!" << std::endl;
            }
    };

    MyClass myObj;
    myObj.print();
    std::cout << "Exited foo()" << std::endl;
}
// MyClass myObj;// error - MyClass is a local class
            // variable "MyClass" is not a type name
// NOTE1: A local class type name can only be used in the enclosing function.
// NOTE2: All the methods of Local classes must be defined inside the class only
// NOTE3: A local class can have static functions but, not static data members.
void bar() {
    std::cout << "Entered bar()" << std::endl;
    // Local Class
    class MyClass {
        // see NOTE3
        // static int i; // static data member
                    // error: static data member declaration is not allowed in this class
        // private static function
        static void print_private() {
            std::cout << "Entered print_private" << std::endl;
            std::cout << "Hello World!" << std::endl;
            std::cout << "Exited print_private" << std::endl;
        }
        public:
            static void print_public() {
                std::cout << "Entered print_public" << std::endl;
                print_private();
                std::cout << "Exited print_public" << std::endl;
            }
            void print() {
                std::cout << "Hello World!" << std::endl;
            }
    };

    // MyClass::print_private(); // error: function "MyClass::print_private" (declared at line 37) is inaccessible
    MyClass::print_public();
    MyClass myObj;
    myObj.print();
    std::cout << "Exited bar()" << std::endl;
}

// NOTE4: Member methods of the local class can only access static and enum
//+ variables of the enclosing function. Non-static variables of the enclosing
//+ function are not accessible inside local classes.
// NOTE5: Local classes can access global types, variables, and functions. Also,
//+ local classes can access other local classes of the same function.
int bla = 5;
static int bla2 = 6;
void fun()
{
    std::cout << "Entered fun()" << std::endl;
    static int x;
    enum { i = 1, j = 2 };

    int y;

    // Local class
    class Test {
        int y;
        int z = x; // works fine
        int w = i; // works fine
        int v = j; // works fine
    public:
        void method()
        {
            std::cout << "Entered method()" << std::endl;
            bla = 8;// works fine: can access global variable bla
            bla2 = 9;// works fine: can access static global variable bla2
            x = 5; // works fine: Member methods of the local class can access static variables in fun()
            // y = 7; // error: reference to local variable of enclosing function is not allowed
            std::cout << "x = " << x
                 << std::endl; // fine as x is static
            std::cout << "i = " << i
                 << std::endl; // fine as i is enum
            std::cout << "Exited method()" << std::endl;
        }
    };

    class Test2 {
        Test t;
    public:
        void method2(){
            std::cout << "Entered method2()" << std::endl;
            t.method();
            std::cout << "Exited method2()" << std::endl;
        }
    };

    Test t;
    t.method();
    Test2 t2;
    t2.method2();
    std::cout << "Exited fun()" << std::endl;
}

int main() {
    foo();
    std::cout << "-----------------" << std::endl;
    bar();
    std::cout << "-----------------" << std::endl;
    fun();
    // MyClass myObj;// error - variable "MyClass" is not a type name
    return 0;
}
