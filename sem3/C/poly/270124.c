#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the structure for a term in the polynomial
struct TERM
{
    int coef, xexp, yexp, zexp;
    struct TERM *next;
};

typedef struct TERM Term;

// Function to accept polynomial terms from the user
void accept(Term **poly)
{
    int n;
    printf("Enter Number of Terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        Term *newTerm = (Term *)malloc(sizeof(Term));
        printf("Enter Term %d\n", i + 1);
        printf("Coefficient: ");
        scanf("%d", &(newTerm->coef));
        printf("X Exponent: ");
        scanf("%d", &(newTerm->xexp));
        printf("Y Exponent: ");
        scanf("%d", &(newTerm->yexp));
        printf("Z Exponent: ");
        scanf("%d", &(newTerm->zexp));

        if (*poly == NULL)
        {
            *poly = newTerm;
            newTerm->next = *poly;
        }
        else
        {
            Term *reachEnd = *poly;
            while (reachEnd->next != *poly)
            {
                reachEnd = reachEnd->next;
            }
            newTerm->next = reachEnd->next;
            reachEnd->next = newTerm;
        }
    }
}

// Function to display the polynomial
void display(Term *poly)
{
    Term *reachedEnd = poly;
    while (poly->next != reachedEnd)
    {
        poly = poly->next;
        printf("%dx^%dy^%dz^%d + ", poly->coef, poly->xexp, poly->yexp, poly->zexp);
    }
    printf("\b\b  \n");
}

// Function to compare two terms for equality
int compare(Term *one, Term *two)
{
    return (one->xexp == two->xexp && one->yexp == two->yexp && one->zexp == two->zexp);
}

// Function to remove duplicate terms from the polynomial
void removeDuplicates(Term **poly)
{
    Term *tempPoly = *poly;
    Term *innerTempPoly = *poly;
    Term *reachEnd = (*poly)->next;

    while (tempPoly->next != reachEnd)
    {
        innerTempPoly = tempPoly;
        while (innerTempPoly->next != reachEnd)
        {
            if (compare(tempPoly->next, innerTempPoly->next->next))
            {
                tempPoly->next->coef += innerTempPoly->next->next->coef;
                Term *toDelete = innerTempPoly->next->next;
                innerTempPoly->next->next = innerTempPoly->next->next->next;
                free(toDelete);
            }
            else
            {
                innerTempPoly = innerTempPoly->next;
            }
        }
        tempPoly = tempPoly->next;
    }
}

void addPoly(Term **resPoly, Term *polyOne, Term *polyTwo)
{
    Term *reachedEndOne = polyOne;
    Term *reachedEndTwo = polyTwo;

    polyOne = polyOne->next;
    polyTwo = polyTwo->next;

    while (polyOne != reachedEndOne)
    {
        Term *newTerm = (Term *)malloc(sizeof(Term));
        newTerm->coef = polyOne->coef;
        newTerm->xexp = polyOne->xexp;
        newTerm->yexp = polyOne->yexp;
        newTerm->zexp = polyOne->zexp;
        newTerm->next = (*resPoly)->next;
        (*resPoly)->next = newTerm;
        polyOne = polyOne->next;
    }

    while (polyTwo != reachedEndTwo)
    {
        int found = 0;
        Term *temp = (*resPoly)->next;
        while (temp != (*resPoly))
        {
            if (temp->xexp == polyTwo->xexp && temp->yexp == polyTwo->yexp && temp->zexp == polyTwo->zexp)
            {
                temp->coef += polyTwo->coef;
                found = 1;
                break;
            }
            temp = temp->next;
        }
        if (!found)
        {
            Term *newTerm = (Term *)malloc(sizeof(Term));
            newTerm->coef = polyTwo->coef;
            newTerm->xexp = polyTwo->xexp;
            newTerm->yexp = polyTwo->yexp;
            newTerm->zexp = polyTwo->zexp;
            newTerm->next = (*resPoly)->next;
            (*resPoly)->next = newTerm;
        }
        polyTwo = polyTwo->next;
    }
}

// Function to evaluate a polynomial at given values of x, y, and z
double evaluateF(Term *poly, const int x, const int y, const int z)
{
    double result = 0;
    Term *reachedEnd = poly;
    while (poly->next != reachedEnd)
    {
        poly = poly->next;
        result += (double)((poly->coef) * pow(x, (poly->xexp)) * pow(y, (poly->yexp)) * pow(z, (poly->zexp)));
    }
    return result;
}

// Function to evaluate the polynomial with user input for x, y, and z
void evaluatePoly(Term *poly)
{
    int x, y, z;
    printf("Enter x, y, and z: ");
    scanf("%d%d%d", &x, &y, &z);
    if (poly->next == poly)
    {
        printf("Resultant Polynomial is empty\n");
    }
    else
    {
        printf("Resultant Polynomial Evaluation: %.4lf\n", evaluateF(poly, x, y, z));
    }
}

// Main function
int main()
{
    int ch;
    Term *polyOne = NULL, *polyTwo = NULL, *resPoly = NULL;
    polyOne = (Term *)malloc(sizeof(Term));
    polyTwo = (Term *)malloc(sizeof(Term));
    resPoly = (Term *)malloc(sizeof(Term));
    polyOne->next = polyOne;
    polyTwo->next = polyTwo;
    resPoly->next = resPoly;

    printf("Enter Polynomial 1\n");
    accept(&polyOne);
    printf("Polynomial 1: ");
    display(polyOne);

    printf("Enter Polynomial 2\n");
    accept(&polyTwo);
    printf("Polynomial 2: ");
    display(polyTwo);

    while (1)
    {
        printf("Enter\n1. Add\n2. Evaluate\n3. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            addPoly(&resPoly, polyOne, polyTwo);
            printf("Resultant Polynomial: ");
            display(resPoly);
            break;
        case 2:
            evaluatePoly(resPoly);
            break;
        case 3:
            printf("Simulation Over!!\n");
            exit(0);
            break;
        default:
            printf("Invalid Choice\n");
        }
    }
    return 0;
}
