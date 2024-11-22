#include <iostream>
#include <thread>
#include <mutex>
#include <deque>
#include <condition_variable>

std::deque<int> buffer;
std::mutex mtx;
std::condition_variable condition_var;

// producer of the data
void function1() {
    int count = 10;
    while (count > 0) {
        std::unique_lock<std::mutex> lock(mtx);
        buffer.push_front(count);
        lock.unlock();
        // after pushing the data and unlocking the mutex, we notify the condition variable
        condition_var.notify_one(); // Notify one waiting thread, if there is one
        // this will wake up one thread if any that is waiting on this condition variable
        std::this_thread::sleep_for(std::chrono::seconds(1));
        count--;
    }
}

// consumer of the data function2
// first way without condition variable.
// void function2() {
//     int data = 0;
//     while (data != 1) {
//         std::unique_lock<std::mutex> lock(mtx);
//         if (!buffer.empty()) {
//             data = buffer.back();
//             buffer.pop_back();
//             lock.unlock();
//             std::cout << "t2 got a value from t1: " << data << std::endl;
//         } else {
//             lock.unlock();
//             std::this_thread::sleep_for(std::chrono::milliseconds(10)); // fist way
//         }
//     }
// }

// second way with condition variable
void function2() {
    int data = 0;
    while (data != 1)
    {
        std::unique_lock<std::mutex> lock(mtx);
        // condition_var.wait(lock); // this will put thread two into sleep untill being notified by thread one
        // كدا كل حاجه المفروض تبق تمام طول ما الثريد التاني في حالة الانتظار
        // و ممكن يقوم و يشتغل في حالة واحده بس و هي اخطاره عن طريق الثريد الاول
        // لكن في الحقيقه دي مش الحالة لان الثريد التاني ممكن يقوم نفسه و ده يطلق عليه
        // spurious wake
        // في الحالة دي احنا مش عايزين الثريد يكمل وعايزينه يرجع يثبت او ينام تاني
        // so the wait function can take another parameter which is a predicate that determines whether the
        // condition is really met for the thread to continue running:
        condition_var.wait(lock, [] { return !buffer.empty(); }); // if the thread is waked up it will check if the queue is empty or not
        // if the queue is empty it will sleep again. and if the queue is not empty then the thread will wake up and continue and pop up
        // the data.
        data = buffer.back();
        buffer.pop_back();
        lock.unlock();
        std::cout << "t2 got a value from t1: " << data << std::endl;
        // Another thing to note is there could be another more than one thread that is waiting for the same condition, and in this case
        // when calling `notify_one()` it only wakes up one thread. if you want to wake up all threads you can use `notify_all()`.  
    }
}

// in this example we have 2 threads and shared resource `buffer` and we used a mutex to synchronize access to it and avoid data race problem.
// However there is another problem, the thread 2 in a busy waiting state it keeps checking if the `buffer` is empty or not, and
// the `buffer` is empty it will unlock the locker and  immediatly go to the next loop, so it will keep looping.
// busy waiting is very inefficient.
// how can we make the program more efficient?
// one way to do that is if the queue is empty, we let the thread to take a nap, and then go to the next loop, this will reduce the number
// of loops (see the line has comment says "fisrt way"), but the problem is how to deside the nap time?, if the snap is too short
// then the thread will still end up spending a lot of time looping, and if the time is too long then it may not be able to get the data in time
// so it is very hard to find the best number and this is where the condition variable comes in.
//
// the second way is using the condition variable. with the mutex we will use the condition variable to notify the thread when the queue is not empty.

int main() {
    // the main function is simple. it creates two threads, thread 1 with function1 and thread 2 with function2
    // and then wait for both threads to finish
    std::thread t1(function1);
    std::thread t2(function2);
    t1.join();
    t2.join();
    return 0;
}
