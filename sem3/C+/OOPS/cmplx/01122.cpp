#include<iostream>
using namespace std;

class comp
{
    int r,i;
    public: void accept();
    void display()const;
    void compare(const comp&)const;

};

int main()
{
    comp c1,c2;
    cout<<"Enter 1st complex number"<<endl;
    c1.accept();
    cout<<"Enter 2nd complex number"<<endl;
    c2.accept();
    c2.compare(c1);
}
void comp::accept()
{
    cout<<"Enter real part"<<endl;
    cin>>r;
    cout<<"Enter imaginary part"<<endl;
    cin>>i;
}
void comp:: compare(const comp& c1)const
{
    if(r==c1.r)
    {
        cout<<"Both are equal";
        display();
    }
    else if(r>c1.r)
    {
        cout<<"Complex number 2 is greater= ";
        display();
    }
    else
    {
        cout<<"Complex number 1 is greater= ";
        c1.display();

    }
}
void comp::display()const
{
    /*cout<<"The entered r value is "<<r;
    cout<<"The entered i value is "<<i;*/
    cout<<r<<"+"<<i<<"i"<<endl;
}