#include <iostream>
using namespace std;

class student
{
    char nm[20];
    char usn[20];
    int m[3];

public:
    void accept()
    {
        cin >> nm;
        cin >> usn;
        for (int i = 0; i < 3; i++)
            cin >> m[i];
    }
    void display()
    {
        cout << nm << endl;
        cout << usn << endl;
        for (int i = 0; i < 3; i++)
            cout << m[i] << endl;
    }
};
int main()
{
    int n;
    student s[20];
    cin >> n;
    for (int i = 0; i < n; i++)
        s[i].accept();

    for (int i = 0; i < n; i++)
        s[i].display();

    return 0;
}