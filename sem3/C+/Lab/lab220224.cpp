#include <iostream>
#include <cstring>
using namespace std;

class mstring
{
    char s[20];

public:
    void accept();
    void display();
};

class student
{
    char name[20];
    char usn[10];
    int marks;

public:
    void accept();
    void display();
};

void mstring::accept()
{
    cin >> s;
}

void mstring::display()
{
    cout << s << endl;
}

void student::accept()
{
    cout << "Enter Name:";
    cin >> name;
    cout << "Enter USN:";
    cin >> usn;
    cout << "Enter Marks:";
    cin >> marks;
}

void student::display()
{
    // cout<<"Address of this:"<<this<<endl;
    // cout<<"Address of name:"<<&(this->name)<<endl;
    cout << "Name:" << name << endl;
    cout << "USN:" << usn << endl;
    cout << "Marks:" << marks << endl;
}

template <class GT>
void sort(GT a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n - i - 1; j++)
        {
            char *point = (char *)&a[j], *point2 = (char *)&a[j + 1];
            if (strcmp((point), (point2)))
            {
                GT temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter size of the arrays\n";
    cin >> n;
    mstring a[n];
    student list[n];
    printf("Enter %d strings\n", n);
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter string " << i + 1 << endl;
        a[i].accept();
    }
    cout << "Entered Strings are:\n";

    for (int i = 0; i < n; i++)
    {
        a[i].display();
    }

    printf("\nEnter %d student details\n", n);
    for (int i = 0; i < n; i++)
    {
        cout << "\nStudent " << i + 1 << endl;
        list[i].accept();
    }
    for (int i = 0; i < n; i++)
    {
        cout << "\nStudent " << i + 1 << endl;
        list[i].display();
    }

    sort(a, n);
    cout << "After Sorting Strings:\n";
    for (int i = 0; i < n; i++)
    {
        a[i].display();
    }

    sort(list, n);
    cout << "After Sorting Student details:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\nStudent " << i + 1 << endl;
        list[i].display();
    }

    return 0;
}