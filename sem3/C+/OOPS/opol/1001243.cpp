//Program to overload + > !!
#include <iostream>
using namespace std;

class location
{
    int lt, lg;

public:
    location(int l1 = 0, int l2 = 0)
    {
        lt = l1;
        lg = l2;
    }
    void accept();
    void display();
    bool operator<(location &) const;
    location operator+(location &) const;
};
int main()
{
    location start(0, 0);
    location stop1(0,0);
    location stop2(0,0);
    location end(0, 0);
    location final(0, 0);
    cout << "Enter Start location\n";
    start.accept();
    cout << "\nEnter 1st stop location\n";
    stop1.accept();
    cout << "\nEnter 2nd stop location\n";
    stop2.accept();
    cout << "\nEnter End location\n";
    end.accept();
    //final = (start + end);
    final=start+end+stop1+stop2;
    cout << "The final location coordinates are:\n";
    final.display();
    if (start < end)
    {
        cout << "\nEnd is greater\n";
        end.display();
    }
    else
    {
        cout << "\nStart is greater\n";
        start.display();
    }
    return 0;
}
void location::accept()
{
    cout << "Longitude:";
    cin >> lt;
    cout << "\nLatitude:";
    cin >> lg;
}
void location::display()
{
    cout << "\nLongitude:" << lt;
    cout << "\nLatitude:" << lg;
}
bool location::operator<(location &end) const
{
    if ((lt < end.lt) && (lg < end.lg))
        return true;
    else
        return false;
    //cout<<"Address: "<<this<<endl;
}
location location::operator+(location &end) const
{
    location temp;
    temp.lt = lt + end.lt;
    temp.lg = lg + end.lg;
    return temp;
}
