// Binary Tree simulation in OOP

#include <iostream>
#include <stdlib.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

class BST
{
    Node *root;

public:
    BST()
    {
        root = NULL;
    }
    Node *insert();
    void inOrder(Node *);
    void preOrder(Node *);
    void postOrder(Node *);
    int countNodesRecursively(Node *);
    int countNodes(Node *);
    bool searchTree(Node *, const int &);
};

Node *BST::insert()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    cout << "Enter Data:";
    cin >> newNode->data;
    cout << "\n";
    newNode->right = newNode->left = NULL;
    if (searchTree(root, newNode->data))
    {
        // already present
        cout << "Existing element cannot be inserted\n";
        return root;
    }
    if (root == NULL)
    {
        root = newNode;
        return newNode;
    }
    Node *cur = root, *prev = NULL;
    while (cur != NULL)
    {
        prev = cur;
        if (newNode->data < cur->data)
        {
            cur = cur->left;
        }
        else
        {
            cur = cur->right;
        }
    }
    if (newNode->data < prev->data)
    {
        prev->left = newNode;
    }
    else
    {
        prev->right = newNode;
    }
    return root;
}

void BST::inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void BST::preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void BST::postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int BST::countNodesRecursively(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);
    // Add 1 for the current node
    return leftCount + rightCount + 1;
}

int countNodes(Node *root)
{
    Node *traverse=root;
    while(traverse!=NULL)
    {
        cnt++;
        traverse=traverse->left;
    }
}

bool BST::searchTree(Node *root, const int &Key)
{
    if (!root)
    {
        return false;
    }
    if (root->data == Key)
    {
        cout << "Element Found!!\n";
        return true;
    }
    else if (root->data < Key)
        searchTree(root->right, Key);
    else
        searchTree(root->left, Key);
}

int main()
{
    Node *root = NULL;
    int ch, key;
    bool res;
    BST one;
    while (1)
    {
        cout << "\nEnter\n1.Insert\n2.In-Order\n3.Pre-order\n4.Post-order\n5.Search\n0.Exit\nChoice:";
        cin >> ch;
        cout << "\n";
        switch (ch)
        {
        case 1:
            root = one.insert();
            break;
        case 2:
            cout << "\nIn-order:";
            one.inOrder(root); //(*&b1)
            break;
        case 3:
            cout << "\nPre-order:";
            one.preOrder(root);
            break;
        case 4:
            cout << "\nPost-order:";
            one.postOrder(root);
            break;
        case 5:
            cout << "\nEnter Key:";
            cin >> key;
            cout << "\n";
            res = one.searchTree(root, key);
            if (!res)
                cout << "Element Not Found!!\n";
            break;
        case 0:
            cout << "Simulation Over!!\n";
            exit(0);
            break;
        default:
            cout << "Invalid Choice\n";
            break;
        }
    }
}