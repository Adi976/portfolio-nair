//Program to find the student with maximum marks and print his/her details

#include <iostream>
using namespace std;

class student
{
    int m;
    char name[20];
    char usn[10];
    int dob;

public:
    void accept();
    void display();
    friend void findMax(student *);
};

void student::accept()
{
    cout << "Enter Name:";
    cin >> this->name;
    cout << "Enter USN:";
    cin >> usn;
    cout << "Enter D.O.B:";
    cin >> dob;
    cout << "Enter Marks:";
    cin >> m;
}

void findMax(student *list)
{
    int max = list[0].m;
    int index = 0;
    for (int i = 0; i < 5; i++)
    {
        if (list[i].m > max)
        {
            max = list[i].m;
            index = i;
        }
    }
    cout << "Student" << index;
    list[index].display();
}

void student::display()
{
    cout << "Name:" << name << endl;
    cout << "USN:" << usn << endl;
    cout << "D.O.B:" << dob << endl;
    cout << "Marks:" << m << endl;
}

int main()
{
    student list[5];
    cout << "Enter details of 5 students\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "Student " << i + 1<<endl;
        list[i].accept();
    }
    findMax(list);
    return 0;
}

//Alternate approach using getMarks function

/*
#include <iostream>
using namespace std;

class student
{
    int m;
    char name[20];
    char usn[10];
    int dob;

public:
    void accept();
    void display();
    int getMarks() const; // Getter function for marks
};

void student::accept()
{
    cout << "Enter Name:";
    cin >> name;
    cout << "Enter USN:";
    cin >> usn;
    cout << "Enter D.O.B:";
    cin >> dob;
    cout << "Enter Marks:";
    cin >> m;
}

void student::display()
{
    cout << "Name:" << name << endl;
    cout << "USN:" << usn << endl;
    cout << "D.O.B:" << dob << endl;
    cout << "Marks:" << m << endl;
}

int student::getMarks() const
{
    return m;
}

int main()
{
    student list[5];
    cout << "Enter details of 5 students\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "Student " << i + 1 << endl;
        list[i].accept();
    }

    // Find student with maximum marks
    int maxMarks = list[0].getMarks();
    int index = 0;
    for (int i = 1; i < 5; i++)
    {
        if (list[i].getMarks() > maxMarks)
        {
            maxMarks = list[i].getMarks();
            index = i;
        }
    }

    // Display details of student with maximum marks
    cout << "Student with maximum marks:\n";
    list[index].display();

    return 0;
}
*/