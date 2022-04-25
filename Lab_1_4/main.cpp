#include <iostream>
#include <stdio.h>
#include <string.h>
#define size 40
#define vis_31 10

using namespace std;

class abiturient {
private:
    char surname[size];
    char name[size];
    char patronymic[size];
    char adress[size];
    int mark_1;
    int mark_2;
    int mark_3;
    int tot_marks;
    int sum_marks();
public:
    void set_surname(char* s_sur){strcpy(surname, s_sur);};
    void set_name(char* s_name){strcpy(name, s_name);};
    void set_patronymic(char* s_patr){strcpy(patronymic, s_patr);};
    void set_adress(char* s_adr){strcpy(adress, s_adr);};
    void set_m_1(int m_1){mark_1 = m_1;};
    void set_m_2(int m_2){mark_2 = m_2;};
    void set_m_3(int m_3){mark_3 = m_3;};
    char get_surname(){return *surname;};
    char get_name(){return *name;};
    char get_patronymic(){return *patronymic;};
    char get_adress(){return *adress;};
    int get_m_1(){return mark_1;};
    int get_m_2(){return mark_2;};
    int get_m_3(){return mark_3;};
    abiturient(char* s, char* n, char* p, char* a, int m_1, int m_2, int m_3);
    ~abiturient();
    void show();
    void neyd(abiturient *DSTU, int vis);
    void sum_scores(abiturient *DSTU, int vis, int n);
    void most_high(abiturient *DSTU, int vis, int h);
//    void half(abiturient *DSTU, int vis);
};

int abiturient::sum_marks(){
    tot_marks = mark_1 + mark_2 + mark_3;
}

void abiturient::show() {
cout << "Surname     :" << surname << endl;
cout << "Name        :" << name << endl;
cout << "Patronymic  :" << patronymic << endl;
cout << "Adress      :" << adress << endl;
cout << "First mark  :" << mark_1 << endl;
cout << "Second mark :" << mark_2 << endl;
cout << "Third mark  :" << mark_3 << endl;
cout << "Total       :" << tot_marks << endl;
}

abiturient::abiturient(char* s, char* n, char* p, char* a, int m_1, int m_2, int m_3) {
    strcpy(surname, s);
    strcpy(name, n);
    strcpy(patronymic, p);
    strcpy(adress, a);
    mark_1 = m_1;
    mark_2 = m_2;
    mark_3 = m_3;
    sum_marks();
}

abiturient::~abiturient(){
}

void abiturient::neyd(abiturient *DSTU, int vis){
    for (int i = 0; i < vis; i++)
    {
        if ((DSTU[i].mark_1 < 3) || (DSTU[i].mark_2 < 3) || (DSTU[i].mark_3 < 3))
        {
            DSTU[i].show();
            cout << endl;
        }
    }
}

void abiturient::sum_scores(abiturient *DSTU, int vis, int n){
    for (int i = 0; i < vis; i++)
    {
        if (DSTU[i].tot_marks >= n)
        {
            DSTU[i].show();
            cout << endl;
        }
    }
}

void abiturient::most_high(abiturient *DSTU, int vis, int h){
    int marks[vis];
    int max = 0, temp = 0;
    for (int i = 0; i < vis; i++)
    {
        marks[i] = DSTU[i].tot_marks;
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < vis; j++)
        {
            if (marks[j] > max)
            {
                max = marks[j];
                temp = j;
            }
        }
        DSTU[temp].show();
        cout << endl;
        max = 0;
        marks[temp] = 0;
    }
}

//void abiturient::half(abiturient *DSTU, int vis){
//    int marks[vis];
//    for (int i = 0; i < vis; i++)
//    {
//        marks[i] = DSTU[i].tot_marks;
//        cout << marks[i] << endl;
//    }
//    for (int i = 0; i < vis-1; i++)
//    {
//        for (int j = i + 1; j < 10; j++)
//        {
//            if (marks[i] == marks[j])
//            {
//                marks[j] = 0;
//                DSTU[j].show();
//                DSTU[i].show();
//            }
//        }
//        marks[i] = 0;
//    }
//}

int main(){
    int N, h, T;
    abiturient DSTU[vis_31] = {
        abiturient("Andreeva", "Tatiana", "Romanova", "Gagarina 1", 5, 4, 3),
        abiturient("Bagdeev", "Vladimir", "Vladimirovich", "Gagarina 2", 3, 2, 4),
        abiturient("Verbitskaya", "Darya", "Alekseevna", "Gagarina 3", 4, 4 , 4),
        abiturient("Gaponov", "Denis", "Aleksandrovich", "Gagarina 4", 5, 2 ,4),
        abiturient("Gerasimchuk", "Vladimir", "Andreevich", "Gagarina 5", 3, 3, 3),
        abiturient("Goryainov", "Bogdan", "Aleksandrovich", "Gagarina 6", 2, 2, 2),
        abiturient("Gromyko", "Anna", "Anatolievna", "Gagarina 7", 5, 4, 4),
        abiturient("Zainchkovsky", "Vladislav", "Anatolyevich", "Gagarina 8", 3, 3, 2),
        abiturient("Zelenov", "Denis", "Alekseevich", "Gagarina 9", 4, 5, 4),
        abiturient("Izmailov", "Egor", "Eduardovich", "Gagarina 10", 5, 5, 5),
};
    while(1)
    {
        cout << "Welcome" << endl;
        cout << "1 - Neuspevayushie\n2 - summa ballov\n3 - Naivishaya otcenka\n4 - Exit\n" << endl;
        cin >> T;
        switch (T){
        case 1:
            cout << "Students with neyd: " << endl;
            DSTU[vis_31].neyd(DSTU, vis_31);
            break;
        case 2:
            cout << "Enter a sum of marks" << endl;
            cout << "Max summa ballov 15" << endl;
            cin >> N;
            if (N > 16)
            {
                cout << "Students cant have sum marks more than 16" << endl;
            }
            if (N < 0)
            {
                cout << "Students cant have sum marks below 0" << endl;
            }
            else
            {
                cout << "Student with more then N" << endl;
                DSTU[vis_31].sum_scores(DSTU, vis_31, N);
            }
            break;
        case 3:
            cout << "Enter how many abiturients need with the most high sum marks" << endl;
            cin >> h;
            if (h < vis_31 && h > 0){
                DSTU[vis_31].most_high(DSTU, vis_31, h);
            }
            else
                cout << "Abiturient only 10" << endl;
            break;
        case 4:
            exit(0);
        }
    }
}
