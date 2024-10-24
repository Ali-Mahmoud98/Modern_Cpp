#include <iostream>
#include <memory>  // For std::shared_ptr

class Resource {
public:
    Resource() { std::cout << "Resource acquired" << std::endl; }
    ~Resource() { std::cout << "Resource destroyed" << std::endl; }
    void sayHello() const { std::cout << "Hello from Resource!" << std::endl; }
};

// Custom deleter
void customDeleter(Resource* res) {
    std::cout << "Custom deleting the resource" << std::endl;
    delete res;
}

int main(){
    std::shared_ptr<int> sp1 = std::make_shared<int>(10);  // Creates a shared_ptr managing the integer 10

    std::cout << "Value: " << *sp1 << std::endl;  // Dereferencing the shared_ptr
    std::cout << "Use count: " << sp1.use_count() << std::endl;  // How many shared_ptrs are sharing the object

    std::cout << "---------------" <<std::endl;
    std::cout << "---------------" <<std::endl;

    std::shared_ptr<int> sp2 = std::make_shared<int>(20);
    std::cout << "Value: " << *sp2 << std::endl;
    std::cout << "Use count: " << sp2.use_count() << std::endl;

    std::shared_ptr<int> sp3 = sp2;  // sp3 and sp2 now share ownership

    std::cout << "Use count: " << sp3.use_count() << std::endl;

    sp2.reset();  // sp2 now owns nothing
    std::cout << "Use count: " << sp2.use_count() << std::endl;
    std::cout << "Use count: " << sp3.use_count() << std::endl;

    std::cout << "---------------" <<std::endl;
    std::cout << "---------------" <<std::endl;

    {
        // Shared pointer with a custom deleter
        std::shared_ptr<Resource> sp1(new Resource, customDeleter);  
        sp1->sayHello();
        std::cout << "Use count: " << sp1.use_count() << std::endl;  // Should be 1

        {
            // Sharing the resource
            std::shared_ptr<Resource> sp2 = sp1;
            std::cout << "Use count after sharing: " << sp1.use_count() << std::endl;  // Should be 2
        }  // sp2 goes out of scope, resource is not deleted because sp1 is still holding it

        std::cout << "Use count after sp2 is out of scope: " << sp1.use_count() << std::endl;  // Should be 1
    }  // sp1 goes out of scope, resource is deleted via the custom deleter

    return 0;
}
