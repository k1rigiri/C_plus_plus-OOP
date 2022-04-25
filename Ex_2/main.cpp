#include <iostream>
#include <string.h>
#define size 40

using namespace std;

class card{
    char Title[size];
    char Autor[size];
    int Quantity;
public:
    void store(char *t, char *name, int num);
    void show();
};

void card::store(char *t, char *name, int num){
    strcpy(Title, t);
    strcpy(Autor, name);
    Quantity = num;
}

void card::show(){
    cout << "Zaglavie   :   " << Title << endl;
    cout << "Avtor      :   " << Autor << endl;
    cout << "Kol-vo     :   " << Quantity << endl;
}

int main()
{
    card b1, b2, b3;
    b1.store("Dune", "Michael", 3);
    b2.store("Guns", "Antonov", 2);
    b3.store("Clue", "Mariann", 4);
    b1.show();
    cout << endl;
    b2.show();
    cout << endl;
    b3.show();
    return 0;
}
