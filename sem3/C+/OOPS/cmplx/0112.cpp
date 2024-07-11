#include <iostream>
using namespace std;
class complex
{
    int r, i;

public:
    void accept();
    void display() const;
    complex add(const complex &) const;
};
void complex::accept()
{
    cout << "Enter r value\n";
    cin >> r;
    cout << "Enter i value\n";
    cin >> i;
}
void complex::display() const
{
    /*cout<<"The entered r value is "<<r;
    cout<<"The entered i value is "<<i;*/
    cout << "Sum=" << r << "+" << i << "i" << endl;
}
complex complex::add(const complex &p) const
{
    complex t;
    t.r = r + p.r;
    t.i = i + p.i;
    return t;
}
int main()
{
    complex c1, c2, c3;
    c1.accept();
    c2.accept();
    c3 = c1.add(c2);
    c3.display();
}