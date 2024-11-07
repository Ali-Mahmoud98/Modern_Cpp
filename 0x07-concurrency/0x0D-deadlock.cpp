#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>

/**
 * in this example:
 * 
 */

class LogFile {
public:
    LogFile() {
        file.open("log.txt");
    }

    ~LogFile() {
        file.close();
    }

    void shared_print(const std::string& message, const int& num) {
        // std::lock_guard<std::mutex> locker1(mtx1);
        // std::lock_guard<std::mutex> locker2(mtx2);
        // the above order will cause deadlock
        // to avoid deadlock you can make sure every body is locking the mutexs in the same order
        // so you can lock locker1 then locker2 in the `shared_print2` or locker2 then locker1 in the `shared_print`
        // I will lock the mutex in the same order like shared_print2
        // std::lock_guard<std::mutex> locker2(mtx2);
        // std::lock_guard<std::mutex> locker1(mtx1);
        // you can use std::lock that standard library support which can lock arbitrary number of lockable objects such as mutexes
        // using certain deadlock avoidance algorithm.
        std::lock(mtx1, mtx2);
        std::lock_guard<std::mutex> locker1(mtx1, std::adopt_lock);
        std::lock_guard<std::mutex> locker2(mtx2, std::adopt_lock);
        
        // the file will only accessed shared_print function.
        // "cout" is global, so it be accessed from anywhere in the program.
        file << message << num << std::endl;
    }
    void shared_print2(const std::string& message, const int& num) {
        // std::lock_guard<std::mutex> locker2(mtx2);
        // std::lock_guard<std::mutex> locker1(mtx1);
        // example using std::lock
        std::lock(mtx2, mtx1);
        std::lock_guard<std::mutex> locker2(mtx2, std::adopt_lock);
        std::lock_guard<std::mutex> locker1(mtx1, std::adopt_lock);


        // the file will only accessed shared_print function.
        // "cout" is global, so it be accessed from anywhere in the program.
        std::cout << message << num << std::endl;
    }

private:
    std::mutex mtx1;
    std::mutex mtx2;
    std::ofstream file;
};


void thread_function(LogFile& log) {
    for (int i = 0; i > -100; --i)
        log.shared_print("From thread: ", i);
}


int main() {
    LogFile log;
    std::thread t1(thread_function, std::ref(log));
    for (int i = 0; i < 100; ++i)
        log.shared_print2("From main: ", i);
    t1.join();
    return 0;
}

/**
 * Avoiding Deadlocks:
 * 1. prefere to lock single mutex at a time
 * 2. avoid locking a mutex and then calling a user provided function
 * 3. use std::lock if you need to lock multiple mutexes at a time
 * 4. if using std::lock is not possible, then lock the mutexs in the same order
 * 
 * Locking Granularity:
 * 1. Fine-grained locking: protects a small amount of data
 * 2. Coarse-grained locking: protects a large amount of data
 */
