#include <iostream>
#include <memory>
#include <thread>
#include <vector>

class B; // Forward declaration

class A {
public:
    std::shared_ptr<B> bPtr; // Pointer to B
    A() { std::cout << "A constructed\n"; }
    ~A() { std::cout << "A destructed\n"; }
};

class B {
public:
    std::weak_ptr<A> aPtr; // Weak pointer to A
    B() { std::cout << "B constructed\n"; }
    ~B() { std::cout << "B destructed\n"; }
};

void createInstances() {
    auto a = std::make_shared<A>();
    auto b = std::make_shared<B>();
    
    a->bPtr = b; // A points to B
    b->aPtr = a; // B points to A (weakly)

    std::cout << "Inside createInstances\n";
}

int main() {
    // Create instances in a thread
    std::thread t(createInstances);
    t.join(); // Wait for the thread to finish

    std::cout << "Exiting main\n";
    return 0;
}
