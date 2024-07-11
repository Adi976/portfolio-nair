
#include <stdio.h>
#include <stdlib.h>
// singly linked list
struct NODDY
{
    int data;
    struct NODDY *next;
    struct NODDY *prev;
};

typedef struct NODDY Node;

void insertFront(Node **node)
{
    Node *newNode = NULL;
    newNode = (Node *)malloc(sizeof(Node));
    printf("Creating newNode\n");
    printf("Enter Data\n");
    scanf("%d", &(newNode->data));
    newNode->next = *node;
    *node = newNode;
}

void insertEnd(Node *node)
{
    while (node->next != NULL)
    {
        node = node->next;
    }
    Node *newNode = NULL;
    newNode = (Node *)malloc(sizeof(Node));
    printf("Creating newNode\n");
    printf("Enter Data\n");
    scanf("%d", &(newNode->data));
    node->next = newNode;
}

void insertNode(Node *node, const int val)
{
    while ((node->data != val) && (node != NULL))
    {
        node = node->next;
    }
    // might have reached the node with the value
    if (node->data == val)
    {
        Node *newNode = NULL;
        newNode = (Node *)malloc(sizeof(Node));
        printf("Creating newNode\n");
        printf("Enter Data\n");
        scanf("%d", &(newNode->data));
        newNode->next = node->next;
        node->next = newNode;
    }
    else
        printf("Element not present in the list\n");
}
void deleteFront(Node **node)
{
    if (*node == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    Node *curFirst = *node;
    printf("%d deleted\n", curFirst->data);
    *node = (*node)->next;
    free(curFirst);
}

void deleteEnd(Node *node)
{
    while (node->next->next != NULL)
    {
        node = node->next;
    }
    // reached the 2nd last node
    Node *curEnd = node->next;
    printf("%d deleted\n", curEnd->data);
    node->next = NULL;
    free(curEnd);
}

void deleteVal(Node *node, const int val)
{
    while ((node->next->data != val) && (node != NULL))
    {
        node = node->next;
    }
    // might have reached the node before the node with the value
    if (node->next->data == val)
    {
        Node *to_del = node->next;
        printf("Deleted %d\n", to_del->data);
        node->next = node->next->next;
        free(to_del);
    }
    else
        printf("Element not present in the list\n");
}
void displayList(Node *node)
{
    // is printing in reverse!!
    while (node != NULL)
    {
        printf("%d<-", node->data);
        node = node->next;
    }
    printf("\b\b  \n");
}
int main()
{
    int ch, val;
    Node *head = NULL;
    printf("Simuation Begins\n");
    printf("Enter Node 1\n");
    head = (Node *)malloc(sizeof(Node));
    printf("Enter Data\n");
    scanf("%d", &(head->data));
    while (1)
    {
        printf("Enter\n1.Insert Front\n2.Insert End\n3.Insert after a Node\n4. Display List\n5.Delete Front\n6.Delete End\n7.Delete Value\n8.Delete Position\n0.Exit Simulation\n");
        printf("Choice: \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertFront(&head);
            break;
        case 2:
            insertEnd(head);
            break;
        case 3:
            printf("Enter the value of the node after which new node has to be inserted\n");
            scanf("%d", &val);
            insertNode(head, val);
            break;
        case 4:
            displayList(head);
            break;
        case 5:
            deleteFront(&head);
            break;
        case 6:
            deleteEnd(head);
            break;
        case 7:
            printf("Enter the value to be deleted\n");
            scanf("%d", &val);
            if (head->data == val)
            {
                printf("%d deleted\n", head->data);
                head = head->next;
            }
            else
                deleteVal(head, val);
            break;
        case 0:
            printf("Simulation Over!!\n");
            exit(0);
            break;
        default:
            printf("Enter a valid choice\n");
        }
    }
    return 0;
}
