#include <iostream>
using namespace std;
class simp
{
public:
    simp();
    ~simp();
};
int main()
{
    simp p;
    cout << "Address of p:" << &p << endl;
    simp *d = new simp;
    delete d;
    cout << "\nMain terminates\n";
    return 0;
}
simp::simp()
{
    cout << "Entered ZPC" << endl;
}
simp::~simp()
{
    cout << "Entered destructor" << endl;
    cout << "This pointer points to " << this << " in destructor";
    cout << "\nExited destructor\n";
}