#include <iostream>
#include <stdexcept>  // for std::out_of_range

// Template class for a custom Array
template <typename T, size_t N>
class MyArray {
private:
    T data[N];  // Fixed-size array to hold elements

public:
    // Constructor (optional, since array elements are default-initialized)
    MyArray() {}

    // Access an element (with bounds checking)
    T& at(size_t index) {
        if (index >= N) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    // Access an element (without bounds checking, like operator[])
    T& operator[](size_t index) {
        return data[index];
    }

    // Get the size of the array
    size_t size() const {
        return N;
    }

    // Get the first element
    T& front() {
        return data[0];
    }

    // Get the last element
    T& back() {
        return data[N - 1];
    }

    // Fill the array with a specific value
    void fill(const T& value) {
        for (size_t i = 0; i < N; ++i) {
            data[i] = value;
        }
    }

    // Provide iterators for compatibility with STL algorithms
    T* begin() { return &data[0]; }
    T* end() { return &data[N]; }
};

int main() {
    // Create a MyArray of 5 integers
    MyArray<int, 5> arr;

    // Set values in the array
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;

    // Print elements using array access
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";  // Output: 10 20 30 40 50
    }

    // Example of bounds checking with at()
    try {
        arr.at(5) = 60;  // This will throw an exception (out of bounds)
    } catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;  // Output: Index out of bounds
    }

    return 0;
}
