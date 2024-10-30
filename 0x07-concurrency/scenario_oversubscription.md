# Oversubscription and thread pools with example
## Real World Scenario: Oversubscription
### Scenario: Image Processing for a Large Batch of Photos

Imagine you're developing a C++ application to process a batch of images. Each image needs to be loaded, processed (e.g., applying a filter), and saved back to disk. You might think of creating a separate thread for each image, which works fine if you’re dealing with a small number of images, but not if you have hundreds or thousands. On a system with limited cores, creating a thread per image will lead to oversubscription.

#### Problem Code: Creating One Thread per Image

Let's say we have 200 images to process. Here’s how oversubscription might occur:

```cpp
#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

void processImage(int imageId) {
    // Simulate image processing work
    std::cout << "Processing image " << imageId << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate processing time
}

int main() {
    const int num_images = 200; // Suppose we have 200 images

    std::vector<std::thread> threads;
    for (int i = 0; i < num_images; ++i) {
        threads.emplace_back(processImage, i);  // Create a thread per image
    }

    for (auto& t : threads) {
        t.join();  // Wait for all threads to complete
    }

    return 0;
}
```

In this code:
- We create a thread for each of the 200 images.
- If run on a system with 8 CPU cores, this will lead to significant oversubscription, as only 8 threads can run concurrently, and the other threads will have to wait, causing delays due to context switching.

#### Solution: Using a Thread Pool to Process the Images

To handle this efficiently, we can use a thread pool to limit the number of threads to a manageable level. The thread pool will keep a fixed number of threads running (matching the number of cores), and each thread will pick up a new image for processing once it’s finished with the previous one. 

Here’s how this could look:

```cpp
#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <chrono>

// ThreadPool class
class ThreadPool {
public:
    ThreadPool(size_t threads);
    ~ThreadPool();

    void enqueue(std::function<void()> task);

private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;

    std::mutex queue_mutex;
    std::condition_variable condition;
    bool stop;

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

// Simulate image processing work
void processImage(int imageId) {
    std::cout << "Processing image " << imageId << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate processing time
}

int main() {
    const int num_images = 200;
    const int num_threads = std::thread::hardware_concurrency(); // Number of hardware threads

    // Initialize thread pool
    ThreadPool pool(num_threads);

    for (int i = 0; i < num_images; ++i) {
        pool.enqueue([i] { processImage(i); });
    }

    return 0;
}
```

### Explanation

1. **Thread Pool Creation**: We create a thread pool with `num_threads` (typically equal to the number of CPU cores).
2. **Task Enqueuing**: Instead of creating a thread for each image, we add each image processing task to the pool. The pool will manage the threads.
3. **Efficient Resource Usage**: As threads in the pool complete an image processing task, they immediately pick up another from the queue until all images are processed. This approach maximizes CPU utilization without oversubscribing.

### Benefits of Using a Thread Pool

1. **Reduced Context Switching**: Only a limited number of threads (equal to available cores) are running, which reduces context-switching overhead.
2. **Improved Cache Utilization**: By reusing the same threads, we retain cache data relevant to each thread, enhancing performance.
3. **Better Resource Management**: The thread pool allows us to manage the number of threads and control system resources effectively, preventing oversubscription and maintaining efficiency.

-------

## What is thread pool?
A **thread pool** is a **design pattern** used in concurrent programming that manages a collection of pre-initialized worker threads. Instead of creating and destroying threads on-the-fly for each task, a thread pool maintains a pool of threads that can be reused to execute multiple tasks. This approach helps to improve performance, manage resources efficiently, and reduce the overhead associated with thread management.

#### Key Features of a Thread Pool

1. **Reusability**: Threads in the pool can be reused for multiple tasks, avoiding the overhead of creating and destroying threads repeatedly. This is particularly useful in applications where tasks are frequently created and destroyed.

2. **Controlled Concurrency**: A thread pool limits the number of concurrent threads that can run, which helps to avoid oversubscription and manage system resources effectively. This is especially important on systems with a limited number of CPU cores.

3. **Task Queue**: Tasks that need to be executed are placed in a queue. Worker threads from the pool take tasks from this queue and execute them. If no tasks are available, the worker threads can either wait or terminate based on the design of the thread pool.

4. **Management of Worker Threads**: A thread pool can dynamically manage the number of worker threads based on the workload, adjusting the number of active threads as needed.

#### Benefits of Using a Thread Pool

- **Performance Improvement**: By reusing threads and reducing the overhead of thread creation and destruction, applications can achieve better performance, particularly in high-load scenarios.

- **Resource Optimization**: Thread pools help to optimize the use of system resources, preventing excessive context switching and minimizing the potential for oversubscription.

- **Simplified Code Management**: Managing a fixed number of threads and delegating tasks to them simplifies the code structure, making it easier to handle concurrency without introducing complexity in thread management.
