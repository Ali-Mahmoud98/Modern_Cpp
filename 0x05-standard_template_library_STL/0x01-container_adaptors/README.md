# Container adaptors

**Container adapters** in C++ are a subset of container types that provide a **restricted interface** over existing containers. They adapt the functionality of standard containers like `std::vector`, `std::deque`, or `std::list` to behave in specific ways, typically to restrict access to certain operations while providing a focused set of capabilities. 

The Standard Template Library (STL) in C++ provides three container adapters:

1. **`std::stack`** (LIFO structure)
2. **`std::queue`** (FIFO structure)
3. **`std::priority_queue`** (Priority-based structure)

These adapters limit the way you interact with the underlying container and expose only specific operations that align with their intended use (e.g., stack operations, queue operations).

### 1. `std::stack`
A **stack** is a **LIFO** (Last In, First Out) data structure. Elements are added and removed only from the top of the stack. The `std::stack` container adapter is built on top of other containers (usually `std::deque` or `std::vector`) and provides the functionality to push, pop, and access the top element.

- **Underlying container:** By default, `std::deque` is used, but you can also use `std::vector` or `std::list`.

### Resources
- [Stack](https://en.cppreference.com/w/cpp/container/stack)
- [Queue](https://en.cppreference.com/w/cpp/container/queue)
- [Priority Queue](https://en.cppreference.com/w/cpp/container/priority_queue)

#### Member Functions:
- **`push(const T& value)`**: Inserts a new element at the top of the stack.
- **`pop()`**: Removes the top element from the stack.
- **`top()`**: Returns a reference to the top element of the stack.
- **`empty()`**: Returns `true` if the stack is empty.
- **`size()`**: Returns the number of elements in the stack.

#### Example:
```cpp
#include <stack>
#include <iostream>

int main() {
    std::stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    
    std::cout << "Top element: " << s.top() << std::endl;  // Output: 30
    
    s.pop();
    std::cout << "Top after pop: " << s.top() << std::endl;  // Output: 20

    return 0;
}
```

### 2. `std::queue`
A **queue** is a **FIFO** (First In, First Out) data structure. Elements are added to the back and removed from the front. The `std::queue` container adapter is built on top of containers like `std::deque` (default) or `std::list` and provides operations to add to the back and remove from the front.

- **Underlying container:** By default, `std::deque` is used, but `std::list` can also be used.
  
#### Member Functions:
- **`push(const T& value)`**: Inserts a new element at the back of the queue.
- **`pop()`**: Removes the front element of the queue.
- **`front()`**: Returns a reference to the front element of the queue.
- **`back()`**: Returns a reference to the last element of the queue.
- **`empty()`**: Returns `true` if the queue is empty.
- **`size()`**: Returns the number of elements in the queue.

#### Example:
```cpp
#include <queue>
#include <iostream>

int main() {
    std::queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    
    std::cout << "Front element: " << q.front() << std::endl;  // Output: 10
    
    q.pop();
    std::cout << "Front after pop: " << q.front() << std::endl;  // Output: 20

    return 0;
}
```

### 3. `std::priority_queue`
A **priority queue** is a **heap-based** data structure where each element has a priority, and elements are served based on their priority rather than the order they were added. By default, `std::priority_queue` is implemented as a **max-heap**, where the largest element has the highest priority.

- **Underlying container:** By default, `std::vector` is used, but `std::deque` can also be used.
  
#### Member Functions:
- **`push(const T& value)`**: Inserts an element into the priority queue in the correct position based on its priority.
- **`pop()`**: Removes the element with the highest priority (i.e., the largest element by default).
- **`top()`**: Returns a reference to the element with the highest priority.
- **`empty()`**: Returns `true` if the queue is empty.
- **`size()`**: Returns the number of elements in the queue.

#### Example:
```cpp
#include <queue>
#include <iostream>

int main() {
    std::priority_queue<int> pq;
    pq.push(10);
    pq.push(20);
    pq.push(5);
    
    std::cout << "Top element: " << pq.top() << std::endl;  // Output: 20
    
    pq.pop();
    std::cout << "Top after pop: " << pq.top() << std::endl;  // Output: 10

    return 0;
}
```

### Summary of Container Adapters:

| **Container Adapter**   | **Underlying Containers**              | **Access Pattern**       | **Use Case**                                |
|-------------------------|----------------------------------------|--------------------------|---------------------------------------------|
| **`std::stack`**         | `std::deque` (default), `std::vector`, `std::list` | LIFO (Last In, First Out) | When you need stack-like behavior, e.g., function call stacks, parsing expressions. |
| **`std::queue`**         | `std::deque` (default), `std::list`    | FIFO (First In, First Out)| When you need queue-like behavior, e.g., scheduling tasks, buffering data.         |
| **`std::priority_queue`**| `std::vector` (default), `std::deque`  | Priority-based            | When you need to process elements by priority, e.g., job scheduling, Dijkstra's algorithm. |

### Important Points to Remember:
1. **Underlying Container**: Each container adapter can use different types of containers underneath. For example, `std::stack` can use `std::deque`, `std::vector`, or `std::list`.
2. **Restricted Interface**: Container adapters provide a restricted interface that exposes only specific operations, hiding the full capabilities of the underlying container.
3. **Efficient for Certain Use Cases**: Each adapter is designed for a specific access pattern (LIFO for `stack`, FIFO for `queue`, etc.), making them efficient for certain use cases but less flexible than the full containers they wrap.

These container adapters are useful when you need to implement specific data structures with a controlled set of operations, making code clearer and easier to maintain.
