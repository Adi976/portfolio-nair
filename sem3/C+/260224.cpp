#include <iostream>
using namespace std;

// Using setf to format the output
int main()
{
    // cout.setf(ios::hex);
    //  cout.setf(ios::showpos);
    //  cout << hex << showbase << 100;
    //  cout << hex << 100; // displays +100.0
    // cout.setf(ios::showbase);
    // cout.width(10);
    // cout.setf(ios::right);
    // cout << "Sample";
    // cout.unsetf(ios::right);

    // multiple flags being set in same function call
    // char c = 'c';
    // cout.setf(ios::uppercase | ios::scientific);
    // cout << 100.12<<endl;
    // cout << c;
    // cout.unsetf(ios::uppercase);
    // cout << 100.12<<endl;

    //cout.setf(ios::showpoint | ios::showpos, ios::showpos);
    //cout << 100.0; // displays 100.0, not +100.0

    cout.setf(ios::oct, ios::basefield);
    cout << 100; // this displays 64
    return 0;
}