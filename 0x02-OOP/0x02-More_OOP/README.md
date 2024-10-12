# More About OOP

## contents:
* [1. Multiple Inheritance and diamond problem](#1-multiple-inheritance-and-diamond-problem)
    * [1.1. The Diamond Problem](#11-the-diamond-problem)
    * [1.2. Virtual Inheritance](#12-virtual-inheritance)
    * [1.3. How Virtual Inheritance Works](#13-how-virtual-inheritance-works)
* [2. Templates and OOP](#2-templates-and-oop)
    * [2.1. What are Templates](#21-what-are-templates)
    * [2.2. Interaction with Object-Oriented Principles](#22-interaction-with-object-oriented-principles)
    * [2.2. Interaction with Object-Oriented Principles](#22-interaction-with-object-oriented-principles)
    * [2.3. Contrast with Inheritance-Based Polymorphism](#23-contrast-with-inheritance-based-polymorphism)
    * [2.4. Example Comparison](#24-example-comparison)
* [3. Copy Constructor and Move Semantics](#3-copy-constructor-and-move-semantics)
    * [3.1. Copy Constructors](#31-copy-constructors)
        * [3.1.1. Shallow Copy Example](#311-shallow-copy-example)
    * [3.2. Deep Copy](#32-deep-copy)
        * [3.2.1. Deep Copy Example](#321-deep-copy-example)
    * [3.3. Move Semantics](#33-move-semantics)
        * [3.3.1. Move Constructor](#331-move-constructor)
        * [3.3.2. Move Assignment Operator](#332-move-assignment-operator)
    * [3.4. Benefits of Move Semantics](#34-benefits-of-move-semantics)
    * [3.5. Example Usage of Move Semantics](#35-example-usage-of-move-semantics)
* [4. Virtual Destructors](#4-virtual-destructors)
    * [4.1. The Need for Virtual Destructors](#41-the-need-for-virtual-destructors)
    * [4.2. How Virtual Destructors Work](#42-how-virtual-destructors-work)
        * [4.2.1. Example of a Virtual Destructor](#421-example-of-a-virtual-destructor)
    * [4.3. Key Points](#43-key-points)
* [5. Interfaces in C++](#5-interfaces-in-c)
    * [5.1. What is an Interface](#51-what-is-an-interface)
    * [5.2. Abstract Classes as Interfaces](#52-abstract-classes-as-interfaces)
        * [5.2.1. Defining an Interface with Abstract Classes](#521-defining-an-interface-with-abstract-classes)
    * [5.3. Implementing Interfaces](#53-implementing-interfaces)
    * [5.4. Using Interfaces](#54-using-interfaces)
    * [5.5. Advantages of Using Abstract Classes as Interfaces](#55-advantages-of-using-abstract-classes-as-interfaces)

## 1. Multiple Inheritance and diamond problem
Multiple inheritance in C++ allows a class to inherit from more than one base class. While this provides flexibility, it introduces certain complexities, particularly the **diamond problem**.

### 1.1. The Diamond Problem:
The diamond problem arises when a class inherits from two or more classes that share a common base class, forming a diamond-shaped inheritance hierarchy. Here's an example:

```cpp
class A {
public:
    void display() { std::cout << "Class A" << std::endl; }
};

class B : public A { };

class C : public A { };

class D : public B, public C { };
```

In this example:
- Class `D` inherits from both `B` and `C`.
- Both `B` and `C` inherit from `A`.

This creates ambiguity. When an object of class `D` tries to access members of class `A`, the compiler doesn't know which `A` (the one from `B` or `C`) it should refer to, leading to **ambiguity**:

```cpp
D obj;
obj.display(); // Ambiguity: Which 'A' should be called, A through B or A through C?
```

This ambiguity results in a **compile-time error** because class `D` inherits two separate copies of class `A`, one through `B` and one through `C`. Essentially, there are **two instances** of `A` in the class `D` object.

### 1.2. Virtual Inheritance:
To resolve the diamond problem, C++ provides **virtual inheritance**. By declaring a class as a **virtual base class**, you ensure that only **one instance** of the base class is shared between all the derived classes. Here’s how the previous example can be modified using virtual inheritance:

```cpp
class A {
public:
    void display() { std::cout << "Class A" << std::endl; }
};

class B : virtual public A { };

class C : virtual public A { };

class D : public B, public C { };
```

In this version:
- `B` and `C` inherit `A` **virtually**, ensuring that only **one shared instance** of `A` exists in class `D`.
- When `D` accesses members of `A`, there’s no ambiguity because only one instance of `A` is inherited, even though `D` inherits from both `B` and `C`.

Now, this works fine:

```cpp
D obj;
obj.display(); // No ambiguity, the shared 'A' is called
```

### 1.3. How Virtual Inheritance Works:
When you use **virtual inheritance**, the base class (`A`) is marked as **shared** among all derived classes. The compiler ensures that only one copy of `A` exists, and that shared instance is used no matter how complex the inheritance hierarchy becomes. However, this adds a small runtime overhead since the access to the shared base class might require an indirection (through a pointer or table lookup).

In summary:
- **Without virtual inheritance**: Multiple instances of the base class can be inherited, leading to ambiguity and redundancy (diamond problem).
- **With virtual inheritance**: A single, shared instance of the base class is inherited, resolving the ambiguity but introducing a bit more complexity in terms of memory access and class structure.

Virtual inheritance is a powerful feature of C++ that allows the flexibility of multiple inheritance while preventing the issues that arise from ambiguous base class inheritance.

## 2. Templates and OOP
Templates in C++ are a powerful feature that allows for **generic programming**—writing code that works with any data type. They enable functions and classes to operate with different types without sacrificing type safety or performance. When discussing how templates interact with object-oriented principles, especially in contrast to inheritance-based polymorphism, several key points come into play.

### 2.1. What are Templates?
Templates enable the creation of functions and classes that are **parameterized** by types. This means you can write a function or class definition once and then instantiate it with different types as needed.

**Function Template Example**:
```cpp
template <typename T>
T add(T a, T b) {
    return a + b;
}
```

**Class Template Example**:
```cpp
template <typename T>
class Box {
private:
    T item;
public:
    Box(T item) : item(item) {}
    T getItem() { return item; }
};
```

### 2.2. Interaction with Object-Oriented Principles
1. **Code Reusability**: 
   - Templates promote code reusability by allowing developers to write generic algorithms and data structures. Instead of creating multiple versions of functions or classes for different types, you can use templates to create a single implementation that works for any type.
   - **Example**: A template class for a `Stack` can be created to hold any data type, such as `Stack<int>` or `Stack<std::string>`.

2. **Type Safety**:
   - Templates ensure type safety at compile time. When you instantiate a template with a specific type, the compiler checks that the operations used in the template are valid for that type, reducing runtime errors.
   - Unlike dynamic polymorphism (achieved through inheritance), which resolves method calls at runtime, templates resolve types and function calls at compile time.

3. **Generic Algorithms**:
   - Many of the algorithms in the Standard Template Library (STL) are written using templates, allowing them to operate on any container type. For example, the `std::sort` function can sort vectors, lists, and arrays of any type, thanks to its template nature.

### 2.3. Contrast with Inheritance-Based Polymorphism
While both templates and inheritance are used to achieve polymorphism in C++, they do so in fundamentally different ways:

1. **Mechanism**:
   - **Inheritance-Based Polymorphism**: This approach allows a derived class to override methods of a base class, enabling runtime polymorphism. The correct method to invoke is determined at runtime based on the actual object type.
   - **Templates**: This mechanism relies on compile-time polymorphism. The specific function or class to use is determined during compilation, creating separate versions of the template for each unique type used.

2. **Performance**:
   - **Inheritance**: Can introduce some runtime overhead due to the use of virtual tables (v-tables) for dynamic dispatch.
   - **Templates**: Generally result in better performance because they do not incur the overhead of virtual function calls. However, they can lead to code bloat if many instantiations of the template are generated.

3. **Flexibility**:
   - **Inheritance**: Provides a clear hierarchy and allows for dynamic behavior, such as changing the implementation at runtime. It also allows for creating interfaces.
   - **Templates**: Offer more flexibility in terms of working with data types but do not support polymorphic behavior in the same way as inheritance. With templates, you cannot change the type used in an instance at runtime.

### 2.4. Example Comparison
**Inheritance Example**:
```cpp
class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
};

class Circle : public Shape {
public:
    void draw() override { std::cout << "Drawing Circle" << std::endl; }
};

class Square : public Shape {
public:
    void draw() override { std::cout << "Drawing Square" << std::endl; }
};

void drawShape(Shape* shape) {
    shape->draw(); // Dynamic dispatch based on actual object type
}
```

**Template Example**:
```cpp
template <typename T>
class Drawer {
public:
    void draw(const T& shape) {
        shape.draw(); // Compile-time resolution of draw method
    }
};

Circle circle;
Square square;

Drawer<Circle> circleDrawer;
circleDrawer.draw(circle); // Works with Circle

Drawer<Square> squareDrawer;
squareDrawer.draw(square); // Works with Square
```

## 3. Copy Constructor and Move Semantics
Certainly! Let's dive deeper into **copy constructors**, **move semantics**, and the related concepts of shallow and deep copying, especially as they pertain to modern C++ (C++11 and beyond).

### 3.1. Copy Constructors
A **copy constructor** is a special constructor in C++ that initializes a new object as a copy of an existing object. The default behavior of the copy constructor performs a **shallow copy**, which means that it copies all member variables from the source object to the new object. This can be problematic when the object contains pointers to dynamically allocated memory.

#### 3.1.1. Shallow Copy Example
```cpp
class Shallow {
public:
    int* data;
    
    // Constructor
    Shallow(int value) {
        data = new int(value); // Allocate memory
    }

    // Copy constructor (shallow copy)
    Shallow(const Shallow& other) {
        data = other.data; // Copy the pointer (shallow copy)
    }

    ~Shallow() {
        delete data; // Danger! This will delete the data pointed by both objects
    }
};
```
In this example, if you create two `Shallow` objects, both will point to the same memory location. If one of them is deleted, the other will now point to a deleted memory area, leading to undefined behavior.

### 3.2. Deep Copy
A **deep copy** creates a new copy of the dynamically allocated memory as well, ensuring that each object maintains its own copy of the data. This is achieved by defining a custom copy constructor.

#### 3.2.1. Deep Copy Example
```cpp
class Deep {
public:
    int* data;

    // Constructor
    Deep(int value) {
        data = new int(value); // Allocate memory
    }

    // Copy constructor (deep copy)
    Deep(const Deep& other) {
        data = new int(*other.data); // Allocate new memory and copy the value
    }

    ~Deep() {
        delete data; // Safely delete the allocated memory
    }
};
```
In this example, each `Deep` object has its own copy of the data, preventing issues associated with shared pointers.

### 3.3. Move Semantics
With the introduction of **C++11**, move semantics provide a new way to manage resources. Move semantics enable the transfer of resources from one object to another rather than copying them. This is particularly beneficial for performance, especially with temporary objects or when returning objects from functions.

#### 3.3.1. Move Constructor
A **move constructor** allows the resources of a temporary object to be transferred to a new object. It "steals" the resources (such as dynamically allocated memory) instead of copying them. 

Here's how you can implement a move constructor:

```cpp
class Move {
public:
    int* data;

    // Constructor
    Move(int value) {
        data = new int(value); // Allocate memory
    }

    // Move constructor
    Move(Move&& other) noexcept : data(other.data) {
        other.data = nullptr; // Leave other in a valid state
    }

    ~Move() {
        delete data; // Safely delete the allocated memory
    }
};
```
In this example:
- The move constructor takes an rvalue reference (`Move&& other`), indicating that it will take ownership of the resources.
- The member variable `data` is initialized with `other.data`, transferring the pointer.
- The original object (`other`) is then left in a valid state by setting `other.data` to `nullptr`, avoiding double deletion.

#### 3.3.2. Move Assignment Operator
In addition to the move constructor, C++11 introduces the **move assignment operator**, which allows an existing object to take ownership of the resources of a temporary object.

```cpp
class Move {
public:
    int* data;

    // Constructor
    Move(int value) {
        data = new int(value); // Allocate memory
    }

    // Move constructor
    Move(Move&& other) noexcept : data(other.data) {
        other.data = nullptr; // Leave other in a valid state
    }

    // Move assignment operator
    Move& operator=(Move&& other) noexcept {
        if (this != &other) { // Check for self-assignment
            delete data; // Clean up existing resource
            data = other.data; // Transfer ownership
            other.data = nullptr; // Leave other in a valid state
        }
        return *this;
    }

    ~Move() {
        delete data; // Safely delete the allocated memory
    }
};
```
In the move assignment operator:
- The function checks for self-assignment to avoid unnecessary work and potential issues.
- It deletes the current object's data to prevent memory leaks, transfers ownership of `other.data`, and nullifies `other.data`.

### 3.4. Benefits of Move Semantics
1. **Performance**: Move semantics can significantly improve performance, particularly in scenarios involving large objects or temporary objects. Instead of duplicating resource-heavy objects, you simply transfer ownership.
  
2. **Resource Management**: Move semantics help to maintain a clear ownership model, reducing the risk of memory leaks or dangling pointers.

3. **Optimized Return Values**: Functions can return large objects without the overhead of copying. If a function returns an object that can be moved, the move constructor will be invoked instead of the copy constructor.

### 3.5. Example Usage of Move Semantics
```cpp
Move createMove() {
    Move temp(42); // Create a temporary object
    return temp;   // Move temp to the caller
}

int main() {
    Move obj = createMove(); // Move constructor is called
}
```
In the `createMove` function, a temporary `Move` object is created, and when it's returned, the move constructor efficiently transfers its resources to `obj` in the calling context.


## 4. Virtual Destructors
**Virtual destructors** play a critical role in C++ object-oriented programming, especially when dealing with inheritance and polymorphism. They ensure that the correct destructor is called when an object is deleted through a pointer to a base class, preventing resource leaks and undefined behavior. Let’s explore why virtual destructors are necessary and how they work.

### 4.1. The Need for Virtual Destructors

1. **Polymorphism in Inheritance**:
   When a derived class inherits from a base class, you can create pointers of the base class type that point to derived class objects. This is useful for leveraging polymorphism, where you can treat different derived classes uniformly through a base class interface.

   ```cpp
   class Base {
   public:
       void show() { std::cout << "Base class" << std::endl; }
       // Destructor
       ~Base() { std::cout << "Base destructor" << std::endl; }
   };

   class Derived : public Base {
   public:
       void show() { std::cout << "Derived class" << std::endl; }
       // Destructor
       ~Derived() { std::cout << "Derived destructor" << std::endl; }
   };
   ```

   Here, `Base` has a destructor that does not need to be virtual.

2. **Destruction of Derived Objects**:
   When you delete an object through a base class pointer, if the base class destructor is not virtual, only the base class destructor is called. This can lead to resource leaks or improper cleanup, especially if the derived class allocates resources that need to be released.

   ```cpp
   Base* b = new Derived(); // Pointer of base class pointing to derived class
   delete b;                // Calls Base destructor only
   ```

   In this scenario:
   - When `delete b;` is executed, the `Base` destructor is called.
   - The `Derived` destructor is **not** invoked, leading to potential memory leaks if `Derived` manages its own resources (e.g., dynamically allocated memory).

### 4.2. How Virtual Destructors Work

To prevent the above problem, the destructor of the base class should be declared as **virtual**. This allows the C++ runtime to determine the correct destructor to call based on the actual object type (the derived class type) when deletion occurs.

#### 4.2.1. Example of a Virtual Destructor
```cpp
class Base {
public:
    virtual ~Base() { // Virtual destructor
        std::cout << "Base destructor" << std::endl;
    }
};

class Derived : public Base {
public:
    ~Derived() override { // Override the base destructor
        std::cout << "Derived destructor" << std::endl;
    }
};

int main() {
    Base* b = new Derived(); // Pointer of base class pointing to derived class
    delete b;                // Calls Derived destructor followed by Base destructor
    return 0;
}
```

**Output**:
```
Derived destructor
Base destructor
```

### 4.3. Key Points

1. **Virtual Destructors**: Declaring the base class destructor as virtual ensures that when an object of a derived class is deleted through a base class pointer, the derived class's destructor is called first, followed by the base class's destructor. This ensures proper cleanup of resources.

2. **Destructor Override**: The derived class can override the base class destructor. Using `override` (C++11 and later) helps catch errors at compile time, ensuring that you are correctly overriding a base class method.

3. **Safety in Base Classes**: Always declare destructors as virtual in base classes that are intended to be used polymorphically. This applies not only to classes that manage resources but also to classes involved in a polymorphic hierarchy.

## 5. Interfaces in C++
In C++, the concept of **interfaces** is implemented through the use of **abstract classes**. Unlike some programming languages that have a dedicated `interface` keyword (like Java or C#), C++ utilizes abstract classes to define interfaces. This allows C++ to leverage polymorphism while maintaining the flexibility of its object-oriented paradigm. Let’s explore how this works in detail.

### 5.1. What is an Interface?
An **interface** is a contract that defines a set of methods (or functions) that a class must implement without providing any implementation details. It specifies what an object can do, but not how it does it. Interfaces enable different classes to be treated similarly, facilitating polymorphic behavior.

### 5.2. Abstract Classes as Interfaces
In C++, an **abstract class** is a class that contains at least one pure virtual function. A pure virtual function is a function that is declared by assigning `0` in its declaration, indicating that it must be overridden by any derived class. Here’s how you can define an interface using an abstract class:

#### 5.2.1. Defining an Interface with Abstract Classes

```cpp
class IShape {
public:
    // Pure virtual function
    virtual void draw() = 0; // This function must be overridden
    virtual double area() = 0; // Another pure virtual function

    // Virtual destructor (optional, but good practice)
    virtual ~IShape() {}
};
```

In this example:
- The `IShape` class serves as an interface.
- It declares two pure virtual functions: `draw()` and `area()`.
- The destructor is declared as virtual, ensuring proper cleanup if derived classes are deleted through a base class pointer.

### 5.3. Implementing Interfaces

Classes that inherit from the abstract class must implement all pure virtual functions to become concrete classes. Here’s how you can implement the `IShape` interface:

```cpp
class Circle : public IShape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    void draw() override {
        std::cout << "Drawing a Circle" << std::endl;
    }

    double area() override {
        return 3.14159 * radius * radius; // πr²
    }
};

class Rectangle : public IShape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    void draw() override {
        std::cout << "Drawing a Rectangle" << std::endl;
    }

    double area() override {
        return width * height; // width * height
    }
};
```

In this example:
- Both `Circle` and `Rectangle` implement the `IShape` interface by providing their versions of the `draw()` and `area()` methods.
- The `override` keyword (introduced in C++11) indicates that these methods are overriding the base class's pure virtual functions, enhancing code clarity and safety.

### 5.4. Using Interfaces

Interfaces in C++ allow you to write functions or methods that can operate on any class implementing that interface. This is useful for achieving polymorphism.

```cpp
void renderShape(IShape* shape) {
    shape->draw();        // Calls the appropriate draw() method
    std::cout << "Area: " << shape->area() << std::endl; // Calls the appropriate area() method
}

int main() {
    Circle circle(5.0);
    Rectangle rectangle(4.0, 3.0);

    renderShape(&circle);      // Calls Circle's draw() and area()
    renderShape(&rectangle);    // Calls Rectangle's draw() and area()

    return 0;
}
```

### 5.5. Advantages of Using Abstract Classes as Interfaces

1. **Flexibility**: You can implement multiple interfaces in a class (using multiple inheritance) and define different behaviors for different contexts.
   
2. **Polymorphism**: Abstract classes facilitate polymorphism, allowing you to treat different objects through a common interface, improving code organization and extensibility.

3. **Separation of Interface and Implementation**: This design principle encourages cleaner code by separating what an object can do from how it does it, enhancing maintainability.

4. **Design Patterns**: Abstract classes as interfaces are commonly used in various design patterns (e.g., Strategy, Observer), promoting best practices in software architecture.
