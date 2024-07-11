#include <stdio.h>
#include <stdlib.h>
//printing error
// doubly linked list//incorrect implementation

struct NODDY
{
    int data;
    struct NODDY *next;
    struct NODDY *prev;
};
typedef struct NODDY Node;

void insertFront(Node **node)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Creating newNode\n");
    printf("Enter Data\n");
    scanf("%d", &(newNode->data));
    (*node)->prev = newNode;
    newNode->next = *node;
    newNode->prev=NULL;
}

void insertEnd(Node *node)
{
    while (node->next != NULL)
    {
        node = node->next;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Creating newNode\n");
    printf("Enter Data\n");
    scanf("%d", &(newNode->data));
    node->next = newNode;
    newNode->prev = node;
    newNode->next = NULL;
}

void insertNode(Node *node, const int val)
{
    while ((node->data != val) && (node->next != NULL))
    {
        node = node->next;
    }
    if (node->data == val)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        printf("Creating newNode\n");
        printf("Enter Data\n");
        scanf("%d", &(newNode->data));
        newNode->next = node->next;
        newNode->prev = node;
        node->next = newNode;
    }
    else
    {
        printf("Element not present in the list\n");
    }
}

void displayList(Node *node)
{
    while (node != NULL)
    {
        printf("%d->", node->data);
        node = node->next;
    }
    printf("\b\b  \n");
}

void displayListReverse(Node *node)
{
    while (node->next != NULL)
    {
        node = node->next;
    }
    
    while (node != NULL)
    {
        printf("%d->", node->data);
        node = node->prev;
    }
    printf("\b\b  \n");
}

void deleteFront(Node **node)
{
    if (*node == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    Node *curFirst = *node;
    printf("%d deleted\n", curFirst->data);
    *node = (*node)->next;
    (*node)->prev = NULL;
    free(curFirst);
}

void deleteEnd(Node *node)
{
    if (node == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (node->next != NULL)
    {
        node = node->next;
    }
    node->prev->next = NULL;
    free(node);
}

void deleteVal(Node *node, const int val)
{
    while ((node->next->data != val) && (node != NULL))
    {
        node = node->next;
    }
    if (node->next->data == val)
    {
        Node *to_del = node->next;
        printf("Deleted %d\n", to_del->data);
        (node->next->next)->prev = node;
        node->next = node->next->next;
        free(to_del);
    }
    else
        printf("Value not present in the list!!\n");
}
int main()
{
    int ch, val;
    Node *first = NULL;
    first = (Node *)malloc(sizeof(Node));
    printf("Simuation Begins\n");
    printf("Enter Node 1\n");
    printf("Enter Data\n");
    scanf("%d", &(first->data));
    first->prev = NULL;
    first->next=NULL;
    while (1)
    {
        printf("Enter\n1.Insert Front\n2.Insert End\n3.Insert after a Node\n4. Display List\n5.Delete Front\n6.Delete End\n7.Delete Value\n8.Delete Position\n0.Exit Simulation\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertFront(&first);
            break;
        case 2:
            insertEnd(first);
            break;
        case 3:
            printf("Enter the value of the node after which new node has to be inserted\n");
            scanf("%d", &val);
            insertNode(first, val);
            break;
        case 4:
            displayList(first);
            break;
        case 5:
            deleteFront(&first);
            break;
        case 6:
            deleteEnd(first);
            break;
        case 7:
            printf("Enter the value to be deleted\n");
            scanf("%d", &val);
            if (first->data == val)
            {
                printf("%d deleted\n", first->data);
                Node *oldFirst = first;
                first = first->next;
                first->prev = NULL;
                free(oldFirst);
            }
            else
                deleteVal(first, val);
            break;
        case 8: // deletePos(first);
            break;
        case 0:
            printf("Simulation Over\n");
            exit(0);
            break;
        default:
            printf("Enter a valid choice\n");
        }
    }
    return 0;
}