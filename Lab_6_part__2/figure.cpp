#include "figure.h"
#include <iostream>
#include <string>

using namespace std;


// Figure
double Figure::area() { return -1; }
void Figure::show() { cout << "Figure" << endl; }


// Circle
Circle::Circle(int _r) {
    if (_r > 0) {
        r = _r;
    } else {
        exit;
    }
}

int* Circle::getR() { return &r; }

double Circle::area() { return r * r * 3.14; }

void Circle::show() {
    Circle c = *this;
    cout << "Circle area: " << c.area() << endl;
    cout << "Circle address: " << &c << endl;
    cout << "r: " << *c.getR() << endl << endl;
}


// Rectangle
int* Rectangle::getA() { return &a; }

int* Rectangle::getB() { return &b; }

double Rectangle::area() { return a * b * 1.0; }

void Rectangle::show() {
    Rectangle r = *this;
    string type = (r.a == r.b) ? "Square" : "Rectangle";
    cout << type << " area: " << r.area() << endl;
    cout << type << " address: " << &r << endl;
    cout << "a: " << *r.getA() << endl;
    cout << "b: " << *r.getB() << endl << endl;
}

Rectangle::Rectangle(int _a) {
    a = _a;
    b = _a;
}

Rectangle::Rectangle(int _a, int _b) {
    a = _a;
    b = _b;
}
