#include <iostream>
using namespace std;
inline void swap(int &, int &);
int main()
{
    int a, b;
    cout << "Enter two int values\n";
    cin >> a >> b;
    cout << "Pre-swap"
         << "\nA=" << a << "\nB=" << b << endl;
    swap(a, b);
    cout << "Post-swap"
         << "\nA=" << a << endl
         << "B=" << b;
    return 0;
}
inline void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}