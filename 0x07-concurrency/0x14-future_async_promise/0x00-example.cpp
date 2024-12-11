#include <iostream>
// #include <thread>
#include <future>

int factorial(int n) {
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    std::cout << "The result is: " << res << std::endl;
    return res;
}

int main() {
    std::future<int> fut = std::async(std::launch::async ,factorial, 4);
    int res = fut.get();
    std::cout << "Factorial of 4 is " << res << std::endl;
    return 0;
}
