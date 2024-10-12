# Vector in C++ STL

`std::vector` is a dynamic array in C++, part of the Standard Template Library (STL). It is a sequence container that can grow or shrink in size as needed. Unlike `std::array`, which is of a fixed size, `std::vector` can dynamically allocate memory, making it a more flexible choice when the number of elements in a collection is not known at compile-time.

**Key Characteristics of Vectors:**
* **Dynamic Sizing:** Vectors automatically resize when you add or remove elements. This flexibility is one of the main reasons vectors are preferred over traditional arrays in many situations.
* **Efficient Access:** Since vector elements are stored in contiguous memory locations, you can access elements in constant time using their index, similar to arrays.
* **Insertion and Deletion:** Insertion of elements is typically done at the end of the vector, where it operates in constant time. However, inserting or deleting elements at the beginning or middle of the vector takes linear time due to the need to shift elements

**The time complexity for doing various operations on vectors is:**
* Random access – constant `O(1)`
* Insertion or removal of elements at the end – constant `O(1)`
* Insertion or removal of elements – linear in the distance to the end of the vector `O(N)`
* Knowing the size – constant `O(1)`
* Resizing the vector– Linear `O(N)`

**READ:** [Vector - C++ Reference](https://en.cppreference.com/w/cpp/container/vector)

### Differences Between `std::vector` and `std::array`

| Feature/Functionality        | **`std::vector`**                                      | **`std::array`**                               |
|------------------------------|-------------------------------------------------------|------------------------------------------------|
| **Size**                     | Dynamic, can grow or shrink during runtime.            | Fixed size, known at compile-time.             |
| **Memory Allocation**        | Dynamically allocated on heap.                         | Allocated on stack (or as part of the object). |
| **Access Time**              | Constant time `O(1)` for random access.                | Constant time `O(1)` for random access.        |
| **Bounds Checking**          | `at()` checks bounds, `operator[]` does not.           | `at()` checks bounds, `operator[]` does not.   |
| **Resizing**                 | Supports resizing using `push_back()`, `resize()`.     | Size is fixed; no resizing is allowed.         |
| **Capacity**                 | Can hold more elements than current size (via `capacity()`). | No concept of capacity; size is fixed.         |
| **Memory Reallocation**      | Automatically reallocates memory when size exceeds capacity. | No reallocation since size is fixed.           |
| **Initialization**           | Can be initialized empty and grow over time.           | Must be initialized with a fixed size.         |
| **Memory Efficiency**        | May allocate more memory than needed (extra capacity). | No memory overhead for unused capacity.        |
| **Use Case**                 | Ideal for dynamic collections where size changes.      | Best for fixed-size collections where size is known. |
| **Iterators**                | Supports full range of iterators (begin, end, rbegin, etc.). | Same as `std::vector`.                        |
| **Memory Overhead**          | Potential for overallocation due to capacity growth.   | No overhead beyond the fixed size.             |
| **Default Size**             | Can be initialized with a size of 0 (empty).           | Must always be initialized with a size.        |
| **Comparison**               | Supports element-wise comparison.                     | Supports element-wise comparison.              |
| **Performance**              | Insertion/deletion at the end is `O(1)`.               | No insertion/deletion possible.                |


### Vector Functions

| **`std::vector` Function**        | **Description**                                                                                      |
|-----------------------------------|------------------------------------------------------------------------------------------------------|
| **`push_back(const T& value)`**   | Adds an element to the end of the vector. If needed, it reallocates memory to accommodate the new size. |
| **`pop_back()`**                  | Removes the last element of the vector, reducing its size by 1.                                        |
| **`resize(size_type count)`**     | Resizes the vector to contain `count` elements. If the new size is larger, default values are added.   |
| **`size()`**                      | Returns the current number of elements in the vector.                                                  |
| **`capacity()`**                  | Returns the current capacity (number of elements the vector can hold before reallocating).             |
| **`empty()`**                     | Returns `true` if the vector contains no elements, otherwise returns `false`.                          |
| **`at(size_type pos)`**           | Returns a reference to the element at position `pos` with bounds checking. Throws `out_of_range` if the position is invalid. |
| **`operator[](size_type pos)`**   | Returns a reference to the element at position `pos` without bounds checking.                          |
| **`front()`**                     | Returns a reference to the first element in the vector.                                                |
| **`back()`**                      | Returns a reference to the last element in the vector.                                                 |
| **`data()`**                      | Returns a pointer to the underlying array used by the vector.                                          |
| **`insert(iterator pos, const T& value)`** | Inserts an element at the specified position, shifting subsequent elements to the right.            |
| **`erase(iterator pos)`**         | Removes the element at the specified position, shifting subsequent elements to the left.               |
| **`clear()`**                     | Removes all elements from the vector, reducing its size to zero.                                       |
| **`assign(size_type count, const T& value)`** | Replaces the contents of the vector with `count` copies of `value`.                                 |
| **`reserve(size_type new_cap)`**  | Requests that the vector capacity be at least enough to contain `new_cap` elements.                   |
| **`shrink_to_fit()`**             | Reduces the capacity of the vector to match its size, releasing any unused memory.                     |
| **`begin()`**                     | Returns an iterator to the first element of the vector.                                                |
| **`end()`**                       | Returns an iterator to the element one past the last element of the vector.                            |
| **`rbegin()`**                    | Returns a reverse iterator to the last element of the vector.                                          |
| **`rend()`**                      | Returns a reverse iterator to one before the first element of the vector.                              |
| **`swap(std::vector<T>& other)`** | Swaps the contents of the vector with those of `other`, exchanging elements in constant time.          |

### Vector Initialization
There are several ways to initialize a `std::vector` in C++. Each method is useful depending on the context in which you need to initialize the vector. Below are the most common ways to initialize a vector:

#### 1. **Default Initialization**
   - Creates an empty vector with no elements.
   ```cpp
   std::vector<int> vec;
   ```

#### 2. **Initializer List**
   - Initializes the vector with a list of values using curly braces.
   ```cpp
   std::vector<int> vec = {1, 2, 3, 4, 5};
   ```

#### 3. **Uniform Initialization (C++11 and later)**
   - Uses curly braces for initialization. This is the same as initializer list but uses the constructor call.
   ```cpp
   std::vector<int> vec{1, 2, 3, 4, 5};
   ```

#### 4. **Fill Constructor**
   - Initializes a vector with a specified number of elements, each initialized to a given value.
   ```cpp
   std::vector<int> vec(5, 10);  // Creates a vector with 5 elements, each initialized to 10
   ```

#### 5. **Size Constructor**
   - Initializes a vector with a specified number of elements, with default-initialized values (`0` for integers, `0.0` for floating point types, empty strings for `std::string`).
   ```cpp
   std::vector<int> vec(5);  // Creates a vector with 5 elements, each initialized to 0
   ```

#### 6. **Copy Constructor**
   - Initializes a vector as a copy of another vector.
   ```cpp
   std::vector<int> vec1 = {1, 2, 3, 4, 5};
   std::vector<int> vec2(vec1);  // Copying vec1 to vec2
   ```

#### 7. **Range Constructor**
   - Initializes a vector by copying elements from another container or array, using iterators to specify the range.
   ```cpp
   std::vector<int> arr = {1, 2, 3, 4, 5};
   std::vector<int> vec(arr.begin(), arr.end());  // Copying elements from arr to vec
   ```

#### 8. **From a C-style Array**
   - Initializes a vector by copying the elements from a C-style array.
   ```cpp
   int arr[] = {1, 2, 3, 4, 5};
   std::vector<int> vec(arr, arr + sizeof(arr)/sizeof(arr[0]));  // Create a vector from C array
   ```

#### 9. **Using `std::move()`**
   - Initializes a vector by moving the contents of another vector (instead of copying).
   ```cpp
   std::vector<int> vec1 = {1, 2, 3};
   std::vector<int> vec2 = std::move(vec1);  // Move vec1 to vec2 (vec1 is left empty)
   ```

#### 10. **Using `std::vector::assign()`**
   - Initializes or assigns values to an already declared vector with a specified number of elements and a value.
   ```cpp
   std::vector<int> vec;
   vec.assign(5, 100);  // Assigns 5 elements, each initialized to 100
   ```

#### Summary of Initialization Methods:

| **Initialization Method**           | **Description**                                                                              |
|-------------------------------------|----------------------------------------------------------------------------------------------|
| **Default Initialization**          | Creates an empty vector.                                                                     |
| **Initializer List**                | Initializes a vector with a list of values.                                                  |
| **Uniform Initialization**          | Same as an initializer list but in constructor form.                                          |
| **Fill Constructor**                | Initializes a vector with a specific number of elements, each initialized to a value.         |
| **Size Constructor**                | Creates a vector of a given size with default values.                                         |
| **Copy Constructor**                | Creates a vector as a copy of another vector.                                                 |
| **Range Constructor**               | Initializes a vector from a range of iterators (e.g., from another container or array).       |
| **From C-style Array**              | Initializes a vector by copying elements from a C-style array.                                |
| **Using `std::move()`**             | Transfers ownership of the data from one vector to another without copying (move semantics).  |
| **Using `assign()`**                | Assigns values to an already declared vector.                                                 |

Each method of initialization has its unique use cases, allowing you to flexibly create vectors depending on how and where you need to use them.

### Example building your own mini vector
```cpp
template <typename T>
class MyVector {
private:
    T* data;           // Pointer to the array
    size_t capacity;   // Current capacity of the vector
    size_t size;       // Current size (number of elements)

    void resize() {
        // Double the capacity
        capacity *= 2;
        T* newData = new T[capacity];
        
        // Copy old data to the new array
        for (size_t i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        
        delete[] data; // Free old array
        data = newData; // Point to the new array
    }

public:
    // default initialization
    MyVector() : size(0), capacity(1) {
        std::cout << "default initialization" << std::endl;
        data = new T[capacity]; // Initialize with capacity of 1
    }

    // size constructor
    MyVector(int n) : size(n), capacity(n), data(new T[n]) {
        std::cout << "size constructor" << std::endl;
        for (int i = 0; i < n; i++)
            data[i] = 0;
    }

    // fill constructor
    MyVector(int n, T value) : size(n), capacity(n), data(new T[n]) {
        std::cout << "fill constructor" << std::endl;
        for (int i = 0; i < n; i++)
            data[i] = value;
    }

    // initializer list
    MyVector(std::initializer_list<T> list) : size(list.size()), capacity(list.size()), data(new T[list.size()]) {
        std::cout << "initializer_list" << std::endl;
        for (size_t i = 0; i < list.size(); i++) {
            data[i] = list.begin()[i];
        }
    }
    // copy constructor
    MyVector(const MyVector& other) : size(other.size), capacity(other.capacity), data(new T[other.capacity]) {
        std::cout << "copy constructor" << std::endl;
        for (size_t i = 0; i < other.size; i++) {
            data[i] = other.data[i];
        }
    }
    // move constructor
    MyVector(MyVector&& other) : size(other.size), capacity(other.capacity), data(other.data) {
        std::cout << "move constructor" << std::endl;
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }

    // copy assignment
    MyVector& operator=(const MyVector& other) {
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
    MyVector& operator=(MyVector&& other) {
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

    ~MyVector() {
        delete[] data; // Free allocated memory
    }

    void push_back(const T& value) {
        if (size == capacity) {
            resize(); // Resize if we reached capacity
        }
        data[size++] = value; // Add new element and increment size
    }

    size_t getSize() const {
        return size; // Return current size
    }

    T& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index]; // Return element at index
    }

    T& at(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index]; // Return element at index
    }

    // print
    void print() {
        for (size_t i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};
```
