#include <iostream>

class MyClass {
    mutable int accessCount = 0;
public:
    void increment() const {
        accessCount++;  // Allowed even though this function is const
    }

    int getAccessCount() const {
        return accessCount;
    }
};

int main() {
    const MyClass obj;
    obj.increment();  // Can modify accessCount even though obj is const
    std::cout << obj.getAccessCount() << std::endl;  // Outputs: 1

    std::cout << "-------------------------" << std::endl;

    int counter = 0;

    auto increment = [counter]() mutable {
        counter++;  // This would be an error without 'mutable'
        return counter;
    };

    std::cout << increment() << std::endl;
    std::cout << increment() << std::endl;
    std::cout << increment() << std::endl;
    std::cout << "counter = " << counter << std::endl;
    
    return 0;
}
