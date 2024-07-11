#include <stdio.h>
#include <stdlib.h>
/*
Develop a Program in C for the following:
a) Declare a calendar as an array of 7 elements (A dynamically Created array) to represent
7 days of a week. Each Element of the array is a structure having three fields. The first
field is the name of the Day (A dynamically allocated String), The second field is the
date of the Day (A integer), the third field is the description of the activity for a
particular day (A dynamically allocated String).
b) Write functions create(), read() and display(); to create the calendar, to read the data
from the keyboard and to print weeks activity details report on screen.
*/

/*
typedef struct
{
    char *day_name;
    int date;
    char *activity;
} day;

void create(day* week)
{
    for(int i=0;i<7;i++)
    {
        week[i].day_name=(char*)malloc(sizeof(char)*10);
        week[i].activity=(char*)malloc(sizeof(char)*10);
        printf("\nEnter Date:");
        scanf("%d",&week[i].date);
        printf("\nEnter Day Name:\n");
        scanf("%s",week[i].day_name);
        printf("\nEnter Activity:\n");
        scanf("%s",week[i].activity);
    }
}

void read(day* week)
{
    int d;
    printf("\nEnter Date for info:");
    scanf("%d",&d);
    for(int i=0;i<7;i++)
    {
        if(d==week[i].date)
        {
            printf("\nDate:%d\nDay:%s\nActivity:%s\n",week[i].date,week[i].day_name,week[i].activity);
            break;
        }
    }
}

void display(day* week)
{
    for(int i=0;i<7;i++)
    {
        printf("\nDate:%d\nDay:%s\nActivity:%s\n",week[i].date,week[i].day_name,week[i].activity);
    }
}
int main()
{
    day *week = NULL;
    while (week == NULL)
        week = (day *)malloc(sizeof(day)*7);
    printf("Create a week\n");
    create(week);
    read(week);
    display(week);
    return 0;
}

*/

/*
2. Develop a Program in C for the following operations on Strings.
a. Read a main String (STR), a Pattern String (PAT) and a Replace String (REP)
b. Perform Pattern Matching Operation: Find and Replace all occurrences of PAT in
STR with REP if PAT exists in STR. Report suitable messages in case PAT does not
exist in STR
Support the program with functions for each of the above operations. Don't use Built-in
functions.
*/

/*
#include <string.h>

void patMatch!(char *str, char *pat, char *rep)
{
    char newSTR[10];
    int j = 0;
    for (int i = 0; i < strlen(str);)
    {
        if ((str[i] == pat[0]) && (str[i + strlen(pat)] == pat[strlen(pat)]))
        {
            char sub[5];
            strncpy(sub, str + i, strlen(pat));
            if (strcmp(sub, pat) == 0)
                printf("Found at index %d!!\n", i);
            for (int k = 0; k < strlen(pat); k++)
                newSTR[j++] = str[i++];
        }
        else
            newSTR[j++] = str[i++];
    }
    newSTR[j++] = '\0';
    printf("\nNew String:%s", newSTR);
}

void patMatch(char *str, char *pat, char *rep)
{
    char newSTR[10]; // Increase array size to accommodate longer strings
    int j = 0;
    int patLen = strlen(pat);
    for (int i = 0; i < strlen(str);)
    {
        if (strncmp(str + i, pat, patLen) == 0)
        { // Compare substring with pattern
            printf("Pattern found at index %d!!\n", i);
            for (int k = 0; k < strlen(rep); k++)
            {
                newSTR[j++] = rep[k]; // Replace pattern with replacement string
            }
            i += patLen; // Move index past the pattern
        }
        else
        {
            newSTR[j++] = str[i++]; // Copy character from original string
        }
    }
    newSTR[j] = '\0'; // Null-terminate the new string
    printf("New String: %s\n", newSTR);
}

int main()
{
    char str[20], pat[5], rep[20];
    printf("Enter STR:");
    scanf("%s", str);
    printf("\nEnter PAT:");
    scanf("%s", pat);
    printf("\nEnter REP:");
    scanf("%s", rep);
    patMatch(str, pat, rep);
    return 0;
}
*/

/*
3. Develop a menu driven Program in C for the following operations on STACK of Integers
(Array Implementation of Stack with maximum size MAX)
a. Push an Element on to Stack
b. Pop an Element from Stack
c. Demonstrate how Stack can be used to check Palindrome
d. Demonstrate Overflow and Underflow situations on Stack
e. Display the status of Stack
f. Exit
Support the program with appropriate functions for each of the above operations
*/

