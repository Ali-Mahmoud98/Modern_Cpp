// Example 1:

// #include <iostream>
// #include <memory>

// class MyClass {
// public:
//     MyClass() {
//         std::cout << "MyClass Constructor" << std::endl;
//     }

//     ~MyClass() {
//         std::cout << "MyClass Destructor" << std::endl;
//     }

//     void performTask() {
//         std::cout << "Task in MyClass" << std::endl;
//     }
// };

// int main() {
//     // Using std::unique_ptr for ownership transfer
//     std::unique_ptr<MyClass> uniquePtr = std::make_unique<MyClass>();
//     std::cout << "u: " << uniquePtr.get() << std::endl;
//     uniquePtr->performTask();

//     {
//     // Transfer ownership to another std::unique_ptr
//     std::unique_ptr<MyClass> transferredPtr = std::move(uniquePtr);
//     // std::unique_ptr<MyClass> transferredPtr2 = uniquePtr; // this will cause error
//     uniquePtr->performTask();
//     transferredPtr->performTask();
//     std::cout << "u: " << uniquePtr.get() << std::endl;
//     std::cout << "t: " <<transferredPtr.get() << std::endl;

//     }

//     // Using std::shared_ptr for shared ownership
//     std::shared_ptr<MyClass> sharedPtr1 = std::make_shared<MyClass>();
//     std::shared_ptr<MyClass> sharedPtr2 = sharedPtr1;  // Shared ownership

//     return 0;
// }

// Example 2: (Geeks For Geeks example)
// C++ program to demonstrate the working of unique_ptr
// Here we are showing the unique_pointer is pointing to P1.
// But, then we remove P1 and assign P2 so the pointer now
// points to P2.

#include <iostream>
using namespace std;
// Dynamic Memory management library
#include <memory>

class Rectangle {
	int length;
	int breadth;

public:
	Rectangle(int l, int b)
	{
		length = l;
		breadth = b;
	}

	int area() { return length * breadth; }
};

int main()
{
// --\/ Smart Pointer
    // unique_ptr<Rectangle> P1(new Rectangle(10, 5));
	unique_ptr<Rectangle> P1 = make_unique<Rectangle>(10, 5);
	cout << P1->area() << endl; // This'll print 50

	// unique_ptr<Rectangle> P2(P1);
	unique_ptr<Rectangle> P2;
	P2 = move(P1); // p2 will steal the p1
    // the control moved to p2; p1 is freed

	// This'll print 50
	cout << P2->area() << endl;

	// cout<<P1->area()<<endl;// this will cause segmentation fault
	return 0;
}
