#include <iostream>
#include <memory>

struct Node {
    std::weak_ptr<Node> next; // weak_ptr to avoid cyclic dependency
    ~Node() { std::cout << "Node destroyed\n"; }
};

int main() {
    std::shared_ptr<Node> node1 = std::make_shared<Node>();
    std::shared_ptr<Node> node2 = std::make_shared<Node>();

    node1->next = node2;
    node2->next = node1; // No cyclic reference here

    if (auto lockedPtr = node1->next.lock()) { // Lock the weak_ptr
        std::cout << "Node2 is still valid\n";
    } else {
        std::cout << "Node2 is expired\n";
    }

    if (auto lockedPtr = node2->next.lock()) { // Lock the weak_ptr
        std::cout << "Node1 is still valid\n";
    } else {
        std::cout << "Node1 is expired\n";
    }

    return 0;
}
