/*#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int number;
    Node *next;
};

void insertNode(Node **head, int A)
{
    Node *n = (Node *)malloc(sizeof(Node));
    cout << "Enter a value\n";
    cin >> A;
    n->number = A;
    n->next = *head;
    *head = n;
}

void deleteNode(Node **head, int position)
{
    Node *temp;
    Node *prev;
    temp = *head;
    prev = *head;
    for (int i = 0; i < position; i++)
    {
        if (i == 0 && position == 1)
        {
            *head = (*head)->next;
            free(temp);
        }
        else
        {
            if (i == position - 1 && temp)
            {
                prev->next = temp->next;
                free(temp);
            }
            else
            {
                prev = temp;
                if (prev == NULL)
                    break;
                temp = temp->next;
            }
        }
    }
}

void displayNode(Node *node)
{
    while (node != NULL)
    {
        printf("%d", node->number);
        node = node->next;
    }
}

int main()
{
    int ch;
    Node *first, *cur_node;
    printf("Enter first node\n");
    insertNode(&first, 0);
    while (1)
    {
        printf("Enter\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertNode(&cur_node, 0);
            break;
        case 2:
            deleteNode(&cur_node, 1);
            break;
        case 3:
            cur_node->next = NULL;
            displayNode(first);
            break;
        case 4:
            printf("Simulation over\n");
            exit(0);
            break;
        }
    }
    return 0;
}
*/

// C++ program to delete a node in
// singly linked list recursively

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int info;
    node *link = NULL;
    node() {}
    node(int a)
        : info(a)
    {
    }
};

// Deletes the node containing 'info'
// part as val and alter the head of
// the linked list (recursive method)
void deleteNode(node *&head, int val)
{

    // Check if list is empty or we
    // reach at the end of the
    // list.
    if (head == NULL)
    {
        cout << "Element not present in the list\n";
        return;
    }

    // If current node is the
    // node to be deleted
    if (head->info == val)
    {
        node *t = head;

        // If it's start of the node head
        // node points to second node
        head = head->link;

        // Else changes previous node's
        // link to current node's link
        delete (t);
        return;
    }
    deleteNode(head->link, val);
}

// Utility function to add a
// node in the linked list
// Here we are passing head by
// reference thus no need to
// return it to the main function
void push(node *&head, int data)
{
    node *newNode = new node(data);
    newNode->link = head;
    head = newNode;
}

void print(node *head)
{

    if (head == NULL and cout << endl)
        return;
    cout << head->info << ' ';
    print(head->link);
}

int main()
{

    // Starting with an empty linked list
    node *head = NULL;

    // Adds new element at the
    // beginning of the list
    push(head, 10);
    push(head, 12);
    push(head, 14);
    push(head, 15);

    // original list
    print(head);

    // Call to delete function
    deleteNode(head, 12);

    // 20 is not present thus no change
    // in the list
    print(head);

    //deleteNode(head, 10);
    //print(head);

    deleteNode(head, 14);
    print(head);

    return 0;
}
