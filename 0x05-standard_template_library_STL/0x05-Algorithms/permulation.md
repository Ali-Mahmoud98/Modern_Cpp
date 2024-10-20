# STL Algorithms - std::next_permutation and std::prev_permutation
### 1. **`std::next_permutation`**

- **Purpose**: `std::next_permutation` rearranges elements in the range `[first, last)` into the **next lexicographically greater permutation**. If such a permutation exists, the function returns `true`; otherwise, the range is rearranged to the smallest (i.e., sorted in ascending order), and `false` is returned.
- **Syntax**:
  ```cpp
  std::next_permutation(first, last);
  ```

- **Basic Example**:
  Given the sequence `{1, 2, 3}`, the next permutations are:
  - `{1, 2, 3}` → `{1, 3, 2}` → `{2, 1, 3}` → and so on.

### 2. **`std::prev_permutation`**

- **Purpose**: `std::prev_permutation` rearranges elements in the range `[first, last)` into the **previous lexicographically smaller permutation**. If such a permutation exists, the function returns `true`; otherwise, the range is rearranged to the largest (i.e., sorted in descending order), and `false` is returned.
- **Syntax**:
  ```cpp
  std::prev_permutation(first, last);
  ```

- **Basic Example**:
  Given the sequence `{3, 2, 1}`, the previous permutations are:
  - `{3, 2, 1}` → `{3, 1, 2}` → `{2, 3, 1}` → and so on.
