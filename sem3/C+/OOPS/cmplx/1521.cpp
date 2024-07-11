#include <iostream>
using namespace std;
class complex
{
private:
    int r, i;

public:
    void accept()
    {
        cin >> r >> i;
    }
    void display()
    {
        cout << r << endl
             << i << endl;
    }
};
int main()
{
    complex c1;
    complex *p = NULL;
    p = &c1;
    p->accept();
    p->display();
    //  cout<<sizeof(c1)<<endl;
    //  cout<<sizeof(p)<<endl;
    //  //cout<<"R="<<p->r;
}
