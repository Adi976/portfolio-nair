#include <iostream>
using namespace std;

//Enumerations
//I/O redirection
//Bit fields
//Range of signed int -2^(n-1) to 2^(n-1)-1

//Program to show inherited template classes
/*template <class GT>
class base
{
    GT a;
};

template <class GT1>
class derived : public base<GT>
{
};*/

struct simp
{
    int i:3;//bitfie;d
    int j:4;
    simp(int i1,int j1)
    {
        i=i1;
        j=j1;
    }
};

int main()
{
    simp one(10,3);
    cout<<"I="<<one.i<<"\nJ="<<one.j;
    return 0;
}