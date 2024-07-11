#include <iostream>
using namespace std;

class comp
{
public:
    comp(const comp &);
    comp();
};
comp::comp()
{
}
comp::comp(const comp &p)
{
    cout << "Entered CC";
}
comp nsimp(comp p)
{
    return p;
}
int main()
{
    comp c1;
    c1 = nsimp(c1);
}