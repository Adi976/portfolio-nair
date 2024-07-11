#include <iostream>
using namespace std;

struct student
{
    string name;
    string usn;
    friend ostream &operator<<(ostream &, const student &);
    friend istream &operator>>(istream &, student &);
};

istream &operator>>(istream &cin, student &s)
{
    cout << "\nEnter Name:";
    cin >> s.name;
    cout << "\nEnter USN:";
    cin >> s.usn;
    cout << "\n";
    return cin;
}

ostream &operator<<(ostream &cout, const student &s)
{
    cout << "Name:" << s.name << "USN: " << s.usn;
    return cout;
}

template <class GT>
class Node
{
public:
    GT data;
    Node *next;
};

template <class GT>
class SLL
{
    Node<GT> *head;

public:
    SLL() : head(NULL) {}
    void insertFront();
    void insertRear();
    void deleteFront();
    void deleteRear();
    void displayList();
};

template <class GT>
void SLL<GT>::insertFront()
{
    Node<GT> *newNode = new Node<GT>;
    cout << "Enter Data:";
    cin >> newNode->data;
    cout << "\n";
    if (head == NULL)
        newNode->next = NULL;
    newNode->next = head;
    head = newNode;
}

template <class GT>
void SLL<GT>::insertRear()
{
    Node<GT> 
    if(head==NULL)
    {
        //1st Node

    }
}

template <class GT>
void SLL<GT>::deleteFront()
{
    if (head == NULL)
    {
        cout << "SLL Empty!!\n";
        return;
    }
    Node<GT> *to_del = head;
    head = head->next;
    cout << "Deleted: " << to_del->data << endl;
    delete to_del;
}

template <class GT>
void SLL<GT>::deleteRear()
{
    if (head == NULL)
    {
        cout << "SLL Empty!!\n";
        return;
    }
    Node<GT> *reachEnd = head;
    while (reachEnd->next->next != NULL)
        reachEnd = reachEnd->next;
    Node<GT> *to_del = reachEnd->next;
    reachEnd->next = NULL;
    cout << "Deleted: " << to_del->data << endl;
    delete to_del;
}

template <class GT>
void SLL<GT>::displayList()
{
    if (head == NULL)
    {
        cout << "SLL is Empty\n";
        return;
    }
    Node<GT> *traverse = head;
    while (traverse != NULL)
    {
        cout << traverse->data << "->";
        traverse = traverse->next;
    }
    cout << "\b\b  \n";
}

int main()
{
    SLL<student> one;
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
            one.displayList();
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