#include<iostream>
using namespace std;
class comp
{
    int r,i;
    public:void display()
    {
        cout<<"R="<<r<<"\nI="<<i;
    }
};
int main()
{
    comp c1;
    int *p=(int*)&c1;
    *p=20;
    p++;
    *p=30;
    c1.display();
}