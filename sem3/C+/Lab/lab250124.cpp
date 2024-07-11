#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node()
    {
        cout << "Enter Data\n";
        cin >> data;
        next = NULL;
    }
};

class SLL
{
    Node *first;

public:
    SLL()
    {
        first = NULL;
    }
    void insertFront();
    void insertRear();
    void display();
    void deleteFront();
    void deleteRear();
    ~SLL();
};

SLL::~SLL()
{
    while (first != NULL)
    {
        Node *to_del = first;
        first = first->next;
        delete to_del;
    }
}
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
    if (first == NULL)
        first = newNode;
    else
    {
        Node *reachEnd = first;
        while (reachEnd->next != NULL)
        {
            reachEnd = reachEnd->next;
        }
        reachEnd->next = newNode;
    }
}

void SLL::display()
{
    if (first == NULL)
        cout << "SLL is Empty!!\n";
    else
    {
        Node *reachedEnd = first;
        while (reachedEnd != NULL)
        {
            cout << reachedEnd->data << "->";
            reachedEnd = reachedEnd->next;
        }
        cout << "\b\b  \n";
    }
}

void SLL::deleteFront()
{
    Node *to_delete = first;
    if (first == NULL)
    {
        cout << "SLL is empty\n";
        return;
    }
    first = first->next;
    cout << "Deleted " << to_delete->data << endl;
    delete[] to_delete;
}

void SLL::deleteRear()
{
    /*if (first == NULL)
    {
        cout << "SLL is empty\n";
    }
    else if (first->next != NULL)
    {
        Node *reachEnd = first;
        while (reachEnd->next->next != NULL)
        {
            // Reached the current 2nd last node
            reachEnd = reachEnd->next;
        }
        Node *to_del = reachEnd->next;
        reachEnd->next = NULL;
        cout << "Deleted " << to_del->data << endl;
        delete to_del;
    }
    else
    {
        // delete current first
        Node *to_del = first;
        cout << "Deleted " << to_del->data << endl;
        first = NULL;
        delete to_del;
    }*/
    if(first==NULL)
    {
        cout<<"SLL is empty!!\n";
        return;
    }
    if(first->next==NULL)
    {
        cout<<"Deleted "<<first->data;
        first=NULL;
    }
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
    cout << "SLL Simulation Begins!!\n";
    while (1)
    {
        cout << "\nEnter\n\n1.Insert Front\n2.Insert Rear\n3.Display\n4.Delete Front\n5.Delete Rear\n0.Exit\n";
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
            one.display();
            break;
        case 4:
            one.deleteFront();
            break;
        case 5:
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

    return 0;
}