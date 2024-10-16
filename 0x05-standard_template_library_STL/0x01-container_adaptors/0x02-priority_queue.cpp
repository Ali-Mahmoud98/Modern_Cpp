#include <iostream>
#include <queue>
#include <vector>
#include <functional> // For std::greater and std::less

int main() {
    // Create a max-heap priority queue (default behavior)
    // max-heap means the largest element has the highest priority
    std::priority_queue<int> maxHeap;

    // Adding elements to the priority queue
    maxHeap.push(10);
    maxHeap.push(30);
    maxHeap.push(20);
    maxHeap.push(5);

    // Displaying the top element
    std::cout << "Top element (max): " << maxHeap.top() << std::endl;  // Output: 30

    // Removing the top element (which is the largest)
    maxHeap.pop();
    std::cout << "Top element after pop: " << maxHeap.top() << std::endl;  // Output: 20

    // Iterating through the priority queue by popping all elements
    std::cout << "Popping all elements from maxHeap: ";
    while (!maxHeap.empty()) {
        std::cout << maxHeap.top() << " ";  // Display the top element
        maxHeap.pop();  // Remove the top element
    }
    std::cout << std::endl;

    // Create a min-heap priority queue by using std::greater<int>
    // min-heap means the smallest element has the highest priority
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    // Adding elements to the min-heap
    minHeap.push(10);
    minHeap.push(30);
    minHeap.push(20);
    minHeap.push(5);

    // Displaying the top element (smallest element)
    std::cout << "Top element (min): " << minHeap.top() << std::endl;  // Output: 5

    // Removing the top element (which is the smallest)
    minHeap.pop();
    std::cout << "Top element after pop: " << minHeap.top() << std::endl;  // Output: 10

    // Iterating through the min-heap by popping all elements
    std::cout << "Popping all elements from minHeap: ";
    while (!minHeap.empty()) {
        std::cout << minHeap.top() << " ";  // Display the top element
        minHeap.pop();  // Remove the top element
    }
    std::cout << std::endl;

    return 0;
}
