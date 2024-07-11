/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 10

int isdigit(int d)
{
    if (d >= 0 && d <= 9)
        return 1;
}

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
    char c, stack[MAX] = {'#'}, infix[MAX], postfix[MAX];
    int top = 0;
    printf("Enter infix expression: \n");
    scanf("%s", infix);
    int j = 0;
    for (int i = 0; i < strlen(infix); i++)
    {
        c = infix[i];
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

    printf("Postfix Expression:%s\n", postfix);
    top = -1;
    double op1, op2;
    for (int i = 0; postfix[i] != '\0'; i++)
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

/*

int main()
{
    int top = -1, j = 0;
    char stack[MAX] = {'#'}, infix[MAX], postfix[MAX];
    printf("Enter an infix expression\n");
    scanf("%s", infix);
    for (int i = 0; i < strlen(infix); i++)
    {
        char c = infix[i];
        if (getPrecedence(stack[top]) > getStackPrecedence(c))
        {
            postfix[j++] = stack[top];
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
    while (stack[top] != '#')
    {
        postfix[j++] = stack[top];
        top--;
    }
    postfix[j] = '\0'; // Null-terminate the postfix expression

    printf("Postfix Expression:%s\n", postfix);
    // EVALUATION
    top = -1;
    double op1, op2;
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
            stack[++top] = compute(postfix[i], op1, op2);
        }
    }
    printf("Result is %lf\n", stack[top--]);
    return 0;
}



int searchBST(Node *root,int Key)
{
    if(!root)
        return 0;
    else
    {
        if(root->key==Key)
            return 1;
        if(root->key<Key)
            return searchBST(root->right,Key);
        return searchBST(root->left,Key);
    }
}

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Term
{
    int coefficient, x_exponent, y_exponent, z_exponent;
    struct Term *next;
};
typedef struct Term PolynomialTerm;

void createPolynomial(PolynomialTerm *);
void displayPolynomial(PolynomialTerm *);
void evaluatePolynomial(PolynomialTerm *);
void addPolynomials(PolynomialTerm *, PolynomialTerm *, PolynomialTerm *);
int compareTerms(PolynomialTerm *, PolynomialTerm *);
void attachTerm(int, PolynomialTerm *, PolynomialTerm *);
void deleteTerm(PolynomialTerm *, PolynomialTerm *);

int main()
{
    PolynomialTerm poly1 = {.next = NULL}, poly2 = {.next = NULL}, result = {.next = NULL};
    int choice;
    while (1)
    {
        printf("1. Evaluate\n2. Polynomial addition\n3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (poly1.next != NULL)
                poly1.next = NULL;
            createPolynomial(&poly1);
            printf("Terms in polynomial are...\n");
            displayPolynomial(&poly1);
            evaluatePolynomial(&poly1);
            break;
        case 2:
            if (poly1.next != NULL)
                poly1.next = NULL;
            if (poly2.next != NULL)
                poly2.next = NULL;
            if (result.next != NULL)
                result.next = NULL;
            createPolynomial(&poly1);
            createPolynomial(&poly2);
            printf("Terms in poly1 are...\n");
            displayPolynomial(&poly1);
            printf("Terms in poly2 are...\n");
            displayPolynomial(&poly2);
            addPolynomials(&poly1, &poly2, &result);
            printf("Resultant polynomial...\n");
            displayPolynomial(&result);
            break;
        case 3:
            return 0;
        }
    }
}

void addPolynomials(PolynomialTerm *poly1, PolynomialTerm *poly2, PolynomialTerm *result)
{
    int val;
    PolynomialTerm *term1 = poly1->next, *term2, *lastAdded = NULL;
    while (term1 != NULL)
    {
        term2 = poly2->next;
        while (term2 != NULL)
        {
            val = compareTerms(term1, term2);
            if (val)
                break;
            term2 = term2->next;
        }
        switch (val)
        {
        case 0:
            attachTerm(0, term1, result);
            term1 = term1->next;
            deleteTerm(poly1, term1);
            break;
        case 1:
            val = term1->coefficient + term2->coefficient;
            attachTerm

                (val, term1, result);
            deleteTerm(poly1, term1);
            deleteTerm(poly2, term2);
            term1 = term1->next;
            term2 = term2->next;
            break;
        }
    }
    term2 = poly2->next;
    while (term2 != NULL)
    {
        attachTerm(0, term2, result);
        term2 = term2->next;
    }
}

int compareTerms(PolynomialTerm *term1, PolynomialTerm *term2)
{
    if ((term1->x_exponent == term2->x_exponent) &&
        (term1->y_exponent == term2->y_exponent) &&
        (term1->z_exponent == term2->z_exponent))
        return 1;
    return 0;
}

void attachTerm(int coefficient, PolynomialTerm *term, PolynomialTerm *result)
{
    PolynomialTerm *lastAdded;
    PolynomialTerm *newTerm = (PolynomialTerm *)malloc(sizeof(PolynomialTerm));
    newTerm->coefficient = (coefficient != 0) ? coefficient : term->coefficient;
    newTerm->x_exponent = term->x_exponent;
    newTerm->y_exponent = term->y_exponent;
    newTerm->z_exponent = term->z_exponent;
    newTerm->next = NULL;
    if (result->next == NULL)
        result->next = newTerm;
    else
        lastAdded->next = newTerm;
    lastAdded = newTerm;
}

void deleteTerm(PolynomialTerm *poly, PolynomialTerm *target)
{
    PolynomialTerm *previous = poly, *current = poly->next;
    while (current != target)
    {
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    free(current);
}
