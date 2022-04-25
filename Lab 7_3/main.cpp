#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Stack {
    int array[T];
  public:
    Stack() {};
    ~Stack() {};
};

int main() {
    Stack<2> s;

    return 0;
}
