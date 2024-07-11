#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *right;
    struct node *left;
    int key;
};

typedef struct node Node;

int search(Node *root, int Key)
{
    if (root == NULL)
    {
        printf("Key not found\n");
        return 0;
    }
    else
    {
        if (root->key == Key)
        {
            printf("Key Found!!\n");
            return 1;
        }
        else if (root->key < Key)
            return search(root->left, Key);
        else
            return search(root->right, Key);
    }
}

Node *newNode(int Key)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = Key;
    newNode->left = newNode->right = NULL;
}

Node *recurInsert(Node **root, int Key)
{
    if (root == NULL)
    {
        return newNode(Key);
    }
    else
    {
        if ((*root)->key < Key)
        {
            (*root)->right = recurInsert((*root)->right, Key);
        }
        else
        {
            (*root)->left = recurInsert((*root)->left, Key);
        }
    }
}

void delete(Node **root)
{
    // check whether it is a leaf or not
    // be one step behind in order not to lose the node itself
    // if not a leaf store the suceeding nodes somewhere
    // Array of pointers pointing to those addresses
    // Call insert by passing key value
    // free after insertion of a particular npde

    /*                                50
                                            70
                                        65        80
                                    60          75  85
    */
    int Key;
    printf("Enter Key to be deleted:");
    scanf("%d",&Key);
    printf("\n");
    if(!search(root,Key))
    {
        printf("Key not present\n");
    }
    if (*root == NULL)
    {
        printf("BST Empty!!\n");
        return;
    }
    Node *traverse=*root;
    //Use any of the traversal techniques
    while((traverse->right->key!=Key)||(traverse->right->key!=Key))
    {
        traverse=traverse->left;
    }
}

void insert(Node **root, const int Key)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = Key;
    newNode->right = newNode->left = NULL;
    if (*root == NULL)
    {
        *root = newNode; // new root
        return;
    }
    else
    {
        Node *cur = *root, *prev = NULL;
        while (cur != NULL)
        {
            prev = cur;
            if (newNode->key < cur->key)
            {
                cur = cur->left;
            }
            else
            {
                cur = cur->right;
            }
        }
        if (newNode->key < prev->key)
        {
            prev->left = newNode;
        }
        else
        {
            prev->right = newNode;
        }
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
        printf("%d ", root->key);
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
        printf("%d ", root->key);
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
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

int main()
{
    int ch, Key;
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
            scanf("%d", &Key);
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
            printf("Enter Key:");
            scanf("%d", &Key);
            printf("\n");
            insert(&root, Key);
            break;
        case 0:
            exit(0);
            printf("Simulation Over!!\n");
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
    return 0;
}