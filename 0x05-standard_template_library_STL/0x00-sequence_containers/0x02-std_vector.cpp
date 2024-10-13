#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    std::cout << v[0] << std::endl; // output: 1
    std::cout << v[1] << std::endl; // output: 2
    std::cout << v[2] << std::endl; // output: 3
    std::cout << "-------" << std::endl;

    // vector initialization methods
    // 1. default initialization
    std::cout << "vector initialization methods:" << std::endl;
    std::cout << "1- default initialization" << std::endl;
    std::vector<int> v1;
    std::cout << v1.size() << std::endl; // output: 0
    v1.push_back(1);
    std::cout << v1.size() << std::endl; // output: 1
    v1.push_back(2);
    std::cout << v1.size() << std::endl; // output: 2
    v1.push_back(3);
    std::cout << v1.size() << std::endl; // output: 3
    
    // 2. initializer list
    std::cout << "-------" << std::endl;
    std::cout << "2- initializer list" << std::endl;
    std::vector<int> v2 = {1, 2, 3, 4, 5};
    std::cout << v2.size() << std::endl; // output: 5

    // 3. uniform initialization
    std::cout << "-------" << std::endl;
    std::cout << "3- uniform initialization" << std::endl;
    std::vector<int> v3{1, 2, 3, 4, 5};
    std::cout << v3.size() << std::endl; // output: 5
    // 4. fill constructor
    std::cout << "-------" << std::endl;
    std::cout << "4- fill constructor" << std::endl;
    std::vector<int> v4(5, 10);
    std::cout << v4.size() << std::endl;
    std::cout << "v4 = ";
    for (int i = 0; i < v4.size(); i++) {
        std::cout << v4[i] << " ";
    }
    std::cout << std::endl;

    // 5. size constructor
    std::cout << "-------" << std::endl;
    std::cout << "5- size constructor" << std::endl;
    std::vector<int> v5(10);
    std::cout << v5.size() << std::endl;
    std::cout << "v5 = ";
    for (int i = 0; i < v5.size(); i++) {
        std::cout << v5[i] << " ";
    }
    std::cout << std::endl;

    // 6. copy constructor
    std::cout << "-------" << std::endl;
    std::cout << "6- copy constructor" << std::endl;
    std::vector<int> v6(v2);
    std::cout << v6.size() << std::endl;
    std::cout << "v6 = ";
    for (int i = 0; i < v6.size(); i++) {
        std::cout << v6[i] << " ";
    }
    std::cout << std::endl;
    
    // 7. move constructor
    std::cout << "-------" << std::endl;
    std::cout << "7- move constructor" << std::endl;
    std::vector<int> v7(std::move(v6));
    std::cout << v7.size() << std::endl;
    std::cout << "v7 = ";
    for (int i = 0; i < v7.size(); i++) {
        std::cout << v7[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "v6.size() = " << v6.size() << std::endl;
    std::cout << "v6 = ";
    for (int i = 0; i < v6.size(); i++) {
        std::cout << v6[i] << " ";
    }
    std::cout << std::endl;

    // 8. copy assignment operator
    std::cout << "-------" << std::endl;
    std::cout << "8- copy assignment operator" << std::endl;
    std::vector<int> v8;
    v8 = v2;
    std::cout << v8.size() << std::endl;
    std::cout << "v8 = ";
    for (int i = 0; i < v8.size(); i++) {
        std::cout << v8[i] << " ";
    }
    std::cout << std::endl;

    // 9. move assignment operator
    std::cout << "-------" << std::endl;
    std::cout << "9- move assignment operator" << std::endl;
    std::vector<int> v9;
    v9 = std::move(v7);
    std::cout << v9.size() << std::endl;
    std::cout << "v9 = ";
    for (int i = 0; i < v9.size(); i++) {
        std::cout << v9[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "v7.size() = " << v7.size() << std::endl;
    std::cout << "v7 = ";
    for (int i = 0; i < v7.size(); i++) {
        std::cout << v7[i] << " ";
    }
    std::cout << std::endl;

    /////////////////////
    std::cout << "----------------" << std::endl;
    std::vector<int> v10({1, 2, 3, 4, 5});
    std::cout << "v10 = ";
    for (int i = 0; i < v10.size(); i++) {
        std::cout << v10[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}