#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX_ELE 30

int digit(int);
// Function to determine the precedence of operators for infix to postfix conversion
int getPrecedence(char operator)
{
    switch (operator)
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
        return 8; // Assuming default precedence to be higher than any other operator
    }
}

// Function to determine the stack precedence of operators for infix to postfix conversion
int getStackPrecedence(char operator)
{
    switch (operator)
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
        return 7; // Assuming default stack precedence to be lower than any other operator
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
    char c, stack[MAX_ELE] = {'#'};
    char infix[MAX_ELE] = {"a/b-(c+d)"};
    char postfix[MAX_ELE];
    int top = 0, i, j = 0; // top = 0 because '#' is already stored in stack
    double op1, op2;
    char symbol;
    printf("Enter the infix expression: %s\n", infix);

    for (i = 0; i < strlen(infix); i++)
    {
        c = infix[i];

        // STEP 1: Pop operators from stack and append to postfix until precedence condition met
        while (getPrecedence(stack[top]) > getStackPrecedence(c))
        {
            postfix[j] = stack[top];
            j++;
            top--;
        }

        // STEP 2: Push operator onto stack if precedence condition is not met
        if (getPrecedence(stack[top]) != getStackPrecedence(c))
        {
            stack[++top] = c;
        }
        else
        {
            top--; // Pop operator from stack if precedence condition is met
        }
    }

    // Pop remaining operators from stack and append to postfix
    for (; stack[top] != '#'; top--)
    {
        postfix[j++] = stack[top];
    }
    postfix[j] = '\0'; // Null-terminate the postfix expression

    printf("The postfix expression: %s\n", postfix);
    top = -1;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        // int isdigit(int c);
        // return value is nonzero or zero
        if (isdigit(postfix[i]))
            stack[++top] = postfix[i] - '0';
        else
        {
            op2 = stack[top--];
            op1 = stack[top--];
            stack[++top] = compute(postfix[i], op1, op2);
        }
    }
    printf("Result is %lf\n", stack[top--]);

    return 0;
}
