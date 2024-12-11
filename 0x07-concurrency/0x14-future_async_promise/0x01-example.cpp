#include <iostream>
#include <future>
#include <thread>

// we use the future to pass a variable from the child thread to the parent thread.

// we use the future and promise to pass a variable from the parent thread to the child thread
//+ not at the time of creation the thread but some time later in the future.

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
    std::promise<int> prom; // Create a promise
    std::future<int> f = prom.get_future(); // Get the associated future
    std::future<int> fut = std::async(std::launch::async ,factorial, std::ref(f));
    
    /**
     * punch of code here
     */
    // simulating some work
    std::this_thread::sleep_for(std::chrono::seconds(2));
    // after doing some work, I will keep my promise
    prom.set_value(4); // I will keep my promise
    // after setting the value 4 the child thread will get the value from the promise

    int res = fut.get();
    std::cout << "Factorial of 4 is " << res << std::endl;
    // Note that the both promise and future are template classes with the type of `int`
    //+ because the value we are transmitting over is an `int`. and `fu` also is a template class
    //+ of type `int` because the return type of the function `factorial` is `int`.
    return 0;
}
