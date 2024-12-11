#include <iostream>
#include <future>
#include <thread>

// suppose the factorial function needs to be computed many times, so
//+ instead of launching one thread to do the computation, I am going
//+ to launch many threads. 

int factorial(std::shared_future<int> f) {
    int res = 1;

    int n = f.get();
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    std::cout << "The result is: " << res << std::endl;
    return res;
}

int main() {
    std::promise<int> prom; // Create a promise
    std::future<int> f = prom.get_future(); // Get the associated future
    std::shared_future<int> shared_fut = f.share();
    std::future<int> fut = std::async(std::launch::async ,factorial, shared_fut);
    std::future<int> fut2 = std::async(std::launch::async ,factorial, shared_fut);
    std::future<int> fut3 = std::async(std::launch::async ,factorial, shared_fut);
    // and more threads.
    // I cannot pass the same future `fut` to all the threads, because each thread
    //+ can call the `f.get()` function only once, so if I have many threads then
    //+ they will call `f.get()` many times, which is not a good idea.
    //+ To deal with something like that you can make a many promises and many futures.
    //+ if you have 10 threads you will need 10 promises and 10 futures, so each thread
    //+ will get its own future, but that is clumsy.
    //+ We have an easier way solution using `shared_future`. a shared future can be copied.

    prom.set_value(4); // I will keep my promise
    // When using the shared future, when the parent thread set a value, all the child threads
    //+ will get the same value when they call `f.get()`. So the shared future is very convenient
    //+ when you have a broadcast kind of communication model. 

    return 0;
}
