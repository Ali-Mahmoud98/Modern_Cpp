# Nested Classes in C++
A nested class is a class which is declared in another enclosing class. A nested class is a member and as such has the same access rights as any other member. The members of an enclosing class have no special access to members of a nested class; the usual access rules shall be obeyed.

## Program 1
```c++
#include<iostream> 

using namespace std; 

/* start of Enclosing class declaration */
class Enclosing {	 
private: 
	int x; 
	
/* start of Nested class declaration */
class Nested { 
	int y; 
	void NestedFun(Enclosing *e) { 
		cout<<e->x; // works fine: nested class can access 
					// private members of Enclosing class 
	}	 
}; // declaration Nested class ends here 
}; // declaration Enclosing class ends here 

int main() 
{	 

} 
```
## Program 2
```c++
#include<iostream> 

using namespace std; 

/* start of Enclosing class declaration */
class Enclosing {	 
		
int x; 
	
/* start of Nested class declaration */
class Nested { 
	int y; 
}; // declaration Nested class ends here 

void EnclosingFun(Nested *n) { 
		cout<<n->y; // Compiler Error: y is private in Nested 
}	 
}; // declaration Enclosing class ends here 

int main() 
{ 
	
} 
```
