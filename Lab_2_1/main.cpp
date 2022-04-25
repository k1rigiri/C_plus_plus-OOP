#include <iostream>
#include <stdio.h>

using namespace std;

class Test{
    int W;
    void Z();
    friend void fun(Test *t);
public:
    Test();
    ~Test();
};

Test::Test(){
    W = 1;
}

Test::~Test(){
};

void fun(Test *t){
    cout << "W= " << t->W << endl;
    t->Z();
}

void Test::Z(){
    cout << "This is a private function of Test class" << endl;
}

int main(){
    Test m;
    fun(&m);
}
