// std::shared_ptr with Multiple Threads Accessing Shared Data
// multiple threads read from a shared resource while one thread writes to it.
#include <iostream>
#include <memory>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>

std::mutex read_mtx;
std::mutex write_mtx;

void readData(std::shared_ptr<int> data) {
    for (int i = 0; i < 10; ++i) {
        {
            std::lock_guard<std::mutex> lock(read_mtx);
            std::cout << "Read value: " << *data << " from thread " << std::this_thread::get_id() << "\n";
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void writeData(std::shared_ptr<int> data) {
    for (int i = 0; i < 10; ++i) {
        {
            std::lock_guard<std::mutex> lock(write_mtx);
            (*data) += 1; // Increment the shared data
            std::cout << "Written value: " << *data << " from thread " << std::this_thread::get_id() << "\n";
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

int main() {
    auto sharedData = std::make_shared<int>(0); // Shared integer

    std::vector<std::thread> readers, writers;

    // Create writer thread
    writers.emplace_back(writeData, sharedData);
    
    // Create multiple reader threads
    for (int i = 0; i < 5; ++i) {
        readers.emplace_back(readData, sharedData);
    }

    // Join all threads
    for (auto& writer : writers) {
        writer.join();
    }
    for (auto& reader : readers) {
        reader.join();
    }

    return 0;
}
