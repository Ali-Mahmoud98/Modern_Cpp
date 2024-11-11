// Unique lock (difference from lock_guard).
// How to handle lazy initialization in the threading invironment?
#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>

class LogFile {
private:
    std::mutex mtx;
    // std::mutex mtx_open; // comment that with example 3
    std::once_flag flag;
    std::ofstream file;
public:
    LogFile() {
        // file.open("log.txt");
    }
    ~LogFile() {
        file.close();
    }
    void shared_print(const std::string& message, const int& num) {

        // example1: (not thread safe)
        // if (!file.is_open()) {
        //     std::unique_lock<std::mutex> locker2(mtx_open);

        //     file.open("log.txt"); // the file will be opened only once in the shared_print function
        //     // this is known as lazy initialization or initialization upon first use idiom
        //     // next thing I want to do is to make sure that this program is thread safe
        //     // to do that we need mutex to synchronize the file openning process
            
        //     // We will not reuse the mutex "mtx" because this print is used to print messages in file
        //     // and the print messages could happen many times but the file only needs to be opened once
        // }
        // std::unique_lock<std::mutex> locker(mtx);
        // file << message << num << std::endl;
        
        // this is not thread safe:
        // say I have two threads running thread "A" and thread "B"
        // thread "A" found the file is not open and it go and lock the mutex and start openning file
        // before it opens the file thread "B" also and found that the file is not open, so it also try to lock the mutex
        // and of course beeing blocked over here.
        // once thread "A" has opened the file and exit the "if" block thread "B" will git the mutex, and thread "B" will open the file
        // again, so the file will be opened twice by two threads, so not only "open()" function need to be synchronized
        // also the "is_open()" function need to be synchronized.

        // example2: (thread safe) - but has a problem
        // {
        //     std::unique_lock<std::mutex> locker2(mtx_open);
        //     if (!file.is_open()) {
        //         file.open("log.txt");
        //     }
        // }
        // std::unique_lock<std::mutex> locker(mtx);
        // file << message << num << std::endl;

        // this example introduces another problem: the file only need to be opened once, but now every time
        // we call "the shared_print()" the program will lock the mutex and check if the file opened or not
        // and then unlock the mutex, so all this locking and unlocking are purely wasting the of computer
        // cycles, and more importantly those extra useless locking and unlocking of the mutex hinders the program
        // from being run concurrently.

        // example3: solving example2 and example1 problem
        // the standard library introduced "std::once_flag", I will use it instead of another mutex 
        std::call_once(flag, [&]() {
            file.open("log.txt");
        }); // file will be opened only once. And lambda function will be called only by one thread
        std::unique_lock<std::mutex> locker(mtx);
        file << message << num << std::endl;
    }
};

int main() {
    return 0;
}