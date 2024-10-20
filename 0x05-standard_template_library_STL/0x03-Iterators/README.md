# Iterators
Iterators are a **generalization of pointers** that allow a C++ program to **work with different data structures** (for example, containers and ranges(since C++20)) in a uniform manner. The iterator library provides definitions for iterators, as well as iterator traits, adaptors, and utility functions.
<br>

Since iterators are an abstraction of pointers, their semantics are a generalization of most of the semantics of pointers in C++. This ensures that every function template that takes iterators works as well with regular pointers.
<br>

An **iterator is an object (like a pointer)** that points to an element inside the container. We can **use iterators to move through the contents** of the container.
They can be visualized as something similar to a pointer pointing to some location and we can access the content at that particular location using them. **Iterators play a critical role in connecting algorithm with containers** along with the manipulation of data stored inside the containers. 


## Resources
* [Introduction to Iterators - GFG](https://www.geeksforgeeks.org/introduction-iterators-c/)
* [C++ Iterators - C++ Reference](https://en.cppreference.com/w/cpp/iterator)
* [C++ Standard Library - Microsoft](https://learn.microsoft.com/en-us/cpp/standard-library/iterators?view=msvc-170)

### Types of iterators: Based upon the functionality of the iterators, they can be classified into five major categories:
* **Input Iterators:** They are the weakest of all the iterators and have very limited functionality. They can only be used in a single-pass algorithms, i.e., those algorithms which process the container sequentially, such that no element is accessed more than once.
* **Output Iterators:** Just like input iterators, they are also very limited in their functionality and can only be used in single-pass algorithm, but not for accessing elements, but for being assigned elements.
* **Forward Iterator:** They are higher in the hierarchy than input and output iterators, and contain all the features present in these two iterators. But, as the name suggests, they also can only move in a forward direction and that too one step at a time.
* **Bidirectional Iterators:** They have all the features of forward iterators along with the fact that they overcome the drawback of forward iterators, as they can move in both the directions, that is why their name is bidirectional.
* **Random-Access Iterators:** They are the most powerful iterators. They are not limited to moving sequentially, as their name suggests, they can randomly access any element inside the container. They are the ones whose functionality are same as pointers.

<br>

**NOTE:** To determine the type of iterator used by a specific container, refer to the Member Types section in the container's documentation on cppreference. This will help you understand which operations can be performed with that iterator.

#### Example: Finding the Iterator Type of `std::vector`

Suppose you are working with a `std::vector` in C++ and want to understand what kind of iterator it uses, as well as the operations supported by that iterator.

1. **Check the Documentation**: Go to the [cppreference page for `std::vector`](https://en.cppreference.com/w/cpp/container/vector).
   
2. **Find the Member Types**: In the documentation, locate the section called **Member Types**. and see the **Iterator** Definition.

3. **Iterator Category**: By looking at the **Member Types** section, you will see that `std::vector` uses a *LegacyRandomAccessIterator* and *LegacyContiguousIterator*. This means it supports operations such as:
   - Incrementing (`++` or `--` for moving forward or backward)
   - Accessing elements by index (`iterator + n` or `iterator[n]`)
   - Comparisons (`==`, `!=`, `<`, `<=`, `>`, `>=`)

This approach can be applied to other containers like `std::list`, `std::map`, or `std::set`, where the iterator type might differ (e.g., bidirectional iterators or input iterators). Each type has a different set of supported operations, and checking the **Member Types** section will help you understand the iterator’s capabilities.

### Example of making a custom iterator
see the files:
* [0x03-myArray.hpp](0x03-myArray.hpp)
* [0x03-myArray.cpp](0x03-myArray.cpp)

those files will help you understand how to make a custom iterator in a simple way.
