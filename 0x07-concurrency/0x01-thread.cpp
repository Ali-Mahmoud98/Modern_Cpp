#include <iostream>
#include <thread>
#include <chrono>

int function1() {
    std::cout << "Hello from thread: " << std::this_thread::get_id() << "\n";
    return 0;
}

int main() {
    // NOTE: thread object can be constructed not only with a regular function but also with any callable object
    // like lambda, or functor
    std::thread t(function1); // t1 starts running
    // if the thread t1 destroys before the thead is joined or detached then your program will terminate
    // so you to make a desicion whether you want to join the thread or detach the thread before t1 goes out of scope
    // try1:
    // std::cout << "Hello from main thread: " << std::this_thread::get_id() << "\n";
    // std::cout << "main: ";
    // for (int i = 0; i < 100; ++i) {
    //     std:: cout << i << " ";
    //     std::this_thread::sleep_for(std::chrono::microseconds(100)); // here try to comment this and run then uncomment it and run again
    //     // if you used sleep the thread will be termintaed before the join called
    // }
    // std::cout << "\n";
    // t.join();
    // try2: (comment try1)
    // try {
    //     std::cout << "Hello from main thread: " << std::this_thread::get_id() << "\n";
    //     std::cout << "main: ";
    //     for (int i = 0; i < 100; ++i) {
    //         std:: cout << i << " ";
    //         // std::this_thread::sleep_for(std::chrono::microseconds(100));
    //     }
    //     std::cout << "\n";
    // }
    // catch (...) {
    //     t.join();
    //     throw;
    // }
    ///////////////////////////////////
    // Resource Acquisition Initialization Approach "RAII"
    // we create a wrapper class that wraps t, and in the destructor of the wrapper class
    // we will call t.join() ot t.detach() in the destructor of the wrapper class
    // See example 0x04-thread.cpp

    return 0;
}