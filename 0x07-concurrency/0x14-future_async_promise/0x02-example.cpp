#include <iostream>
#include <future>
#include <thread>

int factorial(std::future<int>& f) {
    int res = 1;

    int n = f.get();
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    std::cout << "The result is: " << res << std::endl;
    return res;
}

int main() {
    int x;
    std::promise<int> prom;
    std::future<int> f = prom.get_future();
    std::future<int> fut = std::async(std::launch::async, factorial, std::ref(f));

    // suppose I do not need to get anything back from the child thread and after I took a nap
    //+ I totally forgot that I have promised to send a value to the child thread, so I have
    //+ broken my promise
    std::this_thread::sleep_for(std::chrono::seconds(2));
    // prom.set_value(4); // commenting this line to break the promise

    // what will happen after breaking the promise?
    // the f.get() function in the child thread will get an exception
    //+ with the error code std::future_errc::broken_promise
    //+ if I really cannot send a value and I know cannot send a value
    //+ then I can set exception to the promise
    prom.set_exception(std::make_exception_ptr(std::runtime_error("Promise broken"))); // try comment this line and run
    // now when the child thread called the `f.get()` function, it will get this exception
    //+ of runtime_error, so instead of sending over an exception of the infamous broken
    //+ promise, I can come up a fancy excuse for breaking my promise.
    
    // NOTE that niether promise nor future can be copied, they can only be moved, just like
    //+ the thread and the unique_lock. 
    return 0;
}
