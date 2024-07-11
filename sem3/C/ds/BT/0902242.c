#include <stdio.h>
#include <stdlib.h>

int cnt = 100,i=2000;
struct node
{
    struct node *right;
    struct node *left;
    int key;
};

typedef struct node Node;

int recurSearch(Node *root, int key)
{
    if (!root)
    {
        printf("Unsuccessful search\n");
        return 0;
    }
    if (key == root->key)
    {
        printf("Successful search\n");
        return 1;
    }
    if (key < root->key)
        return recurSearch(root->left, key);
    return recurSearch(root->right, key);
}

/*void insertBST(Node **root)
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
    // if (searchBST(&(*root), newNode->key))
    if (recurSearch(*root, newNode->key))
    {
        printf("Key Present\n");
        free(newNode);
        return;
    }
    Node *curNode = *root, *prev = NULL;
    while (curNode)
    {
        prev = curNode;
        if (newNode->key > curNode->key)
            curNode = curNode->right;
        else
            curNode = curNode->left;
    }
    if (newNode->key < prev->key)
        prev->left = newNode;
    else
        prev->right = newNode;
}
*/

void insertBST(Node **root)
{
    int key;
    printf("Enter Key: ");
    scanf("%d", &key);

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;

    if (*root == NULL)
    {
        *root = newNode; // Inserting as root if tree is empty
        return;
    }

    Node *current = *root;
    Node *parent = NULL;

    while (current != NULL)
    {
        parent = current;
        if (key < current->key)
            current = current->left;
        else if (key > current->key)
            current = current->right;
        else
        {
            printf("Duplicate key found. Ignoring insertion.\n");
            free(newNode);
            return;
        }
    }

    if (key < parent->key)
        parent->left = newNode;
    else
        parent->right = newNode;
}

void postOrder(Node *root)
{
    if (root)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->key);
    }
}

void preOrder(Node *root)
{
    printf("%d Iteration %d \n",cnt--,i++);
    if (root)
    {
        /*printf("%d Printing N\n", cnt--);
        printf("%d Printing %d\n", cnt, root->key);
        printf("%d Calling L\n", cnt--);*/
        preOrder(root->left);
        //printf("%d Calling R\n", cnt--);
        preOrder(root->right);
        //printf("%d Iteration %d Over\n", cnt--,i);
    }
}

void inOrder(Node *root)
{
    if (root)
    {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

int main()
{
    Node *root = NULL;
    int key, ch;
    while (1)
    {
        printf("Enter\n1.Search\n2.Insertion\n3.Post-order\n4.Pre-order\n5.In-Order\n0.Exit\nChoice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter Key:");
            scanf("%d", &key);
            printf("\n");
            recurSearch(root, key);
            break;
        case 2:
            insertBST(&root);
            break;
        case 3:
            printf("Post-Order:");
            postOrder(root);
            printf("\n");
            break;
        case 4:
            printf("Pre-Order:");
            preOrder(root);
            printf("\n");
            break;
        case 5:
            printf("In-Order:");
            inOrder(root);
            printf("\n");
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