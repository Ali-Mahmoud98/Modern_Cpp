# Virtual Destructor
In C++, a **virtual destructor** is a special type of destructor that is declared with the keyword `virtual`. The purpose of a virtual destructor is to ensure that the destructor of the correct derived class is called when an object is deleted through a pointer to a base class. This is important in the context of **inheritance** and **polymorphism**.

### Why is a Virtual Destructor Needed?

When using polymorphism (i.e., working with pointers or references to base classes, but the actual object is of a derived class), if you delete an object through a base class pointer, and the base class does not have a virtual destructor, only the base class destructor will be called. This can lead to **resource leaks** because the derived class destructor (which may release memory or other resources) will not be called. Here's an example to illustrate the problem:

```cpp
class Base {
public:
    ~Base() {
        std::cout << "Base destructor\n";
    }
};

class Derived : public Base {
public:
    ~Derived() {
        std::cout << "Derived destructor\n";
    }
};

int main() {
    Base* obj = new Derived();
    delete obj;  // Only Base's destructor will be called, not Derived's
    return 0;
}
```

**Output:**
```
Base destructor
```

In the above code, when the `delete obj;` statement is executed, the `Base` destructor is called, but the `Derived` destructor is **not called**. This can result in memory or resource leaks, especially if the `Derived` class dynamically allocates memory or manages other resources that need to be cleaned up in its destructor.

### Solution: Virtual Destructor

To fix this issue, the base class destructor should be declared `virtual`. When the base class destructor is virtual, C++ will ensure that the correct destructor (i.e., the derived class destructor) is called when deleting an object through a base class pointer.

Here’s the corrected version of the above example with a virtual destructor:

```cpp
class Base {
public:
    virtual ~Base() {
        std::cout << "Base destructor\n";
    }
};

class Derived : public Base {
public:
    ~Derived() {
        std::cout << "Derived destructor\n";
    }
};

int main() {
    Base* obj = new Derived();
    delete obj;  // Both Derived's and Base's destructors will be called
    return 0;
}
```

**Output:**
```
Derived destructor
Base destructor
```

Now, when `delete obj;` is executed, both the `Derived` destructor and the `Base` destructor are called, ensuring proper cleanup of resources.

### How It Works

- When a class has a virtual destructor, the compiler adds a **vtable** (virtual table) entry for the destructor.
- At runtime, when an object is deleted via a pointer to the base class, the vtable ensures that the destructor of the **most derived class** is called first, followed by the destructors of all its base classes.

### Key Points

1. **Polymorphism Requirement:** Virtual destructors are only necessary when you are working with inheritance and intend to delete derived objects through base class pointers.
2. **Performance:** There is a small performance overhead due to the virtual function mechanism (vtable lookup), but this is generally negligible.
3. **Best Practice:** If your class has virtual functions (making it a base class in a polymorphic hierarchy), you should always declare the destructor as `virtual`, even if it does nothing. This ensures safe deletion of derived objects.

### Example of Correct Usage in Polymorphism:

```cpp
class Animal {
public:
    virtual ~Animal() {
        std::cout << "Animal destructor\n";
    }

    virtual void speak() = 0;  // Pure virtual function
};

class Dog : public Animal {
public:
    ~Dog() {
        std::cout << "Dog destructor\n";
    }

    void speak() override {
        std::cout << "Woof!\n";
    }
};

int main() {
    Animal* pet = new Dog();
    pet->speak();  // Calls Dog::speak()
    delete pet;    // Correctly calls Dog's and then Animal's destructors
    return 0;
}
```

**Output:**
```
Woof!
Dog destructor
Animal destructor
```

In this example, `Dog` is correctly cleaned up, and both destructors are invoked in the proper order.
