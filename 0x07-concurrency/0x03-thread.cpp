#include <thread>
#include <iostream>

struct Functor {
    void operator()() const {
        std::cout << "Functor invoked!" << std::endl;
    }
};

// A function that takes a function pointer of type `Functor (*)()` as a parameter
// and returns an `std::thread`.
std::thread createThread(Functor (*func)()) {
    // Start a new thread that runs the provided `Functor` function pointer
    return std::thread(func);
}

int main() {
    // Declare a function pointer of type `std::thread (*)(Functor (*)())`
    std::thread (*threadFuncPtr)(Functor (*)()) = &createThread; // in example 0x02-thread.cpp
    // the compiler translated the thread "t" to a type same as:  std::thread (*threadFuncPtr)(Functor (*)())

    // Use the function pointer to start a thread
    std::thread t = threadFuncPtr([]() -> Functor {
        return Functor();
    });

    std::thread t2([]() -> Functor {
        return Functor();
    });

    // the easiest way by adding paranthes: std::thread t((Functor())); like in example 0x02-thread.cpp
    std::thread t3((Functor()));

    // Wait for the thread to complete
    t.join();
    t2.join();
    t3.join();
    return 0;
}
