#include <iostream>
using namespace std;

class Example {
   int x = 20;
   static int var4;
   public:
      // Public static members can be accessed using an instance of the class
      static int count;
      static int var1;
      static const int var2 = 20; // static const variable can be intialized inside class
      static int var3;
      // note: non-static member functions can access static members
      Example() {
         var1 = 5;
         count++;
         // x = 20;// will not cause error
         // var2++; // error because var is constant
      }

      void setX() const // const prevent changing member
      {
         // x = 20; // error
         // the setX() function is declared as const, which means that it
         //+ cannot modify any member variables or data members of the class.
         var1 = 50; // the var1 is a static member variable
         // static member variable can be changed in const member function
      }

      int getVar4() const
      {
         return var4;
      }
      
      //Note : a const type qualifier is not allowed on a static member function
      static int getVar4_2() /*const*/
      {
         return var4;
      }

      static void displayCount() {
         cout << "The total number of objects created is: " << count << endl;
      }
      static void displayCount2() {
         // x = 50;// error because static member function cannot access non-static members
         // this->x = 5;// error because this cannot be used in static member function 
         cout << "The total number of objects created is: " << count << endl;
         cout << "var1 = " << var1 << endl;
         cout << "var2 = " << var2 << endl;
         cout << "uninitialized var3 = " << var3 << endl;
      }
      static void static_func();
};

/**
 * Note: the static member variables must be
 * initialized outside the class like below.
*/
int Example::count = 0;
int Example::var4 = 10;
int Example::var3;
/**
 * Accessing static variable that is not initialized here will cause
 * linker error (undefined reference).
 * try to comment the following 1 line.
*/
int Example::var1;

void Example::static_func()
{
   std::cout << "Hello from static_func\n";
}

int main() {
   Example e1, e2, e3;
   Example::displayCount();
   Example::displayCount2();

   std::cout<< "---------\n";
   std::cout<< "---------\n";
   std::cout<< "count = " << Example::count << std::endl;
   std::cout<< "var1 = " << Example::var1 << std::endl;
   e2.setX();
   std::cout<< "after setX() -> var1 = " << Example::var1 << std::endl;
   std::cout<< "var2 = " << Example::var2 << std::endl;
   std::cout<< "uninitialized var3 = " << Example::var3 << std::endl;
   // std::cout<< "var4 = " << Example::var4 << std::endl; // error beacuse var is private
   std::cout<< "var4 = " << e1.getVar4() << std::endl;
   std::cout<< "var4 = " << Example::getVar4_2() << std::endl;
   std::cout << "------\n";
   std::cout << "------\n";
   e1.static_func();
   Example::static_func();
   return 0;
}
