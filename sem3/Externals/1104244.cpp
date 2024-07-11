
#include <iostream>
using namespace std;

// 1. Program to use abstract classes to compute liters to gallons and celsius to fahrenhiet

/*
class Convert
{
protected:
    double val;
    double con_val;

public:
    Convert(double i)
    {
        val = i;
    }
    double getInitialVal()
    {
        return val;
    }
    double getConvertedVal()
    {
        return con_val;
    }
    virtual void compute() = 0;
};

class LitersToGallons : public Convert
{
public:
    LitersToGallons(double i) : Convert(i) {}
    void compute()
    {
        con_val = val / 3.7584;
    }
};

class FahrenhietToCelsius : public Convert
{
public:
    FahrenhietToCelsius(double i) : Convert(i) {}
    void compute()
    {
        con_val = val / 1.8;
    }
};

int main()
{
    LitersToGallons obj1(4);
    FahrenhietToCelsius obj2(70);
    cout << obj1.getInitialVal() << " liters is equal to " << obj1.getConvertedVal() << " gallons\n";
    cout << obj2.getInitialVal() << " Fahrenheit is equal to " << obj2.getConvertedVal() << " Celsius\n";
    return 0;
}
*/

// 2.Program to demonstrate use of virtual functions and base class pointer

class base
{
protected:
    int a;

public:
    // virtual void show() = 0; //If the function is a pure vf then the only definition is the derived one hence it is the one which is called
    virtual void show()
    {
        cout << "A=" << a << endl;
    }
    virtual void explanation(int c = 3)
    {
        a = c;
        cout << "This is just a virtual function\n";
    }
};

class derived : public base
{
    int b;

public:
    derived()
    {
        b = 4;
    }
    void show()
    {

        cout << "A=" << a << "\nB=" << b;
    }
};

int main()
{
    base *basePtr;
    derived obj;
    basePtr = &obj;
    basePtr->show();
    return 0;
}

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
