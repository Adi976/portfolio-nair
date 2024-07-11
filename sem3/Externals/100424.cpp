// Program to overload operators +,-

#include <iostream>
using namespace std;

class time
{
    int date;
    int month;
    int year;
    int hour;
    int min;
    int sec;

public:
    void accept();
    void display();
    time operator+(time &);
};

void time::accept()
{
    cout << "Enter Hour:";
    cin >> hour;
    cout << "Enter Minutes:";
    cin >> min;
    cout << "Enter Seconds:";
    cin >> sec;
}

void time::display()
{
    cout << hour << ":" << min << ":" << sec;
    if (hour > 12)
        cout << " PM\n";
    else
        cout << " AM\n";
}

time time::operator+(time &t)
{
    time temp;
    if (sec + t.sec > 60)
    {
        temp.sec = sec + t.sec - 60;
        temp.min += 1;
    }
    else
        temp.sec = sec + t.sec;
    if (min + t.min > 60)
    {
        temp.min = temp.min + (min + t.min - 60);
        temp.hour=0;
        temp.hour++;
    }
    else
        temp.min = min + t.min;
    if (hour + t.hour > 12)
        temp.hour = temp.hour + (hour + t.hour - 12);
    return temp;
}

int main()
{
    time one, two, three;
    cout << "Enter Time 1:\n";
    one.accept();
    cout << "Time 1: ";
    one.display();
    cout << "Enter Time 2:\n";
    two.accept();
    cout << "Time 2: ";
    two.display();
    three = one + two;
    cout<<"Time 3: ";
    three.display();
    return 0;
}