#include <iostream>
using namespace std;
/*

//1. Program to show inheritance on protected members


class base
{
protected:
    int i, j;

public:
    void setij()
    {
        i = 5;
        j = 10;
    }
    void showij()
    {
        cout << "I=" << i << endl;
        cout << "J=" << j << endl;
    }
};

class derived : protected base
{
    int k;

public:
    void setk()
    {
        setij();
        k = 15;
    }
    void showk()
    {
        showij();
        cout << "K=" << k << endl;
    }
};

int main()
{
    derived obj;
    obj.setk();
    obj.showk();
    return 0;
}

*/

/*

// 2. Multiple base class inheritance

class base1
{
protected:
    int x;
    void setx(int &i)
    {
        x = i;
    }
    void showx()
    {
        cout << "X=" << x << endl;
    }
};

class base2
{
protected:
    int y;
    void sety(int &j)
    {
        y = j;
    }
    void showy()
    {
        cout << "Y=" << y << endl;
    }
};

class derived : public base1, public base2
{
public:
    int i, j;
    void setij()
    {
        i = 5;
        j = 10;
        setx(i);
        sety(j);
    }
    void showxy()
    {
        showx();
        showy();
    }
};

int main()
{
    derived obj;
    obj.setij();
    obj.showxy();
    return 0;
}

*/

/*


// 3. Constructors and destructors in inheritance
// Constructor order : 1.Base 2. Derived
// Destructor order : 1. Derived 2. Base

class base
{
public:
    base()
    {
        cout << "In Base Class constructor\n";
    }
    ~base()
    {
        cout << "In Base Class destructor\n";
    }
};

class derived : public base
{
public:
    derived()
    {
        cout << "In Derived Class constructor\n";
    }
    ~derived()
    {
        cout << "In Derived Class destructor\n";
    }
};

int main()
{
    derived obj;
    return 0;
}

*/

/*


// 4. Explicit call of the base class constructor from the derived class with arguments

class base1
{
    int x;

public:
    base1()
    {
    }
    base1(int i)
    {
        x = i;
    }
    void show1()
    {
        cout << "X=" << x << endl;
    }
};

class base2
{
    int y;

public:
    base2()
    {
    }
    base2(int j)
    {
        y = j;
    }
    void show2()
    {
        cout << "Y=" << y << endl;
    }
};

class derived : public base1, public base2
{

public:
    int i, j;
    derived(int i1, int j1):base1(i1),base2(j1)
    {
        i = i1;
        j = j1;
    }
    void show()
    {
        show1();
        show2();
    }
};

int main()
{
    derived obj(2, 3);
    obj.show();
    return 0;
}

*/

// 5.  It might be necessary to grant certain public members of the base class public status in
// the derived class even though the base class is inherited as private

class base
{
    int x;

public:
    int y;
    void setx(int x1)
    {
        x = x1;
    }
    int getx()
    {
        return x;
    }
};

class derived : private base
{
public:
    /* The next three statements override base's inheritance as private and restore j,
    seti(), and geti() to public access. */
    using base::getx;
    using base::setx;
    using base::y;
    // base::i;      // illegal, cannot elevate access
};

int main()
{
    derived obj;
    obj.setx(5);
    printf("X=%d\n",obj.getx());
    return 0;
}