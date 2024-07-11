#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    struct node *right;
    struct node *left;
    char *key;
};

typedef struct node Node;

int search(Node *root, char *Key)
{
    if (root == NULL)
    {
        printf("Key not found\n");
        return 0;
    }
    else
    {
        if (strcmp(root->key, Key))
        {
            printf("Key Found!!\n");
            return 1;
        }
        else if (strcmp(root->key, Key) < 0)
            return search(root->left, Key);
        else
            return search(root->right, Key);
    }
}

void recursearch(Node *root, char *Key)
{
    if (!root)
    {
        printf("Unsuccessful Search!\n");
        return;
    }
    if(Key<root->key)
    {
        recursearch(root->left,Key);
        printf("%s",root->key);
        return;
    }
    recursearch(root->right,Key);
    printf("%s",root->key);
    return;
}
void insert(Node **root)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = (char *)malloc(sizeof(char) * 10);
    printf("Enter Key:");
    scanf("%s", ((newNode)->key));
    newNode->key = (char *)realloc(newNode->key, sizeof(char) * (strlen(newNode->key)));
    printf("\n");
    newNode->right = newNode->left = NULL;
    if (*root == NULL)
    {
        *root = newNode; // new root
        return;
    }
    Node *cur = *root, *prev = NULL;
    while (cur != NULL)
    {
        prev = cur;
        if (strcmp(newNode->key, cur->key) < 0)
        {
            cur = cur->left;
        }
        else
        {
            cur = cur->right;
        }
    }
    if (strcmp(newNode->key, prev->key) < 0)
    {
        prev->left = newNode;
    }
    else
    {
        prev->right = newNode;
    }
}

void preOrder(Node *root)
{
    if (root == NULL)
    {
        // printf("\n");
        return;
    }
    else
    {
        printf("%s ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node *root)
{
    if (root == NULL)
    {
        // printf("\n");
        return;
    }
    else
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%s ", root->key);
    }
}

void inOrder(Node *root)
{
    if (root == NULL)
    {
        // printf("\n");
        return;
    }
    else
    {
        inOrder(root->left);
        printf("%s ", root->key);
        inOrder(root->right);
    }
}

int main()
{
    int ch;
    char Key[10];
    Node *root = NULL;
    while (1)
    {
        printf("Enter\n1.Search\n2.Pre-Order\n3.Post-Order\n4.In-Order\n5.Insert\n0.Exit\nChoice:");
        scanf("%d", &ch);
        printf("\n");
        switch (ch)
        {
        case 1:
            printf("Enter Key\n");
            scanf("%s", &Key);
            search(root, Key);
            break;
        case 2:
            printf("Pre-Order:");
            preOrder(root);
            printf("\n");
            break;
        case 3:
            printf("Post-Order:");
            postOrder(root);
            printf("\n");
            break;
        case 4:
            printf("In-Order:");
            inOrder(root);
            printf("\n");
            break;
        case 5:
            insert(&root);
            break;
        case 0:
            printf("Simulation Over\nHave a nice day!!\n");
            exit(0);
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
    return 0;
}