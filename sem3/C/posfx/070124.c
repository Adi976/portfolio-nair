#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int toPostfix(char[], char[], int *, int);
int prec(char);
char associativity(char);
void display(char[]);
// Program to convert infix to postfix and print the output
int main()
{
	char *stack, i, *pf;
	int top = -1;
	char *exp;
	printf("Enter an expression\n");
	scanf("%s", exp);
	stack = malloc(sizeof(char) * strlen(exp));
	pf = malloc(sizeof(char) * strlen(stack));
	stack[0] = '(';
	for (i = 1; exp[i] != '\0'; i++)
	{
		stack[i] = tolower(exp[i]);
	}
	stack[i] = ')';
	stack[i + 1] = '\0';
	printf("Stack: [ ");
	for (i = 0; stack[i] != '\0'; i++)
	{
		printf("%c,", stack[i]);
	}
	printf("\b ]\n");
	toPostfix(stack, pf, &top, 0);
	display(pf);
	free(stack); // Don't forget to free allocated memory
	free(pf);
	return 0;
}
/*int toPostfix(char stack[], char pf[], int *top, int i)
{
	if (stack[i] != ')')
		return i;
	else
	{
		if (stack[i] == '(')
			i = toPostfix(stack, pf, top, i);
		else
		{
			if ((stack[i] >= 'a' && stack[i] <= 'z') || (stack[i] >= '0' && stack[i] <= '9'))
			{
				(*top)++;
				pf[*top] = stack[i++];
			}
			else
			{
				if (stack[i] == '+' || stack[i] == '-' || stack[i] == '*' || stack[i] == '/')
				{
					while (*top != -1 && prec(pf[*top]) >= prec(stack[i]) && associativity(pf[*top]) == 'L')
					{
						(*top)++;
						pf[*top] = stack[i];
						i++;
					}
				}
			}
		}
	}
}*/
int toPostfix(char stack[], char pf[], int *top, int i)
{
	if (stack[i] != '\0')
	{
		if (isalnum(stack[i]))
		{
			pf[*top] = stack[i];
			(*top)++;
		}
		else if (stack[i] == '(')
		{
			i = toPostfix(stack, pf, top, i + 1);
		}
		else if (stack[i] == ')')
		{
			return i + 1;
		}
		else
		{
			while (*top != -1 && prec(pf[*top]) >= prec(stack[i]) && associativity(pf[*top]) == 'L')
			{
				(*top)--;
				pf[*top] = stack[i];
			}
			(*top)++;
			pf[*top] = stack[i];
		}
		return toPostfix(stack, pf, top, i + 1);
	}
	return i;
}
int prec(char c)
{
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}
char associativity(char c)
{
	if (c == '^')
		return 'R';
	return 'L'; // Default to left-associative
}
void display(char postfix[])
{
	printf("Postfix Expression: %s\n", postfix);
}