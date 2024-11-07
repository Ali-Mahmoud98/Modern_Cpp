#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>

/**
 * In the example:
 * The access of common resource "cout" is synchronized using mutex "mtx". It should
 * never happen that two threads are using cout at the same time as long as they are
 * all using `shared_print` function for printing.
 */

// std::mutex mtx;

// void shared_print(const std::string& message, const int& num) {
//     // mtx.lock(); // not recommended
//     std::lock_guard<std::mutex> guard(mtx); // recommended. RAII "Resource Acquisition Is Initialization" technique
//     // here whenever the guard goes out of scope, the mutex will always be unlocked with or without exceptions.

//     std::cout << message << num << std::endl; // there is a problem with this code. what if is this line throws
//     // an exception then the mutex "mtx" will end up being locked forever.
//     // it is recommended not to use the mutex's lock and unlock functions directly. instead use
//     // std::lock_guard.
//     // mtx.unlock(); // not recommended

//     // there is another problem with this program: the resource "cout" is not completely under the protection
//     // of the mutex "mtx" because "cout" is a global variable, so other threads can still use "cout" directly without
//     // goin through the lock.
//     // In order to protect the resource completely, a mutex must be bundled together with the resource.
//     // use the more enhanced version below.
// }

// More enhanced version
class LogFile {
public:
    LogFile() {
        file.open("log.txt");
    }

    ~LogFile() {
        file.close();
    }

    void shared_print(const std::string& message, const int& num) {
        std::lock_guard<std::mutex> guard(mtx);
        // the file will only accessed shared_print function.
        // "cout" is global, so it be accessed from anywhere in the program.
        file << message << num << std::endl;
    }

private:
    std::mutex mtx;
    std::ofstream file;
};

// void thread_function() {
//     for (int i = 0; i > -100; --i)
//         shared_print("From thread: ", i);
// }
void thread_function(LogFile& log) {
    for (int i = 0; i > -100; --i)
        log.shared_print("From thread: ", i);
}


int main() {
    LogFile log;

    // std::thread t1(thread_function);
    std::thread t1(thread_function, std::ref(log));
    // for (int i = 0; i < 100; ++i)
    //     shared_print("From main: ", i);
    for (int i = 0; i < 100; ++i)
        log.shared_print("From main: ", i);
    t1.join();
    return 0;
}
/**
 * Avoiding Data Race:
 * 1. Use mutex to synchronize data access.
 * 2. Never leak a handle of data to outside.
 * 3. Design interface appropriately.
 */
