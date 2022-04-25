#include <iostream>
#include <stdio.h>
#include <string.h>
#define size 5
#define SIZE 20
using namespace std;

class Abonent{
    int id;
    char surname[SIZE];
    char phone_number[SIZE];
    friend class Notebook;
public:
    ~Abonent();
    Abonent(int i, char* s, char* p_n);
};

class Notebook{
public:
    void change(Abonent *T,char* f, int ID);
    void show(Abonent* T);
};

void Notebook::change(Abonent *T, char* f, int ID){
    for (int i = 0; i < size; i++){
        if (ID == T[i].id){
            strcpy(T[i].phone_number, f);
        }
    }
}

void Notebook::show(Abonent *T){
    for (int i = 0; i < size; i++)
    {
        cout << "ID           :" << T[i].id << endl;
        cout << "Surname      :" << T[i].surname << endl;
        cout << "Phone number :" << T[i].phone_number << endl;
        cout << endl;
    }
}

Abonent::~Abonent(){
    cout << "Destructor" << endl;
};

Abonent::Abonent(int n, char* s, char* p_n){
    cout << "Constructor" << endl;
    id = n;
    strcpy(surname, s);
    strcpy(phone_number, p_n);
}

int main(){
    int ID;
    char f[SIZE];
    Notebook s1;
    Abonent vis[size] = {
        Abonent(14, "Antonov", "79994443355"),
        Abonent(22, "Bubba", "79998887766"),
        Abonent(33, "Kolesnikov", "79994445544"),
        Abonent(45, "Izmailov", "79004003500"),
        Abonent(54, "Falin", "79991203400"),
    };
    cout << "List of abonents:" << endl;
    s1.show(vis);
    cout << endl;
    cout << "Enter Abonent ID:" << endl;
    cin >> ID;
    cout << "Enter a new phone number: " << endl;
    cin >> f;
    s1.change(vis, f, ID);
    cout << "Changed phone number" << endl;
    s1.show(vis);
}
