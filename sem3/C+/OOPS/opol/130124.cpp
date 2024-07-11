//Program to overload operator + and = for string incomp
#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

class MyString
{
    char *s;

public:
    MyString()
    {
    }
    void accept();
    void display();
    MyString operator+(const MyString &) const;
    MyString operator=(const MyString &) const;
};

void MyString::accept()
{
    s = (char *)malloc(sizeof(char) * 100);
    cout << "Enter a string \n";
    cin >> s;
    s = (char *)realloc(s, sizeof(char) * (strlen(s) + 1));
}
void MyString::display()
{
    cout << s << endl;
}

MyString MyString::operator+(const MyString &obj) const
{
    MyString temp;
    temp.s = (char *)malloc(sizeof(char) * (strlen(s) + strlen(obj.s) + 1));
    strcpy(temp.s, s);
    strcpy(temp.s + strlen(s), obj.s);
    cout << "In Overloaded + " << temp.s;
    return temp;
}
MyString MyString::operator=(const MyString &obj) const
{
    MyString temp;
    temp.s = (char *)malloc(sizeof(char) * ((strlen(obj.s)) + 1));
    strcpy(temp.s, obj.s);
    cout << "In overloaded = " << temp.s;
    return temp;
}
int main()
{
    MyString one;
    one.accept();
    MyString two;
    two.accept();
    MyString three, four;
    three = one + two;
    cout << "\n Three: ";
    three.display();
    cout << "\n Four: ";
    four = three;
    four.display();
    return 0;
}