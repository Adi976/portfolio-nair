#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int info;
    struct Node *link;
} Node;

void insertNode(Node **head, int val)
{
    // Node *newNode = new Node(data);
    Node *newNode = malloc(sizeof(Node));
    newNode->link = *head;
    newNode->info = val;
    *head = newNode;
}
/*void deleteNodePosition(Node **head, int position)
{
    Node *temp;
    Node *prev;
    temp = *head;
    prev = *head;
    for (int i = 0; i < position; i++)
    {
        if (i == 0 && position == 1)
        {
            *head = (*head)->link;
            free(temp);
        }
        else
        {
            if (i == position - 1 && temp)
            {
                prev->link = temp->link;
                free(temp);
            }
            else
            {
                prev = temp;
                if (prev == NULL)
                    break;
                temp = temp->link;
            }
        }
    }
}

void deleteNode(Node **head, int val)
{
    /*printf("Enters delete node\n");
    if (*head == NULL)
    {
        printf("Element not present in the list\n");
        return;
    }
    else if ((*head)->info == val)
    {
        Node *t = *head;
        *head = (*head)->link;
    }
    else
    {
        deleteNode(&((*head)->link), val);
    }

    if(((*head)->link==NULL)||(head==NULL))
    {
        printf("Element not present\n");
    }
    else
    {
        if((*head)->info==val)
        {
            printf("Deleted %d from the list",((*head)->info));
            (*head)=(*head)->link;
            return;
        }
        else
        deleteNode(&((*head)->link),val);
    }
}

void deleteNodeFunc(Node **head, int val)
{
    printf("Entered delete\n");
    if ((*head)->link == NULL)
        printf("Empty List\n");
    else if ((*head)->info == val)
    {
        Node *t = *head;
        *head = (*head)->link;
        free(t);
        return;
    }
    else
    {
        deleteNodeFunc(&((*head)->link), val);
    }
}
*/

void deleteFront(Node** head)
{
    if(*head==NULL)
    {
        printf("LL Empty\n");
        return;
    }
    else if((*head)->link==NULL)
    {
        printf("%d deleted\n",(*head)->info);
        *head=NULL;
        return;
    }
    else
    {
        printf("%d deleted\n",(*head)->info);
        *head=(*head)->link;
        return;
    }
}


void displayNode(Node *head)
{
    if (head == NULL)
    {
        printf("NULL \n");
        printf("Simulation Over!\n");
        exit(0);
    }
    printf("%d->", head->info);
    displayNode(head->link);
}
int main()
{
    Node *head = NULL;
    printf("Simulation begins!\n");
    insertNode(&head, 10);
    insertNode(&head, 12);
    insertNode(&head, 14);
    insertNode(&head, 15);
    
    displayNode(head);

    deleteFront(&head);
    deleteFront(&head);
    displayNode(head);
    /*deleteNode(&head, 12);
    deleteNode(&head, 14);
    displayNode(head);*/

    return 0;
}

