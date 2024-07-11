#include <stdio.h>
#include <stdlib.h>
// Doubly LL!!
struct NODDY
{
    struct NODDY *prev;
    struct NODDY *next;
    int data;
};
typedef struct NODDY Node;

void insertFront(Node **first)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Enter data\n");
    scanf("%d", &(newNode->data));
    if (*first == NULL)
    {
        newNode->next = NULL;
    }
    else
    {
        newNode->next = *first;
        (*first)->prev = newNode;
    }
    newNode->prev = NULL;
    *first = newNode;
}

void insertRear(Node **first)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Enter data\n");
    scanf("%d", &(newNode->data));
    if (*first == NULL)
    {
        newNode->prev = NULL;
        *first = newNode;
    }
    else
    {
        Node *reachEnd = *first;
        while (reachEnd->next != NULL)
        {
            reachEnd = reachEnd->next;
        }
        newNode->prev = reachEnd;
        reachEnd->next = newNode;
    }
    newNode->next = NULL;
}

void deleteFront(Node **first)
{
    Node *to_del = *first;
    if (*first == NULL)
    {
        printf("DLL is empty!!");
        return;
    }
    if ((*first)->next == NULL)
    {
        *first = NULL;
    }
    else
    {
        *first = (*first)->next;
    }
    (*first)->prev = NULL;
    printf("Deleted %d\n", to_del->data);
    free(to_del);
}

void deleteRear(Node **first)
{
    Node *to_del = NULL;
    if (*first == NULL)
    {
        printf("DLL is empty!!");
        return;
    }
    if ((*first)->next == NULL)
    {
        to_del = *first;
        *first = NULL;
    }
    else
    {
        // reach the last node
        Node *reachEnd = *first;
        while (reachEnd->next != NULL)
        {
            reachEnd = reachEnd->next;
        }
        to_del = reachEnd;
        (reachEnd->prev)->next = NULL;
    }
    printf("Deleted %d\n", to_del->data);
    free(to_del);
}

void displayF2L(Node *first)
{
    while (first != NULL)
    {
        printf("%d->", first->data);
        first = first->next;
    }
    printf("\b\b  \n");
}

void displayL2F(Node *first)
{
    while (first->next != NULL)
    {
        first = first->next;
    }
    while (first != NULL)
    {
        printf("%d->", first->data);
        first = first->prev;
    }
    printf("\b\b  \n");
}

int main()
{
    Node *first = NULL;
    int ch;
    while (1)
    {
        printf("Enter\n1.Insert Front\n2.Insert Rear\n3.Insert Value\n4.Display F2L\n5.Delete Front\n6.Delete Rear\n7.Display L2F\n0.Exit Simulation\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertFront(&first);
            break;
        case 2:
            insertRear(&first);
            break;
        case 3:
            break;
        case 4:
            displayF2L(first);
            break;
        case 5:
            deleteFront(&first);
            break;
        case 6:
            deleteRear(&first);
            break;
        case 7:
            displayL2F(first);
            break;
        case 0:
            printf("Simulation Over!!\n");
            exit(0);
            break;
        default:
            printf("Invalid Choice\n");
        }
    }
}