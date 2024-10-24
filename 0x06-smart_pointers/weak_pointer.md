## Weak Pointer
### **1. Avoiding Cyclic Dependencies with `std::weak_ptr`:**

When working with `std::shared_ptr`, a common pitfall is **cyclic references**, which can prevent objects from being properly deleted and result in memory leaks. This happens when two (or more) `shared_ptr` objects reference each other directly or indirectly, forming a reference cycle. In such cases, even though both objects go out of scope, their reference count never reaches zero because they "hold on" to each other, preventing deallocation.

#### Example of a cyclic reference:

```cpp
struct Node {
    std::shared_ptr<Node> next;
    ~Node() { std::cout << "Node destroyed\n"; }
};

int main() {
    std::shared_ptr<Node> node1 = std::make_shared<Node>();
    std::shared_ptr<Node> node2 = std::make_shared<Node>();

    node1->next = node2;
    node2->next = node1; // Cyclic reference

    return 0; // Memory leak, because the reference count never drops to zero.
}
```

In this case, even after the scope ends, `node1` and `node2` will not be destroyed because they are holding each other through `shared_ptr`.

#### Solution with `std::weak_ptr`:
`std::weak_ptr` is designed to solve this issue. It is a non-owning smart pointer that doesn’t affect the reference count of the object it points to. By using `std::weak_ptr`, you can break cyclic dependencies because the `weak_ptr` doesn’t contribute to the shared ownership.

```cpp
struct Node {
    std::weak_ptr<Node> next; // Use weak_ptr to avoid cyclic reference
    ~Node() { std::cout << "Node destroyed\n"; }
};

int main() {
    std::shared_ptr<Node> node1 = std::make_shared<Node>();
    std::shared_ptr<Node> node2 = std::make_shared<Node>();

    node1->next = node2;
    node2->next = node1; // No cyclic reference now

    return 0; // Both nodes are destroyed correctly.
}
```

### **2. Locking and Checking a `std::weak_ptr`:**

Since `std::weak_ptr` does not manage the object’s lifetime, you need to check whether the object is still valid (i.e., it hasn't been destroyed) before accessing it. This is done by converting the `weak_ptr` back to a `shared_ptr`. This process is known as **locking** the weak pointer.

- **Locking the weak pointer**:
  You can convert a `weak_ptr` to a `shared_ptr` using the `.lock()` method. If the object still exists, `lock()` returns a valid `shared_ptr`. If the object has been deleted, `lock()` returns an empty `shared_ptr`.

- **Checking the state**:
  You can also check if the `weak_ptr` points to a valid object using the `expired()` method. It returns `true` if the `weak_ptr` no longer points to a valid object.

#### Example:

```cpp
#include <iostream>
#include <memory>

struct Node {
    std::weak_ptr<Node> next; // weak_ptr to avoid cyclic dependency
    ~Node() { std::cout << "Node destroyed\n"; }
};

int main() {
    std::shared_ptr<Node> node1 = std::make_shared<Node>();
    std::shared_ptr<Node> node2 = std::make_shared<Node>();

    node1->next = node2;
    node2->next = node1; // No cyclic reference here

    if (auto lockedPtr = node1->next.lock()) { // Lock the weak_ptr
        std::cout << "Node2 is still valid\n";
    } else {
        std::cout << "Node2 is expired\n";
    }

    return 0;
}
```

Here:
- `node1->next.lock()` returns a `shared_ptr` if `node2` is still valid.
- If `node2` is already destroyed, the `lock()` method would return an empty `shared_ptr`.

### **3. Use Cases of `std::weak_ptr`:**

#### **Observer Pattern:**

The observer pattern is one of the classic use cases for `std::weak_ptr`. In this pattern, multiple observer objects register themselves to observe changes in a subject. Typically, the subject holds a reference to each observer, but we don’t want the observers to have a strong ownership that prevents the subject from being deleted.

Instead of using `std::shared_ptr` in both directions (i.e., the subject and observers), we can use a `std::weak_ptr` to allow the subject to "observe" the observers without creating a strong ownership relationship.

#### Example:

```cpp
#include <iostream>
#include <memory>
#include <vector>

class Observer {
public:
    virtual void notify() = 0;
    virtual ~Observer() { std::cout << "Observer destroyed\n"; }
};

class Subject {
    std::vector<std::weak_ptr<Observer>> observers; // weak_ptr to avoid ownership
public:
    void registerObserver(std::shared_ptr<Observer> obs) {
        observers.push_back(obs);
    }

    void notifyAll() {
        for (auto& weakObs : observers) {
            if (auto obs = weakObs.lock()) { // Lock the weak_ptr to ensure validity
                obs->notify();
            }
        }
    }
};

class ConcreteObserver : public Observer {
public:
    void notify() override {
        std::cout << "Observer notified\n";
    }
    ~ConcreteObserver() {
        std::cout << "ConcreteObserver destroyed\n";
    }
};

int main() {
    Subject subject;
    std::shared_ptr<Observer> obs1 = std::make_shared<ConcreteObserver>();

    subject.registerObserver(obs1);
    
    subject.notifyAll(); // Notify the observer

    // Observer is destroyed when going out of scope
    return 0;
}
```

In this example:
- The `Subject` holds weak references to its observers, avoiding the potential for cyclic references.
- The `Subject` locks the weak pointers during notification to ensure the observers are still valid.

This ensures that if an observer is destroyed (e.g., because it is no longer needed or goes out of scope), the subject does not hold dangling references.

### **Other Use Cases of `std::weak_ptr`:**
- **Caching/Memoization**: `std::weak_ptr` can be useful in caches, where you want to allow objects to be shared, but if no strong references to the object exist, the cache should not keep them alive.
- **Graph Structures**: In structures like graphs, trees, or doubly linked lists where bidirectional relationships are present, `std::weak_ptr` can be used to prevent cycles.
