#include <iostream>
#include <future>

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    std::packaged_task<int(int)> task(factorial); // "task" is a task being packaged up to a package
    //+ and this package can be passed along to different places such as a different function or a different
    //+ object or a different thread.

    // So after this many things could happen and at a particular time of point the "task" task is executed.
    //+ And it can be executed in a different context, other than the place where it is created.

    // Packaged task is a task that can be transported to different place in the program and being executed
    //+ over there.
    
    // Packaged task is a template class that is parameterized with the function signature of the task "factorial"
    //+ in this example "std::packaged_task<int(int)> task(factorial)". So factorial is a function that takes int
    //+ and returns int. when the task is executed it will need to take an int parameter.
    //+ How ever I cannot conveniently get the value from "task" because "task" is always return void.
    //+ To get the return value, I have to do:
    int x = task.get_future().get(); // get the return value from the packaged task
    return 0;
}
