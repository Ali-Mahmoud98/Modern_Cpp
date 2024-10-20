# STL - std::reverse and std::rotate Algorithms
### 1. **`std::reverse`**

- **Purpose**: `std::reverse` is used to reverse the order of elements in a range (like an array or vector).
- **Syntax**:
  ```cpp
  std::reverse(first, last);
  ```
  - `first` and `last` are iterators defining the range to reverse. The range is half-open, meaning it includes `first` but excludes `last`.

- **Basic Usage**: If you have a list of elements, `std::reverse` will reorder them in the opposite order.

### 2. **`std::rotate`**

- **Purpose**: `std::rotate` rotates the elements in a range so that a specific element becomes the new beginning of the range. Elements before that point are shifted to the end.
- **Syntax**:
  ```cpp
  std::rotate(first, new_begin, last);
  ```
  - `first` and `last` define the range to rotate.
  - `new_begin` is the iterator pointing to the element that will become the first element of the new rotated range.

- **Basic Usage**: `std::rotate` is useful when you want to cyclically shift elements in a range.

### Step-by-Step Explanation

1. **`std::reverse(vec.begin(), vec.end());`**:
   - Reverses the entire vector.
   - Initially: `{1, 2, 3, 4, 5, 6}`.
   - After reversing: `{6, 5, 4, 3, 2, 1}`.

2. **`std::reverse(vec.begin() + 1, vec.end() - 1);`**:
   - Reverses the sub-range excluding the first and last elements.
   - Initially: `{6, 5, 4, 3, 2, 1}`.
   - After reversing the sub-range `[5, 4, 3, 2]`: `{6, 3, 4, 5, 2, 1}`.

3. **`std::rotate(vec.begin(), vec.begin() + 3, vec.end());`**:
   - Rotates the entire vector, making the element at index 3 (which is `4`) the new first element.
   - The initial vector is `{6, 3, 4, 5, 2, 1}`.
   - After rotation: `{4, 5, 2, 1, 6, 3}`.

4. **`std::rotate(vec.begin(), vec.begin() + 2, vec.begin() + 5);`**:
   - Rotates only the first 5 elements of the vector, making the element at index 2 (which is `2`) the new first element of the sub-range.
   - Initially: `{4, 5, 2, 1, 6, 3}`.
   - After rotating the first 5 elements: `{2, 1, 4, 5, 6, 3}`.

### Advanced Usage

You can use `std::reverse` and `std::rotate` in various ways:
- Reversing sub-ranges, such as reversing only part of a vector (as demonstrated).
- Rotating sub-ranges, which is useful in cyclic shifts, rearranging parts of a collection efficiently.

### Time Complexity

- **`std::reverse`**: The time complexity is **O(N)**, where N is the number of elements in the range to be reversed.
- **`std::rotate`**: The time complexity is also **O(N)**, where N is the number of elements in the range to be rotated.

### Use Cases

- **`std::reverse`**:
  - Useful in algorithms that require backtracking or reversing sequences (e.g., inverting a path in a graph or reversing a list of operations).
  
- **`std::rotate`**:
  - Often used when circular shifts are needed, such as when implementing round-robin scheduling, cyclic buffer manipulation, or rotating an array for dynamic positioning of elements.
