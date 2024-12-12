#include <iostream>
#include <thread>
#include <deque>
#include <future>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <vector>
#include <functional>

// Simulate a task queue that holds packaged tasks
std::deque<std::packaged_task<std::string()>> task_q;
std::mutex task_q_mutex;
std::condition_variable task_q_cv;

// Function simulating a database query
std::string query_database(int query_id) {
    std::this_thread::sleep_for(std::chrono::seconds(2));  // Simulating a delay
    return "Result of query " + std::to_string(query_id);
}

// Worker thread that processes tasks from the queue
void worker_thread(int worker_id) {
    while (true) {
        std::packaged_task<std::string()> task;
        {
            std::unique_lock<std::mutex> lock(task_q_mutex);
            task_q_cv.wait(lock, [] { return !task_q.empty(); });

            // Pop a task from the queue
            task = std::move(task_q.front());
            task_q.pop_front();
        }

        // Execute the task
        // std::string result = task.get_future().get();
        // std::string result = task();
        task();
        // std::cout << "Worker " << worker_id << " finished task."<< std::endl;
    }
}

int main() {
    // Start worker threads
    const int num_workers = 3;
    std::vector<std::thread> workers;
    for (int i = 0; i < num_workers; ++i) {
        workers.push_back(std::thread(worker_thread, i + 1));
    }

    // Create and push tasks into the queue
    for (int i = 1; i <= 5; ++i) {
        // Create a packaged_task that simulates a database query
        std::packaged_task<std::string()> task(std::bind(query_database, i));
        
        // Get the future associated with the task
        std::future<std::string> f = task.get_future();
        
        {
            std::lock_guard<std::mutex> lock(task_q_mutex);
            task_q.push_back(std::move(task));  // Push the task into the queue
        }

        task_q_cv.notify_one();  // Notify one worker thread

        // Optionally, handle the future in the main thread (for demonstration)
        std::cout << "Main thread waiting for result of query " << i << std::endl;
        std::cout << "Result: " << f.get() << std::endl;
    }

    // Wait for all worker threads to finish (just for demonstration)
    for (auto& worker : workers) {
        worker.join();
    }

    return 0;
}
