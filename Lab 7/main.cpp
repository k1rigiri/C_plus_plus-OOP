#include <iostream>
using namespace std;

// template <class T, class T> T f(T x); одно и тоже имя для переменных

// template <class T1, T2> void f(T1 x); один тип данных для двух переменных

// template <class T>  T  f(int x); все верно

// inline template <class T> T f(T x, T y); шаблонные функции уже Inline нет надобности снова это указывать



template <class T> void swaP (T&x, T&y){
T z;
z=x; x=y; y=z;}



template <class T> void mAx(T x , T y){
    if (x > y){
        cout<<x<<endl;
    }
    else{
        cout<<y<<endl;
    }

cout<<"template fun"<<endl<<endl;
}
template <char> void mAx(char* x , char* y){
    if (x > y){
        cout<<x<<endl;
    }
    else{
        cout<<y<<endl;
    }

cout<<"template spezz fun"<<endl<<endl;
}

int main(){

int i=1, j=2;
double a=1.1, b=2.2;
char x='x', y='y';
swaP (i, j);
cout<<i<<" "<<j<<endl;
swaP (a,b);
cout<<a<<" "<<b<<endl;
swaP(x,y);
cout<<x<<" "<<y<<endl<<endl;

cout<<"part 2"<<endl<<endl;
mAx(0,1);
mAx('a','1');
mAx('Hello','World');

    return 0;
}
