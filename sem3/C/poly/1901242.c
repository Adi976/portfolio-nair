#include <stdio.h>
#include <stdlib.h>
//Polynomial add using LL!!
struct TERM
{
    int coef, exp;
    struct TERM *next;
};
typedef struct TERM Term;

void accept(Term **poly)
{
    int i = 0, n;
    Term *last = NULL;
    printf("Enter Number of Terms\n");
    scanf("%d", &n);
    while (i < n)//accepting n terms of a polynomial 
    {
        Term *newTerm = (Term *)malloc(sizeof(Term));
        if (*poly == NULL)
        {
            // storing address of 1st node
            *poly = last = newTerm;
        }
        printf("\nTerm %d: ", i + 1);
        printf("\nCoef:");
        scanf("%d", &(newTerm)->coef);
        printf("Exp:");
        scanf("%d", &(newTerm)->exp);
        newTerm->next = NULL;
        last->next = newTerm;
        last = newTerm;
        i++;//moving onto the next term of the polynomial
    }
}

void display(Term *poly)
{
    while (poly != NULL)
    {
        printf("%dX^%d+", poly->coef, poly->exp);
        poly = poly->next;
    }
    printf("\b \n");
}
int compare(int exp1, int exp2)
{
    if (exp1 < exp2)
        return -1;
    else if (exp1 > exp2)
        return 1;
    else
        return 0;
}

void attach(Term **res_poly, int coef, int exp)
{
    Term *newTerm = (Term *)malloc(sizeof(Term));//The new term in the resultant polynomial
    if(*res_poly==NULL)
    {
       *res_poly=newTerm; 
       (*res_poly)->next=NULL;
    }
    Term* res_poly_temp=*res_poly;
    while((res_poly_temp)->next!=NULL)
    {
        res_poly_temp=(res_poly_temp)->next;
    }
    newTerm->coef = coef;
    newTerm->exp = exp;
    (res_poly_temp)->next=newTerm;
    newTerm->next=NULL;
}
void polyAdd(Term **res_poly, Term *poly_one, Term *poly_two)
{
    if ((poly_one == NULL) || (poly_two == NULL))
    {
        printf("Enter Valid Polynomial!!\n");
        return;
    }
    while (poly_one && poly_two)
    {
        switch (compare(poly_one->exp, poly_two->exp))
        {
        case 1:
            attach(&(*res_poly), poly_one->coef, poly_one->exp);
            poly_one = poly_one->next;
            break;
        case 0:
            attach(&(*res_poly), poly_one->coef + poly_two->coef, poly_one->exp);
            poly_one = poly_one->next;
            poly_two = poly_two->next;
            break;
        case -1:
            attach(&(*res_poly), poly_two->coef, poly_two->exp);
            poly_two = poly_two->next;
            break;
        }
    }
    while (poly_one != NULL)
    {
        attach(&(*res_poly), poly_one->coef, poly_one->exp);
        poly_one = poly_one->next;
    }
    while (poly_two != NULL)
    {
        attach(&(*res_poly), poly_two->coef, poly_two->exp);
        poly_two = poly_two->next;
    }
}
int main()
{
    Term *poly_one = NULL, *poly_two = NULL, *res_poly = NULL;

    printf("Enter Polynomial 1\n");
    accept(&poly_one);
    printf("\nPolynomial 1:");
    display(poly_one);

    printf("\nEnter Polynomial 2\n");
    accept(&poly_two);
    printf("\nPolynomial 2:");
    display(poly_two);

    printf("Performing Polynomial Addition\n");
    polyAdd(&res_poly, poly_one, poly_two);

    printf("\nResultant Polynomial:");
    display(res_poly);
    return 0;
}