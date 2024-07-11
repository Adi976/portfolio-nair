#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

// Deletes the node containing 'info'
// part as val and alter the head of
// the linked list (recursive method)
void deleteNode(struct Node **head, int val)
{
    // Check if list is empty or we
    // reach at the end of the
    // list.
    if (*head == NULL)
    {
        printf("Element not present in the list\n");
        return;
    }

    // If current node is the
    // node to be deleted
    if ((*head)->info == val)
    {
        struct Node *t = *head;

        // If it's start of the node head
        // node points to the second node
        *head = (*head)->link;

        // Else changes previous node's
        // link to the current node's link
        free(t);
        return;
    }
    deleteNode(&((*head)->link), val);
}

// Utility function to add a
// node in the linked list
// Here we are passing head by
// reference thus no need to
// return it to the main function
void push(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = data;
    newNode->link = *head;
    *head = newNode;
}

void print(struct Node *head)
{
    if (head == NULL)
    {
        printf("\n");
        return;
    }
    printf("%d ", head->info);
    print(head->link);
}

int main()
{
    // Starting with an empty linked list
    struct Node *head = NULL;

    // Adds a new element at the
    // beginning of the list
    push(&head, 10);
    push(&head, 12);
    push(&head, 14);
    push(&head, 15);

    // original list
    print(head);

    // Call to delete function
    deleteNode(&head, 12);

    // 20 is not present thus no change
    // in the list
    print(head);

    // deleteNode(&head, 10);
    // print(head);

    deleteNode(&head, 14);
    print(head);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int info;
    struct Node *link;
} Node;

void insertNode(Node **head, int val)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->link = *head;
    newNode->info = val;
    *head = newNode;
}

void deleteNode(Node **head, int val)
{
    // Check if list is empty
    if (*head == NULL)
    {
        printf("Empty List\n");
        return;
    }

    printf("Entered delete node\n");

    // If current node is the node to be deleted
    if ((*head)->info == val)
    {
        Node *t = *head;

        // If it's the start of the node, head node points to the second node
        *head = (*head)->link;

        // Free the memory of the deleted node
        free(t);
        return;
    }

    // Recursively call deleteNode on the next node in the list
    deleteNode(&((*head)->link), val);
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

    deleteNode(&head, 12);
    deleteNode(&head, 14);

    displayNode(head);

    return 0;
}
