//Using generic function, design a sort algorithm for the same 

/*#include <iostream>
#include <cstring>
using namespace std;

class sing
{
    char s[20];
public:
    sing()
    {
        memset(s, '\0', sizeof(s));
    }
    sing operator+(sing &);
    void accept();
    void display();
};

void sing::accept()
{
    cin >> s;
}
void sing::display()
{
    cout << s<<endl;
}
sing sing::operator+(sing &p)
{
    sing t;
    strcat(t.s, s);
    strcat(t.s, p.s);
    return t;
}

int main()
{
    sing s1, s2, s3;
    cout << "Enter String 1:";
    s1.accept();
    cout << "String 1:";
    s1.display();
    cout << "Enter String 2:";
    s2.accept();
    cout << "String 2:";
    s2.display();
    s3 = s1 + s2;
    cout << "String 3:";
    s3.display();
    return 0;
}
*/

/*class comp
{
    int r;
    int i;

public:
    comp operator+(comp &);
    void accept();
    void display();
};

void comp::accept()
{
    cout << "Enter Real:";
    cin >> r;
    cout << "Enter Imaginary:";
    cin >> i;
}

void comp::display()
{
    cout << r << "+" << i << "i\n";
}

comp comp::operator+(comp &p)
{
    comp temp;
    temp.r = r + p.r;
    temp.i = i + p.i;
    return temp;
}

int main()
{
    comp one, two, three;
    cout << "Enter comp 1: ";
    one.accept();
    cout << "Comp 1:";
    one.display();
    cout << "Enter comp 1: ";
    two.accept();
    cout << "Comp 2:";
    two.display();
    three = one + two;
    cout << "Comp 3:";
    three.display();
    return 0;
}
*/

/*
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
*/
/*
#include <iostream>

// Define multiple overloaded functions
void foo(int x) {
    std::cout << "foo(int): " << x << std::endl;
}

void foo(double x) {
    std::cout << "foo(double): " << x << std::endl;
}

// Main function
int main() {
    // Use the address-of operator to get the address of the overloaded functions
    void (*ptr1)(int) = &foo;
    void (*ptr2)(double)= &foo;

    // Print the addresses
    //std::cout << "Address of foo(int): " << ptr1 << std::endl;
    //std::cout << "Address of foo(double): " << ptr2 << std::endl;
    printf("Address of foo(int)=%x\n",ptr1);
    printf("Address of foo(double)=%x",ptr2);

    return 0;
}
*/

