#include <iostream>

using namespace std;

class Base {
public:
    int base_pub;
    Base(): base_priv(1), base_prot(2), base_pub(3) {
        cout << "Base Constructor 1" << endl;
    }
    Base(int base_pub): base_pub(base_pub) {
        cout << "Base Constructor 2" << endl;
    }
protected:
    int base_prot;
private:
    int base_priv;
};

// The derived class inherits the publicity from base class
class Derived : public Base {
protected:
    int derived_prot;
private:
    int derived_priv;
public:
    void display() {
        cout<< "Base Public: " << base_pub <<endl;
        cout<< "Base Protected: " << base_prot <<endl;
        // cout<< "Base Private: " << base_priv <<endl; // this will case error, cannot access private data of Base class from drive class
        cout << "this->base_pub = " << this->base_pub << endl;
        cout << "this->base_prot = " << this->base_prot << endl;
        // cout << "this->base_priv = " << this->base_priv << endl; // this will case error, cannot access private data of Base class from drive class

        cout << "-----------------------------------------" << endl;
        cout << "My derived_prot: " << derived_prot << endl;
        cout << "My derived_priv: " << derived_priv << endl;
        cout << "this->derived_prot = " << this->derived_prot << endl;
        cout << "this->derived_priv = " << this->derived_priv << endl;
    }
    // comment one of the following lines and run
    Derived(): Base(33), derived_priv(11), derived_prot(22) { // this will print base_pub = 3
        cout << "Drived Constructor" << endl; // the "Base Constructor 2" will be printed before this line
    }
    // Derived(): derived_priv(11), derived_prot(22) { this will print base_pub = 33
    //     cout << "Derived Constructor" << endl; //the "Base Constructor 1" will be printed before this line
    // }

    //Important Note: by default when creating an instance of derived class, the default constructor is called if I did not
    //+ specify which constructor will be called. 
};

class Base2{
public:
    Base2(){
        cout << "Base2 constractor" << endl;
    }
};
class Derived2 : public Base2{
public:
    Derived2(){
        cout << "Derived2 constractor" << endl;
    }
};

int main() {
    Derived2 d2; // the base constructor will be called automatically before the constructor of derived class
    cout<<"--------------------------------"<<endl;
    Derived d;
    cout << "access public variable member from derived class object -> " << d.base_pub << endl;
    d.display();
    return 0;
}
