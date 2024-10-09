// C++ program to demonstrate working of
// Variadic function Template
#include <iostream>
using namespace std;

template <typename T, typename... Types>
void print(T var1, Types... var2)
{
	cout << var1 << endl;
    (cout << ... << var2)<<endl; // Fold expression to print the remaining arguments
	// C++17 fold expression
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
