// std::shared_ptr with Multithreading
// Example: Create multiple threads that share ownership of a std::shared_ptr and safely increment a counter.
#include <iostream>
#include <memory>
#include <thread>
#include <vector>
#include <mutex>

std::mutex mtx; // Mutex for protecting shared data

void incrementCounter(std::shared_ptr<int> counter) {
    for (int i = 0; i < 1000; ++i) {
        // Lock the mutex to ensure thread safety when modifying the counter
        std::lock_guard<std::mutex> lock(mtx);
        ++(*counter);
    }
}

int main() {
    auto counter = std::make_shared<int>(0); // Create a shared pointer to an integer
    // create a vector to store the threads
    std::vector<std::thread> threads;

    // Create multiple threads
    for (int i = 0; i < 10; ++i) {
        // Pass a shared pointer to the counter to each thread
        threads.emplace_back(incrementCounter, counter); // direct construction of thread objects in a container
    }

    // Join all threads
    for (auto& th : threads) {
        th.join();
    }

    // Print the final count
    std::cout << "Final counter value: " << *counter << std::endl; // Should be 10000
    return 0;
}
