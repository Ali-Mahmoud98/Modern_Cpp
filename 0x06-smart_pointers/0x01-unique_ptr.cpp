#include <iostream>
#include <memory>  // For std::unique_ptr

#define SAFE_CALL(ptr, expr)                     \
    if ((ptr) == nullptr) {                      \
        std::cout << #ptr " is nullptr!" << std::endl; \
    } else {                                     \
        expr;                                    \
    }

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

void printArray(int* array) {
    for (int i = 0; i < 5; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void do_ptint(T entity) {
    entity->print();
}

int main() {
    // make an array of size 5
    auto array = std::make_unique<int[]>(5);
    printArray(array.get());
    array.get()[0] = 10;
    printArray(array.get());

    auto entity = std::make_shared<Entity>();
    do_ptint(entity);

    auto entity1 = std::make_unique<Entity>();
    do_ptint(entity1.get());
    do_ptint(std::move(entity1));
    // entity1->print();// this will cause undefined behavior
    // entity1.get()->print();// this will cause undefined behavior
    // avoid use a smart pointer if you transfer ownership using std::move
    // because it will cause undefined behavior
    // check the pointer before using it, you can use a macro SAFE_CALL

    // if (entity1 == nullptr)
    // {
    //     std::cout << "entity1 is nullptr" << std::endl;
    // }
    // entity1.get()->print(); // this will cause undefined behavior
    std::cout << "--------------" << std::endl;
    SAFE_CALL(entity1.get(), entity1.get()->print());
    SAFE_CALL(entity1, entity1->print());
    std::cout << "--------------" << std::endl;
    entity1 = std::make_unique<Entity>();
    SAFE_CALL(entity1.get(), entity1.get()->print());
    SAFE_CALL(entity1, entity1->print());

    return 0;
}
