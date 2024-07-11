#include <iostream>
using namespace std;
class comp
{
    int *r, *i;

public:
    comp(int a, int b)
    {
        cout << "Entered constructor" << endl;
        r = new int(a);
        i = new int(b);
    }
    // comp(int a, int b) : r(a), i(b) {}
    void display() const
    {
        cout << "R=" << r << "\nI=" << i << endl;
        *r = 100;
    }
    ~comp();
    // comp(const comp &);
};
comp::~comp()
{
    cout << "\nEntered destructor\n";
    delete r;
    delete i;
    cout << "Exited destructor\n";
}
int main()
{
    comp c1(10, 20);
    cout << "c1 created" << endl;
    c1.display();
    comp c2 = c1; // exact copy of c1 along with the addresses
    cout << "c2 created" << endl;
    c2.display();
    comp c3(1, 2);
    cout << "c3 created" << endl;
    c3.display();
    // cout<<"Address of c1 is "<<&c1<<endl;

    return 0;
}
/*comp::comp(const comp &p)
{
    r = p.r;
}*/