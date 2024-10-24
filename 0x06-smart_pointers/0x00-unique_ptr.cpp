#include <iostream>
#include <memory>  // For std::unique_ptr

class Entity {
public:
    Entity() {
        std::cout << "Entity Constructor" << std::endl;
    }

    ~Entity() {
        std::cout << "Entity Destructor" << std::endl;
    }
    
    void print() {
        std::cout << "Hello World" << std::endl;
    }
};

int main() {
    // Initialization of std::unique_ptr
    // 1. Using std::make_unique (Recommended)
    std::unique_ptr<Entity> entityPtr = std::make_unique<Entity>();
    std::unique_ptr<Entity> entityPtr1;

    // 2. Using new
    //std::unique_ptr<Entity> entityPtr2 = new Entity(); // this will cause error because
    //+ copy from lvalue is deleted:
    //+ unique_ptr(const unique_ptr&) = delete;
    //+ unique_ptr& operator=(const unique_ptr&) = delete;
    
    std::unique_ptr<Entity> entityPtr2(new Entity());


    std::unique_ptr<Entity> entityPtr3 = std::move(entityPtr2);
    if (entityPtr2 == nullptr)
    {
        std::cout << "entityPtr2 is nullptr" << std::endl;
    }
    std::unique_ptr<Entity> entityPtr4(std::move(entityPtr3));
    if (entityPtr3 == nullptr)
    {
        std::cout << "entityPtr3 is nullptr" << std::endl;
    }
    {
        entityPtr1 = std::move(entityPtr4);
        std::unique_ptr<Entity> entityPtr5(std::move(entityPtr1));
        // std::shared_ptr<Entity> entityPtr6 = entityPtr1; this will cause error
        //std::weak_ptr<Entity> entityPtr6(entityPtr1); // this will cause error
        if (entityPtr1 == nullptr)
        {
            std::cout << "entityPtr1 is nullptr" << std::endl;
        }
    }
        
    std::cout << "Hello World" << std::endl;
    return 0;
}
