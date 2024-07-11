#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
};
class DLL
{
    Node *head;

public:
    DLL()
    {
        head = NULL;
    }
    ~DLL()
    {
        while(head!=NULL)
        {
            Node *to_del=head;
            delete to_del;
            head=head->next;
        }
    }
    void call();
    void concat(DLL &);
    void insertFront();
    void insertRear();
    void deleteRear();
    void deleteFront();
    void displayF2L();
    void displayL2F();
};

void DLL::concat(DLL &two)
{
    Node *reachEndOne = head, *reachEndTwo = two.head;
    while (reachEndOne->next != NULL)
        reachEndOne = reachEndOne->next;

    while (reachEndTwo != NULL)
    {
        reachEndOne->next = reachEndTwo;
        reachEndOne = reachEndOne->next;
        reachEndOne->prev = reachEndTwo;
        reachEndTwo = reachEndTwo->next;
    }
    cout << "Post-Concat:\n";
    displayF2L();
}

void DLL::insertFront()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    cout << "Enter Data\n";
    cin >> newNode->data;
    if (head == NULL)
    {
        newNode->next = NULL;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
    }
    newNode->prev = NULL;
    head = newNode;
}

void DLL::insertRear()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    cout << "Enter Data\n";
    cin >> newNode->data;
    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
    }
    else
    {
        Node *reachEnd = head;
        while (reachEnd->next != NULL)
            reachEnd = reachEnd->next;
        newNode->prev = reachEnd;
        reachEnd->next = newNode;
    }
    newNode->next = NULL;
}

void DLL::deleteFront()
{
    if (head == NULL)
    {
        cout << "DLL Empty!!\n";
        return;
    }
    Node *to_del = head;
    if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        head = head->next;
        head->prev = NULL;
    }
    cout << "Deleted " << to_del->data << endl;
    delete to_del;
}

void DLL::deleteRear()
{
    if (head == NULL)
    {
        cout << "DLL Empty!!\n";
        return;
    }
    Node *to_del, *reachEnd = head;
    if (head->prev == NULL)
    {
        // only one node
        head = NULL;
    }
    else
    {
        while (reachEnd->next != NULL)
            reachEnd = reachEnd->next;
        to_del = reachEnd;
        (reachEnd->prev)->next = NULL;
    }
    cout << "Deleted " << to_del->data << endl;
    delete to_del;
}

void DLL::displayF2L()
{
    Node *reachEnd = head;
    while (reachEnd != NULL)
    {
        cout << reachEnd->data << "->";
        reachEnd = reachEnd->next;
    }
    cout << "\b\b  \n";
}

void DLL::displayL2F()
{
    Node *reachEnd = head;
    while (reachEnd->next != NULL)
        reachEnd = reachEnd->next;
    while (reachEnd != NULL)
    {
        cout << reachEnd->data << "->";
        reachEnd = reachEnd->prev;
    }
    cout << "\b\b  \n";
}

int main()
{
    DLL one, two;
    int ch;
    while (1)
    {
        cout << "\nEnter\n1.One\n2.Two\n3.Concat\n4.Exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            one.call();
            break;
        case 2:
            two.call();
            break;
        case 3:
            cout << "Enter choice:\n 1.One+Two\n2.Two+One\n";
            cin >> ch;
            if (ch == 1)
                one.concat(two);
            else
                two.concat(one);
            break;
        case 4:
            cout << "Simulation Over!!\n";
            exit(0);
            break;
        default:
            cout << "Invalid Choice\n";
        }
    }
    return 0;
}
void DLL::call()
{
    int ch;
    while (1)
    {
        cout << "Enter\n1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n7.DisplayF2L\n8.Display L2F\n0.Main Menu\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            insertFront();
            break;
        case 2:
            insertRear();
            break;
        case 3:
            deleteFront();
            break;
        case 4:
            deleteRear();
            break;
        case 7:
            displayF2L();
            break;
        case 8:
            displayL2F();
            break;
        case 0:
            return;
        default:
            cout << "Invalid Choice\n";
        }
    }
}