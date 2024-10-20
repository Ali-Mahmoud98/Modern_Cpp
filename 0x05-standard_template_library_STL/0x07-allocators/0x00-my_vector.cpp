#include <iostream>
#include <memory>  // For std::allocator
#include <stdexcept> // For std::out_of_range

template <typename T, typename Alloc = std::allocator<T>>
class MyVector {
public:
    // type aliases
    using size_type = std::size_t;
    using value_type = T;

    // default constructor
    MyVector() : size_(0), capacity_(1) {
        // Allocate memory for the vector
        // allocates uninitialized storage
        data_ = allocator_.allocate(capacity_); // using allocator for handling memory management
    }

    // destructor
    ~MyVector() {
        clear();
        allocator_.deallocate(data_, capacity_); // deallocates storage
    }

    // push_back
    void push_back(const T& value) {
        if (size_ == capacity_) {
            resize(capacity_ * 2);
        }
        allocator_.construct(data_ + size_, value); // constructs an object in allocated storage
        ++size_;
    }

    // operator[] overload
    T& operator[](size_type index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

    const T& operator[](size_type index) const {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

    size_type size() const { return size_; }

    void clear() {
        for (size_type i = 0; i < size_; ++i) {
            allocator_.destroy(data_ + i);
        }
        size_ = 0;
    }

private:
    void resize(size_type new_capacity) {
        T* new_data = allocator_.allocate(new_capacity); // allocates uninitialized storage
        for (size_type i = 0; i < size_; ++i) {
            allocator_.construct(new_data + i, std::move(data_[i])); // constructs an object in allocated storage
            // std::move(data_[i]); for transfering ownership
            allocator_.destroy(data_ + i); // destructs an object in allocated storage
        }
        allocator_.deallocate(data_, capacity_); // deallocates storage
        data_ = new_data;
        capacity_ = new_capacity;
    }

    Alloc allocator_; // Allocator instance
    T* data_;
    size_type size_;
    size_type capacity_;
};

int main() {
    MyVector<int> vec;  // Create a MyVector for ints

    // Push back some values
    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
    }

    // Access and print values
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << "vec[" << i << "] = " << vec[i] << std::endl;
    }

    // Clear the vector
    vec.clear();

    // Check size after clearing
    std::cout << "Size after clearing: " << vec.size() << std::endl;

    return 0;
}
