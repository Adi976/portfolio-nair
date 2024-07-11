//Program to demonstrate inheritance

#include<iostream>
using namespace std;

class base
{
    public:
    int i,j;
    void set(int a,int b)
    {
        i=a;
        j=b;
    }
    void show()
    {
        cout<<"\nI="<<i<<"\nJ="<<j;
    }
};

class derived: public base
{
    public:
    int k;
    void setD(int a)
    {
        k=a;
    }
    void showD()
    {
        show();
        cout<<"\nK="<<k;
    }
};

int main()
{
    derived obj2,obj3;
    obj2.set(1,2);
    obj2.setD(3);
    cout<<"Via base object\n";
    obj2.show();
    cout<<"\nVia derived object\n";
    obj2.showD();
}