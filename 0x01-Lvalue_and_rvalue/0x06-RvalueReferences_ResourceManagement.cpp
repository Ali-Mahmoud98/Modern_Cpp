#include <iostream>
#include <vector>

class ResourceHolder {
public:
    // Constructor
    ResourceHolder(size_t size) : data(new int[size]), size(size) {
        std::cout << "ResourceHolder Constructor" << std::endl;
    }

    // Move Constructor
    ResourceHolder(ResourceHolder&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;  // Prevent double deletion
        other.size = 0;
        std::cout << "ResourceHolder Move Constructor" << std::endl;
    }

    // Move Assignment Operator
    ResourceHolder& operator=(ResourceHolder&& other) noexcept {
        if (this != &other) {
            delete[] data;  // Release current resources
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
            std::cout << "ResourceHolder Move Assignment Operator" << std::endl;
        }
        return *this;
    }

    // Destructor
    ~ResourceHolder() {
        delete[] data;
        std::cout << "ResourceHolder Destructor" << std::endl;
    }

private:
    int* data;
    size_t size;
};

int main() {
    ResourceHolder original(5);  // Create a ResourceHolder object

    // Move semantics in action
    ResourceHolder movedObject = std::move(original);

    return 0;
}
