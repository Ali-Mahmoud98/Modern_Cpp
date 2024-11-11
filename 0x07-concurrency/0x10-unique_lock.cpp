// Unique lock (difference from lock_guard).
#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>

class LogFile {
private:
    std::mutex mtx;
    std::ofstream file;
public:
    LogFile() {
        file.open("log.txt");
    }
    ~LogFile() {
        file.close();
    }
    void shared_print(const std::string& message, const int& num) {
        // std::lock_guard<std::mutex> guard(mtx);
        // you can use std::unique_lock that standard library support which
        // can lock arbitrary number of lockable objects such as mutexes
        std::unique_lock<std::mutex> locker(mtx); // similar to std::lock_guard but it provides more flexibility
        file << message << num << std::endl;
        // على سبيل المثال بعد ما تطبع على الفايل ستريم في مجموعة حجات انت عايز تعملها والحجات مش بتتطلب
        // ان الميوتكس يكون معموله قفل او معموله لوك
        // with unique lock you can unlock the mutex then only `file << message << num << std::endl;` will be synchronized
        locker.unlock();
        // bunch of other things which are not needed to be synchronized

        // you can lock and unlock only sections which are needed to be synchronized
        // locker.lock();
        // file << message << num << std::endl;
        // locker.unlock();

        // unique lock provides a more flexible way to implement a final grand lock

        // with a unique lock you can even construct the locker without actually locking the mutex
        // to do that: std::unique_lock<std::mutex> locker(mtx, std::defer_lock);
        // now the locker is the owner of the mutex but the mutex not locked yet.
        // example:
        // std::unique_lock<std::mutex> locker(mtx, std::defer_lock);
        // /* bunch of code that does not use or access the ofstream file */
        // /* before using the ofstream file you will call locker.lock(); */
        // locker.lock();
        // file << message << num << std::endl;
        // locker.unlock();
        // then continue in this way
        
        // NOTE: So you can lock and unlock arbitrary number of times in the code which you cannot do with lock_guard
        // NOTE: the wrapper class of mutex whether it is lock_guard or unique_lock can never be copied, however a unique_lock can be moved
        // NOTE: when you move a unique lock you are transfering ownership of the mutex from one unique_lock to another unique_lock.
        // example: std::unique_lock<std::mutex> locker2 = std::move(locker);
        // NOTE: lock gaurd can never be moved

        // Question: if a unique lock is so much more flexible than lock_guard, why do I want to use a lock guard at all?
        // Answer: the flexibility of unique lock is not free. the unique lock is a little bit more heavy weighted than
        // a lock guard, so if the performance is what you really concerned about and don't really need the extra flexibility
        // of the unique lock, you might just use lock guard.  
    }
};

int main() {
    return 0;
}
