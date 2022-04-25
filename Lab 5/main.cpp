#include <iostream>

using namespace std;

class  BASE {
    double d;
protected:
    long l;
public:
    int i;
    BASE () {};
    ~BASE () {};
    BASE (int Bi, long Bl, double Bd);
    void ff(){cout << "base class";};
    double get_d () {return d;};
};

BASE::BASE(int Bi, long Bl, double Bd){
    i = Bi;
    l = Bl;
    d = Bd;
}

class DERIVED: private BASE {
    float f;
public:
    DERIVED(){};
    ~DERIVED(){};
    void ff(){cout << "derived class";};
    DERIVED(int Bi, long Bl, double Bd, float Df);
    friend void operator << ( ostream& stream, DERIVED &s){
        double base_d;
        base_d = s.get_d();
        stream << " d = " << base_d << ":" << " adres_d = " << &base_d << endl;
        stream << " i = " << s.i << ":" << " adres_i = " << &s.i << endl;
        stream << " l = " << s.l << ":" << " adres_l = " << &s.l << endl;
        stream << " f = " << s.f << ":" << " adres_f = " << &s.f << endl;
    }
} ;

DERIVED::DERIVED(int Bi, long Bl, double Bd, float Df): BASE(Bi, Bl, Bd){
    f = Df;
}

class DERIVED_1: public DERIVED {
public:
    DERIVED_1(){};
    ~DERIVED_1(){};
    long get_l(){return l;};
    int get_i(){return i;};
    DERIVED_1(int Bi, long Bl, double Bd, float Df): DERIVED(Bi, Bl, Bd, Df){};
    void foo(){
        i++;
        l++;
        ff();
    };
    void ff(){cout << "Derived_1 class";};
};

int main()
{
    DERIVED d;
    BASE b;
    DERIVED_1 f;
    cout << "sizeof(b) = " << sizeof(b) << endl;
    cout << "sizeof(d) = " << sizeof(d) << endl;
    DERIVED d1(11.5, 422222, 35, 55.1010);
    cout << d1;
    f.foo();
    return 0;
}
