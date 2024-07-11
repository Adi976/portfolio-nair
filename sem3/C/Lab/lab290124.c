#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Structure for stack
struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};

// Function to create a stack of given capacity
struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to check if the stack is full
int isFull(struct Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// Function to push element onto the stack
void push(struct Stack *stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

// Function to pop element from the stack
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

// Function to return the top element of the stack
int peek(struct Stack *stack)
{
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top];
}

// Function to determine precedence of operators
int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    }
    return -1;
}

// Function to convert infix expression to postfix
void infixToPostfix(char *infix, char *postfix)
{
    struct Stack *stack = createStack(strlen(infix));
    int i, k;
    for (i = 0, k = -1; infix[i]; ++i)
    {
        // If the scanned character is an operand, add it to output
        if (isalnum(infix[i]))
            postfix[++k] = infix[i];
        // If the scanned character is an '(', push it to the stack
        else if (infix[i] == '(')
            push(stack, infix[i]);
        // If the scanned character is an ')', pop and output from the stack until an '(' is encountered
        else if (infix[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
                postfix[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return; // Invalid expression
            else
                pop(stack);
        }
        else
        { // An operator is encountered
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(peek(stack)))
                postfix[++k] = pop(stack);
            push(stack, infix[i]);
        }
    }
    // Pop all the remaining elements from the stack
    while (!isEmpty(stack))
        postfix[++k] = pop(stack);
    postfix[++k] = '\0';
}

// Function to evaluate postfix expression
int evaluatePostfix(char *postfix)
{
    struct Stack *stack = createStack(strlen(postfix));
    int i;
    for (i = 0; postfix[i]; ++i)
    {
        if (isdigit(postfix[i]))
            push(stack, postfix[i] - '0');
        else
        {
            int val1 = pop(stack);
            int val2 = pop(stack);
            switch (postfix[i])
            {
            case '+':
                push(stack, val2 + val1);
                break;
            case '-':
                push(stack, val2 - val1);
                break;
            case '*':
                push(stack, val2 * val1);
                break;
            case '/':
                push(stack, val2 / val1);
                break;
            }
        }
    }
    return pop(stack);
}

int main()
{
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    printf("Enter infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
    infix[strlen(infix) - 1] = '\0'; // Remove the newline character
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result after evaluation: %d\n", result);

    return 0;
}
