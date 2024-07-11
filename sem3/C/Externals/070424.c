// Infix to postfix

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

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

double compute(char symbol, double op1, double op2)
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
    case '$':
    case '^':
        return pow(op1, op2);
    }
}

int main()
{
    char c, postfix[20], infix[20], stack[20] = {'#'};
    int top = 0, i, j = 0;
    printf("Enter Infix Expression:");
    scanf("%s", infix);
    for (i = 0; i < strlen(infix); i++)
    {
        c = infix[i];
        while (getPrecedence(stack[top]) > getStackPrecedence(c))
        {
            postfix[j] = stack[top];
            j++;
            top--;
        }
        if (getPrecedence(stack[top]) != getStackPrecedence(c))
            stack[++top] = c;
        else
            top--;
    }
    for (; stack[top] != '#'; top--)
    {
        postfix[j++] = stack[top];
    }
    postfix[j] = '\0';
    printf("Postfix expression is %s\n", postfix);
    double st[20];
    double op1, op2;
    top = -1;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isdigit(postfix[i]))
            st[++top] = postfix[i] - '0';
        else
        {
            op2 = st[top--];
            op1 = st[top--];
            st[++top] = compute(postfix[i], op1, op2);
        }
    }
    printf("Result is %lf\n", stack[top--]);
    return 0;
}