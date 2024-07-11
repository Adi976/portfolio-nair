#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *right;
    struct node *left;
    int key;
};

typedef struct node Node;

int searchBST(Node **root, const int Key)
{
    if (*root == NULL)
    {
        printf("BST Empty\n");
        return 0;
    }
    // Left-side
    Node *left_traverse = *root;
    while (left_traverse != NULL)
    {
        if (left_traverse->key == Key)
        {
            printf("Key found!!\n");
            return 1;
        }
        left_traverse = left_traverse->left;
    }
    // right side
    Node *right_traverse = *root;
    while (left_traverse != NULL)
    {
        if (right_traverse->key == Key)
        {
            printf("Key found!!\n");
            return 1;
        }
        right_traverse = right_traverse->right;
    }
    return 0;
}

void insert(Node *root, Node **newNode)
{
    if ((root->right == NULL) && (root->left == NULL))
    {
        // connect the newNode here
        if ((*newNode)->key > root->key)
        {
            // add to right
            root->right = *newNode;
        }
        else
        {
            // add to left
            root->left = *newNode;
        }
        return;
    }
    else
    {
        if ((*newNode)->key < root->key)
            insert(root->left, &(*newNode));
        else
            insert(root->right, &(*newNode));
    }
}

void insertBST(Node **root)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Enter Key:");
    scanf("%d", &(newNode->key));
    newNode->left = NULL;
    newNode->right = NULL;
    if (*root == NULL)
    {
        *root = newNode;
        return;
    }
    if (searchBST(&(*root), newNode->key))
    {
        printf("Key Present\n");
        free(newNode);
        return;
    }
    if (newNode->key > (*root)->key)
    {
        // add to right
        insert(((*root)->right), &newNode);
    }
    else
    {
        // add to left
        insert((*root)->left, &newNode);
    }
}

void postTraversal(Node *root)
{
}

void preTraversal(Node *root)
{
}
int main()
{
    Node *root = NULL;
    int key, ch;
    while (1)
    {
        printf("Enter\n1.Search\n2.Insertion\n3.Post-order\n0.Exit\nChoice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter Key:");
            scanf("%d", &key);
            printf("\n");
            searchBST(&root, key);
            break;
        case 2:
            insertBST(&root);
            break;
        case 3:
            postTraversal(root);
            break;
        case 4:
            preTraversal(root);
            break;
        case 0:
            printf("Simulation Over!!\n");
            exit(0);
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
    return 0;
}