/*
void push(int stack[], int n, int *top, int *cnt)
{
    if (*top == n - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    printf("Enter Element:");
    scanf("%d", &stack[++(*(top))]);
    cnt++;
}
void pop(int stack[], int n, int *top, int *cnt)
{
    if (*top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    printf("Deleted:%d", stack[*(top)--]);
    cnt--;
}

void checkPalindrome1(char string[]) {
    int len = strlen(string);
    char stack[len];
    int top = -1;

    // Push characters onto the stack
    for (int i = 0; i < len; i++) {
        stack[++top] = string[i];
    }

    // Compare characters from the stack with the original string
    for (int i = 0; i < len; i++) {
        if (stack[top--] != string[i]) {
            printf("Not Palindrome!!\n");
            return;
        }
    }

    printf("Palindrome\n");
}
void checkPalindrome(char string[], int top)
{
    char stack[strlen(string)];
    int j = 0;
    for (int i = 0; string[i] != '\0'; i++)
    {
        stack[j++] = string[i];
    }
    int i = 0;
    while (j != -1)
    {
        if (stack[j--] != string[i++])
        {
            printf("Not Palindrome!!\n");
            return;
        }
    }
    printf("Palindrome\n");
}
void showStatus(int cnt, int n)
{
    printf("Empty:%d\tFull:%d", n - cnt, cnt);
}
void displayStack(int stack[], int top, int n)
{
    if (top == -1)
    {
        printf("Stack Empty\n");
    }
    for (int i = top; i >= 0; i--)
        printf("%d\n", stack[i]);
}
int main()
{
    int ch, n, cnt, top = -1;
    printf("\nEnter Stack Size:");
    scanf("%d", &n);
    printf("\n");
    int stack[n];
    printf("Simulation Begins!!\n");
    while (1)
    {
        printf("Enter\n1.Push\n2.Pop\n3.Check Palindrome\n4.Show Status\n5.Display\n0.Exit\nChoice:");
        scanf("%d", &ch);
        printf("\n");
        switch (ch)
        {
        case 1:
            push(stack, n, &top, &cnt);
            break;
        case 2:
            pop(stack, n, &top, &cnt);
            break;
        case 3: // checkPalindrome();
            break;
        case 4:
            showStatus(cnt, n);
            break;
        case 5:
            displayStack(stack, top, n);
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

/*
4. Develop a Program in C for converting an Infix Expression to Postfix Expression. Program
should support for both  parenthesized and free parenthesized
expressions with the operators: +, -, *, /, % (Remainder), ^ (Power) and alphanumeric
operands.*/

/*
#include <string.h>

#define MAX 10

int getPrecedence(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 4;
    case '$':
    case '^':
        return 5;
    case '(':
        return 0;
    case '#':
        return -1;
    default:
        return 8;
    }
}
int getStackPrecedence(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 3;
    case '$':
    case '^':
        return 6;
    case '(':
        return 9;
    case ')':
        return 0;
    default:
        return 7;
    }
}
int main()
{
    char c, stack[MAX] = {'#'}, infix[MAX], postfix[MAX];
    int top = 0, i = 0, j = 0;
    printf("Enter Infix Expression:");
    scanf("%s", infix);
    printf("\n");
    for (i = 0; i < strlen(infix); i++)
    {
        c = infix[i];
        while (getPrecedence(stack[top]) > getStackPrecedence(c))
        {
            postfix[j++] = stack[top--];
        }
        if (getPrecedence(stack[top]) != getStackPrecedence(c))
        {
            stack[++top] = c;
        }
        else
            top--;
    }
    while (stack[top] != '#')
    {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
    printf("Postfix Expression:%s\n", postfix);
    return 0;
}
*/

/*
5. Develop a Program in C for the following Stack Applications
a. Evaluation of Suffix expression with single digit operands and operators: +, -, *, /, %,
*/

/*
#include <math.h>
#include<ctype.h>

double compute(double op1, double op2, char symbol)
{
    switch (symbol)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    case '^':
        return pow(op1, op2);
    }
}
int main()
{
    char postfix[20];//665*+
    int top = -1;
    double op1, op2,stack[20];
    printf("Enter Postfix Expression:");
    scanf("%s", postfix);
    printf("\n");
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (isdigit(postfix[i]))
        {
            stack[++top] = postfix[i] - '0';
        }
        else
        {
            op2 = stack[top--];
            op1 = stack[top--];
            stack[++top] = compute(op1, op2, postfix[i]);
        }
    }
    printf("Result is %lf\n", stack[top--]);
    return 0;
}
*/

// 5b. Solving Tower of Hanoi problem with n disks

/*
void hanoi(int n, char A, char B, char C)
{
    if (n == 0)
        return;
    hanoi(n - 1, A, C, B);
    printf("Move Disk %d from %c to %c\n", n, A, C);
    hanoi(n - 1, B, A, C);
}
int main()
{
    int n;
    printf("Enter number of disks:");
    scanf("%d", &n);
    printf("\n");
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
*/

