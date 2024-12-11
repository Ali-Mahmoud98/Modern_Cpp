# Future, Async, and Promise
see the following example:
```cpp
#include <iostream>
#include <thread>

using namespace std;

void factorial(int n) {
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    cout << "Factorial of " << n << " is " << res << endl;
}

int main() {
    std::thread t1(factorial, 4);
    t1.join(); // wait to t1 to finish
    return 0;
}
```
In this example we have a function factorial which computes a factorual of a number "n", and in a main function we create a thread "t1" to compute
factorial of 4, so thread t1 will compute the factorial of 4 and print the result to standard output. (good and this program will run well)

But we do not just print the result to the standard out, we want to return the result from the child thread to the parent thread to do somthing with it.
We can do that like the following:
```cpp
#include <iostream>
#include <thread>

using namespace std;

void factorial(int n, int& x) {
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    // cout << "Factorial of " << n << " is " << res << endl;
    x = res;
}

int main() {
    int x;
    std::thread t1(factorial, 4, std::ref(x));
    t1.join(); // wait to t1 to finish
    return 0;
}
```
In this example the variable "x" is shared between the child and parent threads, so we will need to protect it with mutex and we also want to make sure that
the child thread will set the variable "x" first and the the parent thread go ahead and fetch the variable, so we may also need the condition variable. So our code structure will become pretty messy, does it have be this complecated?. All I need to do is launch a thread and get the result from the thread.

The standard library provides us an easier way to do that. So instead of using thread object to create a thread  we can use `std::async`. like:
```cpp
std::async(factorial, 4);
```
The `std::thread` is a class and `std::async` is a function, and this function returns `std::future`.
```cpp
std::future<int> fut = std::async(factorial, 4); // the fut is a channel to get the result from the child thread

//getting the result
int res;
res = fut.get();
// future object can call get() function only once, the program will crash if we call fut.get() again
```
The new shape of the `factorial` function is:
```cpp
int factorial(int n) {
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
    }

    return res;
}
```
**NOTE:** the `std::async` may or may not craete another thread. and that can be controlled by another parameter:
* to make the `std::async` to not create a new thread:
```cpp
std::future<int> fut = std::async(std::launch::deferred, factorial, 4);
```
* to make the `std::async` to create a new thread:
```cpp
std::future<int> fut = std::async(std::launch::async, factorial, 4);
```
* the default value of first parameter is like:
```cpp
std::future<int> fut = std::async(std::launch::deferred | std::launch::async ,factorial, 4);
// the above line of code is same as the following line:
// std::future<int> fut = std::async(factorial, 4); // exactly the same
```

### **0. Examples**
- [0x00-example.cpp](./0x00-example.cpp)
- [0x01-example.cpp](./0x01-example.cpp)
- [0x02-example.cpp](./0x02-example.cpp)
- [0x03-example.cpp](./0x03-example.cpp)

### **1. Basics**

#### **What Are They?**
These are part of the C++ Standard Library and provide mechanisms for **asynchronous operations** and **thread management**.

1. **`std::async`**:
   - A high-level function to run a task asynchronously (in a separate thread).
   - Simplifies multithreading by abstracting thread creation and synchronization.

2. **`std::future`**:
   - A mechanism to access the result of an asynchronous computation.
   - Represents a "placeholder" for the result that is being calculated.

3. **`std::promise`**:
   - A way to explicitly set a value or an exception that a `std::future` will eventually hold.
   - You create a promise, retrieve its associated future, and then fulfill the promise in your code.

---

### **2. Step-by-Step Explanation**

#### **`std::async`**
- It is used to launch a function in a new thread (or possibly run it synchronously).
- Returns a `std::future` object that can be used to retrieve the function's result.

##### **Example**
```cpp
#include <iostream>
#include <future>

int compute_sum(int a, int b) {
    return a + b;
}

int main() {
    // Launch async task
    std::future<int> result = std::async(std::launch::async, compute_sum, 10, 20);

    // Do other work here (if needed)

    // Get the result (blocks if the task is still running)
    std::cout << "Result: " << result.get() << std::endl;

    return 0;
}
```

