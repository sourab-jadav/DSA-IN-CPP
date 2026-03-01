#include <cmath>
#include <iostream>

class Shape {
    public:
        virtual double calculateArea() const = 0; // pure virtual function
        virtual void draw() const {
            std::cout << "drawing a generic shape" << std::endl;
        }
};
class Circle : public Shape {
    private:
        double radius;

    public:
        Circle(double r) : radius(r){};
        double calculateArea() const override { return 3.14 * radius * radius; }
        void draw() const override { std::cout << "drawing a circle" << std::endl; }
};
class Rectangle : public Shape {
    private:
        double length;
        double width;

    public:
        Rectangle(double l, double w) : length(l), width(w){};
        double calculateArea() const override { return length * width; }
        void draw() const override {
            std::cout << "Drawing a rectangle" << std::endl;
        }
};
void processShape(const Shape& shape){
    
    shape.draw();
}
int main() {
    Circle circle(5.0);
    Rectangle rect(4.0,6.0);
    processShape(circle);
    processShape(rect);
    return 0;
}