/*
6. Develop a menu driven Program in C for the following operations on Circular QUEUE of
Characters (Array Implementation of Queue with maximum size MAX)
a. Insert an Element on to Circular QUEUE
b. Delete an Element from Circular QUEUE
c. Demonstrate Overflow and Underflow situations on Circular QUEUE
d. Display the status of Circular QUEUE
e. Exit
Support the program with appropriate functions for each of the above operations
*/

/*
7. Develop a menu driven Program in C for the following operations on Singly Linked List
(SLL) of Student Data with the fields: USN, Name, Programme, Sem,
PhNo
a. Create a SLL of N Students Data by using front insertion.
b. Display the status of SLL and count the number of nodes in it
c. Perform Insertion / Deletion at End of SLL
d. Perform Insertion / Deletion at Front of SLL(Demonstration of stack)
e. Exit
*/

/*
8. Develop a menu driven Program in C for the following operations on Doubly Linked List
(DLL) of Employee Data with the fields: SSN, Name, Dept, Designation,
Sal, PhNo
a. Create a DLL of N Employees Data by using end insertion.
b. Display the status of DLL and count the number of nodes in it
c. Perform Insertion and Deletion at End of DLL
d. Perform Insertion and Deletion at Front of DLL
e. Demonstrate how this DLL can be used as Double Ended Queue.
f. Exit
*/

/*
9. Develop a Program in C for the following operations on Singly Circular Linked List (SCLL)
with header nodes
a. Represent and Evaluate a Polynomial P(x,y,z) = 6x2y2z-4yz5+3x3yz+2xy5z-2xyz3
b. Find the sum of two polynomials POLY1(x,y,z) and POLY2(x,y,z) and store the
result in POLYSUM(x,y,z)
Support the program with appropriate functions for each of the above operations

In the `addPolynomials` function, when adding terms to the resultant polynomial, the terms that are being deleted from the original two polynomials (`poly1` and `poly2`) are the ones that have been combined or attached to the resultant polynomial (`result`).

Here's how it works:
- When a term from `poly1` matches a term from `poly2` based on their exponents, and they are added together, both of these matching terms are deleted from their respective original polynomials.
- If a term from `poly1` does not have a match in `poly2`, it is simply attached to the resultant polynomial, and then it's deleted from `poly1`.
- Similarly, any terms in `poly2` that don't have a match in `poly1` are attached to the resultant polynomial and then deleted from `poly2`.

This deletion process ensures that the terms which have been successfully combined and added to the resultant polynomial are removed from the original polynomials to avoid duplication or incorrect computation when processing subsequent terms.
*/
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct term
{
    int coef;
    int xexp;
    int yexp;
    int zexp;
    struct term *next;
} Term;

void accept(Term **poly)
{
    int n;
    printf("Enter number of terms:");
    scanf("%d", &n);
    Term *prev = NULL;
    Term *head = NULL; // head of the circular list
    for (int i = 0; i < n; i++)
    {
        Term *newTerm = (Term *)malloc(sizeof(Term));
        printf("\nEnter Term %d:\n", i + 1);
        printf("Coef:");
        scanf("%d", &newTerm->coef);
        printf("\nxexp:");
        scanf("%d", &newTerm->xexp);
        printf("\nyexp:");
        scanf("%d", &newTerm->yexp);
        printf("\nzexp:");
        scanf("%d", &newTerm->zexp);
        newTerm->next = NULL;
        if (*poly == NULL)
        {
            *poly = newTerm;
            head = newTerm;
        }
        else
        {
            prev->next = newTerm;
        }
        prev = newTerm;
    }
    // Connect the last node to the head to form a circular list
    prev->next = head;
}

void display(Term *poly)
{
    if (poly == NULL)
    {
        printf("Polynomial Not Entered\n");
        return;
    }
    Term *head = poly; // save the head node
    do
    {
        printf("%dx^%dy^%dz^%d+", poly->coef, poly->xexp, poly->yexp, poly->zexp);
        poly = poly->next;
    } while (poly != head); // loop until we reach the head again
    printf("\b \n");
}

int compare(Term *one, Term *two)
{
    if (one->xexp == two->xexp && one->yexp == two->yexp && one->zexp == two->zexp)
        return 1;
    else
        return 0;
}

void attach(Term **res_poly, Term *poly, int coef)
{
    Term *newTerm = (Term *)malloc(sizeof(Term));
    newTerm->coef = coef;
    newTerm->xexp = poly->xexp;
    newTerm->yexp = poly->yexp;
    newTerm->zexp = poly->zexp;
    newTerm->next = *res_poly;
    *res_poly = newTerm;
}

