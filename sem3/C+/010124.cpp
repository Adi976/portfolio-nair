// Program to show the usage of default value
/*#include<iostream>
using namespace std;
int gv=10;
int func1();
void default_value(int=gv,int=func1(),int=1000);
int main()
{
    cout<<"Default values are used\n";
    default_value();
    cout<<"\nExplicit mention of value\n";
    default_value(30,40,50);
}
int func1()
{
    return 100;
}
void default_value(int a,int b,int c)
{
    cout<<"A="<<a<<"\nB="<<b<<"\nC="<<c;
}*/

// Program to show ambiguity in overloaded functions

/*#include<iostream>
using namespace std;
float myFunc(float);
double myFunc(double);
int main()
{
    cout<<myFunc(10.1);
    //cout<<myFunc(10);
    return 0;
}
float myFunc(float i)
{
    return i;
}
double myFunc(double i)
{
    return -1;
}*/

// Program to overload constructors

/*#include <iostream>
using namespace std;

class date
{
    int day, month, year;

public:
    date(char *d);
    date(int m, int d, int y);
    void show_date();
};
date::date(char* d)
{
    sscanf(d,"%d%*c%d%*c%d",&month,&day,&year);
    //The %*c ignores the / symbol
}
date::date(int m,int d,int y)
{
    day=d;month=m;year=y;
}
void date::show_date()
{
    cout<<month<<
}*/

// Program depicting usage of template

// Program 1
/*#include<iostream>
template<class GT>
void ex(GT a)
{
    cout<<size(a);
}
int main()
{
    ex(10);
    ex(10.2);
    ex('a');
}*/

// Program to illustrate use

/*#include<iostream>
using namespace std;

template<class type1,class type2>
void myFunc(type1 x,type2 y)
{
    cout<<"\n"<<x<<' '<<y<<'\n';
    cout<<"Size of x="<<sizeof(x)<<"\nSize of y="<<sizeof(y);
}
int main()
{
    myFunc(10,"I like C++");
    myFunc(98.6,19L);
    return 0;
}*/

// Program to overload GF with a normal function

/*#include <iostream>
using namespace std;
void swapArgs(int *, int *);
template <class X>
void swapArgs(X &a, X &b)
{
    cout<<"\nEntered template scope\n";
    X temp;
    temp = a;
    a = b;
    b = temp;
}
int main()
{
    int a = 10, b = 20;
    double c = 4.2, d = 6.2;
    cout << "\nPre Swap:\nA=" << a << "\nB=" << b;
    swapArgs(&a, &b);
    cout << "\nPost Swap:\nA=" << a << "\nB=" << b;
    cout << "\nPre Swap:\nC=" << c << "\nD=" << d;
    swapArgs(c, d);
    cout << "\nPost Swap:\nC=" << c << "\nD=" << d;
    return 0;
}
void swapArgs(int *a, int *b)
{
    cout << "\nEntered Explicitly coded fuction\n";
    int temp = *a;
    *a = *b;
    *b = temp;
}*/

// Program to sort arrays and print them using templates

#include <iostream>
using namespace std;


template <class X>
void display(X *ar, int count, char *msg = NULL)
{
    cout << msg;
    for (int i = 0; i < count; i++)
    {
        cout << ar[i] << endl;
    }
}
template <class X>
void sort(X *ar, int count)
{
    for (int i = 0; i < count; i++)
    {
        for (int j = i; j < count - 1; j++)
        {
            if (ar[j] > ar[j + 1])
            {
                X temp = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = temp;
            }
        }
    }
}

int main()
{
    return 0;
}
