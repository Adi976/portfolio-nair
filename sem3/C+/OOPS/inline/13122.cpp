#include<iostream>
using namespace std;
class comp{
    int r,i;
    public:
    friend void accept(comp&);
    friend void display(const comp&);
    int main();
};
int main()
{
    comp c1;
    accept(c1);
    display(c1);
    return 0;
}
void accept(comp& c)
{
    cin>>c.r>>c.i;
}
void display(const comp& c)
{
    cout<<"R="<<c.r<<"\nI="<<c.i;
}

