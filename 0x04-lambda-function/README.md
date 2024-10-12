# Lambda Function

## Resources:
* [Lambda expressions in C++ - Microsoft](https://learn.microsoft.com/en-us/cpp/cpp/lambda-expressions-in-cpp?view=msvc-170)
* [Lambda expression in C++ - GFG](https://www.geeksforgeeks.org/lambda-expression-in-c/)


### Syntax of Lambda Expressions
In C++11 and later, a lambda expression—often called a lambda—is a convenient way of defining an anonymous function object (a closure) right at the
location where it's invoked or passed as an argument to a function. Typically lambdas are used to encapsulate a few lines of code that are passed to
algorithms or asynchronous functions. This article defines what lambdas are, and compares them to other programming techniques.
It describes their advantages, and provides some basic examples.

Lambda expression can be defined as follows:
```c++
[ capture clause ] (parameters) -> return-type  
{   
   definition of method   
} 
```

Generally, the return-type in lambda expressions is evaluated by the compiler itself and we do not need to specify it explicitly.
Also the -> return-type part can be ignored.  However, in some complex cases e.g. conditional statements, the compiler cannot determine the return type
and explicit specification is required.

#### Each part of this syntax has a specific role:

1. Capture List or capture clause (`[]`): This specifies which external variables are captured (i.e., made available) inside the lambda function and how they are captured (by value or by reference). The capture list can be:
* `[ ]` → No capture, meaning the lambda has no access to variables outside its scope.
* `[=]` → Capture all external variables by value.
* `[&]` → Capture all external variables by reference.
* `[a]` → Capture only the variable a by value.
* `[&a]` → Capture only the variable a by reference.
* Mixed capture is also possible, such as `[=, &a]`, which captures all variables by value except `a`, which is captured by reference.
2. Parameters (`( )`): These define the parameters of the lambda function, similar to how you define parameters in a regular function. You can leave the parentheses empty if the lambda takes no arguments.
3. Return Type (`-> return_type`): This specifies the return type of the lambda. It is optional if the return type can be deduced automatically by the compiler, which is often the case with simple lambdas.
4. Body (`{ }`): The body of the lambda contains the code that will be executed when the lambda is called, just like the body of a regular function.


**NOTE:** variables captured by value in a lambda are immutable, meaning they cannot be modified inside the lambda function. However, by using the `mutable` keyword, you can change this behavior and make those captured variables modifiable within the lambda.
```c++
int counter = 0;

auto increment = [counter]() mutable {
    counter++;  // This would be an error without 'mutable'
    return counter;
};

std::cout << increment();  // Outputs: 1
std::cout << increment();  // Outputs: 1 again (captured by value)
```
