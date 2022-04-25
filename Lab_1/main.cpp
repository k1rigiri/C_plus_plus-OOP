#include <iostream>
#include <string.h>
#define FIVE 5
//#define size 40
const int size = 40;
using namespace std;

class stock{
    char company_name[size];
    int quantity_stock;
    int price_stock;
    int total_price;
    int set_tot();
public:
    stock();
    stock(char *n, int q, int p);
    ~stock();
    void aquire(char *t, int q, int p);
    void show();
    void buy(int q, int p);
    void sell(int q, int p);
    void update(int p);
};

int stock::set_tot(){
    total_price = quantity_stock * price_stock;
}

void stock::aquire(char *t, int q, int p){
    strcpy(company_name, t);
    quantity_stock = q;
    price_stock = p;
    set_tot();
    show();
    cout << endl;
}

void stock::buy(int q, int p){
    if (q < 0)
            return;
    quantity_stock += q;
    stock::update(p);
    show();
    cout << endl;
}

void stock::update(int p){
    price_stock = p;
    set_tot();
}

void stock::sell(int q, int p){
    if ((q > quantity_stock) or (q < 0))
    {
            cout << "Failed!";
            return;
    }
    quantity_stock -= q;
    update(p);
    show();
    cout << endl;
}

void stock::show(){
    cout << "Name of company     :" << company_name << endl;
    cout << "quantity of stocks  :" << quantity_stock << endl;
    cout << "price of stock      :" << price_stock << endl;
    cout << "Total price =       :" << total_price << endl;
}

stock::stock(){
    cout << "Default constructor\n";
    strcpy(company_name, "NONE");
    quantity_stock = 0;
    price_stock = 0;
    set_tot();
}

stock::stock(char *n, int q, int p){
    cout << "Constructor with parameters\n";
    strcpy(company_name, n);
    quantity_stock = q;
    price_stock = p;
    set_tot();
}

stock::~stock(){
    cout << "Deleting...\n";
}

int main()
{
    stock c1;
    c1.show();
    cout << "--------------------------------\n";
    stock c2("DSTU", 5, 120);
    c2.show();
    cout << "\nMASSIVE from five\n";
    stock k[FIVE] =
    {
        stock ("VISA", 14, 16),
        stock ("MAESTRO", 10, 5),
        stock ("SUSSA", 5, 10),
        stock ("AMOUS", 7, 6),
        stock ("BANANA", 4, 3),
    };
    k[3].show();
    cout << "\n";
    k[1].show();
//    stock c1;
//    c1.aquire("Yandex", 15, 2);
//    cout << "BUING STOCKS\n\n";
//    c1.buy(5, 5);
//    cout << "SELLING STOCKS\n\n";
//    c1.sell(15, 40);
}
