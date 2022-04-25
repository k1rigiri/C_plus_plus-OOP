#include <iostream>
#include <string>

using namespace std;

template <class T>
class Complex {
    T a;
    T b;
  public:
    Complex& operator+(Complex& comp) {
        a += comp.a;
        b += comp.b;
        return *this;
    };
    Complex& operator-(Complex& comp) {
        a -= comp.a;
        b -= comp.b;
        return *this;
    };

    Complex& operator+=(Complex& comp) {
        a += comp.a;
        b += comp.b;
        return *this;
    };
    Complex& operator-=(Complex& comp) {
        a -= comp.a;
        b -= comp.b;
        return *this;
    };

    friend ostream& operator<<(ostream& stream, Complex &c) {
        stream << "Z = " << c.a << " + (" << c.b << ")i";
        return stream;
    };

    T getA() { return a; };
    void setA(T _a) { a = _a; };
    T getB() { return b; };
    void setB(T _b) { b = _b; };

    Complex() {};
    Complex(T _a, T _b) {
        a = _a;
        b = _b;
    };
};

template <class T>
class Matrix {
    int m;
    int n;
  public:
    T **array;

    Matrix& operator+(Matrix& matr) {
        if (m == matr.m && n = matr.n) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    array[i][j] += matr.array[i][j];
                }
            }
        }
        return *this;
    };
    Matrix& operator-(Matrix& matr) {
        if (m == matr.m && n = matr.n) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    array[i][j] -= matr.array[i][j];
                }
            }
        }
        return *this;
    };

    void operator=(Matrix& matr) {
        array = matr.array;
        m = matr.m;
        n = matr.n;
    };

    friend ostream& operator<<(ostream& stream, Matrix &m) {
        for (int i = 0; i < m.m; i++) {
            for (int j = 0; j < m.n; j++) {
                stream << m.array[i][j]<< "\t";
            }
            stream << endl;
        }
        return stream;
    };

    Matrix(int _m, int _n) {
        m = _m;
        n = _n;
        array = new T * [m];
        for (int i = 0; i < m; i++) {
            array[i] = new T [n];
        }
    }
};

int main() {
    Complex<int> c1(1, -2), c2(7, 9), c3(5, 2), c4(-2, -5);
    Complex<double> d1(5.2, -2.49), d2(12.5, -2.5);

    Matrix<int> m(2, 2);
    m.array[0][0] = 1;
    m.array[0][1] = 2;
    m.array[1][0] = 3;
    m.array[1][1] = 4;
    cout << m;

    Matrix<Complex<int>> m2(2, 2);
    m2.array[0][0] = c1;
    m2.array[0][1] = c2;
    m2.array[1][0] = c3;
    m2.array[1][1] = c4;

    cout << m2;

    return 0;
}
