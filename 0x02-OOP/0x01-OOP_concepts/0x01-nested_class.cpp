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
            // cout<<e->y; // class "Enclosing" has no member "y"
            cout<<this->y; // works fine.
        }	 
    }; // declaration Nested class ends here 
}; // declaration Enclosing class ends here 

/* start of Enclosing class declaration */  
class Enclosing2 {       
        
   int x; 
     
   /* start of Nested class declaration */  
   class Nested { 
      int y;    
   }; // declaration Nested class ends here 
  
   void EnclosingFun(Nested *n) { 
        // cout<<n->y;  // Compiler Error: y is private in Nested 
        // cout<<n->Nested::y; // Error: member "Enclosing2::Nested::y"
                            // (declared at line 28) is inaccessible
        cout<<this->x;
        // n = new Nested(); //works fine
   }       
}; // declaration Enclosing class ends here 

int main() 
{
    return 0;
} 
