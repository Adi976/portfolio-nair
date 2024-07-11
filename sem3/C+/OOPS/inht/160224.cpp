// Program to showacase use of pure virtual functions,abstract classes

#include <iostream>
using namespace std;

// Microsoft Foundation Classes

// To declare a pure virtual function, use this general form:
//           virtual type func-name(parameter-list) = 0;

/*When a virtual function is made pure, any derived class must provide its own
 definition. If the derived class fails to override the pure virtual function, a
 compile-time error will result.*/

/*
class parent
{
    int a;
public:
    virtual void display() = 0; //If there is even one virtual function in a class then the class serves as an abstract class for derived classes
    //A class that contains at least one pure virtual function is said to be abstract
    //A class without any members is also abstract
};

class child1 : public parent
{
    public:
    virtual void display()//virtual not compulsory to be included
    {
        cout<<"Child1 display()\n";
    }
};

class child2 : public parent
{
    public:
    void display()
    {
        cout<<"Child 2 display()\n";
    }
};

int main()
{
    child1 obj1;
    child2 obj2;
    //parent obj2; //creation of an object of abstract type classes is not allowed
    obj1.display();
    obj2.display();
    return 0;
}
*/

// Program to use abstract classes to compute liters to gallons and celsius to fahrenhiet

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