// Handling Thread Safety with Custom Deleters
// use custom deleters with std::shared_ptr while ensuring thread safety.
// Using Custom Deleters with std::shared_ptr in a Multithreaded Environment
#include <iostream>
#include <memory>
#include <thread>
#include <vector>
#include <mutex>

std::mutex mtx;

struct Data {
    int value;
    Data(int val) : value(val) { std::cout << "Data created: " << value << "\n"; }
    ~Data() { std::cout << "Data destructed: " << value << "\n"; }
};

void customDeleter(Data* p) {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Custom deleter called for: " << p->value << "\n";
    delete p;
}

void useSharedPtr(std::shared_ptr<Data> data) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "Using data: " << data->value << "\n";
}

int main() {
    std::shared_ptr<Data> ptr1(new Data(1), customDeleter);
    
    std::vector<std::thread> threads;
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(useSharedPtr, ptr1); // Use the shared pointer in multiple threads
    }

    for (auto& th : threads) {
        th.join(); // Wait for all threads to finish
    }

    return 0;
}
