#include <iostream>
#include <future>
#include <functional>

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    // in thread I can do the following:
    std::thread t1(factorial, 4); // here I passed additional parameter to the constructor of the thread
    //+ and this parameter will be treated as a parameter to the function "factorial". I cannot do that for
    //+ the packaged task, I cannot pass additional parameter into the constructor of the packaged task:
    // std::packaged_task<int(int)> task(factorial, 6); // this will cause error
    //+ I can do the following:
    std::packaged_task<int()> task(std::bind(factorial, 4)); // here I bind the function "factorial" with the parameter 4,
    //+ then create a function object, and this function object is then passed to the constructor of the packaged task,
    //+ to create a packaged task. NOTE: The new constructed object cannot take any parameter.
    // task(6); // error
    task();
    // The main advantage of a packaged task is that it can link a callable object to a future, and that is very important
    //+ in a threading environment.

    return 0;
}
