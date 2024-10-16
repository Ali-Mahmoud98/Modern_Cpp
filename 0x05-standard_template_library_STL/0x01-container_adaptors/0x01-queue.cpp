#include <iostream>
#include <queue>
#include <string>

int main() {
    // Create a queue of integers
    std::queue<int> intQueue;

    // Adding elements to the queue (enqueue)
    intQueue.push(10);  // Add 10 to the back
    intQueue.push(20);  // Add 20 to the back
    intQueue.push(30);  // Add 30 to the back

    // Accessing the front and back elements
    std::cout << "Front element of intQueue: " << intQueue.front() << std::endl;  // Output: 10
    std::cout << "Back element of intQueue: " << intQueue.back() << std::endl;    // Output: 30

    // Removing the front element from the queue (dequeue)
    intQueue.pop();
    std::cout << "Front element after pop: " << intQueue.front() << std::endl;  // Output: 20

    // Checking if the queue is empty
    if (!intQueue.empty()) {
        std::cout << "Queue is not empty." << std::endl;
    }

    // Checking the size of the queue
    std::cout << "Size of intQueue: " << intQueue.size() << std::endl;  // Output: 2

    // Create a queue of strings
    std::queue<std::string> stringQueue;

    // Adding elements to the string queue
    stringQueue.push("Hello");
    stringQueue.push("World");

    // Accessing the front and back elements
    std::cout << "Front element of stringQueue: " << stringQueue.front() << std::endl;  // Output: Hello
    std::cout << "Back element of stringQueue: " << stringQueue.back() << std::endl;    // Output: World

    // Removing the front element from the string queue
    stringQueue.pop();
    std::cout << "Front element after pop: " << stringQueue.front() << std::endl;  // Output: World

    // Demonstrate dequeuing all elements
    while (!intQueue.empty()) {
        std::cout << "Dequeuing element: " << intQueue.front() << std::endl;
        intQueue.pop();  // Remove the front element
    }

    if (intQueue.empty()) {
        std::cout << "intQueue is now empty." << std::endl;
    }

    return 0;
}
