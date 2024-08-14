## Keywords in C++ Object-Oriented Programming (OOP)

### 1. `default`
The `default` keyword in C++ is used to explicitly declare that a default implementation of a function should be provided by the compiler. This is commonly used with special member functions such as constructors, destructors, copy constructors, and copy assignment operators.

#### Usage
```cpp
class MyClass {
public:
    MyClass() = default;             // Use the compiler-generated default constructor
    ~MyClass() = default;            // Use the compiler-generated destructor
    MyClass(const MyClass&) = default;  // Use the compiler-generated copy constructor
    MyClass& operator=(const MyClass&) = default; // Use the compiler-generated copy assignment operator
};
```

### 2. `delete`
The `delete` keyword is used to prevent the generation of certain functions by the compiler. When a function is marked with `= delete`, any use of that function will result in a compilation error. This is particularly useful for preventing unwanted copy operations.

#### Usage
```cpp
class MyClass {
public:
    MyClass() = default;
    MyClass(const MyClass&) = delete;  // Prevent copying
    MyClass& operator=(const MyClass&) = delete; // Prevent assignment
};
```

### 3. `override`
The `override` keyword is used to indicate that a member function is intended to override a virtual function in a base class. It helps catch errors at compile-time by ensuring that the function is correctly overriding a base class function.

#### Usage
```cpp
class Base {
public:
    virtual void display() const;
};

class Derived : public Base {
public:
    void display() const override; // Indicates this overrides Base::display
};
```

### 4. `final`
The `final` keyword is used to prevent a class from being inherited or a virtual function from being overridden further. When applied to a class, it prevents subclassing. When applied to a virtual function, it prevents further overriding.

#### Usage
```cpp
class Base {
public:
    virtual void display() const final; // No further overrides allowed
};

class Derived : public Base {
public:
    // void display() const override; // This would be a compile-time error
};

class NonInheritable final {
    // No classes can inherit from NonInheritable
};
```

### 5. `constexpr`
The `constexpr` keyword indicates that the value of a variable or the return value of a function can be evaluated at compile time. It is often used for constants and for functions that are expected to be evaluated at compile time.

#### Usage
```cpp
constexpr int square(int x) {
    return x * x;
}

constexpr int value = square(5); // Evaluated at compile time
```

### 6. `virtual`
The `virtual` keyword is used to declare virtual functions in a base class, which can be overridden in derived classes. It enables polymorphism, allowing the appropriate function to be called based on the actual type of the object, even when accessed through a base class pointer or reference.

#### Usage
```cpp
class Base {
public:
    virtual void display() const; // Virtual function
};

class Derived : public Base {
public:
    void display() const override; // Override the virtual function
};
```

### 7. `mutable`
The `mutable` keyword allows a member of an object to be modified even if the object is const. It is used to indicate that a particular member can change even when the rest of the object remains unchanged.

#### Usage
```cpp
class MyClass {
public:
    void update() const {
        ++mutableCounter; // Allowed because mutableCounter is mutable
    }

private:
    mutable int mutableCounter = 0; // Mutable member
};
```

### 8. `explicit`
The `explicit` keyword is used to prevent implicit conversions and copy-initialization for constructors. This is particularly useful for constructors that can be called with a single argument, preventing unintended conversions.

#### Usage
```cpp
class MyClass {
public:
    explicit MyClass(int value); // Prevents implicit conversion from int to MyClass
};

MyClass obj1 = 42; // Error: No implicit conversion allowed
MyClass obj2(42);  // OK: Direct initialization
```
