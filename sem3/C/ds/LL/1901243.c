#include <stdio.h>
#include <stdlib.h>
// circular singly LL incomp pos and val
struct NODDY
{
    int data;
    struct NODDY *next;
};
typedef struct NODDY Node;

void insertFront(Node *head)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Enter Data\n");
    scanf("%d", &(newNode->data));
    newNode->next = head->next;
    head->next = newNode;
}
void insertEnd(Node *head)
{
    Node *reachEnd = head;
    while (reachEnd->next != head)
    {
        reachEnd = reachEnd->next;
    } // Reached end in temp
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Enter Data\n");
    scanf("%d", &(newNode->data));
    reachEnd->next = newNode;
    newNode->next = head;
}

void deleteFront(Node **head)
{
    Node *curFront = (*head)->next;
    printf("Deleted %d\n", curFront->data);
    (*head)->next = (*head)->next->next;
    free(curFront);
}

void deleteEnd(Node *head)
{
    Node *temp = head;
    while ((head->next)->next != temp)
    {
        // 2nd last node
        head = head->next;
    }
    Node* to_delete=head->next;
    printf("Deleted %d\n\n", (head->next)->data);
    free(to_delete);
    head->next = temp;
}

void deleteVal(Node* head,int val)
{
    Node* reachEnd=head;
    while(reachEnd->next!=head&&reachEnd->data!=val)
    {
        
    }
}
void deletePos(Node* head)
{

}
void displayList(Node *head)
{
    /*Node *reachEnd = head;
    while (reachEnd->next != head)
    {
        reachEnd = reachEnd->next;
    } // Reached end in temp
    head=head->next;
    while(reachEnd->next!=head)
    {
        printf("%d->",head->data);
        head=head->next;
    }
    */
    Node *p = head->next;
    do
    {
        printf("%d->", p->data);
        p = p->next;
    } while (p != head);

    printf("\b\b  \n");
}

int main()
{
    Node *head;//head is also a node with insignificant data portion
    head = (Node *)malloc(sizeof(Node));
    head->next = head;
    head->data = 100;
    int ch, val;
    printf("Simulation Begins!!\n");
    while (1)
    {
        printf("Enter Choice:\n\nInsert:\n1. Front\n2. End\n3. Val\n\n4.Display\n\nDelete:\n5. Front\n6. End\n7. Value\n8. Position\n\n0. Exit Simulation\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertFront(head);
            break;
        case 2:
            insertEnd(head);
            break;
        case 3: // insertNode(&head);
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
            printf("Enter value to be deleted\n");
            scanf("%d",&val);
            deleteVal(head,val);
            break;
        case 8:deletePos(head);
            break;
        case 0:
            printf("Simulation Over!!\n");
            exit(0);
            break;
        default:
            printf("Enter Valid Option\n");
        }
    }
    free(head);
    return 0;
}