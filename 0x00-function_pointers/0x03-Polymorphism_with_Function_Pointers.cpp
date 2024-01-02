#include <iostream>

// Base class with a virtual function
class Shape {
public:
    virtual void draw() const {
        std::cout << "Drawing a generic shape." << std::endl;
    }

    virtual ~Shape() {}  // Virtual destructor for proper cleanup
};

// Derived class 1
class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a circle." << std::endl;
    }
};

// Derived class 2
class Square : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a square." << std::endl;
    }
};

// Function pointer type for drawing functions
using DrawFunctionPointer = void (Shape::*)() const;
/**
 * (Shape::*): This part declares a pointer to a member of the Shape class.
 * It indicates that the member function is a member of the Shape class.
*/


// Function to draw any shape using a function pointer
void drawShape(const Shape& shape, DrawFunctionPointer drawFunction) {
    (shape.*drawFunction)();  // Call the specified draw function for the given shape
}

int main() {
    Circle circle;
    Square square;

    // Define function pointers for drawing functions
    DrawFunctionPointer drawCircle = &Shape::draw;
    DrawFunctionPointer drawSquare = &Shape::draw;

    // Draw shapes using function pointers
    drawShape(circle, drawCircle);  // Output: Drawing a circle.
    drawShape(square, drawSquare);  // Output: Drawing a square.

    return 0;
}
