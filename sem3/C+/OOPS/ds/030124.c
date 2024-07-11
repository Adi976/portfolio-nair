// Program to simulate stack
/*#include<stdio.h>
#define MAX 3
void push(int [],int *);
void pop(int [],int* );
void display(int [],int );
int main()
{
    int stack[3];int top=-1;
    int ch;
    printf("Enter\n 1.POP \n 2.PUSH \n3.Display elements\n");
    printf("Enter the choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:pop(stack,&top);break;
        case 2: push(stack,&top);break;
        case 3:display(stack,top);break;
        default:printf("Invalid Choice");
    }
    return 0;
}
void push(int stack[],int *top)
{
    if(*top==MAX-1)
    {
        printf("Stack Full\n");
        return;
    }
    printf("Enter an element\n");
    scanf("%d",&stack[(*top)++]);
}
void pop(int stack[],int* top)
{
    if(*top==-1)
    {
        printf("Stack Empty\n");
        return;
    }
    (*top)--;
}
void display(int stack[],int top)
{
    for(int i=top;i>=0;i--)
    printf("%d\n",stack[top]);
}*/

// Program to simulate stack using dynamic memory allocation

#include <stdio.h>
#include <stdlib.h>
void push(int **, int *, int *);
void pop(int[], int *);
void display(int[], int);
int main()
{
    int *stack = NULL, n, ch, top = -1, loop = 1;
    printf("Enter size of n\n");
    scanf("%d",&n);
    stack = malloc(sizeof(int) * n);
    printf("Stack simulation begins\n");
    for(;;)
    {
        printf("Enter\n 1.POP \n 2.PUSH \n3.Display elements\n 4.Exit Simulation\n");
        printf("Enter the choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            pop(stack, &top);
            break;
        case 2:
            push(&stack, &top, &n);
            break;
        case 3:
            display(stack, top);
            break;
        default:
            printf("Simulation over");
            return;
        }
    }
    return 0;
}
void push(int **stack, int *top, int *n)
{
    if (*top == (*n) - 1)
    {
        (*n) *= 2;
        stack = realloc(stack, sizeof(int) * (*n));
    }
    printf("Enter an element\n");
    scanf("%d", (*stack)[(*top)++]);
}
void pop(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("Stack Empty\n");
        return;
    }
    (*top)--;
}
void display(int stack[], int top)
{
    for (int i = top; i >= 0; i--)
        printf("%d\n", stack[top]);
}
