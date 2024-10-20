# STL Algorithms - Non-Modifying Algorithms 
Non-modifying algorithms in C++ are algorithms that operate on a range of elements but do not modify the elements themselves. These algorithms are part of the C++ Standard Template Library (STL) and typically work with iterators. Here's a detailed explanation of some key non-modifying algorithms:

### 1. **`std::find`**
**Purpose:**  
Finds the first occurrence of a value in a given range of elements.

**Syntax:**  
```cpp
template <class InputIterator, class T>
InputIterator find(InputIterator first, InputIterator last, const T& value);
```

- **Parameters:**
  - `first`: Iterator to the beginning of the range.
  - `last`: Iterator to the end of the range.
  - `value`: The value to search for.

- **Returns:**  
  An iterator pointing to the first occurrence of the element that equals `value`. If no such element is found, it returns the `last` iterator.

- **Example:**
  ```cpp
  #include <iostream>
  #include <vector>
  #include <algorithm>

  int main() {
      std::vector<int> vec = {1, 2, 3, 4, 5, 6};
      auto it = std::find(vec.begin(), vec.end(), 4);

      if (it != vec.end()) {
          std::cout << "Element found at position: " << std::distance(vec.begin(), it) << std::endl;
      } else {
          std::cout << "Element not found!" << std::endl;
      }
  }
  ```
  **Output:**  
  `Element found at position: 3`

---

### 2. **`std::count`**
**Purpose:**  
Counts how many times a specific value appears in a range of elements.

**Syntax:**  
```cpp
template <class InputIterator, class T>
typename iterator_traits<InputIterator>::difference_type 
count(InputIterator first, InputIterator last, const T& value);
```

- **Parameters:**
  - `first`: Iterator to the beginning of the range.
  - `last`: Iterator to the end of the range.
  - `value`: The value to count.

- **Returns:**  
  The number of times `value` appears in the range `[first, last)`.

- **Example:**
  ```cpp
  #include <iostream>
  #include <vector>
  #include <algorithm>

  int main() {
      std::vector<int> vec = {1, 2, 3, 1, 4, 1, 5};
      int count_of_ones = std::count(vec.begin(), vec.end(), 1);

      std::cout << "Number of 1s in the vector: " << count_of_ones << std::endl;
  }
  ```
  **Output:**  
  `Number of 1s in the vector: 3`

---

### 3. **`std::equal`**
**Purpose:**  
Compares two ranges for equality. The ranges are considered equal if all corresponding elements are equal.

**Syntax:**  
```cpp
template <class InputIterator1, class InputIterator2>
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2);
```

- **Parameters:**
  - `first1`: Iterator to the beginning of the first range.
  - `last1`: Iterator to the end of the first range.
  - `first2`: Iterator to the beginning of the second range.

- **Returns:**  
  `true` if all corresponding elements are equal, otherwise `false`.

- **Example:**
  ```cpp
  #include <iostream>
  #include <vector>
  #include <algorithm>

  int main() {
      std::vector<int> vec1 = {1, 2, 3};
      std::vector<int> vec2 = {1, 2, 3};

      if (std::equal(vec1.begin(), vec1.end(), vec2.begin())) {
          std::cout << "The vectors are equal!" << std::endl;
      } else {
          std::cout << "The vectors are not equal!" << std::endl;
      }
  }
  ```
  **Output:**  
  `The vectors are equal!`

---

### 4. **`std::mismatch`**
**Purpose:**  
Finds the first position where two ranges differ.

**Syntax:**  
```cpp
template <class InputIterator1, class InputIterator2>
std::pair<InputIterator1, InputIterator2> mismatch(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2);
```

- **Parameters:**
  - `first1`: Iterator to the beginning of the first range.
  - `last1`: Iterator to the end of the first range.
  - `first2`: Iterator to the beginning of the second range.

- **Returns:**  
  A pair of iterators:  
  - The first iterator points to the first differing element in the first range.
  - The second iterator points to the first differing element in the second range.

- **Example:**
  ```cpp
  #include <iostream>
  #include <vector>
  #include <algorithm>

  int main() {
      std::vector<int> vec1 = {1, 2, 3, 4};
      std::vector<int> vec2 = {1, 2, 5, 4};

      auto result = std::mismatch(vec1.begin(), vec1.end(), vec2.begin());

      if (result.first != vec1.end()) {
          std::cout << "First mismatch: " << *result.first << " and " << *result.second << std::endl;
      } else {
          std::cout << "No mismatch found!" << std::endl;
      }
  }
  ```
  **Output:**  
  `First mismatch: 3 and 5`

---

### 5. **`std::search`**
**Purpose:**  
Searches for the first occurrence of a subsequence in a range.

**Syntax:**  
```cpp
template <class ForwardIterator1, class ForwardIterator2>
ForwardIterator1 search(ForwardIterator1 first1, ForwardIterator1 last1,
                        ForwardIterator2 first2, ForwardIterator2 last2);
```

- **Parameters:**
  - `first1`: Iterator to the beginning of the first range.
  - `last1`: Iterator to the end of the first range.
  - `first2`: Iterator to the beginning of the subsequence to search for.
  - `last2`: Iterator to the end of the subsequence.

- **Returns:**  
  An iterator pointing to the beginning of the first occurrence of the subsequence. If the subsequence is not found, it returns `last1`.

- **Example:**
  ```cpp
  #include <iostream>
  #include <vector>
  #include <algorithm>

  int main() {
      std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
      std::vector<int> sub = {4, 5, 6};

      auto it = std::search(vec.begin(), vec.end(), sub.begin(), sub.end());

      if (it != vec.end()) {
          std::cout << "Subsequence found at position: " << std::distance(vec.begin(), it) << std::endl;
      } else {
          std::cout << "Subsequence not found!" << std::endl;
      }
  }
  ```
  **Output:**  
  `Subsequence found at position: 3`

---

These algorithms are very useful in various real-world scenarios where searching, counting, or comparing data is required, and the fact that they don't modify the original range makes them highly efficient for read-only operations.
