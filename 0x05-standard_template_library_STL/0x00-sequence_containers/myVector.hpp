#ifndef MY_VECTOR_HPP
#define MY_VECTOR_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class MyVector {
private:
    T* data;           // Pointer to the array
    size_t capacity;   // Current capacity of the vector
    size_t size;       // Current size (number of elements)

    void resize();

public:
    // Constractors
    // default initialization
    MyVector();
    // size constructor
    MyVector(int n);
    // fill constructor
    MyVector(int n, T value);
    // initializer list
    MyVector(std::initializer_list<T> list);
    // copy constructor
    MyVector(const MyVector& other);
    // move constructor
    MyVector(MyVector&& other);
    //////////////////////////////
    
    //////////////////////////////
    // Operator Overloading
    // copy assignment
    MyVector& operator=(const MyVector& other);
    // move assignment
    MyVector& operator=(MyVector&& other);
    // operator[]
    T& operator[](size_t index);
    //////////////////////////////
    
    //////////////////////////////
    // Set ot functions
    // push_back
    void push_back(const T& value);
    // getSize
    size_t getSize();
    T& at(size_t index);
    // print
    void print();
    //////////////////////////////

    // destructor
    ~MyVector();
};

// default initialization
template <typename T>
MyVector<T>::MyVector() : size(0), capacity(1) {
    std::cout << "default initialization" << std::endl;
    data = new T[capacity]; // Initialize with capacity of 1
}
// size constructor
template <typename T>
MyVector<T>::MyVector(int n) : size(n), capacity(n), data(new T[n]) {
    std::cout << "size constructor" << std::endl;
    for (int i = 0; i < n; i++)
        data[i] = 0;
}
// fill constructor
template <typename T>
MyVector<T>::MyVector(int n, T value) : size(n), capacity(n), data(new T[n]) {
    std::cout << "fill constructor" << std::endl;
    for (int i = 0; i < n; i++) {
        data[i] = value;
    }
}
// initializer list
template <typename T>
MyVector<T>::MyVector(std::initializer_list<T> list) : size(list.size()), capacity(list.size()), data(new T[list.size()]) {
    std::cout << "initializer_list" << std::endl;
    for (size_t i = 0; i < list.size(); i++) {
        data[i] = list.begin()[i];
    }
}
// copy constructor
template <typename T>
MyVector<T>::MyVector(const MyVector& other) : size(other.size), capacity(other.capacity), data(new T[other.capacity]) {
    std::cout << "copy constructor" << std::endl;
    for (size_t i = 0; i < other.size; i++) {
        data[i] = other.data[i];
    }
}
// move constructor
template <typename T>
MyVector<T>::MyVector(MyVector&& other) : size(other.size), capacity(other.capacity), data(other.data) {
    std::cout << "move constructor" << std::endl;
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}
// copy assignment
template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& other) {
    std::cout << "copy assignment" << std::endl;
    if (this != &other) {
        delete[] data;
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];
        for (size_t i = 0; i < other.size; i++) {
            data[i] = other.data[i];
        }
    }
    return *this;
}
// move assignment
template <typename T>
MyVector<T>& MyVector<T>::operator=(MyVector&& other) {
    std::cout << "move assignment" << std::endl;
    if (this != &other) {
        delete[] data;
        size = other.size;
        capacity = other.capacity;
        data = other.data;
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    return *this;
}
// destructor
template <typename T>
MyVector<T>::~MyVector() {
    std::cout << "destructor" << std::endl;
    delete[] data;
}

template <typename T>
void MyVector<T>::push_back(const T& value) {
    if (size == capacity) {
        resize();
    }
    data[size++] = value;
}

template <typename T>
size_t MyVector<T>::getSize() {
    return size;
}

template <typename T>
T& MyVector<T>::operator[](size_t index) {
    return data[index];
}

template <typename T>
T& MyVector<T>::at(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

template <typename T>
void MyVector<T>::print() {
    for (size_t i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void MyVector<T>::resize() {
    capacity *= 2;
    T* newData = new T[capacity];
    for (size_t i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}

#endif