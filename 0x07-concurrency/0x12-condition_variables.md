# Condition Variables in C++ Multithreading

We use mutex to synchronize the access to a shared or common resource among the threads in C++ multithreading. we will talk about another synchronization issue which using mutex alone cannot help us to solve the problem. see example: [0x13-condition_variables.cpp](0x13-condition_variables.cpp)

In C++, the condition variable is a synchronization primitive that is used to notify the other threads in a multithreading environment that the shared resource is free to access. It is defined as the `std::condition_variable` class inside the `<condition_variable>` header file.
