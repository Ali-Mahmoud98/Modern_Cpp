// Capturing this Pointer
// In object-oriented code, lambdas can also capture the this pointer to access members of the enclosing class:
#include <iostream>

class Enclosing {
    int x;
    int y;
public:
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    int getX() { return x; }
    int getY() { return y; }
    void do_magic() {
        auto magic = [this]() {
            std::cout << "magic result is = " << y << x + y << x << std::endl;
        };
        magic();
    }
    // In this case, the lambda captures the this pointer, allowing it to access the value member of the class.
    // If you removed this, you will not be able to access members variables of the class.
};

int main() {
    Enclosing e;
    e.setX(5);
    e.setY(10);
    e.do_magic();
    return 0;
}
