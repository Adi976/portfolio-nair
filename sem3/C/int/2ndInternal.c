#include <stdlib.h>
#include <stdio.h>

/*Topics for 2nd internal DS
Stack
Dynamic stack
Linear Queue
Circular queue
Dynamic CQ
Recursion - factorial, tower of Hanoi, printing natural numbers
Infix to postfix
Postfix evaluation
SLL
SLL with header node
(Not necessary to be circular list)
DLL*/

/*// 1. Stacks using arrays
int top = -1, MAX = 5;

void pop(const int *stack)
{
    if (top == -1)
        printf("Stack Underflow!!\n");
    else
        printf("Popped: %d\n", stack[top--]);
}
void push(const int *stack)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow!!\n");
        return;
    }
    printf("Enter Element:\n");
    scanf("%d", &stack[++top]);
}

void display(const int *stack)
{
    for (int i = top; i > -1; i--)
    {
        printf("%d\n", *(stack + 1));
    }
}
int main()
{
    int ch;
    int *stack = NULL;
    while (stack == NULL)
        stack = (int *)malloc(sizeof(int) * MAX);
    while (1)
    {
        printf("1.Pop\n2.Push\n3.Display\n4.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            pop(stack);
            break;
        case 2:
            push(stack);
            break;
        case 3:
            display(stack);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid Choice\n");
        }
    }
    return 0;
}*/

/*// 2. Stacks using structures
#define MAX 4
typedef struct
{
    int st[MAX];
    int top;
} Stack;

void pop(Stack *one)
{
    if (one->top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    printf("Popped:%d", one->st[(one->top)]);
    (one->top)--;
}

void push(Stack *one)
{
    if (one->top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    printf("Enter Element\n");
    (one->top) += 1;
    scanf("%d", &(one->st[(one->top)]));
}

void display(Stack one)
{
    for (int i = one.top; i >= 0; i--)
    {
        printf("%d\n", one.st[i]);
    }
}

int main()
{
    Stack one;
    int ch;
    one.top = -1;
    while (1)
    {
        printf("1.Pop\n2.Push\n3.Display\n4.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            pop(&one);
            break;
        case 2:
            push(&one);
            break;
        case 3:
            display(one);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid Choice\n");
        }
    }
    return 0;
}*/

// 3.Circular Queue

#define MAX 4
typedef struct
{
    int front, rear;
    int cq[MAX];
} CQ;

int cnt = 0;

void insertCQ(CQ *one)
{
    if (cnt == MAX)
    {
        printf("Circular Queue Oveflow\n");
        return;
    }
    one->rear = (one->rear + 1) % MAX;
    scanf("%d", &(one->cq[(one->rear)]));
    cnt++;
}

void deleteCQ(CQ *one)
{
    if (cnt == -1)
    {
        printf("Circular Queue Underflow\n");
        return;
    }
    printf("Deleted:%d\n", one->cq[(one->front)]);
    one->front = (one->front + 1) % MAX;
    cnt--;
}

void displayCQ(const CQ one)
{
    for (int i = one.front, j = 0; j < cnt; j++)
    {
        printf("%d\n", one.cq[i]);
        i = (i + 1) % MAX;
    }
}

int main()
{
    CQ one;
    int ch;
    one.front = -1;
    one.rear = 0;
    while (1)
    {
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertCQ(&one);
            break;
        case 2:
            deleteCQ(&one);
            break;
        case 3:
            displayCQ(one);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid Choice\n");
        }
    }
    return 0;
}