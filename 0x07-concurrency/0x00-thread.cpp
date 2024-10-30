#include <iostream>
#include <thread>
#include <chrono>
// use the following headers with detach
#include <sstream>
#include <fstream>

void function() {
    std::cout << "Hello from thread: " << std::this_thread::get_id() << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(10));
    std::cout << "Goodbye from thread: " << std::this_thread::get_id() << "\n";

    //////////////////////////////////////////////////////////////////
    // use the follwoing code with detach:
    // open file in write mode
    // std::ofstream outFile("file.txt");
    // if (!outFile) {
    //     std::cout << "Error opening file\n";
    //     return;
    // }

    // outFile << "Hello from thread: " << std::this_thread::get_id() << "\n";
    // std::this_thread::sleep_for(std::chrono::seconds(10));
    // outFile << "Goodbye from thread: " << std::this_thread::get_id() << "\n";
}

int main() {
    std::thread t(function); // t1 starts running
    //////////////////////////////////////////////////////////////////
    // 1. thread join
    t.join(); // main thread waits for t1 to finish
    // the code after t.join() won't be executed until t1 is finished
    
    // 2. detach
    // t.detach(); // separate the connection between main thread and t
    // t will run freely
    // std::this_thread::sleep_for(std::chrono::microseconds(200));
    // if (t.joinable()) { // t.joinable() will return 0 with detach
    //     t.join();
    // }
    // std::cout << "t.joinable() = " << t.joinable() << "\n";
    // NOTE: if the main thread finishes before t, t will not be executed
    //////////////////////////////////////////////////////////////////
    std::cout << "Hello from main thread: " << std::this_thread::get_id() << "\n";
    return 0;
}