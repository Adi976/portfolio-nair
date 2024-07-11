// Arrange BAT
// Sorting a linked list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    struct node *next;
    char data[5];
};

typedef struct node Node;

void insert(Node **head)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Enter Data:");
    scanf("%s", (newNode->data));
    printf("\n");
    if (*head == NULL)
    {
        newNode->next = NULL;
    }
    else
    {
        newNode->next = *head;
    }
    *head = newNode;
}

void display(Node *head)
{
    if (head == NULL)
    {
        printf("SLL Empty\n");
        return;
    }
    while (head != NULL)
    {
        printf("%s->", head->data);
        head = head->next;
    }
    printf("\b\b  \n");
}

int countNodes(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void sortList(Node *head)
{
    int cnt = countNodes(head);

    for (int i = 0; i < cnt; i++)
    {
        Node *temp = head->next;

        for (int j = 0; j < cnt - i - 1; j++)
        {
            if (strcmp(head->data, temp->data) > 0)
            {
                char data[4];
                strcpy(data, head->data);
                strcpy(head->data, temp->data);
                strcpy(temp->data, data);
            }
            temp = temp->next;
        }
        head = head->next;
    }
}

int main()
{
    int ch;
    Node *head = NULL;
    while (1)
    {
        printf("Enter\n1.Insert\n2.Delete\n3.Sort\n4.Display\n0.Exit\nChoice:");
        scanf("%d", &ch);
        printf("\n");
        switch (ch)
        {
        case 1:
            insert(&head);
            break;
        case 2:
            // delete (&head);
            break;
        case 3:
            sortList(head);
            break;
        case 4:
            display(head);
            break;
        case 0:
            printf("Simulation Over!!\n");
            exit(0);
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
    return 0;
}