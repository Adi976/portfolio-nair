#include <iostream>
#include <cstring>
using namespace std;

template <class Swap>
void swapValue(Swap &a, Swap &b)
{
    Swap *temp = a;
    a = b;
    b = temp;
}

struct student
{
    char n[20], usn[10];
    int m[3];
};
class emp
{
    char name[20], eid[10];
    float salary;

public:
    emp(char *nm, char *eid, float sal)
    {
        strcpy(name, nm);
        strcpy(eid, eid);
        sal = salary;
    }
    void display()
    {
        cout << name << eid << salary;
    }
};
int main()
{
    int a = 10, b = 20;
    cout << a << b << endl;
    swapValue(a, b);
    student p = {"abc", "123", {1, 2, 3}};
    student q = {"pqr", "456", {4, 5, 6}};
    emp x("ppp", "123", 1234.56);
    emp y("qqq", "345", 5678.90);
    cout << "Before Swap\n";
    x.display();
    y.display();
    cout << "after Swap\n";
    swapValue(x, y);
    x.display();
    y.display();
    return 0;
}