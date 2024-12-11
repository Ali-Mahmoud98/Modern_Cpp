#include <iostream>
#include <thread>
#include <functional>
#include <future>
#include <mutex>

class Callable {
public:
    int mul2(int n) {return (n*2);}
    void fun1(int n, char c) {}
    int operator()(int n) {return (n+1);} // this indicates that Callable is also a functor
};

void foo(int x){}

int main() {
    Callable c;
    // there are two ways to launch a child thread:
    // 1. using thread object
    // std::thread t1(c, 4);
    
    //2. using async function
    // std::async(std::launch::async, c, 4);
    // the thread object and the async function have similar function signature:
    //+ they take a callable object followed by a variable number of arguments.

    /////////////////////////////////////////////////////////////////////////////////
    // there are two other functions which are take a callable object as an argument and followed by other arguments:
    // 1. std::bind
    // std::bind(c, 4);
    // 2. std::call_once
    // std::once_flag oflag;
    // std::call_once(oflag ,c, 4);

    ////////////////////////////////////////////////////////////////////////////////
    // Creating threads in different ways:
    std::thread t1(c, 4); // creating a copy of "c" and invoke it as a functor in a different thread
    std::thread t2(std::ref(c), 4); // using the same "c", then launch "c" as fanctor in different thread
    std::thread t3(Callable(), 4); // Creating "Callable()" in a fly, and then use it as a functor in different thread
    //+ Create a temp "Callable" and then temp "Callable" is moved into the thread object and then create the thread

    // the callable object does not have to be a functor, it can be a regular function, and it can be a lambda function.
    std::thread t4([](int n) {
        return n*n;
    }, 6);
    std::thread t5(foo, 6);
    
    // we can create a thread with the member functions:
    std::thread t6(&Callable::mul2, c, 6); // making a copy of Callable "c" and then invoke "Callable's mul2 function" with
    //+ 6 as a parameter in a different thread
    std::thread t7(&Callable::mul2, &c, 6); // passing "c" address, if I do not want to make a copy of "Callable c". and
    //+ will simply invoke c.mul2(6) in a different thread.

    // If I do not want to make a copy of "c" and I do not want to pass "c" as a reference, then I can use move function:
    std::thread t8(std::move(c), 6); // this will move "c" from the current thread to the child thread.
    //+ we need to be very careful that "c" is no longer usable in in main thread or in the parent thread.


    return 0;
}