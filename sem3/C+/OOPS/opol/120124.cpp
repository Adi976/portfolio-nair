//Program to overload +,= using variable LHS and RHS!!
#include <iostream>
using namespace std;

class loc
{
    int lt, lg;

public:
    loc()
    {
    }
    loc(int l1, int l2)
    {
        lt = 0;
        lg = 0;
    }
    void accept();
    void display();
    loc operator++();
    loc operator++(int);
    loc operator=(loc &);
    friend loc operator+(const loc &, const loc &);
    friend loc operator+(const loc &, const int &);
    friend loc operator+(const int &, const loc &);
};

loc operator+(const loc &obj1, const int &var1)
{
    cout << "(loc,int)\n";
    loc temp;
    temp.lt = obj1.lt + var1;
    temp.lg = obj1.lg + var1;
    return temp;
}

loc operator+(const int &var1, const loc &obj1)
{
    cout << "(loc,int)\n";
    loc temp;
    temp.lt = obj1.lt + var1;
    temp.lg = obj1.lg + var1;
    return temp;
}

loc operator+(const loc &obj1, const loc &obj2)
{
    loc temp;
    temp.lt = obj1.lt + obj2.lt;
    temp.lg = obj1.lg + obj2.lg;
    return temp;
}

void loc::accept()
{
    cout << "Enter longitude\n";
    cin >> lt;
    cout << "Enter latitude\n";
    cin >> lg;
}

void loc::display()
{
    cout << "Latitude: " << lt << endl;
    cout << "Longitude: " << lg << endl;
}
loc loc::operator=(loc &obj)
{
    cout << "Equal ()\n";
    lt = obj.lt;
    lg = obj.lg;
    return *this;
}

loc loc::operator++()
{
    loc temp;
    cout << "Prefix ()\n";
    lt++;
    lg++;
    temp = (*this);
    return temp;
}

loc loc::operator++(int t)
{
    loc temp;
    cout << "Postfix ()\n";
    lt++;
    lg++;
    temp = (*this);
    return temp;
}

int main()
{
    loc obj1, obj2, obj3;

    cout << "Enter obj1\n";
    obj1.accept();
    cout << "Enter obj2\n";
    obj2.accept();

    obj1++;
    ++obj1;
    cout << "Obj 1:\n";
    obj1.display();
    obj2 = obj1;
    cout << "Obj 2:\n";
    obj2.display();
}