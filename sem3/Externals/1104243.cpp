#include <iostream>
using namespace std;

// 1. WAP to swap two int,student type of information using generic function

/*class student
{
    int m;
    char usn[20];
    char name[20];
    public:
        void accept();
        void display();
};

void student::accept()
{
    cout<<"Enter Marks:";
    cin>>m;
    cout<<"Enter USN:";
    cin>>usn;
    cout<<"Enter Name:";
    cin>>name;
}

void student::display()
{
    cout<<"Marks:"<<m<<"\nUSN:"<<usn<<"\nName:"<<name<<endl;
}

template< class GT>
void swapin(GT  &a,GT &b)
{
    GT temp;
    temp=a;
    a=b;
    b=temp;
}

int main()
{
    int a=5,b=7;
    swapin(a,b);
    cout<<"A="<<a<<"\nB="<<b<<endl;

    student s1,s2;
    cout<<"Enter Student 1 Details:";
    s1.accept();
    cout<<"Enter Student 2 Details:";
    s2.accept();
    swap(s1,s2);
    cout<<"Student 1:\n";
    s1.display();
    cout<<"Student 2:\n";
    s2.display();
    return 0;
}*/

// 2.Write the syntax of creating a generic class with an example

/*

// Generic class to hold a pair of elements
template <class T>
class Pair {
private:
    T first;
    T second;

public:
    Pair(T f, T s) : first(f), second(s) {}

    void display() {
        cout << "Pair: (" << first << ", " << second << ")" << endl;
    }
};

int main() {
    // Create a Pair of integers
    Pair<int> intPair(10, 20);
    intPair.display();

    // Create a Pair of characters
    Pair<char> charPair('A', 'B');
    charPair.display();

    // Create a Pair of doubles
    Pair<double> doublePair(3.14, 6.28);
    doublePair.display();

    return 0;
}
*/

// 3. WAP to show two generic classes in a function

/*

// Forward declaration of classes
class Class1;
class Class2;

// Generic function that operates on two classes
template <class T, class U>
void genericFunction(T obj1, U obj2) {
    obj1.someMethod();  // Call a method of Class1
    obj2.anotherMethod();  // Call a method of Class2
}

// Class1 definition
class Class1 {
public:
    void someMethod() {
        cout << "Method called from Class1" << endl;
    }
};

// Class2 definition
class Class2 {
public:
    void anotherMethod() {
        cout << "Method called from Class2" << endl;
    }
};

int main() {
    // Create objects of Class1 and Class2
    Class1 obj1;
    Class2 obj2;

    // Call the generic function with objects of different classes
    genericFunction(obj1, obj2);

    return 0;
}*/

// 4. WAP to simulate a stack of integers and float values using generic classes

#include<stdlib.h>

#define MAX 10

template <class GT>
class stack
{
public:
    GT arr[20];
    int top;

    stack()
    {
        top = -1;
    }
    void push();
    void pop();
    void display();
};

template <class GT>
void stack<GT>::push()
{
    if (top == MAX - 1)
    {
        cout << "Stack Overflow!!\n";
        return;
    }
    cin >> arr[++top];
}

template <class GT>
void stack<GT>::pop()
{
    if (top == -1)
    {
        cout << "Stack Underflow!!\n";
        return;
    }
    cout << "Popped:" << arr[top--]<<endl;
}

template <class GT>
void stack<GT>::display()
{
    for(int i=top;i>=0;i--)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int ch;
    // cout << "Enter\n 1.Integer Stack\n2.Float Stack\nChoice:";
    // cin >> ch;
    // if (ch == 1)
    //     stack<int> one;
    // else
    //     stack<float> one;

    stack<int> one;
    while (1)
    {
        cout << "1.Push\n2.Pop\n3.Display\n0.ExitChoice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            one.push();
            break;
        case 2:
            one.pop();
            break;
        case 3:
            one.display();
            break;
        case 0:
            cout << "Simulation Over!!\n";
            exit(0);
        default:
            cout << "Invalid Choice\n";
            break;
        }
    }
    return 0;
}
