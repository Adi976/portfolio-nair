#include<iostream>
using namespace std;

//POWSDM://Pearls of wisdom

// Inheritance is hierarchical in C++, hence virtual functions are also hierarchical.
// This means that when a derived class fails to override a virtual function,
// the first redefinition found in reverse order of derivation is used.

//IMP:
//  Restriction on virtual function is that it must be nonstatic members of the classes. //static is single copy
//  Virtual functions cannot be friend functions //not a member function
//  Constructor functions cannot be virtual, but destructor functions can.whhy??

//1. Program to show that pointer of base class type can be used to access derived base class objects of the derived class

/* The members of the base class inherited into derived class can only be
 accessed, the members which belong exclusively to derived class cannot be
 accessed from the base class pointer.


class parent
{
    int i;
    public:
    void seti(int i1)
    {
        i=i1;
    }
    void displayi()
    {
        cout<<"I="<<i<<endl;
    }
};

class child1:public parent
{
    int j;
    public:
    void setj(int j1)
    {
        j=j1;
    }
    void displayj()
    {
        cout<<"J="<<j<<endl;
    }
};

int main()
{
    parent *pointer=NULL;
    child1 obj;
    pointer=&obj;   // members which are inherited from base to derived classes can be accessed using base class pointer
    pointer->seti(5);
    obj.setj(10);
    pointer->displayi();
    obj.displayj();
    cout<<"Using child object:\n";
    obj.displayi();
    return 0;
}

*/

/*
//2. Program to showcase use of virtual functions and compile time polymorphism

class parent
{
    int i;
    public:
    void seti(int i1)
    {
        i=i1;
    }
    virtual void display()
    {
        cout<<"I="<<i<<endl;
    }
};

class child1:public parent
{
    int x;
    public:
    void setx(int x1)
    {
        x=x1;
    }
    void display()
    {
        //display(); //leads to ambiguity because the complier presumes it is a recursive call to the same function
        //parent::display();// Therefore using scope resolutio operator to remove ambiguity
        cout<<"X="<<x<<endl;
    }
};

class child2:public parent
{
    int y;
    public:
    void sety(int y1)
    {
        y=y1;
    }
    void display()
    {
        cout<<"Y="<<y<<endl;
    }
};

int main()
{
    child1 one;
    child2 two;
    one.setx(20);
    one.seti(5);
    two.sety(30);
    one.display();
    two.display();
    one.parent::display();      //specifically for the parent class display()
    return 0;
}

*/

/*

//3.Program to showcase run-time polymorphism using virtual functions

//Although a virtual function can be invoked in a "normal" manner by using an
// object's name and the dot operator, it is only when access is through a
// base-class pointer (or reference) that run-time polymorphism is achieved


class parent
{
    public:
    virtual void display()
    {
        cout<<"Base-class function\n";
    }
};

class child1:public parent
{
    public:
    void display()
    {
        cout<<"Child-1 class function\n";
    }
};

class child2:public parent
{
    public:
    void display()
    {
        cout<<"Child-2 class function\n";
    }
};
int main()
{
    parent *pointer=NULL,pobj;
    child1 one;
    pointer=&pobj;
    child2 two;
    pointer->display();
    pointer=&one;
    pointer->display();
    pointer=&two;
    pointer->display();
    return 0;
}

*/

//4. Program to show hierarchial inheritance in C++

//In the following program, grandchild is derived from child,
// which is derived from parent. However, grandchild does not override display( ).
// This means that, relative to grandchild, the closest version of display( ) is in
// child. Therefore, it is child::display( ) that is used when an object of
// grandchild attempts to call display( ).

class parent
{

};

class child:public parent
{

};

int main()
{
    return 0;
}