**Key Points**:
- **`std::launch::async`**: Forces the task to run asynchronously.
- The `get()` method blocks the calling thread until the result is ready.

---

#### **`std::future`**
- Represents the result of an asynchronous computation.
- Can only be retrieved once via `get()`.
- Provides methods to check the status:
  - `valid()`: Checks if the `std::future` contains a result.
  - `wait()`: Blocks until the result is available.
  - `wait_for()`/`wait_until()`: Wait for a specified amount of time or until a deadline.

##### **Example**
```cpp
#include <iostream>
#include <future>
#include <thread>
#include <chrono>

int slow_task() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return 42;
}

int main() {
    std::future<int> fut = std::async(std::launch::async, slow_task);

    std::cout << "Waiting for result..." << std::endl;

    // Wait for the result for 1 second
    if (fut.wait_for(std::chrono::seconds(1)) == std::future_status::timeout) {
        std::cout << "Still waiting..." << std::endl;
    }

    // Get the result (blocks if not ready)
    std::cout << "Result: " << fut.get() << std::endl;

    return 0;
}
```

**Key Points**:
- `std::future_status::timeout`: Indicates the result isn't ready yet.
- `std::future_status::ready`: The result is ready.

---

#### **`std::promise`**
- Used to set a value (or exception) that a `std::future` will retrieve.
- You explicitly link the producer (the thread setting the value) with the consumer (the thread accessing the value).

##### **Example**
```cpp
#include <iostream>
#include <future>
#include <thread>

void producer(std::promise<int> prom) {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    prom.set_value(10); // Set the result
}

void consumer(std::future<int> fut) {
    std::cout << "Waiting for value..." << std::endl;
    std::cout << "Received value: " << fut.get() << std::endl;
}

int main() {
    std::promise<int> prom;              // Create a promise
    std::future<int> fut = prom.get_future(); // Get associated future

    std::thread prod(producer, std::move(prom)); // Producer thread
    std::thread cons(consumer, std::move(fut));  // Consumer thread

    prod.join();
    cons.join();

    return 0;
}
```

**Key Points**:
- **`set_value()`**: Sets the result.
- **`get_future()`**: Retrieves the `std::future` tied to the promise.

---

### **3. Advanced Usage**

#### **Combining `std::async`, `std::future`, and `std::promise`**
You can combine these tools for flexible threading scenarios. For instance, using promises to pass results between threads and `std::future` to retrieve them.

---

#### **Exception Handling**
- A promise can set an exception that a future will receive.

##### **Example**
```cpp
#include <iostream>
#include <future>
#include <exception>
#include <thread>

void producer_with_error(std::promise<int> prom) {
    try {
        throw std::runtime_error("An error occurred!");
    } catch (...) {
        prom.set_exception(std::current_exception()); // Pass the exception
    }
}

int main() {
    std::promise<int> prom;
    std::future<int> fut = prom.get_future();

    std::thread prod(producer_with_error, std::move(prom));

    try {
        std::cout << "Value: " << fut.get() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    prod.join();
    return 0;
}
```

**Key Points**:
- **`set_exception()`**: Sets an exception instead of a value.
- The future's `get()` method will rethrow the exception.

---

#### **Shared Futures**
- Use `std::shared_future` to allow multiple threads to access the same result.

##### **Example**
```cpp
#include <iostream>
#include <future>
#include <thread>

void task(std::shared_future<int> shared_fut) {
    std::cout << "Received value: " << shared_fut.get() << std::endl;
}

int main() {
    std::promise<int> prom;
    std::shared_future<int> shared_fut = prom.get_future().share();

    std::thread t1(task, shared_fut);
    std::thread t2(task, shared_fut);

    prom.set_value(42);

    t1.join();
    t2.join();

    return 0;
}
```

**Key Points**:
- Unlike `std::future`, `std::shared_future` allows multiple calls to `get()`.

---

### **4. Performance and Best Practices**
1. Use `std::async` for simple, one-off asynchronous tasks.
2. Use `std::promise` and `std::future` for more complex producer-consumer patterns.
3. Prefer `std::shared_future` if multiple threads need to access the same result.
4. Always handle exceptions properly in both the promise and the future.
