#include <iostream>
#include <string.h>
#define size 20
#define size_constr 5
 using namespace std;

 class Goods{
    char name[size];
    char date[size];
    int price;
    int quantity;
    int id;
public:
    int get_price(){return price;}
    int get_quantity(){return quantity;}
    Goods();
    Goods(char* n, char* d, int p, int q, int id);
    ~Goods();
    int sum();
    int change(char* n, char* d, int p, int q, int nof);
    void show();
    Goods(const Goods &obj);
    Goods tovar(Goods s){return s;}
    Goods operator=(Goods obj);
 };

    Goods Goods::operator=(Goods obj){
        strcpy(name, obj.name);
        strcpy(date, obj.date);
        price = obj.price;
        quantity = obj.quantity;
        id = obj.id;
        return *this;
    };

Goods::Goods(const Goods &obj){
    strcpy(name, obj.name);
    strcpy(date, obj.date);
    price = obj.price;
    quantity = obj.quantity;
    id = obj.id;
 }

 void Goods::show(){
    cout << "Name     :" << name << endl;
    cout << "Date     :" << date << endl;
    cout << "Price    :" << price << endl;
    cout << "Quantity :" << quantity << endl;
    cout << "ID       :" << id << endl;
 }

int Goods::change(char* n, char* d, int p, int q, int nof){
    strcpy(name, n);
    strcpy(date, d);
    price = p;
    quantity = q;
    id = nof;
};

 int Goods::sum(){
    return price * quantity;
 };

Goods::Goods(){
    cout<< "Default constructor;" << endl;
    strcpy(name, "Name");
    strcpy(date, "0000/00/00");
    price = 0;
    quantity = 0;
    id = 0;
};

Goods::Goods(char* n, char* d, int p, int q, int nof){
    cout << "Constructor with paramametrs: " << endl;
    strcpy(name, n);
    strcpy(date, d);
    price = p;
    quantity = q;
    id = nof;
};

Goods::~Goods(){
    cout << "Destructor  :" << endl;
};

int main()
{
    int T, i, p, q, nof;
    char n[size], d[size];
    cout << "Enter in func main()  :" << endl;
    Goods Shop[size_constr] = {
        Goods("Kartoshka", "2021/10/07", 20, 4, 1),
        Goods("Shokolad", "2021/10/06", 30, 6, 2),
        Goods("Cblrok", "2021/10/05", 40, 8, 3),
        Goods("Sok", "2021/10/04", 50, 10, 4),
        Goods("Voda", "2021/10/03", 60, 12, 5)
    };
    Goods p1, p2;
    Goods Auchan(Shop[0]);
    while(1)
    {
        cout << "\nWelcome, choose an action" << endl;
        cout << "1 - BblBod \n2 - Redaktirovanie \n3 - vichislenie summbl tovara\n4 - konstruktor copy \n5 - Func tovar \n6 - Peregruzka \n7 - Exit\n:";
        cin >> T;
        switch(T)
        {
        case 1:
            {
                cout << "Which do you want to show?\n Enter a number: " ;
                cin >> i;
                cout << endl;
                if ((i < 6) && (i > 0))
                    Shop[i-1].show();
                else
                    cout << "We have only 5 items\n" << endl;
                break;
            }
        case 2:
            cout << "Which do you want to change?\n Enter a number: " ;
            cin >> i;
            cout << endl;
            if ((i < 6) && (i > 0))
            {
                cout << "Enter a new info:\n";
                cout << "In order: name, date, price, quantity, id" << endl;
                cin >> n;
                cin >> d;
                cin >> p;
                cin >> q;
                cin >> nof;
                Shop[i-1].change(n, d, p, q, nof);
            }
            else
                cout << "We have only 5 items\n" << endl;
            break;
        case 3:
                cout << "Which sum do you want to know?\n Enter a number: " ;
                cin >> i;
                cout << endl;
                if ((i < 6) && (i > 0))
                {
                    cout << "Summa tovara = " << Shop[i-1].sum() << endl;
                }
                else
                    cout << "We have only 5 items\n" << endl;
        break;
        case 4:
            cout << "Constr copy BbiBod pervogo" << endl;
            Auchan.show();
        break;
        case 5:
            cout << "Global func tovar" << endl;
            Auchan.tovar(Auchan);
        break;
        case 6:
            cout << "Overload" << endl;
            p1 = p2 = Shop[3];
            cout << "Vizov pervogo" << endl;
            p1.show();
            cout << "Vizov vtorogo" << endl;
            p2.show();
        break;
        case 7:
            exit(0);
        }
            cout << "Exit from func main() :" << endl;
    }
}
