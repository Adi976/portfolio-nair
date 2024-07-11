#include <stdio.h>
#include <stdlib.h>
// Program to implement stack
void push(int[], int *, const int);
void pop(int[], int *);
void display(int[], const int);
int main()
{
	int *st = NULL;
	int n, ch, top = -1;
	printf("Enter the size of the stack\n");
	scanf("%d", &n);
	st = malloc(sizeof(int) * n);
	printf("Simulation Begins!!\n\n");
	while (1)
	{
		printf("Enter\n'1' for push\n'2' for pop\n'3' for display\n'4' for exit\n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			push(st, &top, n);
			break;
		case 2:
			pop(st, &top);
			break;
		case 3:
			display(st, top);
			break;
		case 4:
			printf("Simulation Over!!\n");
			exit(0);
			break;
		default:
			printf("Enter valid choice\n");
		}
	}
	return 0;
}
void push(int stack[], int *top, const int n)
{
	int ele;

	printf("Enter an element to be pushed into the stack\n");
	scanf("%d", &ele);
	if (*top == n - 1)
	{
		printf("Stack Overflow\n");
		return;
	}
	(*top)++;
	stack[*top] = ele;
}
void pop(int stack[], int *top)
{
	if (*top == -1)
	{
		printf("Stack Underflow\n");
		return;
	}
	printf("%d deleted\n", stack[*top]);
	(*top)--;
}
void display(int stack[], const int top)
{
	printf("Current Elements=[ ");
	for (int i = top; i >= 0; i--)
	{
		printf("%d,", stack[i]);
	}
	printf("\b ]\n");
}