#ifndef MY_ARRAY_HPP_
#define MY_ARRAY_HPP_

#include <iostream>

template <typename T>
class MyArray {
///////////////////////
// Start of My iterator
///////////////////////
public:
    struct iterator {
        // Prperties of our iterator
        using Category = std::forward_iterator_tag;
        using Distance = std::ptrdiff_t;
        // Shorthand for pointer type
        using Pointer = T*;
        using Reference = T&;
        using Value_Type = T;

        // Constructor
        iterator(Pointer ptr) : myPtr(ptr) {}
        // Dereference operator (to access the value)
        Reference operator*() const {
            return *myPtr;
        }

        // Pre-increment operator (++it)
        iterator operator++() {
            ++myPtr;  // Move the pointer to the next element
            return *this;
        }

        // Post-increment operator (it++)
        iterator operator++(int) {
            iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        // Comparison operator (to check if two iterators are not equal)
        bool operator!=(const iterator& other) const {
            return myPtr != other.myPtr;
        }
    private:
        Pointer myPtr;
    };
/////////////////////
// End of My iterator
////////////////////
private:
    T *data;
    size_t capacity;
public:
    MyArray(size_t capacity) : capacity(capacity) {
        data = new T[capacity];
    }

    ~MyArray() {
        if (data != nullptr) {
            delete[] data;
            data = nullptr;
        }
    }

    T& operator[](size_t index) {
        return data[index];
    }

    size_t arrCapacity() const {
        return capacity;
    }

    // Begin iterator (points to the first element)
    iterator begin() {
        return iterator(data);
    }

    // End iterator (points to the element after the last element)
    // End iterator (points to one past the last element)
    iterator end() {
        return iterator(data + capacity);
    }
};

#endif