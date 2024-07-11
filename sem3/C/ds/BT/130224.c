//Threaded binary tree
#include<stdio.h>

struct node
{
    int data;
    short int leftThread;
    short int rightThread; 
    struct node* left;
    struct node* right;
};

typedef struct node Node;

void insert(Node **root)
{
    Node *newNode=(Node*)malloc(sizeof(Node));
    printf("Enter Data:");
    scanf("%d",&newNode->data);
    printf("\n");
    newNode->left=newNode->right=NULL;
    if(!*root)
    {
        *root=newNode;
    } 
}

void createThreads(Node *root)
{
    if(!root)
    {
        printf("BT Empty!!\n");
    }
}
int main()
{
    Node *root=NULL;
    int ch;
    while (1)
    {
        printf("Enter\n1.Insert\n2.Search\n3.Thread creation\n4.In-Order\n0.Exit\nChoice:");
        scanf("%d",&ch);
        printf("\n");
        switch (ch)
        {
        case 1:insert(&root);
            break;
        case 2:search(root);
            break;
        case 3:inThread(root);
            break;
        case 4:inOrder(root);
            break;
        case 0:printf("Simulation Over\n");
            break;
        default:printf("Invalid Choice\n");
            break;
        }
    }
    return 0;
}