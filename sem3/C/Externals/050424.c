// Inverting a LL

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    // struct node *prev;
};

typedef struct node Node;

void insertRear(Node **one)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Enter Data:");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if (*one == NULL)
    {
        // first node
        *one = newNode;
        return;
    }
    Node *reachEnd = *one;
    while (reachEnd->next != NULL)
    {
        reachEnd = reachEnd->next;
    }
    reachEnd->next = newNode;
}

void display(Node *one)
{
    while (one != NULL)
    {
        printf("%d->", one->data);
        one = one->next;
    }
    printf("\b\b  \n");
}

void insertFront(Node **one)
{
}

void deleteFront(Node **one)
{
}

void deleteRear(Node **one)
{
}

void reverseLL(Node **one)
{
    Node *curNode = *one, *prevNode = NULL, *nextNode = NULL;
    while (curNode != NULL)
    {
        nextNode = curNode->next;
        curNode->next = prevNode;
        prevNode = curNode;
        curNode = nextNode;
    }
    *one = prevNode;
}

int main()
{
    Node *one = NULL;
    int ch;
    while (1)
    {
        printf("1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Display\n6.Reverse\n0.Exit\nEnter Choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            // insertFront(&one);
            break;
        case 2:
            insertRear(&one);
            break;
        case 3:
            // deleteFront(&one);
            break;
        case 4:
            // deleteRear(&one);
            break;
        case 5:
            display(one);
            break;
        case 6:
            // reverseLL(&one);
            break;
        case 0:
            exit(0);
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
    return 0;
}
