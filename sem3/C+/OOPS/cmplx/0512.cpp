#include <iostream>
using namespace std;

class comp
{

    int r, i;

public:
    comp()
    {
        cout << "Content of this is " << this << endl;
        r = 0;
        i = 0;
        cout << "Constructor" << endl;
    }
};
int main()
{
    // comp c1;
    // comp* c1 will not call the constructor because it is a pointer to an object
    // cout<<"Address of c1 is "<<&c1<<endl;
    comp *ptr = new comp[2];
    cout << "Content of ptr[0]" << ptr << endl
         << "Content of ptr[1]";
    cout << ptr + 1 << endl;

    return 0;
}