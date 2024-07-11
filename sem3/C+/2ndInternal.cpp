#include <iostream>
using namespace std;

/*
1.Operator Overloading
cannot be overloaded:
sizeof
typeid
Scope resolution (::)
Class member access operators (.(dot), .* (pointer to member operator))
Ternary or conditional (?:)

// Program to overload new and delete

#include <iostream>
#include <stdlib.h>

using namespace std;

void *operator new(size_t size)
{
    void *temp = NULL;
    while (temp == NULL)
        temp = malloc(size);
    return temp;
}
void operator delete(void *p)
{
    if (p != NULL)
        free(p);
}

int main()
{
    int *s = NULL;
    cout << "Pre-new" << s;
    s = new int;
    cout << "\nPost-new" << s;
    return 0;
}


2.Function Overloading
    Disadvantages:
    1.Implicit Type Conversion
    2.Ambiguity

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
}

3.Default Arguments 4.Copy Constructor 5.Inheritance

    6. Scope resolution(::) Operator
    This helps identify and specify the context to which an identifier refers by specifying a namespace.
*/

// Program to show the usage of default value

/*
1. We write the default values in the protoype of the function
2. If explicit values are not mentioned default arguments are used

*/
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
}



// Program to show inheritance for a class of vehicles trying friend functions too

/*class Vehicle
{
public:
    void modelNumber()
    {
        cout << "Hey There!!\n";
    }
    void speedometer()
    {
        cout << "Drive Slow!!\n";
    }
};

// GF: class <derived-class name> : <access-specifier> <parent class name>

class Bus : public Vehicle
{
public:
    void invoke()
    {
        modelNumber();
        speedometer();
    }
};

class Taxi : public Vehicle
{
public:
    void invoke()
    {
        modelNumber();
        speedometer();
    }
};

class Truck : public Vehicle
{
public:
    void invoke()
    {
        modelNumber();
        speedometer();
    }
};

int main()
{
    cout << "Creating truck object\n";
    Truck one;
    one.invoke();
    cout << "Creating Bus object\n";
    Bus b_one;
    b_one.invoke();
    return 0;
}
*/