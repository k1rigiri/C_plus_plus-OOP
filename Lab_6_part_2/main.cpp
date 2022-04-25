#include <iostream>
#include <string>

using namespace std;

class DomesticAnimal {
    int weight;
    int price;
    string color;
public:
    void print() {
        cout << "class - DomesticAnimal" << endl;
        cout << "Weight = " << weight << endl;
        cout << "Price = " << price << endl;
        cout << "Color - " << color << endl;
    }

    DomesticAnimal() {};
    DomesticAnimal(int _weight, int _price, string _color) {
        cout << "Domestic" << endl;
        weight = _weight;
        price = _price;
        color = _color;
    }
};

class Cow : public DomesticAnimal {
    public:
    void print() { cout << "Cow" << endl; };

    Cow() : DomesticAnimal() {};
    Cow(int _weight, int _price, string _color) : DomesticAnimal(_weight, _price, _color) {};
};

class Buffalo : public DomesticAnimal {
    public:
    void print() { cout << "Buffalo" << endl; };

    Buffalo() : DomesticAnimal() {};
    Buffalo(int _weight, int _price, string _color) : DomesticAnimal(_weight, _price, _color) {};
};

class Beefalo : public Cow, public Buffalo {
    public:
    void print() { cout << "Beefalo" << endl; };

    Beefalo(int _weight, int _price, string _color) : Cow(_weight, _price, _color),Buffalo(_weight, _price, _color) {};
};

int main() {
    Beefalo b(1, 2, "Red");
    b.print();

    Cow c;
    c.print();

    return 0;
}
