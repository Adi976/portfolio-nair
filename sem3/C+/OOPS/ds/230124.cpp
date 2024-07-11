#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node()
    {
        cout << "Enter Data:";
        cin >> data;
        cout << "\n";
        next = NULL;
    }
};
class SLL
{
    Node *first;

public:
    SLL() : first(NULL) {}
    void insertFront();
    void insertRear();
    void display();
    void deleteFront();
    void deleteRear();
};

void SLL::insertFront()
{
    Node *newNode = new Node;
    if (first != NULL)
        newNode->next = first;
    first = newNode;
}
void SLL::insertRear()
{
    Node *newNode = new Node;
    Node *reachEnd = first;
    while (reachEnd->next != NULL)
    {
        reachEnd = reachEnd->next;
    }
    reachEnd->next = newNode;
}
void SLL::display()
{
    Node *reachEnd = first;
    while (reachEnd != NULL)
    {
        cout << reachEnd->data << "->";
        reachEnd = reachEnd->next;
    }
    cout << "\b\b  \n";
}

void SLL::deleteFront()
{
    Node *to_delete = first;
    first = first->next;
    cout << "Deleted " << to_delete->data << endl;
    delete[] to_delete;
}
void SLL::deleteRear()
{
    Node *reachEnd = first;
    while ((reachEnd->next)->next != NULL)
    {
        reachEnd = reachEnd->next;
    }
    Node *to_delete = reachEnd->next;
    reachEnd->next = NULL;
    cout << "Deleted " << to_delete->data << endl;
    delete[] to_delete;
}
int main()
{
    SLL one;
    int ch;
    cout << "Simulation Begins!!\n";
    while (1)
    {
        cout << "Enter Choice:\n1.Insert Front\n2.Insert End\n3.Insert Value\n4.Display\n5.Delete Front\n6.Delete Rear\n7.Delete Value\n0.Exit Simulation\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            one.insertFront();
            break;
        case 2:
            one.insertRear();
            break;
        case 3:
            break;
        case 4:
            one.display();
            break;
        case 5:
            one.deleteFront();
            break;
        case 6:
            one.deleteRear();
            break;
        case 0:
            cout << "Simulation Over!!\n";
            exit(0);
            break;
        default:
            cout << "Invalid Choice\n";
        }
    }
}
