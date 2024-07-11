#include <stdio.h>
#include <stdlib.h>
// linear stack and linear queue using SLL
struct NODDY
{
    int data;
    struct NODDY *next;
};
typedef struct NODDY Node;

void pushStack(Node **Top)
{
    // insertFront
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Enter Data\n");
    scanf("%d", &(newNode->data));
    newNode->next = (*Top)->next;
    (*Top)->next = newNode;
}
void popStack(Node **Top)
{
    // deleteFront
    if (*Top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }
    Node *to_del = (*Top)->next;
    printf("Popped %d\n", to_del->data);
    (*Top) = (*Top)->next;
    free(to_del);
}
void displayStack(Node *Top)
{
    do
    {
        printf("%d\n", Top->data);
        Top = Top->next;
    } while (Top != NULL);
}
void linearStack()
{
    int ch;
    Node *Top = NULL;
    while (1)
    {
        printf("Enter Choice:\n1.Pop\n2.Push\n3.Display\n4.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            popStack(&Top);
            break;
        case 2:
            pushStack(&Top);
            break;
        case 3:
            displayStack(Top);
            break;
        case 4:
            printf("Simulation Over\n");
            exit(0);
            break;
        default:
            ("Invalid Choice!\n");
        }
    }
}
void insertQ(Node **front, Node **rear)
{
    // insert rear
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Enter Data\n");
    scanf("%d", &(newNode->data));
    newNode->next = NULL;
    if (*front == NULL)
    {
        (*front) = newNode;
        *rear = newNode;
    }
    else
    {
        (*rear)->next = newNode;
        (*rear) = newNode;
    }
}
void deleteQ(Node **front, Node **rear)
{
    // delete front
    if ((*front) == (*rear)->next)
    {
        printf("Queue Underflow\n");
        return;
    }
    else
    {
        printf("Deleted %d\n", (*front)->data);
        free(*front);
        (*front) = (*front)->next;
    }
}
void displayQ(Node *front, Node *rear)
{
    while (front != rear->next)
    {
        printf("%d->", front->data);
        front = front->next;
    }
    printf("\b\b  \n");
}
void linearQueue()
{
    int ch;
    Node *front = NULL, *rear = NULL;
    printf("Simulation Begins!!\n");
    while (1)
    {
        printf("Enter Choice:\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertQ(&front, &rear);
            break;
        case 2:
            deleteQ(&front, &rear);
            break;
        case 3:
            displayQ(front, rear);
            break;
        case 4:
            printf("Simulation Over!!\n");
            exit(0);
            break;
        default:
            ("Invalid Choice!\n");
        }
    }
}
void insertCQ()
{
}
void deleteCQ()
{
}
void displayCQ()
{
}
void circularQueue()
{
    int ch;
    Node *front = NULL, *rear = NULL;
    while (1)
    {
        printf("Enter Choice:\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertCQ(&front, &rear);
            break;
        case 2:
            deleteCQ(&front, &rear);
            break;
        case 3:
            displayCQ(front, rear);
            break;
        case 4:
            printf("Simulation Over\n");
            exit(0);
            break;
        default:
            ("Invalid Choice!\n");
        }
    }
}
int main()
{
    int ch;
    printf("Enter\n1.Linear Stack\n2.Linear Queue\n3.Circular Queue\n");
    scanf("%d", &ch);
    if (ch == 1)
        linearStack();
    else if (ch == 2)
        linearQueue();
    else if (ch == 3)
        circularQueue();
    else
        printf("Invalid Option\n");
    return 0;
}