void delete(Term *from,Term *this)
{
    Term *find=from,*prev=NULL;
    while(find!=this)
    {
        prev=find;
        find=find->next;
    }
    prev->next=this->next;
    free(this);
}

void polyAdd(Term **res_poly, Term *poly_one, Term *poly_two)
{
    // Add all terms in res_poly and remove duplicates from both polynomials
    Term *one = poly_one;
    Term *two = poly_two;
    while (one != poly_one)
    {
        switch (compare(one, two))
        {
        case 1: // Just add coef and send to attach
            attach(&(*res_poly), one, one->coef + two->coef);
            delete (poly_one, one);
            delete (poly_two, two);
            one = one->next;
            two = two->next;
        case 0: // add poly_one term
            attach(&(*res_poly), one, one->coef);
            delete (poly_one, one);
            one = one->next;
        }
    }
    while (two != poly_two)
    {
        attach(&(*res_poly), two, two->coef);
        two = two->next;
    }
    display(*res_poly);
}

int main()
{
    Term *poly_one = NULL;
    Term *poly_two = NULL;
    Term *res_poly = NULL;
    res_poly->next=res_poly;
    printf("Enter Polynomial 1:\n");
    accept(&poly_one);
    printf("Polynomial 1: ");
    display(poly_one);
    printf("Enter Polynomial 2:\n");
    accept(&poly_two);
    printf("Polynomial 2: ");
    display(poly_one);
    int ch;
    while (1)
    {
        printf("Enter\n1.Add\n2.Evaluate\n3.Exit\nChoice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            polyAdd(&res_poly, poly_one, poly_two);
            break;
        case 2:
            printf("Enter\n1.Polynomial One\n2.Polynomial Two\nChoice:");
            scanf("%d", &ch);
            break;
        case 3:
            printf("Simulation Over\n");
            exit(0);
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
    return 0;
}
*/

/*
10. Develop a menu driven Program in C for the following operations on Binary Search Tree
(BST) of Integers .
a. Create a BST of N Integers: 6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2
b. Traverse the BST in Inorder, Preorder and Post Order
c. Search the BST for a given element (KEY) and report the appropriate message
d. Exit
*/
/*
// Data-set:  15 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;

int search(Node *root, int key)
{
    if (root != NULL)
    {
        if (root->data == key)
        {
            printf("Key %d found\n", key);
            return 1;
        }
        else if (root->data > key)
            return search(root->left, key);
        else
            return search(root->right, key);
    }
    //printf("Key %d not found\n", key);
    return -1;
}

void insert(Node **root)
{
    int n;
    printf("Enter number of nodes:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        printf("Enter Data:");
        scanf("%d", &(newNode->data));
        newNode->left = newNode->right = NULL;
        if (*root == NULL)
        {
            *root = newNode;
            continue;
        }
        if (search(*root, newNode->data) != -1)
        {
            printf("Redundant Data\n");
            continue;
        }
        Node *curNode = *root, *prevNode;
        while (curNode != NULL)
        {
            prevNode = curNode;
            if (curNode->data < newNode->data)
                curNode = curNode->right;
            else
                curNode = curNode->left;
        }
        if (prevNode->data < newNode->data)
            prevNode->right = newNode;
        else
            prevNode->left = newNode;
    }
}

void preOrder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}
void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main()
{
    Node *root = NULL;
    int key;
    int ch;
    while (1)
    {
        printf("1.Insert\n2.Pre-Order\n3.Post-Order\n4.In-Order\n5.Search\n0.Exit\nEnter Choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert(&root);
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
            printf("Enter Key to be searched:");
            scanf("%d", &key);
            search(root, key);
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


/*
11. Develop a Program in C for the following operations on Graph(G) of Cities
a. Create a Graph of N cities using Adjacency Matrix.
b. Print all the nodes reachable from a given starting node in a digraph using DFS/BFS
method
*/

// 1. Create 2D int array of nxn accept the amat and then display it
// 2.Take source as input to know from where to begin
// 3. Set the vertices for the visited array to 0
// 4. Call the bfs function bfs(source,visited,amat,n)
// 5. Now run a loop to check which all vertices have been visited
// 6.Reset visited array to 0
// 7. Call dfs(source,visited,amat[][20],n)

// 4. In bfs function
// 1.Declare an integer queue,front and rear
// 2.Declare int u,v. u for popped queue element and v for setting visited value of that vertex in the array to 1
// 3.Set visited of source visited[source]=1 and append it to the queue q[r]=source
// 4.While(f<=r) { pop element and store in u=q[f++]}
// 5.Run a loop with v as loop variable
// 6.Check if amat[u][v]==1&&(visited[v]==0)//connected and not yet visited
// 7. Add it to q for further exploration and set visited[v]=1
// Data set:
/*The adjacency matrix is:
0 1 1
1 0 0
1 0 0
*/

/*
#include <stdio.h>

#define SIZE 20

void bfs(int visited[], int source, int amat[][SIZE], int n)
{
    int q[n], f = 0, r = 0, u, v;
    visited[source] = 1;
    q[r++] = source;
    while (f < r)
    {
        u = q[f++];
        for (v = 0; v < n; v++)
        {
            if (amat[u][v] == 1 && visited[v] == 0)
            {
                visited[v] = 1;
                q[r++] = v;
            }
        }
    }
}

void dfs(int visited[], int source, int amat[][SIZE], int n)
{
    visited[source] = 1;
    printf("%d ", source); // Print the current vertex
    for (int i = 0; i < n; i++)
    {
        if (amat[source][i] == 1 && visited[i] == 0)
        {
            dfs(visited, i, amat, n); // Recursively call DFS for adjacent vertices
        }
    }
}

int main()
{
    int n, amat[SIZE][SIZE], source, visited[SIZE];
    printf("Enter number of vertices:");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Row %d:", i + 1);
        for (int j = 0; j < n; j++)
            scanf("%d", &amat[i][j]);
        printf("\n");
    }
    printf("The adjacency matrix is:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", amat[i][j]);
        printf("\n");
    }
    printf("Give the source:\n");
    scanf("%d", &source);
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    printf("BFS traversal starting from vertex %d: ", source);
    bfs(visited, source, amat, n);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 1)
            printf("%d is reachable\n", i);
        else
            printf("%d is not reachable\n", i);
    }
    printf("DFS traversal starting from vertex %d: ", source);
    for (int i = 0; i < n; i++)
        visited[i] = 0; // Reset visited array for DFS
    dfs(visited, source, amat, n);
    printf("\n");
    return 0;
}
*/

/*
12. Given a File of N employee records with a set K of Keys (4-digit) which uniquely determine
the records in file F. Assume that file F is maintained in memory by a Hash Table (HT) of m
memory locations with L as the set of memory addresses (2-digit) of locations in HT. Let the
keys in K and addresses in L are Integers. Develop a Program in C that uses Hash function H:
K →L as H(K)=K mod m (remainder method), and implement hashing
technique to map

Main()
1. Declare a hash table ht[HZ] and a FILE *fp
2. Open a file emp.txt fp=fopen("emp.txt","w+")
3. Using a for loop set the key values of all indexes to -1 to state unoccupiedness
4. Menu Option

Search(FILE *fp,ht,n)
1. Declare emp a for accepting empno value to be searched
2. Declare int hindex and countindex
3. Get the hindex for the given empno from the hashval function
4. Set countindex value to hindex value too
5. We iterate using a while loop to reach the given empno
6. While(h[hindex].key!=a.empno)
7. hindex=(hindex+1)%HZ
8. if(hindex==countindex){Search Unsuccessful Return}
9. If not returned in the while loop we can infer that we found it by means of termination of while condition
10. Hence printf(Search Successful)
11. Bring the file pointer to the current hindex
12. fseek(fp,h[hindex].addr,SEEK_SET)
13. fscanf(fp,"%d%s%d",&(a.empno),&(a.empname),&(a.sal))
14. printf("%d%s%d",a.empno,a.empname,a.sal)
*/

/*#include <stdio.h>
#include <stdlib.h>

#define HZ 3

typedef struct ht
{
    int key;
    long int addr;
} hashtable;

typedef struct emp
{
    char name[10];
    int emp_no;
    int sal;
} employee;

int hashVal(int num)
{
    int key;
    key = num % HZ;
    return key;
}

void insert(FILE *fp, hashtable table[], int n)
{
    employee a;
    int flag = 0;
    int hindex, countindex;
    for (int i = 0; i < n; i++, flag = 0)
    {
        printf("Enter empno, name, and salary\n");
        scanf("%d%s%d", &a.emp_no, a.name, &a.sal);
        hindex = hashVal(a.emp_no);
        countindex = hindex;
        while (table[hindex].key != -1)
        {
            hindex = (hindex + 1) % HZ;
            flag = 1;
            if (hindex == countindex)
            {
                printf("Entry not possible\n");
                return;
            }
        }
        table[hindex].key = a.emp_no;
        fseek(fp, 0, SEEK_END);
        table[hindex].addr = ftell(fp);
        fprintf(fp, "%d %s %d\n", a.emp_no, a.name, a.sal);
        printf("Entry Successful\n");
        if (flag)
            printf("Linear probing used\n");
    }
}

void search(FILE *fp, hashtable table[], int n)
{
    employee a;
    int hindex, countindex;
    printf("Enter Employee Number:");
    scanf("%d", &a.emp_no); // Corrected: pass the address of emp_no
    hindex = hashVal(a.emp_no);
    countindex = hindex;
    while (table[hindex].key != a.emp_no)
    {
        hindex = (hindex + 1) % HZ;
        if (hindex == countindex)
        {
            printf("Search Unsuccessful\n");
            return;
        }
    }
    printf("Search Successful\n");
    fseek(fp, table[hindex].addr, SEEK_SET);
    fscanf(fp, "%d%s%d", &(a.emp_no), a.name, &(a.sal));
    printf("%d %s %d\n", a.emp_no, a.name, a.sal); // Corrected: added a space between name and sal
}

void display(FILE *fp, hashtable table[], int n)
{
    employee a;
    for (int i = 0; i < HZ; i++)
    {
        if (table[i].key != -1)
        {
            printf("Hash table: %d %ld |\t", table[i].key, table[i].addr);
            fseek(fp, table[i].addr, SEEK_SET);
            fscanf(fp, "%d%s%d", &(a.emp_no), a.name, &(a.sal));
            printf("%d %s %d\n", a.emp_no, a.name, a.sal); // Corrected: added a space between name and sal
        }
    }
}

int main()
{
    FILE *fp;
    fp = fopen("emp.txt", "w+");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }
    hashtable table[HZ];
    int n, ch;
    for (int i = 0; i < HZ; i++)
        table[i].key = -1;
    while (1)
    {
        printf("1.Insert\n2.Search\n3.Display\n4.Exit\nEnter Choice:");
        scanf("%d", &ch);
        printf("\n");
        switch (ch)
        {
        case 1:
            printf("Enter number of employees\n");
            scanf("%d", &n);
            insert(fp, table, n);
            break;
        case 2:
            search(fp, table, n);
            break;
        case 3:
            display(fp, table, n);
            break;
        case 4:
            printf("Simulation Over!!\n");
            fclose(fp);
            exit(0);
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
    return 0;
}
*/

// Program 4 Infix to postfix

/*#include <string.h>

int getPrecedence(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 4;
    case '$':
    case '^':
        return 5;
    case '(':
        return 0;
    case '#':
        return -1;
    default:
        return 8;
    }
}
int getStackPrecedence(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 3;
    case '$':
    case '^':
        return 6;
    case '(':
        return 9;
    case ')':
        return 0;
    default:
        return 7;
    }
}
int main()
{
    char infix[10], postfix[10], stack[10] = {"#"};
    int top = 0, i = 0, j = 0;
    char c;
    printf("Enter Infix Expression:");
    scanf("%s", infix);
    for (i = 0; i < strlen(infix); i++)
    {
        c = infix[i];
        while (getPrecedence(stack[top]) > getStackPrecedence(c))
        {
            postfix[j++] = stack[top--];
        }
        if (getPrecedence(stack[top]) != getStackPrecedence(c))
        {
            stack[++top] = c;
        }
        else
            top--;
    }
    while (stack[top] != '#')
    {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
    printf("Postfix Expression:%s", postfix);
    return 0;
}
*/

// 9. Polynomial Add

/*#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct term
{
    int coef;
    int xexp;
    int yexp;
    int zexp;
    struct term *next;
} Term;

int compare(Term *one, Term *two)
{
    if (one->xexp == two->xexp && one->yexp == two->yexp && one->zexp == two->zexp)
        return 0;
    return 1; // Exponents are not equal
}

void attach(Term **res_poly, Term *poly, int coef)
{
    Term *newTerm = (Term *)malloc(sizeof(Term));
    newTerm->coef = coef;
    newTerm->xexp = poly->xexp;
    newTerm->yexp = poly->yexp;
    newTerm->zexp = poly->zexp;
    newTerm->next = *res_poly;
    *res_poly = newTerm;
}

void delete(Term *from, Term *this)
{
    Term *find = from, *prev = NULL;
    while (find != this)
    {
        prev = find;
        find = find->next;
    }
    prev->next = this->next;
    free(this);
}

void accept(Term **poly)
{
    int n;
    printf("Terms:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        Term *newTerm = (Term *)malloc(sizeof(Term));
        newTerm->next = NULL;
        printf("Enter coef, xexp, yexp & zexp\n");
        scanf("%d%d%d%d", &newTerm->coef, &newTerm->xexp, &newTerm->yexp, &newTerm->zexp);
        if (*poly == NULL)
        {
            *poly = newTerm;
            continue;
        }
        newTerm->next = *poly;
        *poly = newTerm;
    }
}

void display(Term *poly)
{
    if (poly == NULL)
    {
        printf("Polynomial Empty\n");
        return;
    }
    while (poly != NULL)
    {
        printf("%dx^%dy^%dz^%d+", poly->coef, poly->xexp, poly->yexp, poly->zexp);
        poly = poly->next;
    }
    printf("\n"); // Print a newline character at the end
}

double evaluate(Term *poly)
{
    int x, y, z;
    double sum = 0.0;
    printf("Enter x, y & z values\n");
    scanf("%d%d%d", &x, &y, &z);
    while (poly != NULL)
    {
        sum += poly->coef * (pow(x, poly->xexp) * pow(y, poly->yexp) * pow(z, poly->zexp));
        poly = poly->next;
    }
    return sum;
}

void addPoly(Term **res_poly, Term *poly_one, Term *poly_two)
{
    Term *one = poly_one, *two = poly_two;
    while (one != NULL && two != NULL)
    {
        switch (compare(one, two))
        {
        case 0: // Exponents match
            attach(res_poly, one, one->coef + two->coef);
            delete (poly_one, one);
            delete (poly_two, two);
            one = one->next; // Move to the next term in poly_one
            two = two->next; // Move to the next term in poly_two
            break;
        case 1: // Exponents don't match or one's exponent is greater
            attach(res_poly, one, one->coef);
            one = one->next; // Move to the next term in poly_one
            break;
        }
    }
    while (two != NULL)
    {
        attach(res_poly, two, two->coef);
        two = two->next; // Move to the next term in poly_two
    }
    display(*res_poly);
}

int main()
{
    Term *poly_one = NULL, *poly_two = NULL, *res_poly = NULL;
    printf("Enter Polynomial 1\n");
    accept(&poly_one);
    printf("Polynomial 1:");
    display(poly_one);
    printf("Enter Polynomial 2\n");
    accept(&poly_two);
    printf("Polynomial 2:");
    display(poly_two);
    double res1, res2;
    int ch;
    while (1)
    {
        printf("1.Add\n2.Evaluate\n3.Display\n0.Exit\nEnter Choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            addPoly(&res_poly, poly_one, poly_two);
            break;
        case 2:
            res1 = evaluate(poly_one);
            res2 = evaluate(poly_two);
            printf("One:%lf\nTwo:%lf\n", res1, res2);
            break;
        case 3:
            break;
        case 0:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
    return 0;
}
*/

// Lab 6 Circular Queue

/*
#define MAX 5

int cnt = 0;

void insert(int CQ[], int *f, int *r)
{
    if (cnt == MAX)
    {
        printf("Queue Overflow\n");
        return;
    }
    *r = (*r + 1) % MAX;
    printf("Enter Element:");
    scanf("%d", &CQ[(*r)]);
    cnt++;
}
void delete(int CQ[], int *f, int *r)
{
    if (cnt == 0)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted:%d\n", CQ[*f]);
    *f = (*f + 1) % MAX;
    cnt--;
}
void display(int CQ[], int f)
{
    if (cnt == 0)
    {
        printf("CQ Empty\n");
        return;
    }
    for (int i = 0; i < cnt; i++)
    {
        printf("%d ", CQ[f]);
        f = (f + 1) % MAX;
    }
    printf("\n");
}
int main()
{
    int CQ[MAX];
    int f = 0, r = -1, ch;
    while (1)
    {
        printf("1.Insert\n2.Delete\n3.Display\n0.Exit\nEnter Choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert(CQ, &f, &r);
            break;
        case 2:
            delete (CQ, &f, &r);
            break;
        case 3:
            display(CQ, f);
            break;
        case 0:
            printf("Simulation Over\n");
            exit(0);
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
    return 0;
}
*/

/* 5 Postfix Evaluation

1. Declare a double stack and op1,op2
2. Declare char postfix array and symbol
3. for(int i=0;postfix[i]!='\0';i++)
4. if(isdigit(postfix[i])){st[++top]=postfix[i]-'\0'} //digit stored in stack
5. else {op2=stack[top--];op1=stack[top--];stack[++top]=compute(op1,op2,postfix[i])} //operator encountered so two operands popped out
*/

/*
#include <ctype.h>
#include <math.h>

double compute(double op1, double op2, char symbol)
{
    switch (symbol)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    case '^':
        return pow(op1, op2);
    }
}
int main()
{
    double stack[10], op1, op2;
    char postfix[10], symbol;
    int top = -1;
    printf("Enter Postfix Expression:");
    scanf("%s", postfix);
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (isdigit(postfix[i]))
            stack[++top] = postfix[i] - '0';
        else
        {
            op2 = stack[top--];
            op1 = stack[top--];
            stack[++top] = compute(op1, op2, postfix[i]);
        }
    }
    printf("Postfix Expression Yields:%lf\n", stack[top--]);
    return 0;
}
*/
/*
// 5b Tower of Hanoi

void hanoi(int n, char A, char B, char C)
{
    if (n == 0)
        return;
    hanoi(n - 1, A, C, B);
    printf("Moved disk %d from %c to %c\n", n, A, C);
    hanoi(n - 1, B, A, C);
}

int main()
{
    int n;
    printf("Enter number of disks\n");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    return 0;
}*/

/*//Pattern Matching

int matchPattern(char *text, char *pattern)
{
    int textLen = strlen(text);
    int patternLen = strlen(pattern);

    for (int i = 0; i <= textLen - patternLen; i++)
    {
        int j;
        for (j = 0; j < patternLen; j++)
        {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == patternLen)
            return i; // pattern found at index i in the text
    }
    return -1; // pattern not found
}

int main()
{
    char text[100];
    char pattern[100];

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // remove trailing newline character

    printf("Enter pattern: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0'; // remove trailing newline character

    int index = matchPattern(text, pattern);
    if (index != -1)
        printf("Pattern found at index %d\n", index);
    else
        printf("Pattern not found\n");

    return 0;
}
void bfs(int visited[], int source, int amat[][SIZE], int n)
{
    int q[n], f = 0, r = 0, u, v;
    visited[source] = 1;
    q[r++] = source;
    while (f < r)
    {
        u = q[f++];
        for (v = 0; v < n; v++)
        {
            if (amat[u][v] == 1 && visited[v] == 0)
            {
                visited[v] = 1;
                q[r++] = v;
            }
        }
    }
}*/

/*
// 11. Graph

void bfs(int source, int visited[], int amat[][20], int n)
{
    int q[n], f = 0, r = 0, u, v;
    visited[source] = 1;
    q[++r] = source;
    while (f < r)
    {
        u = q[f++];
        for (v = 0; v < n; v++)
        {
            if (amat[u][v] == 1 && visited[v] == 0)
            {
                visited[v] = 1;
                q[r++] = v;
            }
        }
    }
}
void dfs(int visited[], int source, int amat[][20], int n)
{
    visited[source] = 1;
    printf("%d ", source);
    for (int i = 0; i < n; i++)
    {
        if (amat[source][i] == 1 && visited[i] == 0)
        {
            dfs(visited, i, amat, n);
        }
    }
}
int main()
{
    int n;
    printf("Enter Number of vertices\n");
    scanf("%d", &n);
    int amat[n][n], source, visited[n];
    printf("Enter the Adjacency Matrix\n");
    for (int i = 0; i < n; i++)
    {
        printf("Row %d:", i + 1);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &amat[i][j]);
        }
        printf("\n");
    }
    printf("The Adjacency Matrix is\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", amat[i][j]);
        printf("\n");
    }
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    printf("Enter Source:");
    scanf("%d", &source);
    bfs(source, visited, amat, n);
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 1)
            printf("%d is visited\n");
        else
            printf("%d is not visited\n");
    }
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    dfs(visited, source, amat, n);
    return 0;
}*/

// 12 Hashing:

#define HZ 3

typedef struct
{
    int key;
    int addr;
} hashtable;

typedef struct
{
    int empno;
    char name[10];
    int sal;
} emp;

void insert(FILE *fp, hashtable table[], int n)
{
    emp a;
    int hindex, countindex, flag = 0;
    for (int i = 0; i < n; i++, flag = 0)
    {
        printf("Enter empno,name & sal\n");
        scanf("%d%s%d", &a.empno, a.name, &a.sal);
        hindex = hashVal(a.empno);
        countindex = hindex;
        while (table[hindex].key != -1)
        {
            hindex = (hindex + 1) % HZ;
            flag = 1;
            if (hindex == countindex)
            {
                printf("Entry Unsuccessfull\n");
                return;
            }
        }
    }
    table[hindex].key = a.empno;
    fseek(fp, 0, SEEK_END);
    table[hindex].addr = ftell(fp);
    fprintf(fp, "%d %s %d\n", a.empno, a.name, a.sal);
    printf("Entry Successful\n");
    if (flag)
        printf("Linear probing used\n");
}
int main()
{
    FILE *fp;
    fp = fopen("emp.txt", "w+");
    emp a;
    hashtable table[HZ];
    for (int i = 0; i < HZ; i++)
        table[i].key = -1;
    int ch, n;
    while (1)
    {
        printf("1.Insert\n2.Search\n3.Display\n0.Exit\nEnter Choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter number of employees:");
            scanf("%d", &n);
            insert(fp, table, n);
            break;
        case 2:
            search(fp, table, n);
            break;
        case 3:
            display(fp, table, n);
            break;
        case 0:
            printf("Program Over\n");
            exit(0);
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
    return 0;
}

table[hindex].key=a.empno;
fseek(fp,0,SEEK_END);
table[hindex].addr=ftell(fp);
fprintf(fp,"");
if(flag)
//Lp