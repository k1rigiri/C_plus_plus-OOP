#include "new_fig.h"
#include <iostream>
#include <math.h>

using namespace std;

int Triangle::getA() { return a; }
int Triangle::getB() { return b; }
int Triangle::getC() { return c; }

double Triangle::area() {
    double p = (a + b + c) / 2.;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void Triangle::show() {
    Triangle t = *this;
    cout << "Triangle area: " << t.area() << endl;
    cout << "Triangle address: " << &t << endl;
    cout << "a: " << t.getA() << endl;
    cout << "b: " << t.getB() << endl;
    cout << "c: " << t.getC() << endl << endl;
}

Triangle::Triangle(int _a, int _b, int _c) {
    if (_a + _b > _c) {
        a = _a;
        b = _b;
        c = _c;
    } else {
        cout << "Can't create Triangle" << endl;
        exit;
    }
}