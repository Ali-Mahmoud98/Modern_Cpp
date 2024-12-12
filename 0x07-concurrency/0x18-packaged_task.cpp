#include <iostream>
#include <future>
#include <functional>
#include <deque>

// Let's say we have a task queue task_q which is a deque of packaged tasks.
std::deque<std::packaged_task<int()>> task_q;
// In the main function, I don't want to execute the task "t", which is not very helpful.
//+ Instead, after creating the task "t", I'll push it into the task queue "task_q".
//+ Hopping that somebody will pop off the task "t" and execute it in an appropriate time,
//+ and this somebody would be another thread.

// we will need mutex to handle the shared resource "task_q":
std::mutex task_q_mutex;
std::condition_variable task_q_cv;

void thread1() {
    std::packaged_task<int()> t;
    {
        std::unique_lock<std::mutex> lock(task_q_mutex);
        task_q_cv.wait(lock, [] { return !task_q.empty(); });
        t = std::move(task_q.front());
        task_q.pop_front();
    }
    t();
}

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    std::thread t1(thread1);
    // The main advantage of a packaged task is that it can link a callable object to a future, and that is very important
    //+ in a threading environment.
    std::packaged_task<int()> t(std::bind(factorial, 4));
    // to get the return value:
    std::future<int> f = t.get_future();

    {
        std::lock_guard<std::mutex> lock(task_q_mutex);
        // task_q.push_back(t);
        task_q.push_back(std::move(t));
    }
    task_q_cv.notify_one();

    // print the result:
    std::cout << f.get() << std::endl;

    // So now the main thread will create a task then push it into task_q then the thread1 will pop off the task from the
    //+ task_q and then execute the task.

    t1.join();
    return 0;
}
