#include "figure.h"

class Triangle : public Figure {
    int a;
    int b;
    int c;
  public:
    int getA();
    int getB();
    int getC();
    
    virtual double area();
    virtual void show();
    Triangle(int _a, int _b, int _c);
};