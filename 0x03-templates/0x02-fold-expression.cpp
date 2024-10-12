// C++ program to demonstrate working of
// Variadic function Template
#include <iostream>
using namespace std;

template <typename T>
void printVar(T var) {
    cout << var << endl;
}

template <typename T, typename... Types>
void print(T var1, Types... var2)
{
	cout << var1 << endl;
    (printVar(var2), ...); // Fold expression to print the remaining arguments
    // cout << endl;
}

// Driver code
int main()
{
	print(1, 2, 3.14,
		"Pass me any "
		"number of arguments",
		"I will print\n");

	return 0;
}
