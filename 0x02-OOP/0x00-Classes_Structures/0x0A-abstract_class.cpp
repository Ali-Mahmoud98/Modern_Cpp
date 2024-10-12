#include <iostream>
using namespace std;

// Abstract class
class Shape {
public:
    // Pure virtual function
    virtual void draw() = 0;

    // Regular member function
    void setColor(string col) {
        color = col;
    }

    string getColor() {
        return color;
    }

private:
    string color;
};

// Derived class from Shape
class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Circle" << endl;
    }
};

// Derived class from Shape
class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Rectangle" << endl;
    }
};

int main() {
    // Shape s; // This will give a compilation error because Shape is an abstract class
    //Shape* s2 = new Shape();// error: cannot create an instance of an abstract class
    Shape* s = new Circle();
    s->setColor("Green");
    cout << "Shape color: " << s->getColor() << endl;
    s->draw();
    delete s;
    //------------------------------------------------------------
    Circle circle;
    circle.setColor("Red");
    cout << "Circle color: " << circle.getColor() << endl;
    circle.draw();

    Rectangle rectangle;
    rectangle.setColor("Blue");
    cout << "Rectangle color: " << rectangle.getColor() << endl;
    rectangle.draw();

    return 0;
}
