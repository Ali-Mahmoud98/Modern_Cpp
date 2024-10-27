### Thread Functions

| **Function/Type**                     | **Description**                                                                                           | **Example**                                                 |
|---------------------------------------|-----------------------------------------------------------------------------------------------------------|-------------------------------------------------------------|
| **`std::thread`**                     | Class representing a single thread of execution.                                                          | `std::thread t(myFunction);`                               |
| **`std::thread::join()`**            | Blocks the calling thread until the thread represented by the `std::thread` object has finished executing.| `t.join();`                                                |
| **`std::thread::detach()`**          | Allows the thread to run independently. After this, the thread cannot be joined.                         | `t.detach();`                                             |
| **`std::thread::get_id()`**          | Returns a unique identifier for the thread.                                                              | `std::thread::id tid = t.get_id();`                       |
| **`std::thread::joinable()`**        | Checks if the thread is joinable (i.e., not yet joined or detached).                                     | `if (t.joinable()) t.join();`                             |
| **`std::thread::swap()`**            | Exchanges the states of two `std::thread` objects.                                                       | `t1.swap(t2);`                                           |
| **`std::this_thread::sleep_for()`**  | Puts the current thread to sleep for a specified duration.                                               | `std::this_thread::sleep_for(std::chrono::seconds(1));`   |
| **`std::this_thread::sleep_until()`**| Puts the current thread to sleep until a specified time point.                                          | `std::this_thread::sleep_until(timePoint);`               |
| **`std::this_thread::get_id()`**     | Returns the ID of the calling thread.                                                                     | `std::thread::id myId = std::this_thread::get_id();`      |
| **`std::this_thread::yield()`**      | Hints to the implementation to yield the execution of the calling thread, allowing other threads to run.| `std::this_thread::yield();`                               |

### Thread Synchronization Functions

| **Function/Type**                     | **Description**                                                                                           | **Example**                                                 |
|---------------------------------------|-----------------------------------------------------------------------------------------------------------|-------------------------------------------------------------|
| **`std::mutex`**                      | Class that provides mutual exclusion for shared data.                                                   | `std::mutex mtx;`                                         |
| **`std::mutex::lock()`**             | Locks the mutex. If the mutex is already locked, the calling thread will block until it is unlocked.     | `mtx.lock();`                                             |
| **`std::mutex::unlock()`**           | Unlocks the mutex.                                                                                        | `mtx.unlock();`                                           |
| **`std::mutex::try_lock()`**         | Attempts to lock the mutex without blocking. Returns `true` if successful, `false` otherwise.           | `if (mtx.try_lock()) { /* ... */ mtx.unlock(); }`        |
| **`std::lock_guard`**                 | RAII-style mechanism for managing mutexes. Locks the mutex upon construction and unlocks it upon destruction.| `std::lock_guard<std::mutex> lock(mtx);`                 |
| **`std::unique_lock`**                | Provides more flexibility than `lock_guard`, allowing deferred locking and manual unlocking.              | `std::unique_lock<std::mutex> ul(mtx);`                  |
| **`std::condition_variable`**         | Used for signaling between threads. Allows threads to wait until notified.                                | `std::condition_variable cv;`                              |
| **`std::condition_variable::wait()`** | Blocks the calling thread until notified or spurious wakeup occurs.                                        | `cv.wait(lock);`                                         |
| **`std::condition_variable::notify_one()`** | Wakes up one waiting thread.                                                                             | `cv.notify_one();`                                        |
| **`std::condition_variable::notify_all()`** | Wakes up all waiting threads.                                                                            | `cv.notify_all();`                                        |

### Atomic Operations

| **Function/Type**                     | **Description**                                                                                           | **Example**                                                 |
|---------------------------------------|-----------------------------------------------------------------------------------------------------------|-------------------------------------------------------------|
| **`std::atomic<T>`**                 | Template class for atomic operations on shared data.                                                    | `std::atomic<int> count(0);`                               |
| **`std::atomic::load()`**            | Returns the current value of the atomic variable.                                                        | `int value = count.load();`                                 |
| **`std::atomic::store()`**           | Sets the value of the atomic variable.                                                                    | `count.store(10);`                                         |
| **`std::atomic::exchange()`**        | Sets the value and returns the old value of the atomic variable.                                         | `int oldValue = count.exchange(20);`                       |
| **`std::atomic::fetch_add()`**       | Atomically adds a value and returns the old value.                                                       | `int oldValue = count.fetch_add(1);`                       |
| **`std::atomic::fetch_sub()`**       | Atomically subtracts a value and returns the old value.                                                  | `int oldValue = count.fetch_sub(1);`                       |
| **`std::atomic::compare_exchange_strong()`** | Atomically compares and exchanges values.                                                             | `count.compare_exchange_strong(expected, desired);`        |

### Thread Utilities

| **Function/Type**                     | **Description**                                                                                           | **Example**                                                 |
|---------------------------------------|-----------------------------------------------------------------------------------------------------------|-------------------------------------------------------------|
| **`std::thread::hardware_concurrency()`** | Returns the number of concurrent threads supported by the implementation.                              | `unsigned int nThreads = std::thread::hardware_concurrency();` |
