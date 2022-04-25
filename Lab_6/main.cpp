#include <iostream>
#include <string>

using namespace std;

class Base1 {
    int i;
public:
    void putI(int _i) {i = _i;};
    int getI() {return i;};

    Base1(){
        cout << "Base1 without params" << endl;
        i = 0;
    };
    Base1(int _i){
        i = _i;
    };
};

class Base2 {
    string name;
  public:
    string getN() { return name; };
    void putN(string _name) { name = _name; };

    Base2() {
        cout << "Base2 without params" << endl;
        name = "Empty";
    };
    Base2(string _name) {
        name = _name;
    };
};

class Derived : public Base1, public Base2 {
    char ch;
public:
    void putCh(char _ch) {ch = _ch;};
    char getCh() {return ch;};

    Derived() {
        ch = 'V';
    };
    Derived(int _i, string _name, char _ch) : Base1(_i), Base2(_name) {
        ch = _ch;
    };

    friend ostream& operator<< (ostream& stream, Derived d){
        stream << "i = " << d.getI() << endl;
        stream << "name = " << d.getN() << endl;
        stream << "ch = " << d.getCh() << endl;
        return stream;
    };
};

int main() {
    Derived d;
    Derived d1(5, "odin", 'f');

    cout << d << endl;
    cout << d1 << endl;
    return 0;
}
