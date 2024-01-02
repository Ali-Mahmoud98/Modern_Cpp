#include <iostream>
#include <utility>

// Function that takes an rvalue reference
void moveResource(int&& source) {
    std::cout<<"Starting function moveResource\n";
    // Do something with the resource (in this case, just print)
    std::cout << "Moved Resource: " << source << std::endl;
    std::cout<<"ending function moveResource\n";
}

// Function that takes an rvalue reference
void moveResource2(std::string&& source) {
    std::cout<<"Starting function moveResource2\n";
    // Do something with the resource (in this case, just print)
    std::cout << "Moved Resource: " << source << std::endl;
    std::cout<<"ending function moveResource2\n";
}

// Function that takes an rvalue reference
void moveResource3(std::string source) {
    std::cout<<"Starting function moveResource2\n";
    // Do something with the resource (in this case, just print)
    std::cout << "Moved Resource: " << source << std::endl;
    std::cout<<"ending function moveResource2\n";
}

int main() {
    int original = 42;

    // Create an rvalue reference using std::move
    int&& movedValue = std::move(original);

    // try the below line: comment it then run and uncomment it then run 
    // int var = std::move(movedValue);
    // std::cout << "var Value: " << var << std::endl;

    // The original value is no longer accessible here
    std::cout << "Original Value: " << original << std::endl;

    // Pass an rvalue to a function
    moveResource(std::move(original));

    std::cout<<"\nTesting move with string\n";
    std::string s1 = "Hello";
    std::string s2 = "World";

    std::string&& str_rvref = std::move(s1);

    // try the below line: comment it then run and uncomment it then run 
    // std::string s3 = std::move(s1); // this line will steal the value of s1 and str_rvref
    
    // try the below line: comment it then run and uncomment it then run 
    // std::string s3 = std::move(str_rvref); // this line will steal the value of s1 and str_rvref
    // std::cout<<"s3 : "<< s3 << std::endl;

    std::cout<< "s1 after std::move(s1) : " << s1 << std::endl;
    std::cout<< "str_rvref after std::move(s1) : " << str_rvref << std::endl;
    std::cout<< "s2 before moveResource2(std::move(s2)) : " << s2 << std::endl;

    moveResource2(std::move(s2));
    std::cout<< "s2 after moveResource2(std::move(s2)) : " << s2 << std::endl;

    std::cout<< "\ns2 before moveResource3(std::move(s2)) : " << s2 << std::endl;
    moveResource3(std::move(s2));
    std::cout<< "s2 after moveResource3(std::move(s2)) : " << s2 << std::endl;


    return 0;
}
