#include <iostream>

class MyClass {
private:
    int privateVar;
public:
    MyClass(int val) : privateVar(val) {}

    // Declaration of a friend function
    friend void displayPrivateVar(const MyClass& obj);
    // Declaration of a friend class
    friend class FriendClass;
};
// Definition of the friend function
void displayPrivateVar(const MyClass& obj) {
    std::cout << "PrivateVar from friend function: " << obj.privateVar << std::endl;
}

class FriendClass {
public:
    // virtual will be discussed later
    /*virtual*/ void displayPrivateVar(const MyClass& obj) {
        std::cout << "PrivateVar from friend class: " << obj.privateVar << std::endl;
    }
};

/**
 * the base class of Derived1 is FriendClass
*/
class Drived1 : public FriendClass
{
public:
    Drived1(){
        std::cout << "Drived1\n";
    }
    // uncomment the following function with uncomment virtual
    //+ in base class then run and see the result.
    // void displayPrivateVar(const MyClass& obj) override
    // {
    //     std::cout << "PrivateVar from Drived1 " << obj.privateVar << std::endl;
        // the privateVar is private in base class
    // }

    // also try this function
    // void displayPrivateVar2(const MyClass& obj)
    // {
        //std::cout << "PrivateVar from Drived1 " << obj.privateVar << std::endl; // error
        // the privateVar is private in base class
    // }
};

/**
 * the base class of Derived2 is MyClass
*/
class Drived2 : public MyClass
{
public:
    // Note: if you do not add MyClass(10) an error will occure
    //+ the reason why error happen will be discussed in inheritance section.
    Drived2(int var): MyClass(var)
    {
        std::cout << "parameterized Drived2\n";
    }
};


int main() {
    MyClass myObject(42);

    // Creating an object of FriendClass and accessing privateVar
    FriendClass myFriend;
    myFriend.displayPrivateVar(myObject);

    Drived2 d2(10);
    Drived1 d1;
    // commenting virtual and overriden fuction will cause
    //+ calling displayPrivateVar from base class (Myclass).
    d1.displayPrivateVar(myObject);
    
    myFriend.displayPrivateVar(d2);
    myFriend.displayPrivateVar(myObject);
    d1.displayPrivateVar(d2);
    displayPrivateVar(myObject);
    displayPrivateVar(d2);
    

    return 0;
}
