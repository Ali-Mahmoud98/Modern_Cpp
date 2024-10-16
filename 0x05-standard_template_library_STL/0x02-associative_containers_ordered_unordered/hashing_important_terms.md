# Maps Important Terms
## Content:
* [What bucket means?](#what-bucket-means?)
* [What is the bucket size and bucket count?](#what-is-the-bucket-size-and-bucket-count)
* [Is the bucket in the context of map like in the context of set?](#is-the-bucket-in-the-context-of-map-like-in-the-context-of-set)
* [What is the load factor?](#what-is-the-load-factor)

## What bucket means?
In the context of hash tables, a **bucket** is a storage unit used to hold one or more elements that hash to the same index in the hash table. Buckets are crucial for managing hash collisions, which occur when different keys produce the same hash value and, consequently, map to the same bucket.

### Key Concepts Related to Buckets

1. **Hash Function**:
   - When a key is inserted into a hash table (like `std::unordered_map`), a hash function computes a hash code for that key. This hash code is then used to determine which bucket to place the key-value pair in.
   - The hash function must distribute keys uniformly across buckets to minimize collisions.

2. **Collision Handling**:
   - When two or more keys hash to the same bucket, a collision occurs. To handle this, hash tables can employ different strategies:
     - **Separate Chaining**: Each bucket contains a linked list (or another structure) that holds all elements that hash to the same bucket. This way, multiple elements can be stored in a single bucket.
     - **Open Addressing**: In this approach, if a collision occurs, the algorithm seeks the next available bucket based on a probing sequence until an empty bucket is found.

3. **Buckets in `std::unordered_map`**:
   - In `std::unordered_map`, buckets are automatically managed. The container internally maintains an array of buckets, and when you insert elements, they are placed into the appropriate bucket based on their hash value.
   - You can access the number of buckets using the `bucket_count()` method and check how many elements are in a specific bucket using `bucket_size(size_t n)`.

### Example Illustration

Here’s a simple illustration of how buckets work in a hash table:

1. **Keys and Hashing**:
   - Suppose you have keys `A`, `B`, `C`, and `D`.
   - A hash function maps these keys to bucket indices:
     - `A` -> Bucket 0
     - `B` -> Bucket 1
     - `C` -> Bucket 0 (collision with `A`)
     - `D` -> Bucket 2

2. **Bucket Storage**:
   - The hash table might look like this:
     ```
     Bucket 0: [A, C]
     Bucket 1: [B]
     Bucket 2: [D]
     ```

3. **Accessing Elements**:
   - When you search for a key, the hash function calculates its hash, finds the appropriate bucket, and then checks the bucket for the presence of that key (and potentially traverses a linked list if using separate chaining).

## what is the bucket size and bucket count?
In the context of `std::unordered_map` in C++, **bucket size** and **bucket count** are concepts related to how the underlying hash table is organized. Here's a detailed explanation of each:

### Bucket Count

- **Definition**: The **bucket count** refers to the number of buckets that the hash table uses to store elements.
- **Implementation**: When you insert a key-value pair into an `unordered_map`, a hash function computes the hash value for the key. This hash value is then used to determine which bucket (index) the element will be placed in.
- **Purpose**: The purpose of having multiple buckets is to help manage hash collisions. When two keys hash to the same bucket, they can be stored in the same bucket using a collision resolution method, such as separate chaining (using a linked list, for example) or open addressing.

### Bucket Size

- **Definition**: The **bucket size** refers to the number of elements stored in a specific bucket.
- **Implementation**: The bucket size can vary from bucket to bucket, depending on how many keys hash to the same bucket. If multiple keys map to the same bucket, the bucket size will be greater than 1.
- **Usage**: You can use the `bucket_size(size_t n)` method to get the size of a specific bucket `n`. This allows you to see how many elements are stored in that particular bucket.

### Example Usage

Here’s an example demonstrating how to obtain the bucket count and the bucket size in an `std::unordered_map`:

```cpp
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<int, std::string> myUnorderedMap;

    // Inserting elements into the unordered_map
    myUnorderedMap[1] = "One";
    myUnorderedMap[2] = "Two";
    myUnorderedMap[3] = "Three";
    myUnorderedMap[4] = "Four";

    // Get and display the bucket count
    size_t bucketCount = myUnorderedMap.bucket_count();
    std::cout << "Bucket Count: " << bucketCount << std::endl;

    // Get and display the size of each bucket
    for (size_t i = 0; i < bucketCount; ++i) {
        std::cout << "Bucket " << i << " size: " << myUnorderedMap.bucket_size(i) << std::endl;
    }

    return 0;
}
```

### Output Example

```
Bucket Count: 8
Bucket 0 size: 0
Bucket 1 size: 0
Bucket 2 size: 1
Bucket 3 size: 1
Bucket 4 size: 1
Bucket 5 size: 1
Bucket 6 size: 0
Bucket 7 size: 0
```

## Is the bucket in the context of map like in the context of set?
In C++, the concept of **buckets** applies similarly to both `std::unordered_map` and `std::unordered_set`, as both of these containers are based on hash tables. However, while they share a common underlying structure, their purpose and functionality differ. Here's a breakdown of how buckets are used in both contexts:

### Buckets in `std::unordered_map`

- **Purpose**: 
  - In `std::unordered_map`, buckets are used to store key-value pairs. Each bucket can hold one or more pairs, particularly when there are hash collisions (i.e., multiple keys that hash to the same bucket).
  
- **Collision Handling**: 
  - When two different keys produce the same hash code, they will be placed in the same bucket. The `unordered_map` uses separate chaining (typically with linked lists) to store multiple key-value pairs within a single bucket.

- **Accessing Buckets**: 
  - You can use methods like `bucket_count()` to find the total number of buckets and `bucket_size(size_t n)` to find out how many elements are in a specific bucket.

### Buckets in `std::unordered_set`

- **Purpose**: 
  - In `std::unordered_set`, buckets are used to store unique keys (elements). Since `unordered_set` does not have associated values, it only stores keys.
  
- **Collision Handling**: 
  - Similar to `unordered_map`, when two different keys hash to the same bucket, they will be placed there using the same collision resolution technique (separate chaining).

- **Accessing Buckets**: 
  - You can also use methods like `bucket_count()` to find the number of buckets and `bucket_size(size_t n)` to determine how many elements are in a specific bucket.

### Key Differences Between `unordered_map` and `unordered_set`

| Feature                | `std::unordered_map`             | `std::unordered_set`             |
|------------------------|----------------------------------|----------------------------------|
| **Stored Elements**     | Key-value pairs                  | Unique keys (no associated values) |
| **Purpose**            | Map keys to values               | Store unique elements             |
| **Collision Handling** | Allows multiple pairs in a bucket | Allows multiple elements in a bucket |
| **Accessing Elements** | Access via key                   | Access via key                   |

### Summary

- **Similar Concept**: Both `std::unordered_map` and `std::unordered_set` use buckets to manage elements and handle collisions through methods like separate chaining.
- **Different Usage**: The main difference lies in what they store: `unordered_map` stores key-value pairs, while `unordered_set` only stores unique keys.


## what is the load factor?
The **load factor** is a measure that describes how full a hash table (such as those used in `std::unordered_map` and `std::unordered_set` in C++) is, relative to its capacity. It plays a crucial role in determining the performance of hash tables, especially in terms of how often they may need to be resized or rehashed.

### Definition

The load factor (\( \lambda \)) is defined mathematically as:

\[
\text{Load Factor} = \frac{n}{b}
\]

Where:
- \( n \) = the number of elements (keys) stored in the hash table.
- \( b \) = the number of buckets (or slots) available in the hash table.

### Purpose of Load Factor

1. **Performance Indicator**:
   - The load factor helps assess how efficient a hash table is. A low load factor indicates that the hash table is underutilized, while a high load factor suggests that the hash table is becoming congested.

2. **Collision Management**:
   - A high load factor increases the likelihood of collisions (i.e., multiple keys hashing to the same bucket), which can degrade performance. As collisions increase, the average time for search, insert, and delete operations may approach O(n) instead of remaining O(1).

3. **Rehashing**:
   - When the load factor exceeds a certain threshold (typically around 0.7 to 0.75), the hash table may be resized. This involves creating a new, larger array of buckets and rehashing the existing elements into the new buckets. This process helps maintain efficient performance.

### Example Usage in C++

In C++, you can retrieve the load factor of an `std::unordered_map` or `std::unordered_set` using the `load_factor()` method. Here’s a simple example:

```cpp
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<int, std::string> myMap;

    // Inserting elements
    myMap[1] = "One";
    myMap[2] = "Two";
    myMap[3] = "Three";

    // Get the load factor
    float loadFactor = myMap.load_factor();
    std::cout << "Load Factor: " << loadFactor << std::endl;

    return 0;
}
```

## Conclusion
- **Bucket**: A fundamental unit in a hash table used to store elements that hash to the same index. Buckets help manage collisions and ensure efficient data retrieval.
- **Collision Handling**: Buckets allow for the storage of multiple elements through methods like separate chaining, enabling the hash table to maintain performance even when many keys hash to the same value.
- **Bucket Count**: Represents the total number of buckets in the `unordered_map`.
- **Bucket Size**: Represents the number of elements stored in a specific bucket.
- **Load Factor**: A critical metric that indicates how full a hash table is, calculated as the ratio of the number of stored elements to the number of available buckets.
- **Performance Impact**: Affects the efficiency of operations in hash tables, influencing collision rates and the need for rehashing.
- **Managing Load Factor**: Proper management of the load factor through resizing helps maintain optimal performance, ensuring average-case time complexity remains efficient. 