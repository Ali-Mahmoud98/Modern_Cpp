# Oversubscription in Multithreading
In multithreading, *oversubscription* occurs when the number of active threads in a program exceeds the number of available hardware execution units, such as CPU cores or hyper-threads, in the system. In C++, this issue typically arises when multiple threads are created but there aren’t enough physical cores to handle each thread simultaneously. Oversubscription can lead to performance problems, like increased context-switching overhead, cache misses, and ultimately reduced efficiency due to time spent scheduling threads rather than executing them.

### How Oversubscription Happens in C++

In C++, oversubscription often results from code that creates a large number of threads without accounting for the number of physical cores. This can happen in several ways:

1. **Loop-based thread creation**: Developers might create a thread in each iteration of a loop without limiting the number of threads to the system's core count. 
2. **Nested parallelism**: If one thread creates additional threads (e.g., a parallel task inside another parallel task), it can quickly multiply the number of threads beyond the available cores.
3. **Using third-party libraries**: Some libraries may internally create threads that are not immediately visible to the developer, leading to unintended oversubscription when combined with explicit thread creation in user code.

### Effects of Oversubscription

Oversubscription leads to performance degradation due to:

- **Increased context switching**: When the system has more threads than it can run in parallel, it must switch between threads frequently, which incurs overhead.
- **Cache thrashing**: Frequent context switches can disrupt CPU cache utilization, as each thread may need to reload data into the cache.
- **Contention for shared resources**: Multiple threads might compete for memory bandwidth and other system resources, causing delays.
- **Lowered performance for I/O-bound and CPU-bound tasks**: In CPU-bound tasks, oversubscription can slow down processing as threads compete for CPU cycles; for I/O-bound tasks, it can exacerbate the time waiting on I/O completion.

### Managing Oversubscription

To avoid oversubscription in C++:

1. **Limit thread count**: Limit the number of threads based on `std::thread::hardware_concurrency`, which provides the number of hardware threads (usually cores or hyper-threads) available. For example:

   ```cpp
   unsigned int max_threads = std::thread::hardware_concurrency();
   ```

2. **Thread pools**: Use a thread pool to control the number of active threads. A thread pool allows you to reuse threads and limit the maximum number of threads created, avoiding oversubscription.

3. **Task-based parallelism**: Modern C++ libraries, like C++17’s `<execution>` library, support parallel algorithms that manage threading efficiently. Libraries like Intel Threading Building Blocks (TBB) or OpenMP also help in optimizing thread creation based on available resources.

By considering these strategies, developers can avoid oversubscription and ensure efficient multithreaded performance in C++ programs.

### Example: Oversubscription by Creating Too Many Threads

Let’s say you have a program where you spawn a thread for each element in a large array to perform some computation. If your system has only 4 CPU cores, and you create hundreds of threads, this will likely lead to oversubscription.

Here’s an example of oversubscription:

```cpp
#include <iostream>
#include <thread>
#include <vector>

// Function to simulate some work
void work(int id) {
    std::cout << "Thread " << id << " is doing some work\n";
    // Simulating workload
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

int main() {
    const int num_tasks = 100;  // Simulate 100 tasks

    // Creating a thread for each task
    std::vector<std::thread> threads;
    for (int i = 0; i < num_tasks; ++i) {
        threads.emplace_back(work, i);
    }

    // Join all threads
    for (auto& t : threads) {
        t.join();
    }

    return 0;
}
```

In this code:
- We create 100 threads, each of which does some simulated work.
- If run on a system with only 4 CPU cores, oversubscription occurs because only 4 threads can run concurrently, while the other threads must wait their turn.
  
This leads to a lot of context switching, increased cache misses, and reduced performance.

### Solution: Using a Thread Pool to Avoid Oversubscription

A thread pool limits the number of threads to the available hardware threads, reusing them for multiple tasks. Here’s how to implement a simple thread pool to avoid oversubscription.

```cpp
#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>

// ThreadPool class
class ThreadPool {
public:
    ThreadPool(size_t threads);
    ~ThreadPool();

    // Add a new task to the pool
    void enqueue(std::function<void()> task);

private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;

    std::mutex queue_mutex;
    std::condition_variable condition;
    bool stop;

    // Worker thread function
    void worker_thread();
};

ThreadPool::ThreadPool(size_t threads) : stop(false) {
    for (size_t i = 0; i < threads; ++i) {
        workers.emplace_back(&ThreadPool::worker_thread, this);
    }
}

ThreadPool::~ThreadPool() {
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        stop = true;
    }
    condition.notify_all();
    for (std::thread &worker : workers) {
        worker.join();
    }
}

void ThreadPool::enqueue(std::function<void()> task) {
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        tasks.push(std::move(task));
    }
    condition.notify_one();
}

void ThreadPool::worker_thread() {
    while (true) {
        std::function<void()> task;
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            condition.wait(lock, [this]{ return stop || !tasks.empty(); });
            if (stop && tasks.empty()) return;
            task = std::move(tasks.front());
            tasks.pop();
        }
        task();
    }
}

void work(int id) {
    std::cout << "Thread " << id << " is doing some work\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

int main() {
    const int num_tasks = 100;
    const int num_threads = std::thread::hardware_concurrency(); // Number of hardware threads

    // Initialize thread pool with a limited number of threads
    ThreadPool pool(num_threads);

    for (int i = 0; i < num_tasks; ++i) {
        pool.enqueue([i] { work(i); });
    }

    return 0;
}
```

In this code:

- We create a `ThreadPool` class with a limited number of threads, based on `std::thread::hardware_concurrency()`—typically the number of available cores or hyper-threads.
- Instead of creating a thread for each task, we add tasks to the thread pool with `enqueue`, and a limited number of threads pick up tasks as they become available.
- When each thread completes a task, it immediately checks for a new one, which helps in efficiently utilizing CPU resources without oversubscribing.

