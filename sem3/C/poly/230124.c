// Program to perform polynomial addition and evaluation using CSLL
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
// Approach: add all terms of polynomial 1 and 2 and then remove duplicates
struct TERM
{
    int coef, xexp, yexp, zexp;
    struct TERM *next;
};
typedef struct TERM Term;
void accept(Term **poly)
{
    int n;
    printf("Enter Number of Terms\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        Term *newTerm = (Term *)malloc(sizeof(Term));
        printf("Enter Term %d\n", i + 1);
        printf("Coefficient: ");
        scanf("%d", &(newTerm->coef));
        printf("\nX Exponent:");
        scanf("%d", &(newTerm->xexp));
        printf("\nY Exponent:");
        scanf("%d", &(newTerm->yexp));
        printf("\nZ Exponent:");
        scanf("%d", &(newTerm->zexp));

        if (*poly == NULL)
        {
            // poly has to point to the first node
            newTerm->next = (*poly)->next;
            (*poly)->next = newTerm;
        }
        else
        {
            // insert end
            Term *reachEnd = *poly;
            while (reachEnd->next != (*poly))
            {
                reachEnd = reachEnd->next;
            }
            newTerm->next = reachEnd->next;
            reachEnd->next = newTerm;
        }
    }
}

void display(Term *poly)
{
    Term *reachedEnd = poly;
    while (poly->next != reachedEnd)
    {
        poly = poly->next;
        printf(" %dx^%dy^%dz^%d +", poly->coef, poly->xexp, poly->yexp, poly->zexp);
    }
    printf("\b \n");
}

int compare(Term *one, Term *two)
{
    if ((one->xexp == two->xexp) && (one->yexp == two->yexp) && (one->zexp == two->zexp))
        return 1;
    else
        return 0;
}
void removeDuplicates(Term **res_poly)
{
    Term *temp_res_poly = (*res_poly);
    Term *innertemp_res_poly = (*res_poly);
    Term *reachEnd = (*res_poly);
    innertemp_res_poly = innertemp_res_poly->next;
    temp_res_poly = temp_res_poly->next;
    int cnt = 0;
    while (temp_res_poly != reachEnd)
    {
        cnt = 0;
        while (innertemp_res_poly != reachEnd)
        {
            if (compare(temp_res_poly, innertemp_res_poly->next))
            {
                cnt++;
            }
            if (cnt == 2)
            {
                // remove current node
                int coef = innertemp_res_poly->next->coef;
                temp_res_poly->coef += coef;
                Term *to_delete = innertemp_res_poly->next;
                innertemp_res_poly->next = innertemp_res_poly->next->next;
                free(to_delete);
            }
            else
                innertemp_res_poly = innertemp_res_poly->next;
        }
        temp_res_poly = temp_res_poly->next;
    }
}
void addPoly(Term **res_poly, Term *poly_one, Term *poly_two)
{
    // adding first node
    Term *reachedEnd = poly_one;
    poly_one = poly_one->next; // moving to the first node
    Term *resTerms = *res_poly;
    (resTerms)->next = poly_one;
    resTerms = resTerms->next;
    poly_one = poly_one->next;
    //(resTerms)->next=(*res_poly);

    // adding remaining poly one nodes
    while (poly_one != reachedEnd)
    {
        resTerms->next = poly_one;
        resTerms = resTerms->next;
        poly_one = poly_one->next;
    }
    // adding poly 2 terms
    reachedEnd = poly_two;
    poly_two = poly_two->next;
    while (poly_two != reachedEnd)
    {
        resTerms->next = poly_two;
        resTerms = resTerms->next;
        poly_two = poly_two->next;
    }
    resTerms->next = (*res_poly);
    // added all poly 1 terms
    removeDuplicates(&(*res_poly));
}

int evaluateF(Term *poly, const int x, const int y, const int z)
{
    double result = 0;
    Term *reachedEnd = poly;
    while (poly->next != reachedEnd)
    {
        poly = poly->next;
        result += (double)((poly->coef) * pow(x, (poly->xexp)) * pow(y, (poly->yexp)) * pow(z, (poly->zexp)));
    }
    printf("%.4lf\n", result);
}
int evaluatePoly(Term *poly)
{
    int x, y, z;
    printf("Enter x,y & z\n");
    scanf("%d%d%d", &x, &y, &z);
    if (poly->next == poly)
    {
        printf("Resultant Polynomial is empty\n");
    }
    else
    {
        printf("Resultant Polynomial:");
        evaluateF(poly, x, y, z);
    }
    // printf("\nPolynomial 1:");
    evaluateF(poly, x, y, z);
    // printf("\nPolynomial 2:");
    // evaluateF(poly_two, x, y, z);
}

int main()
{
    int ch;
    Term *poly_one = NULL, *poly_two = NULL, *res_poly = NULL;
    poly_one = (Term *)malloc(sizeof(Term));
    poly_two = (Term *)malloc(sizeof(Term));
    res_poly = (Term *)malloc(sizeof(Term));
    poly_one->next = poly_one;
    poly_two->next = poly_two;
    res_poly->next = res_poly;
    printf("Enter Polynomial 1\n");
    accept(&poly_one);
    printf("Here's Polynomial 1 you entered:");
    display(poly_one);
    printf("Enter Polynomial 2\n");
    accept(&poly_two);
    printf("Here's Polynomial 2 you entered:");
    display(poly_two);
    int res1 = evaluatePoly(poly_one);
    int res2 = evaluatePoly(poly_two);
    while (1)
    {
        printf("Enter\n1.Add\n2.Evaluate\n3.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Appending Poly_one\n");
            addPoly(&res_poly, poly_one, poly_two);
            printf("Resultant Polynomial:");
            display(res_poly);
            break;
        case 2:
            printf("\nPolynomial 1: %d", res1);

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