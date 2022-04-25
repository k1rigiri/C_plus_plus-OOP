class Figure {
  public:
    virtual double area();
    virtual void show();
};

class Circle : public Figure {
    int r;
  public:
    int* getR();

    virtual double area();
    virtual void show();

    Circle(int _r);
};

class Rectangle : public Figure {
    int a;
    int b;
  public:
    int* getA();
    int* getB();

    virtual double area();
    virtual void show();

    Rectangle(int _a);
    Rectangle(int _a, int _b);
};
