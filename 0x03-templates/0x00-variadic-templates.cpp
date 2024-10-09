// C++ program to demonstrate working of
// Variadic function Template
#include <iostream>
using namespace std;

int count = 1;

// To handle base case of below recursive
// Variadic function Template
void print()
{
    static int count1 = 1;
	cout << "I am empty function and "
			"I am called at last.\n";
    cout << " >> The print() called " << count1++ << " times\n";
}

// Variadic function Template that takes
// variable number of arguments and prints
// all of them.
template <typename T, typename... Types>
void print(T var1, Types... var2)
{
	cout << var1 << endl;
    cout << " >> The variadic func print called " << count++ << " times\n";
	print(var2...); // here is recursion
    // this function will be called 1 + numOfparams times
    // but it will cause error when at the call number (num Of variadic params)
    // the error is like: no matching function for call to ‘print()’
    // So we will need to add a function "print()" that should not take any arguments
}

// Driver code
int main()
{
	print(1, 2, 3.14,
		"Pass me any "
		"number of arguments",
		"I will print\n"); // the number of parameters here is 6
        // the template function with variadic templates will be called 5 times => see the function: void print(T var1, Types... var2)
        // the 5 is the number of params passed to var2.
        // at first call the 1 and 2 will be printed then do recursion by calling print(3.14).
        // at the second call the 3.14 will be printed then do recursion by calling print("Pass me any ") and so on.
        // at the last call the when executing print("I will print\n") the message will be printed then the function print() will be called at last.
        // So You Need To Make A Function Which Take no Parameters to avoid errors.

	return 0;
}
