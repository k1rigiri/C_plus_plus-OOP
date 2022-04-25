#include <iostream>
#include <string>

using namespace std;
#define MC 13

class Date {
    int day;
    int month;
    int year;
    const int days[12] = {31, 28, 31, 30, 31, 30, 30, 31, 30, 30, 31, 30};
public:
    int getDay() { return day; };
    void setDay(int d) { day = d; };
    int getMonth() { return month; };
    void setMonth(int m) { month = m; };
    int getYear() { return year; };
    void setYear(int y) { year = y; };

    Date();
    Date(int _day, int _month, int _year);
    Date& operator=(Date& assdate);

    Date& operator++();
    Date operator++(int);
    Date& operator--();
    Date operator--(int);

    Date& operator+(Date& d);
    Date& operator-(Date& d);

    Date& operator+(int d);
    Date& operator-(int d);

    friend ostream& operator<<(ostream& os, const Date& dt);
    friend Date& operator+(int a, Date& d);
};

Date::Date(int _day, int _month, int _year) {
    if (_month > 13 || _month < 1) {
        cout << "Month not valid" << endl;
        _month = 1;
    }
    if (_day > days[_month - 1] || _day < 1) {
        cout << "Day not valid" << endl;
        _day = 1;
    }
    day = _day;
    month = _month;
    year = _year;
}

ostream& operator<<(ostream& os, const Date& d) {
    os << d.day << '/' << d.month << '/' << d.year;
    return os;
}

Date& Date::operator=(Date& d) {
    month = d.month;
    day = d.day;
    year = d.year;

    return *this;
}

Date& Date::operator++() {
    day++;

    if (month > 12) {
        year++;
        month = 1;
    }
    if (day > days[month - 1]) {
        day -= days[month - 1];
        month++;
    }
    return *this;
}

Date Date::operator++(int) {
    ++(*this);
    return *this;
}

Date& Date::operator--() {
    day--;

    if (month < 1) {
        year--;
        month = 12;
    }
    if (day < 1) {
        month--;
        day += days[month - 1];
    }
    return *this;
}

Date Date::operator--(int) {
    --(*this);
    return *this;
}

Date& Date::operator+(Date& d) {
    day += d.day;
    month += d.month;
    year += d.year;

    if (month > 12) {
        year++;
        month = 1;
    }
    if (day > days[month - 1]) {
        day -= days[month - 1];
        month++;
    }
    return *this;
}

Date& Date::operator-(Date& d) {
    day -= d.day;
    month -= d.month;
    year -= d.year;

    if (month < 1) {
        year--;
        month = 12;
    }
    if (day < 1) {
        month--;
        day += days[month - 1];
    }
    return *this;
}

Date& Date::operator+(int d) {
    day += d;

    if (day > days[month - 1]) {
        day -= days[month - 1];
        month++;
    }
    if (month > 12) {
        year++;
        month = 1;
    }
    return *this;
}

Date& Date::operator-(int d) {
    day -= d;

    if (day < 1) {
        month--;
        day += days[month - 1];
    }
    if (month < 1) {
        year--;
        month = 12;
    }
    return *this;
}

Date& operator+(int a, Date& d) {
    d.day += a;

    if (d.day > d.days[d.month - 1]) {
        d.day -= d.days[d.month - 1];
        d.month++;
    }
    if (d.month > 12) {
        d.year++;
        d.month = 1;
    }
    return d;
}

int main() {
    int f;
    Date d1(1, 4, 2010);
    Date d2(10, 3, 2);
    Date d3(11, 7, 12);

    while(1)
    {
        cout << " 1 - Start date\n 2 - Date of end\n 3 - date + int\n 4 - date - int\n 5 - uznat datu nachala\n 6 - pereiti na sled datu\n 7 - exit\n" << endl;
        cout << "Enter action number:" << endl;
        cin >> f;
        switch(f)
        {
        case 1:
            cout << d1 << endl;
            break;
        case 2:
            cout << d1+d2 << endl;
            break;
        case 3:
            cout << d1+5 << endl;
            break;
        case 4:
            cout << d1-5 << endl;
            break;
        case 5:
            cout << d3-d2 << endl;
            break;
        case 6:
            cout << d1++ << endl;
            break;
        case 7:
            exit(0);
        }
    }
    return 0;
}
