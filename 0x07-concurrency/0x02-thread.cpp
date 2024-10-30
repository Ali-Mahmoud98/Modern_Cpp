#include <iostream>
#include <thread>
#include <chrono>
// NOTE: thread object can be constructed not only with a regular function but also with any callable object
// like lambda, or functor

// 1. regular function
void function1() {
    std::cout << "Hello from thread: " << std::this_thread::get_id() << "\n";
}

// 2. functor
struct Functor {
    void operator()() {
        std::cout << "Hello from thread: " << std::this_thread::get_id() << "\n";
    }
};

int main() {
    // 1. use functor
    // Functor fnctr;
    // std::thread t(fnctr);

    // 1.1. using one line:
    // the below line is known as most vexing syntax in C++ - the line will give error
    // std::thread t(Functor()); // here we are declaring a function with name "t" and this function
    // takes a single parameter which is a pointer to another function and this function takes no 
    // parameters and return a functor and function "t" returns a thread.
    // t -> will be a function takes a one parameter and returns a thread. => 
    // the "t" parameter -> function pointer takes no parameter and return a functor.
    // the complier will see std::thread t(Functor()) as std::thread t(Functor (*)())
    //-------
    // NOTE: C++ says whenever a statement can be interpreted as a function declaration it will
    // be treated as a function declaration.
    // solution is adding "Functor()" inside another pair of parenthesis to be "std::thread t((Functor()))"
    // the right syntax:
    std::thread t((Functor()));
    // the added parenthesis will constructing a functor and pass as a parameter to the constructor of "t" 
    // it is good to see another example: "0x03-thread.cpp"
    //-------

    // 2. use regular function
    std::thread t1(function1);
    // 3. use lambda
    std::thread t2([]() {
        std::cout << "Hello from thread: " << std::this_thread::get_id() << "\n";
    });

    t.join();
    t1.join();
    t2.join();

    return 0;
}