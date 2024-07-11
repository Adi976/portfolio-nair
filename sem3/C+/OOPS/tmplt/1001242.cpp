// Incomplete
/*#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;
const int SIZE = 10;
template <class StackT>
class Stack
{
    Stack stack[SIZE];
    int top;

public:
    Stack()
    {
        top = -1;
    }
    void push();
    Stack pop();
    void display();
};

int main()
{
    Stack<char> charStack[2];
    int ch;
    while (1)
    {
        cout << "Enter\n 1. Stack1\n 2. Stack2\n3. Exit Simulation\n";
        cin >> ch;
        if (ch == 1)
            operateStack(charStack[0]);
        else if (ch == 2)
            operateStack(charStack[1]);
        else
        {
            cout << "Simulation Over\n";
            exit(0);
        }
    }
    return 0;
}
template <class StackT>
void operateStack(StackT charStack)
{
    int ch;
    while(1)
    {
        cout<<"Enter\n 1. Pop\n2.Push\n3.Display\n4.Exit Stack\n";
        cin>>ch;
        switch(ch)
        {
            case 1:charStack.pop();
                    break;
            case 2:charStack.push();
                    break;
            case 3:charStack.display();
                    break;
            case 4:cout<<"Exiting this stack\n";
                    exit(0);
        }
    }
}*/
#include <iostream>
#include <cstdlib>
using namespace std;

const int SIZE = 10;

template <class StackT>
class Stack
{
    StackT stack[SIZE];
    int top;

public:
    Stack()
    {
        top = -1;
    }
    void push();
    StackT pop();
    void display();
};

template <class StackT>
void operateStack(Stack<StackT> &charStack)
{
    int ch;
    while (1)
    {
        cout << "Enter\n 1. Pop\n2.Push\n3.Display\n4.Exit Stack\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            charStack.pop();
            break;
        case 2:
            charStack.push();
            break;
        case 3:
            charStack.display();
            break;
        case 4:
            cout << "Exiting this stack\n";
            exit(0);
        }
    }
}

template <class StackT>
void Stack<StackT>::push()
{
    // Implementation of push
}

template <class StackT>
StackT Stack<StackT>::pop()
{
    // Implementation of pop
    return StackT(); // Placeholder return, replace with actual value
}

template <class StackT>
void Stack<StackT>::display()
{
    // Implementation of display
}

int main()
{
    Stack<char> charStack[2];
    int ch;
    while (1)
    {
        cout << "Enter\n 1. Stack1\n 2. Stack2\n3. Exit Simulation\n";
        cin >> ch;
        if (ch == 1)
            operateStack(charStack[0]);
        else if (ch == 2)
            operateStack(charStack[1]);
        else
        {
            cout << "Simulation Over\n";
            exit(0);
        }
    }
    return 0;
}
