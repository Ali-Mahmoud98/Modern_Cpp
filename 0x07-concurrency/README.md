# Concurrency
Concurrency in C++ is a powerful feature that enables developers to create applications capable of performing multiple tasks simultaneously.

Concurrency refers to the ability to process multiple tasks or threads at the same time. It is used to improve the program’s performance and response time. In this article, we will discuss how concurrency is achieved in C++ and what are its benefits.

Genrally there are two kinds of concurrent programming models:
* Multiprocessing: each process has only one thread running, and all the processes communicate with each other through the regular **interprocess communication** channels (such as files, pipes, message queues, and etc).
* Multithreading: One process contains two or more threads and all the threads communicate with each other through **shared memory**.
    * **Pros:**
        * **Fast to start** (it is usually slow and complicated to start a process because the operating system needs to devote a bunch of internal resources to manage the process). **A thread is considered as a light-weight process**.
        * **Low overhead** (thread takes lower overhead in running). A process has more overhead (**example:** the OS needs to provide a lot of protection for the process, so that one process will not accedently step onto another process). **Communicating through shared memory is a lot faster** than communicating through interprocess communication channels.
    * **Cons:**
        * **Difficult to implement**: there are bunch of threading specific issues that needs to be carefully handled.
        * **Cannot run on distributed systems** (A multiprocessing program can be easily distributed to multiple computers and long concurrently)

**Note:** Multithreading provides better performance than multiprocessing.

<dev align="center">
  <p><img src="./process_vs_thread.png" alt="Process vs. Thread"></p>
  <p> Process vs. Thread </p>
</dev>

## Resources:
- [Concurrency in C++ : Multithreading and Concurrent Programming](https://medium.com/@lfoster49203/concurrency-in-c-multithreading-and-concurrent-programming-ccf81110c284)
- [Concurrency in C++ - GeeksforGeeks](https://www.geeksforgeeks.org/cpp-concurrency/)

## Examples and Multithreading Topics Explaination:
### Constructing a Thread
* [0x00-thread.cpp](./0x00-thread.cpp): this explains thread `join` and `detach`.
* [0x01-thread.cpp](./0x01-thread.cpp): thread lifecycle management issue.
* [0x02-thread.cpp](./0x02-thread.cpp): this explains constructing a thread with lambda function, regular function, and functor.
* [0x03-thread.cpp](./0x03-thread.cpp): this explains in details constructing a thread with functors.
* [0x04-thread.cpp](./0x04-thread.cpp): this explains in details constructing a thread with RAII.
* [0x05-thread.cpp](./0x05-thread.cpp): passing arguments to a thread using `std::ref`.

### Oversubscription
* [0x06-thread.cpp](./0x06-thread.cpp): getting maximum number of threads supported by hardware.
* [0x07-design_oversubscription.md](./0x07-design_oversubscription.md): explains Oversubscription in Multithreading.
* [0x08-scenario_oversubscription.md](./0x08-scenario_oversubscription.md): Example of Oversubscription and thread pools.

### Resource Management in Multithreading
* [0x09-data_race_and_mutex.md](./0x09-data_race_and_mutex.md): explains Data Race problems and how to solve them.
* [0x0A-thread_data_race.cpp](./0x0A-thread_data_race.cpp): data race example.
* [0x0B-thread_mutex.cpp](./0x0B-thread_mutex.cpp): solving data race by using mutex example.

### Multithreading Design Problems
* [0x0C-deadlock.md](./0x0C-deadlock.md): explains Deadlock problem and how to avoid it.
* [0x0D-deadlock.cpp](./0x0D-deadlock.cpp): Deadlock example.
* [0x0E-locking_granularity.md](./0x0E-locking_granularity.md): explains what is locking granularity.
