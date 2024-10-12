#include <iostream>
#include <stdexcept>
#include "myVector.hpp"

int main()
{
    // initialization methods
    // 1. default initialization
    MyVector<int> v1;
    std::cout << "v1.getSize(): " << v1.getSize() << std::endl;
    std::cout << "v1 = ";
    v1.print();
    // 2. initializer list
    MyVector<int> v2 = {1, 2, 3, 4, 5};
    std::cout << "v2.getSize(): " << v2.getSize() << std::endl;
    std::cout << "v2 = ";
    v2.print();
    // 3. uniform initialization
    MyVector<int> v3(10);
    std::cout << "v3.getSize(): " << v3.getSize() << std::endl;
    std::cout << "v3 = ";
    v3.print();
    // 4. copy initialization
    MyVector<int> v4(v2);
    std::cout << "v4.getSize(): " << v4.getSize() << std::endl;
    std::cout << "v4 = ";
    v4.print();
    // 5. copy assignment
    MyVector<int> v5 = v2;
    std::cout << "v5.getSize(): " << v5.getSize() << std::endl;
    std::cout << "v5 = ";
    v5.print();
    // 6. initializer_list
    MyVector<int> v6 = {1, 2, 3, 4, 5};
    std::cout << "v6.getSize(): " << v6.getSize() << std::endl;
    std::cout << "v6 = ";
    v6.print();
    // 7. move constructor
    MyVector<int> v7(std::move(v6));
    std::cout << "v7.getSize(): " << v7.getSize() << std::endl;
    std::cout << "v7 = ";
    v7.print();
    // 8. copy assignment operator
    v5 = v2;
    std::cout << "v5.getSize(): " << v5.getSize() << std::endl;
    std::cout << "v5 = ";
    v5.print();
    // 9. move assignment operator
    v5 = std::move(v6);
    std::cout << "v5.getSize(): " << v5.getSize() << std::endl;
    std::cout << "v5 = ";
    v5.print();
    std::cout << "v6.getSize(): " << v6.getSize() << std::endl;
    std::cout << "v6 = ";
    v6.print();
    // 10. fill constructor
    MyVector<int> v10(10, 5);
    std::cout << "v10.getSize(): " << v10.getSize() << std::endl;
    std::cout << "v10 = ";
    v10.print();
    return 0;
}
