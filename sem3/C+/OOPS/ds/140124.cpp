/* Program to overload special operators
#include <iostream>
using namespace std;
class loc
{
    int longitude, latitude;

public:
    loc() {}
    loc(int lg, int lt)
    {
        longitude = lg;
        latitude = lt;
    }
    void show()
    {
        cout << longitude << " ";
        cout << latitude << "\n";
    }
    loc operator+(loc op2);
    loc operator()(int i, int j);
};
// Overload ( ) for loc.
loc loc::operator()(int i, int j)
{
    longitude = i;
    latitude = j;
    return *this;
}
// Overload + for loc.
loc loc::operator+(loc op2)
{
    loc temp;
    temp.longitude = op2.longitude + longitude;
    temp.latitude = op2.latitude + latitude;
    return temp;
}
int main()
{
    loc ob1(10, 20), ob2(1, 1);
    ob1.show();
    ob1(7, 8); // can be executed by itself
    ob1.show();
    ob1 = ob2 + ob1(10, 10); // can be used in expressions
    ob1.show();
    return 0;
}*/

/* Program to implement two generic classes
#include <iostream>
using namespace std;
template <class Type1, class Type2>
class myclass
{
    Type1 i;
    Type2 j;

public:
    myclass(Type1 a, Type2 b)
    {
        i = a;
        j = b;
    }
    void show() { cout << i << ' ' << j << '\n'; }
};
int main()
{
    myclass<int, double> ob1(10, 0.23);
    myclass<char, char *> ob2('X', "Templates add power.");
    ob1.show(); // show int, double
    ob2.show(); // show char, char *
    return 0;
}
*/

/*
#include <iostream>
#include <cstdlib>
using namespace std;
const int SIZE = 10;
template <class AType>
class atype
{
    AType a[SIZE];

public:
    atype()
    {
        register int i;
        for (i = 0; i < SIZE; i++)
            a[i] = i;
    }
    AType &operator[](int i);
};
// Provide range checking for atype.
template <class AType>
AType &atype<AType>::operator[](int i)
{
    if (i < 0 || i > SIZE - 1)
    {
        cout << "\nIndex value of ";
        cout << i << " is out-of-bounds.\n";
        exit(1);
    }
    return a[i];
}
int main()
{
    atype<int> intob;       // integer array
    atype<double> doubleob; // double array
    int i;
    cout << "Integer array: ";
    for (i = 0; i < SIZE; i++)
        intob[i] = i;
    for (i = 0; i < SIZE; i++)
        cout << intob[i] << " ";
    cout << '\n';
    cout << "Double array: ";
    for (i = 0; i < SIZE; i++)
        doubleob[i] = (double)i / 3;
    for (i = 0; i < SIZE; i++)
        cout << doubleob[i] << " ";
    cout << '\n';
    intob[12] = 100; // generates runtime error
    return 0;
}
*/
#include <iostream>
#include <cstdlib>
using namespace std;
// Here, AType defaults to int and size defaults to 10.
template <class AType = int, int size = 10>
class atype
{
    AType a[size]; // size of array is passed in size
public:
    atype()
    {
        register int i;
        for (i = 0; i < size; i++)
            a[i] = i;
    }
    AType &operator[](int i);
};
// Provide range checking for atype.
template <class AType, int size>
AType &atype<AType, size>::operator[](int i)
{
    if (i < 0 || i > size - 1)
    {
        cout << "\nIndex value of ";
        cout << i << " is out-of-bounds.\n";
        exit(1);
    }
    return a[i];
}
int main()
{
    atype<int, 100> intarray;  // integer array, size 100
    atype<double> doublearray; // double array, default size
    atype<> defarray;          // default to int array of size 10
    int i;
    cout << "int array: ";
    for (i = 0; i < 100; i++)
        intarray[i] = i;
    for (i = 0; i < 100; i++)
        cout << intarray[i] << " ";
    cout << '\n';
    cout << "double array: ";
    for (i = 0; i < 10; i++)
        doublearray[i] = (double)i / 3;
    for (i = 0; i < 10; i++)
        cout << doublearray[i] << " ";
    cout << '\n';
    cout << "defarray array: ";
    for (i = 0; i < 10; i++)
        defarray[i] = i;
    for (i = 0; i < 10; i++)
        cout << defarray[i] << " ";
    cout << '\n';
    return 0;
}