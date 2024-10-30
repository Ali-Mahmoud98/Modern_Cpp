#include <iostream>
#include <thread>

class ThreadRAII {
public:
    // DtorAction: Destructor Action
    enum class DtorAction { join, detach }; // Choose action in destructor

    ThreadRAII(std::thread t, DtorAction action)
        : t_(std::move(t)), action_(action) {
        if (!t_.joinable()) {
            throw std::logic_error("No thread to manage");
        }
    }

    // Destructor to join or detach the thread based on `DtorAction`
    ~ThreadRAII() {
        if (t_.joinable()) {
            if (action_ == DtorAction::join) {
                t_.join();
            } else {
                t_.detach();
            }
        }
    }

    // Delete copy operations to avoid unintended behavior
    ThreadRAII(const ThreadRAII&) = delete;
    ThreadRAII& operator=(const ThreadRAII&) = delete;

    // Move constructor and assignment to allow transfer of ownership
    ThreadRAII(ThreadRAII&& other) noexcept
        : t_(std::move(other.t_)), action_(other.action_) {}

    ThreadRAII& operator=(ThreadRAII&& other) noexcept {
        if (this != &other) {
            if (t_.joinable()) {
                if (action_ == DtorAction::join) {
                    t_.join();
                } else {
                    t_.detach();
                }
            }
            t_ = std::move(other.t_);
            action_ = other.action_;
        }
        return *this;
    }

private:
    std::thread t_; // Wrapped thread
    DtorAction action_; // Action to perform on destruction
};

void exampleFunction() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "Running in thread: " << std::this_thread::get_id() << ", i = " << i << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

int main() {
    try {
        // Create a thread and wrap it with RAII management
        ThreadRAII managedThread(std::thread(exampleFunction), ThreadRAII::DtorAction::join);
        // ThreadRAII managedThread2(std::thread(exampleFunction), ThreadRAII::DtorAction::detach);

        // `managedThread` goes out of scope here, and its destructor will
        // ensure that the thread is properly joined before exiting.
    } catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << "\n";
    }
    std::cout << "Hello from main thread: " << std::this_thread::get_id() << "\n";
    // Note: No need to explicitly join or detach the thread; it’s managed automatically.
}
