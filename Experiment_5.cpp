#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() = 0;

    virtual ~Shape() {}
};

class Circle : public Shape {
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
    double length, breadth;

public:
    Rectangle(double l, double b)
        : length(l), breadth(b) {}

    double area() override {
        return length * breadth;
    }
};

class Triangle : public Shape {
    double base, height;

public:
    Triangle(double b, double h)
        : base(b), height(h) {}

    double area() override {
        return 0.5 * base * height;
    }
};

int main() {
    Circle c(5);
    Rectangle r(4, 6);
    Triangle t(4, 5);

    Shape* s;

    s = &c;
    cout << "Circle Area: " << s->area() << endl;

    s = &r;
    cout << "Rectangle Area: " << s->area() << endl;

    s = &t;
    cout << "Triangle Area: " << s->area() << endl;

    return 0;
}
