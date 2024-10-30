#include <iostream>
#include <thread>
#include <chrono>
#include <functional> // for std::ref
// example of thread with parameter

struct Functor {
    void operator()(std::string& name) {
        std::cout << "Hello from functor thread: " << std::this_thread::get_id() << "\n";
        std::cout << "Name: " << name << "\n";
        name = "Ahmed";
    }
};

void function(std::string& name) {
    std::cout << "Hello from function thread: " << std::this_thread::get_id() << "\n";
    std::cout << "Name: " << name << "\n";
    name = "Mohamed";
}

int main() {
    std::string name = "Ali";
    // std::thread t((Functor()), name); // this line will cause error:
    // The error you're encountering is due to the fact that you're trying to pass a
    // non-const reference (std::string&) to a thread, which isn't allowed because
    // threads require their arguments to be copyable or movable. You can solve this issue by
    // using std::ref to pass the string by reference
    std::thread t((Functor()), std::ref(name)); // std::ref is a reference wrapper to name
    std::thread t2(function, std::ref(name));
    std::thread t3([&]() {
        std::cout << "Hello from lambda thread: " << std::this_thread::get_id() << "\n";
        std::cout << "Name: " << name << "\n";
        name = "Youssef";
    });
    std::thread t4([](const std::string& name){
        std::cout << "Hello from lambda thread2: " << std::this_thread::get_id() << "\n";
        std::cout << "Name: " << name << "\n";
    }, name);
    std::thread t5([](std::string& name){
        std::cout << "Hello from lambda thread3: " << std::this_thread::get_id() << "\n";
        std::cout << "Name: " << name << "\n";
        name = "Zeyad";
    }, std::ref(name));

    t.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    std::cout << "Hello from main: " << std::this_thread::get_id() << "\n";
    std::cout << "Name: " << name << "\n";
    return 0;
}