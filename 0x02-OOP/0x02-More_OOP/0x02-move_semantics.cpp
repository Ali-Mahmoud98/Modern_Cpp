#include <iostream>
#include <utility> // For std::move

class DynamicArray {
private:
    int* data;    // Pointer to dynamically allocated array
    size_t size;  // Size of the array

public:
    // Constructor
    DynamicArray(size_t s) : size(s), data(new int[s]) {
        for (size_t i = 0; i < size; ++i) {
            data[i] = 0; // Initialize array with zeros
        }
        std::cout << "Constructor: Created an array of size " << size << std::endl;
    }

    // Destructor
    ~DynamicArray() {
        delete[] data;
        std::cout << "Destructor: Cleaned up array of size " << size << std::endl;
    }

    // Copy Constructor (deep copy)
    DynamicArray(const DynamicArray& other) : size(other.size), data(new int[other.size]) {
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i]; // Deep copy
        }
        std::cout << "Copy Constructor: Copied an array of size " << size << std::endl;
    }

    // Copy Assignment Operator (deep copy)
    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            // Release the existing resources
            delete[] data;

            // Allocate new memory and copy data
            size = other.size;
            data = new int[size];
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
            std::cout << "Copy Assignment Operator: Copied an array of size " << size << std::endl;
        }
        return *this;
    }

    // Move Constructor (transfer ownership)
    DynamicArray(DynamicArray&& other) noexcept : size(other.size), data(other.data) {
        other.size = 0;
        other.data = nullptr; // Leave the source object in a valid state
        std::cout << "Move Constructor: Moved an array of size " << size << std::endl;
    }

    // Move Assignment Operator (transfer ownership)
    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this != &other) {
            // Release the existing resources
            delete[] data;

            // Transfer ownership of resources
            size = other.size;
            data = other.data;
            
            other.size = 0;
            other.data = nullptr; // Leave the source object in a valid state
            std::cout << "Move Assignment Operator: Moved an array of size " << size << std::endl;
        }
        return *this;
    }

    // Utility function to set a value
    void setValue(size_t index, int value) {
        if (index < size) {
            data[index] = value;
        }
    }

    // Utility function to print the array
    void print() const {
        std::cout << "Array contents: ";
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    // Create an array of size 5
    DynamicArray arr1(5);
    arr1.setValue(0, 10);
    arr1.setValue(1, 20);
    arr1.setValue(2, 30);
    std::cout << "Array 1:" << std::endl;
    arr1.print();

    // Use copy constructor to create a new array
    DynamicArray arr2 = arr1;
    std::cout << "\nArray 2 (copied from Array 1):" << std::endl;
    arr2.print();

    // Use copy assignment operator
    DynamicArray arr3(3);
    arr3 = arr1;
    std::cout << "\nArray 3 (assigned from Array 1):" << std::endl;
    arr3.print();

    // Use move constructor
    DynamicArray arr4 = std::move(arr1);
    std::cout << "\nArray 4 (moved from Array 1):" << std::endl;
    arr4.print();

    std::cout << "\nArray 1 after move (should be empty):" << std::endl;
    arr1.print();  // Should print an empty or invalid array state

    // Use move assignment operator
    DynamicArray arr5(2);
    arr5 = std::move(arr2);
    std::cout << "\nArray 5 (moved from Array 2):" << std::endl;
    arr5.print();

    std::cout << "\nArray 2 after move (should be empty):" << std::endl;
    arr2.print();  // Should print an empty or invalid array state

    return 0;
}
