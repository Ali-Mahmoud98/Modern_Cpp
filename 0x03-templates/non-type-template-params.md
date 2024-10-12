### **Non-Type Template Parameters**

**Non-type template parameters** are template parameters that represent values (rather than types) and are known at compile time. While type template parameters are used to define generic data types, **non-type template parameters** allow you to pass compile-time constant values such as integers, pointers, or references to templates.

### **Explanation of Non-Type Template Parameters**

In a non-type template parameter, the template can accept a constant value rather than a type. These values are evaluated at compile time and allow templates to be parameterized by values like:
- **Integer constants**
- **Pointers**
- **References**

The values passed as non-type template parameters must be compile-time constants, and they are generally used when you want to configure a template with a fixed, constant value that doesn't change at runtime.

#### **Syntax:**
```cpp
template <typename T, int N>
class Array {
    T data[N];  // Fixed-size array
public:
    T& operator[](int index) { return data[index]; }
};
```

In this example:
- `T` is a **type template parameter**.
- `N` is an **integer non-type template parameter** used to specify the size of the array.

### **Using Integers, Pointers, and References as Template Parameters**

Non-type template parameters can be of several types, as long as their values are known at compile time:

#### 1. **Integer Values**
   Integer constants are the most common non-type template parameters. For example, they are often used to specify the size of arrays or other compile-time fixed values.
   
   ```cpp
   template <typename T, int Size>
   class FixedArray {
       T data[Size];
   public:
       FixedArray() = default;
       T& operator[](int index) { return data[index]; }
   };
   
   int main() {
       FixedArray<int, 10> array;  // Creates an array of size 10
       array[0] = 5;
       std::cout << array[0];  // Outputs 5
   }
   ```

   In this example:
   - The `Size` parameter specifies the size of the array at compile time, making the array fixed in size.

#### 2. **Pointer Values**
   You can also pass pointers as non-type template parameters. The pointer must be known at compile time, which usually limits this feature to `nullptr` or static/global variables.
   
   ```cpp
   template <typename T, T* Ptr>
   class PointerWrapper {
   public:
       void setValue(T value) { *Ptr = value; }
   };
   
   int globalValue = 42;

   int main() {
       PointerWrapper<int, &globalValue> wrapper;
       wrapper.setValue(100);  // Modifies the global variable
       std::cout << globalValue;  // Outputs 100
   }
   ```

   Here, `Ptr` is a non-type template parameter that holds a pointer to a global or static variable (`&globalValue`).

#### 3. **Reference Values**
   References can also be used as non-type template parameters. The reference must refer to a constant object or variable known at compile time.

   ```cpp
   template <int& Ref>
   class ReferenceWrapper {
   public:
       void increment() { Ref++; }
   };

   int globalCounter = 0;

   int main() {
       ReferenceWrapper<globalCounter> counterWrapper;
       counterWrapper.increment();  // Increments the globalCounter
       std::cout << globalCounter;  // Outputs 1
   }
   ```

   In this example, `Ref` is a reference to the global variable `globalCounter`, which is used as a non-type template parameter.

### **Common Use Cases for Non-Type Template Parameters**

Non-type template parameters are often used in scenarios where you need to pass compile-time constants into templates, especially for optimization and static configurations. Some common use cases include:

#### 1. **Fixed-Size Arrays**
   A typical use case is defining fixed-size arrays or containers where the size is a constant known at compile time.

   ```cpp
   template <typename T, int Size>
   class FixedArray {
       T arr[Size];
   public:
       T& operator[](int index) { return arr[index]; }
   };
   ```

   In this example, the array's size is determined by the template parameter `Size`, and it is enforced as a compile-time constant.

#### 2. **Matrix Dimensions**
   Another use case is in defining fixed-size matrices or multi-dimensional arrays.

   ```cpp
   template <typename T, int Rows, int Cols>
   class Matrix {
       T data[Rows][Cols];
   public:
       T& get(int row, int col) { return data[row][col]; }
   };
   ```

   This allows you to create matrices with predefined, fixed dimensions, such as `Matrix<int, 3, 3>` for a 3x3 matrix.

#### 3. **Policy or Behavior Control**
   Non-type template parameters can be used to control the behavior of a class or function. For example, you can pass a boolean flag as a template parameter to toggle certain features.

   ```cpp
   template <bool EnableLogging>
   class Logger {
   public:
       void log(const std::string& message) {
           if constexpr (EnableLogging) {
               std::cout << "Log: " << message << std::endl;
           }
       }
   };

   int main() {
       Logger<true> logger;  // Enables logging
       logger.log("Logging enabled");  // Outputs: Log: Logging enabled

       Logger<false> silentLogger;  // Disables logging
       silentLogger.log("No output");  // No output
   }
   ```

   Here, the boolean non-type template parameter `EnableLogging` controls whether the `log()` function outputs anything. This allows for conditional compilation based on the template argument.

#### 4. **Compile-Time Optimizations**
   Since non-type template parameters are evaluated at compile time, they allow the compiler to perform optimizations like constant folding, loop unrolling, and removing dead code, especially in template metaprogramming scenarios.

#### 5. **Handling Multiple Instances of Static Data**
   You can use non-type template parameters to differentiate between multiple instances of static data in templates.

   ```cpp
   template <int Id>
   class StaticCounter {
   public:
       static int value;
   };

   template <int Id>
   int StaticCounter<Id>::value = 0;

   int main() {
       StaticCounter<1>::value = 10;
       StaticCounter<2>::value = 20;

       std::cout << StaticCounter<1>::value << std::endl;  // Outputs 10
       std::cout << StaticCounter<2>::value << std::endl;  // Outputs 20
   }
   ```

   In this case, `StaticCounter<1>` and `StaticCounter<2>` are treated as separate classes, each with its own static `value`.

---

### **Summary of Non-Type Template Parameters**
- **Non-type template parameters** allow you to pass values (such as integers, pointers, and references) to a template instead of types.
- These parameters must be **compile-time constants**.
- They are commonly used to parameterize templates with fixed values, such as array sizes, matrix dimensions, or feature toggles.
- Common use cases include fixed-size arrays, compile-time optimizations, or static data management. They enable templates to behave more flexibly and efficiently by using known values during compilation.