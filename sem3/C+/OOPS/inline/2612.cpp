/*#include <iostream>
using namespace std;
class shared
{
    static int a;
    int b;

public:
    void set(int i, int j)
    {
        a = i;
        b = j;
    }
    void show();
};
void shared::show()
{
    cout << "a=" << a << "\nb=" << b;
}
int shared::a;
int main()
{
    shared x, y;
    x.set(1, 1);
    cout << "For X\n";
    x.show();
    cout << "\nFor Y\n";
    y.show();
    y.set(2, 2);
    cout << "\nFor X\n";
    x.show();
    cout << "\nFor Y\n";
    y.show();
}
*/

/*
#include <iostream>
using namespace std;

class shared
{
    int b;

public:
    static int a;
};
int shared::a;
int main()
{
    shared::a = 90;
    cout << "A=" << shared::a;
}
*/

#include <iostream>
using namespace std;

// #define CNT_DISP(s) cout << "There are " << s<< " objects of the class\n";
inline void CNT_DISP(int s)
{
    cout << "There are " << s << " objects of the class\n";
    /*if (shared::cnt!=0)
    CNT_DISP();*/
}
class shared
{
public:
    static int cnt;
    shared()
    {
        cout<<"INSIDE ZPC\n";
        cnt++;
    }
    shared(const shared &) { cnt++; }
    ~shared()
    {
        cout<<"INSIDE DESTRUCTOR\n";
        cnt--;
        CNT_DISP(shared::cnt);
    }
};
void fun1(shared x)
{
    cout<<"INSIDE CPY CONSTRUCTOR\n";
    return;
}
int shared::cnt;
int main()
{
    // CNT_DISP(shared::cnt)
    CNT_DISP(shared::cnt);
    shared x, y, a[2];
    cout<<"4 auto objects created\n";
    shared *p = NULL;
    shared &Q = x;
    cout<<"Before creation of p\n";
    CNT_DISP(shared::cnt);
    cout<<"Creating p\n";
    p = new shared();//calls zpc
    cout<<"After creation of p\n";
    CNT_DISP(shared::cnt);
    cout<<"Calling fun1\n";
    fun1(*p);//calls cpy constructor
    cout<<"Before delete p\n";
    CNT_DISP(shared::cnt);
    delete p;
    cout<<"After delete p\n";
    // CNT_DISP(shared::cnt)
    CNT_DISP(shared::cnt);
    
    return 0;
}