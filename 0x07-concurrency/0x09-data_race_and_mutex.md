# Multi-Threaded Programming: Data Race and Mutexes
### 1. **Understanding Data Race**
In the context of multi-threading, a **data race** occurs when two or more threads access the same memory location (variable) at the same time, and at least one of those accesses is a write. When this happens, the outcome is often unpredictable because:

   - The value of the variable may change unexpectedly.
   - Different threads may overwrite each other's work, leading to inconsistencies and bugs.

Imagine this simple scenario:

```cpp
#include <iostream>
#include <thread>

int counter = 0;

void increment() {
    for (int i = 0; i < 1000; ++i) {
        ++counter;
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "Counter: " << counter << std::endl;
    return 0;
}
```

Here, two threads (`t1` and `t2`) are simultaneously trying to increment the `counter` variable. Each thread performs multiple increments, but since both are accessing and modifying `counter` at the same time, the final result may vary every time you run the program. This unpredictable behavior is a **data race**. In a multi-threaded environment, without protection, the `++counter` operation is **not atomic** (it’s made up of multiple steps), so threads may interrupt each other, creating inconsistent states.

### 2. **Solving Data Races with Mutexes**
A **mutex** (short for "mutual exclusion") is a synchronization tool that can prevent data races by allowing only one thread at a time to access the shared resource. A mutex has two key operations:

   - **Lock**: A thread locks the mutex before accessing the shared data.
   - **Unlock**: After finishing with the data, the thread unlocks the mutex, allowing other threads to proceed.

Let’s rewrite the above code with a `std::mutex` to avoid data races:

```cpp
#include <iostream>
#include <thread>
#include <mutex>

int counter = 0;
std::mutex mtx;

void increment() {
    for (int i = 0; i < 1000; ++i) {
        mtx.lock();   // Lock the mutex
        ++counter;    // Critical section
        mtx.unlock(); // Unlock the mutex
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "Counter: " << counter << std::endl;
    return 0;
}
```

In this code:

1. Before incrementing `counter`, each thread calls `mtx.lock()`, which locks the mutex.
2. Only one thread can hold the lock at a time, so if `t1` locks it first, `t2` must wait until `t1` unlocks it.
3. The `++counter` line is now protected, so only one thread can increment `counter` at any given time.
4. After incrementing, the thread releases the lock by calling `mtx.unlock()`.

Using a mutex like this **ensures that only one thread accesses the critical section** at any time, eliminating the data race.

### 3. **Using `std::lock_guard` for Safer Code**
While using `mtx.lock()` and `mtx.unlock()` works, it can be error-prone, especially if the function has multiple return points or exceptions, making it easy to forget to unlock the mutex. C++ provides a safer alternative, `std::lock_guard`, which locks the mutex when created and automatically unlocks it when it goes out of scope:

```cpp
void increment() {
    for (int i = 0; i < 1000; ++i) {
        std::lock_guard<std::mutex> guard(mtx); // Locks mtx at the start of the scope
        ++counter; // Critical section
    } // guard is destroyed here, automatically unlocking mtx
}
```

### 4. **Summary**
   - **Data Race**: Occurs when multiple threads access and modify the same data simultaneously without proper synchronization, leading to unpredictable results.
   - **Mutex**: A synchronization tool that prevents data races by allowing only one thread to access a shared resource at a time.
   - **std::lock_guard**: A RAII wrapper that ensures a mutex is properly locked and unlocked, even if exceptions or early returns occur.

Using mutexes and understanding data races are essential skills in multi-threaded programming in C++. By effectively synchronizing access to shared data, you can prevent bugs and ensure that your programs behave predictably.