# Variable Templates

In C++, **variable templates** allow you to define a variable that is parameterized by a template. **Introduced in C++14**, they are similar to function and class templates but are applied to variables instead. A variable template enables you to define a single variable that can operate with different types or values depending on the template arguments provided.

### Syntax of Variable Templates:

```cpp
template<typename T>
constexpr T pi = T(3.1415926535897932385);
```

In this example, `pi` is a variable template where the type `T` can vary. Depending on the type you pass, `pi` will adapt:

```cpp
double myPi = pi<double>;  // pi with double type
float myPiF = pi<float>;   // pi with float type
```

### Key points:
- **Parameterization**: Variable templates allow variables to be defined for different types using a template parameter.
- **constexpr**: It's common to use `constexpr` with variable templates when the value is known at compile time, but this is not mandatory.
- **Specialization**: You can specialize variable templates just like you can specialize function or class templates.

### Example of Variable Template Specialization:

```cpp
template<typename T>
constexpr T identity = T(0); // Generic case

template<>
constexpr int identity<int> = 42; // Specialization for int

int main() {
    std::cout << identity<double> << std::endl; // Outputs 0.0
    std::cout << identity<int> << std::endl;    // Outputs 42
}
```

This example shows how you can provide specialized values for specific types.

### Use Cases:
1. **Constants**: Useful for defining type-dependent constants.
2. **Traits**: Can be used in template metaprogramming where you might want to use different compile-time values based on the type.
