#include <iostream>
#include <memory>  // For std::shared_ptr

struct Node {
    std::shared_ptr<Node> next;
    ~Node() { std::cout << "Node destroyed\n"; }
};

struct Node2 {
    std::weak_ptr<Node2> next;
    ~Node2() { std::cout << "Node destroyed\n"; }
};

int main() {
    // std::shared_ptr<Node> node1 = std::make_shared<Node>();
    // std::shared_ptr<Node> node2 = std::make_shared<Node>();

    // node1->next = node2;
    // node2->next = node1; // Cyclic reference

    // using weak_ptr
    std::shared_ptr<Node2> node2_weak = std::make_shared<Node2>();
    std::shared_ptr<Node2> node1_weak = std::make_shared<Node2>();

    node2_weak->next = node1_weak;
    node1_weak->next = node2_weak;

    return 0; // Memory leak, because the reference count never drops to zero.
}
