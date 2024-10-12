#include <iostream>

// Class with a non-virtual destructor (BAD EXAMPLE)
class BaseNonVirtual {
public:
    // Non-virtual destructor
    ~BaseNonVirtual() {
        std::cout << "BaseNonVirtual destructor\n";
    }
};

class DerivedNonVirtual : public BaseNonVirtual {
public:
    // Destructor of derived class
    ~DerivedNonVirtual() {
        std::cout << "DerivedNonVirtual destructor\n";
    }
};

// Class with a virtual destructor (GOOD EXAMPLE)
class BaseVirtual {
public:
    // Virtual destructor
    virtual ~BaseVirtual() {
        std::cout << "BaseVirtual destructor\n";
    }
};

class DerivedVirtual : public BaseVirtual {
public:
    // Destructor of derived class
    ~DerivedVirtual() override {
        std::cout << "DerivedVirtual destructor\n";
    }
};

int main() {
    // Example without virtual destructor (BAD)
    std::cout << "Deleting a DerivedNonVirtual object via a BaseNonVirtual pointer:\n";
    BaseNonVirtual* obj1 = new DerivedNonVirtual();
    delete obj1;  // Only BaseNonVirtual's destructor will be called, DerivedNonVirtual's destructor will be skipped

    std::cout << "\n";

    // Example with virtual destructor (GOOD)
    std::cout << "Deleting a DerivedVirtual object via a BaseVirtual pointer:\n";
    BaseVirtual* obj2 = new DerivedVirtual();
    delete obj2;  // Both DerivedVirtual's and BaseVirtual's destructors will be called

    return 0;
}
