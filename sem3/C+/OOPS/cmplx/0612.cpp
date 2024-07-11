#include<iostream>
using namespace std;

class comp{

    int r,i;
    public:comp(int,int);
            comp();
    void display(int,int);

};
comp::comp(int r,int i)
{
    this->r=r;
    this->i=i;
    display(this->r,this->i);
}
comp::comp()
{
    r=i=0;
    display(r,i);
}
void comp::display(int r,int i)
{
    cout<<"r="<<r<<endl;
    cout<<"i="<<i<<endl;
}
int main()
{
    comp p(1,2);
    comp ar[3]={comp(10,20)};

    return 0;
}