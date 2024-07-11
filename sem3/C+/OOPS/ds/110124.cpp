// Program to implement stack using classes!! (Better available lab)

#include <iostream>
#include <stdlib.h>
using namespace std;
const int MAX = 10;
class Stack
{
    int stack[MAX];
    int top;

public:
    Stack(int t)
    {
        top = t;
    }
    void pushElmnt();
    int popElmnt();
    void displayStack();
};

void Stack::pushElmnt()
{
    if (top == MAX - 1)
    {
        cout << "Stack Overflow\n";
        exit(0);
    }
    top++;
    cout << "Enter an element\n";
    cin >> stack[top];
}
int Stack::popElmnt()
{
    if (top == -1)
    {
        cout << "Stack Underflow\n";
        exit(0);
    }
    cout<<stack[top]<<" is popped\n";
    return (stack[top--]);
}
void Stack::displayStack()
{
    for (int i = top; i >= 0; i--)
    {
        cout << stack[i];
    }
}
int main()
{
    Stack one(-1);
    int ch;
    cout<<"Simulation Begins!!\n";
    while (1)
    {
        cout << "Enter\n1.Pop\n2.Push\n3.Display\n4.Exit Simulation\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            one.popElmnt();
            break;
        case 2:
            one.pushElmnt();
            break;
        case 3:
            one.displayStack();
            break;
        case 4: cout<<"Simulation Over!!\n";
            exit(0);
            break;
        default:cout<<"Enter a valid option\n";
        }
    }
}