#include <iostream>
using namespace std;

/*
// C++ program to demonstrate how we will calculate
// area of shapes without virtual function

// Base class
class Shape
{
public:
    // parameterized constructor
    Shape(int l, int w)
    {
        length = l;
        width = w;
    }
    int get_Area()
    {
        cout << "This is call to parent class area\n";
        // Returning 1 in user-defined function means true
        return 1;
    }

protected:
    int length, width;
};

// Derived class
class Square : public Shape
{
public:
    Square(int l = 0, int w = 0)
        : Shape(l, w)
    {
    } // declaring and initializing derived class
    // constructor
    int get_Area()
    {
        cout << "Square area: " << length * width << '\n';
        return (length * width);
    }
};
// Derived class
class Rectangle : public Shape
{
public:
    Rectangle(int l = 0, int w = 0)
        : Shape(l, w)
    {
    } // declaring and initializing derived class
    // constructor
    int get_Area()
    {
        cout << "Rectangle area: " << length * width
             << '\n';
        return (length * width);
    }
};

int main()
{
    Shape *s;

    // Making object of child class Square
    Square sq(5, 5);

    // Making object of child class Rectangle
    Rectangle rec(4, 5);
    s = &sq; // reference variable
    s->get_Area();
    s = &rec; // reference variable
    s->get_Area();

    return 0; // too tell the program executed
              // successfully
}

*/

#include <iostream>
using namespace std;
class number
{
protected:
    int val;

public:
    void setval(int i) { val = i; }
    // show() is a pure virtual function
    virtual void show() = 0;
};
class hextype : public number
{
public:
    void show()
    {
        cout << hex << val << "\n";
    }
    // hex is a manipulator that converts the next numerical value to hexadecimal value.
};
class dectype : public number
{
public:
    void show() 
    {
        cout << val << "\n";
    }
};
class octtype : public number
{
public:
    void show()
    {
        cout << oct << val << "\n";
    }
    // oct is a manipulator that converts the next numerical value to octal value.
};
int main()
{
    dectype d;
    hextype h;
    octtype o;
    number *p;
    cout<<"Size of p="<<sizeof(p)<<endl;
    d.setval(20);
    d.show(); // displays 20- decimal
    h.setval(20);
    h.show(); // displays 14- hexadecimal
    o.setval(20);
    o.show(); // displays 24- octal
    cout<<"Size of d="<<sizeof(d)<<"\nSize of h="<<sizeof(h)<<"\nSize of o="<<sizeof(o);
    return 0;
}