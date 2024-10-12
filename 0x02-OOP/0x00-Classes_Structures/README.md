# Classes and Structures

## Contents
1. [Introduction](#introduction)
2. [Access specifiers](#access-specifiers)
3. [Constructors and Destructors](#constructors-and-destructors)
3. [Static members](#static-members)
3. [Friend Function and Friend Class](#friend-function-and-friend-class)
4. [References](#references)

## Introduction:
**Class** is a user-defined data type in C++ that represents a blueprint for creating objects. It encapsulates data members and member functions that operate on these data members. Objects are instances of classes, and they allow you to model real-world entities by bundling data and functionality together.

**Structure** is a user-defined data type that groups together variables of different data types under a single name. <u>It is similar to a class in that both hold a collection of data of different data types</u>.

There are two main differences between a structure and a class:

* By default, the members of a structure are public, while the members of a class are private.
* A structure will by default not hide its implementation details from whoever uses it in code, while a class by default hides all its implementation details and will therefore by default prevent the programmer from accessing them.

**Note:** We use keywords such as `public`, `private`, and `protected` while using classes or structures. Those keywords are known as <u>access specifiers</u>.

## Access specifiers
**Access specifiers** are keywords that define the visibility and accessibility of class or structure members.

1. Public access:

   The public access specifier allows members to be accessible from outside the class or structure. This creates an interface for external code to interact with.
   ```
   class MyClass {
    public:
        // public class members
    };
    int main()
    {
        MyClass B;
        // can access public member variable
        // B.{name_of_memberVar} = Value
        // can call public member fuctions
        // B.{member_function_name}(params)
        return 0;
    }
   ```

2. Private Access:

   The private access specifier restricts access to members within the class or structure. Private members are hidden from external access, allowing the class or structure to control its internal state.
    ```
    class MyClass {
    private:
        // private class members
        int x;
        void print()
        {
            std::cout<<"Hello from MyClass"<<std::endl;
        }
    };
    int main()
    {
        MyClass B;
        // can't access the private members
        B.x = 50 // error: 'int MyClass::x' is private within this context
        return 0;
    }
   ```

3. Protected Access:

   The protected access specifier is similar to private but allows access to derived classes. It is often used in the context of inheritance.
   ```
   #include <iostream>
   using namespace std;

    class Base {
       protected:
          int x;
    };

    class Derived : public Base {
    public:
        void set(int a) {
            x = a;// x can be accessed in derived class
        }
        void display() {
            cout << "The value of x is: " << x << endl;
        }
    };

    int main() {
        Derived d;
        d.set(25);
        d.display();
        return 0;
    }
   ```
4. Default Access:

   If no access specifier is specified in a class, members are private by default. In structures, members are public by default if no access specifier is provided.
   ```
   class DefaultAccessClass {
        int privateVar;  // private by default
    public:
        int publicVar;
    };
    struct DefaultAccessStruct {
        int publicVar;   // public by default
    };
   ```

## Constructors and Destructors
**Constructors and destructors** are special functions in object-oriented programming that are used to initialize and clean up objects. They are used to create and destroy objects, respectively.

There are four types of constructors in C++:

* <b>Default constructor:</b> This is the constructor that takes no arguments. It is called when an object is created without any arguments.
* <b>Parametrized constructor:</b> This is the constructor that takes arguments. It is used to initialize the object with specific values.
* <b>Copy constructor:</b> This is the constructor that is used to create a new object from an existing object. It is called when an object is passed as an argument to a function or when an object is assigned to another object.
* <b>Move constructor:</b> This is the constructor that is used to create a new object from an existing object in a more efficient way. It is called when an object is passed as an argument to a function or when an object is assigned to another object.

**Destructors** are used to clean up objects and free up memory. They are called automatically when an object is destroyed. Destructors are also used to deallocate memory that was allocated by the object.

In summary, constructors are used to initialize objects, destructors are used to clean up objects, and there are four types of constructors: default, parametrized, copy, and move constructor.

## Static members
static member variables and static member functions are features associated with the class itself rather than instances of the class.

### Static Member Variables:
**Definition:** A static member variable is a class variable that belongs to the class rather than to any specific instance of the class.
There is only one copy of a static member variable for the entire class, regardless of how many objects of that class are created.

It is declared using the static keyword. **It should be initialized outside the class**, typically in the source file.
```
class MyClass {
public:
    static int staticVar; // Declaration
};
// Initialization (outside the class)
int MyClass::staticVar = 0;
```

### Static Member Functions:
**Definition:** A static member function is a function that belongs to the class rather than a specific instance of the class.
It can be called on the class itself, not requiring an instance of the class to invoke the function.
Declaration:

It is declared using the static keyword.

**Important:** <u>Static Member Functions can only access static member variables and other static member functions</u>.
```
class MyClass {
public:
    static void staticFunction() {
        cout << "Static function" << endl;
    }
};
```
## Friend Function and Friend Class
**A friend function** is a function that is not a member of a class but is granted the same access privileges as if it were a member. friend functions are often used to allow external functions or other classes to access private or protected members of a class.

**A friend Class** is a class that is granted access to the private and protected members of another class. Like friend functions, friend classes allow specific external classes to access otherwise restricted members.

## References:
* [When should you use a class vs a struct in C++?](https://stackoverflow.com/questions/54585/when-should-you-use-a-class-vs-a-struct-in-c)
* [Difference Between Structure and Class in C++](https://www.geeksforgeeks.org/structure-vs-class-in-cpp/)
* [Object Oriented Programming in C++](https://www.geeksforgeeks.org/object-oriented-programming-in-cpp/)
* [Classes](https://en.cppreference.com/w/cpp/language/classes)
