#include <iostream>
#include <utility>

// Function template using perfect forwarding
template <typename T>
void processValue(T&& value) {
    // Perform some operations with the forwarded value
    std::cout << "Processing: " << value << std::endl;
}

int main() {
    // Use perfect forwarding with lvalues
    int x = 42;
    processValue(x);

    // Use perfect forwarding with rvalues
    processValue(3.14);

    processValue("Hello");

    std::string s = "World";
    processValue(s);
    std::cout<< "s: " << s << std::endl;
    
    processValue(std::move(s));
    std::cout<< "s: " << s << std::endl;

    return 0;
}
