#include <iostream>

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

    //*********** try following lines and see erroe messages *********
    // MyClass c4;// default constructor called
    // c4 = c2; this line will cause error -> need operator overloading

    // c4 = std::move(c2);// this line will cause error -> need operator overloading
    // c4(std::move(c2)); // this will cause error
    // Note: the constructors called only during making instances.
    //*********** after trying comment the line *******

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

    return 0;
}
