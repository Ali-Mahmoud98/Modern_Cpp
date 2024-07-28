#include <iostream>

/**
 * Note: Some operators cannot be overloaded which include sizeof operator,
 * typeid, Scope resolution (::), Class member access operator (.),
 * Ternary or conditional operator (?:)
 */
class MyClass
{
public:
    std::string name;
    int age;

    MyClass();//default constructor
    MyClass(std::string n, int num);//parametrized constructor
    MyClass(MyClass& other);//copy constructor
    MyClass(MyClass&& other);//move constructor
    ~MyClass();//destructor
    MyClass& operator=(const MyClass& other);// operator overloading
    // the proto type of operator overloading function:
    // retType operator{operator like =, or ==}(paramType1 param1, paramType2 param2, ...)
    
    // Define the operator<< function for the MyClass class.
    // With this operator<< function defined, you can now use it to print MyClass objects to the console
    friend std::ostream& operator<<(std::ostream& os, const MyClass& obj) {
        os << obj.name << " (" << obj.age << " years old)";
        return os;
    }
};
// Note: ":name(""), age(0)" is called member initialization list
//default constructor
MyClass::MyClass():name(""), age(0) 
{
    std::cout<<"*** default constructor called ***\n";
}
//parametrized constructor
MyClass::MyClass(std::string n, int num):name(n), age(num) 
{
    std::cout<<"*** parametrized constructor called ***\n";
}
//copy constructor
MyClass::MyClass(MyClass& other)
{
    std::cout<<"*** copy constructor called ***\n";
    name = other.name;
    age = other.age;
}
//move constructor
MyClass::MyClass(MyClass&& other): name(std::move(other.name)),
                                    age(other.age)
{
    std::cout<<"*** move constructor called ***\n";
    other.age = 0;
}

MyClass& MyClass::operator=(const MyClass& other) {
    std::cout << "Operator overloading\n";
    name = other.name;
    age = other.age;
    return *this;
}

//destructor
MyClass::~MyClass()
{
    std::cout<<"** Destructor called **\n";
}

int main()
{
    MyClass c1;// default constructor called
    c1.name = "Ahmed";
    c1.age = 30;
    std::cout << "C1: " << c1.name << " (" << c1.age << " years old)" << std::endl;
    
    MyClass c2("Ali", 25);// parametrized constructor called
    std::cout << "C2: " << c2.name << " (" << c2.age << " years old)" << std::endl;

    MyClass c3 = c2;// copy constructor called
    std::cout << "C2: " << c2.name << " (" << c2.age << " years old)" << std::endl;
    std::cout << "C3: " << c3.name << " (" << c3.age << " years old)" << std::endl;

    MyClass c4(std::move(c2));// move constructor called
    std::cout << "C2: " << c2.name << " (" << c2.age << " years old)" << std::endl;
    std::cout << "C4: " << c4.name << " (" << c4.age << " years old)" << std::endl;

    // try this
    std::cout<<"-------\n";
    std::cout<<"-------\n";
    MyClass&& c5 = std::move(c4);
    std::cout << "C4: " << c4.name << " (" << c4.age << " years old)" << std::endl;
    std::cout << "C5: " << c5.name << " (" << c5.age << " years old)" << std::endl;
    std::cout << "ref C4 = " << &c4 << ", ref C5 = "<< &c5 << std::endl;

    MyClass c6(c5); // copy constructor called
    std::cout << "C5: " << c5.name << " (" << c5.age << " years old)" << std::endl;
    std::cout << "C6: " << c6.name << " (" << c6.age << " years old)" << std::endl;

    std::cout << "-----------\n";
    std::cout << "-----------\n";
    //*********** try following lines and see erroe messages *********
    MyClass c7;// default constructor called
    c7 = c1; // operator overloading
    std::cout << "C1: " << c1.name << " (" << c1.age << " years old)" << std::endl;
    std::cout << "C7: " << c7.name << " (" << c7.age << " years old)" << std::endl;
    std::cout << "C7: " << c7;

    return 0;
}
