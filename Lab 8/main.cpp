#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
     //task 1
    int a = 64;
    cout << oct << a <<endl;
    cout << a << endl;
    cout.unsetf(ios::oct);
    cout << a<<endl<<endl;
    // task 2
    double f = 1.12345678;
    cout << f<<endl;
    cout <<setprecision(3)<< f <<endl;
    //task 3
    float t  = 5.5;
    cout.width('4');
    cout << t <<endl;
    cout.setf(ios::scientific);
    cout << t << endl;
    cout.unsetf(ios::scientific);
    cout <<setw(20)<< left << t <<endl;
    cout <<setw(20)<< right <<setfill('-')<< t <<endl;
    return 0;
}
