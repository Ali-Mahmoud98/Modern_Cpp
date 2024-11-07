#include <iostream>
#include <thread>

/**
 * Data race:
 * Here (in this example) we have two thread running and both threads are racing for the common resource "cout".
 * 
 * Race condition is a condition where the outcome of a program depends on the relative execution order of two or more threads.
 * Race is not good for our program, and we should try to avoid it.
 * 
 * One way to avoid race condition is to use `mutex`, to synchronize access to the shared or common resource.
 * 
 * Shared resource may be:
 * 1. I/O stream (like cout)
 * 2. file
 * 3. database
 * 4. network
 * 5. containers
 * 6. Global or Static Variables
 * 7. Class Member Variables
 */

void thread_function() {
    for (int i = 0; i > -100; --i)
        std::cout << "From thread: " << i << std::endl;
}

int main() {
    std::thread t1(thread_function);
    for (int i = 0; i < 100; ++i)
        std::cout << "From main: " << i << std::endl;
    t1.join();
    return 0;
}