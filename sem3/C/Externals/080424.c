#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Polynomial Add

struct term
{
    int coef;
    int exp;
    struct term *next;
};

typedef struct term Term;

void accept(Term **poly)
{
    int n;
    printf("Enter Terms:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        Term *newTerm = (Term *)malloc(sizeof(Term));
        printf("Enter coef and exp:");
        scanf("%d%d", &newTerm->coef, &newTerm->exp);
        newTerm->next = NULL;
        if (*poly == NULL)
        {
            *poly = newTerm;
            continue;
        }
        newTerm->next = *poly;
        *poly = newTerm;
    }
}

void display(Term *poly)
{
    while (poly != NULL)
    {
        printf("%dx^%d+", poly->coef, poly->exp);
        poly = poly->next;
    }
    printf("\b \n");
}

int compare(Term *one, Term *two)
{
    if (one->exp > two->exp)
        return 1;
    if (one->exp == two->exp)
        return 0;
    if (one->exp < two->exp)
        return -1;
}
void addPoly(Term **poly_one, Term **poly_two, Term **res_poly)
{
    Term *one = *poly_one, *two = *poly_two;
    while (one != NULL)
    {
        while (two != NULL)
        {
            switch (compare(one, two))
            {
            case 1:
                attach(&(*res_poly), one->coef, one->exp);
                one = one->next;
                delete(one);
                break;
            case 0:
                attach(&(*res_poly), one->coef + two->coef, one->exp);
                one = one->next;
                two = two->next;
                delete(one);
                delete(two);
                break;
            case -1:
                attach(&(*res_poly), two =) break;
            default:
                break;
            }
        }
        two=two
    }
    while (one != NULL)
    {
    }
    while (two != NULL)
    {
    }
}

void evaluate(Term *poly)
{
    int x;
    double res = 0.0;
    printf("Enter x value:");
    scanf("%d", &x);
    while (poly != NULL)
    {
        res += poly->coef * (pow(x, poly->exp));
        poly = poly->next;
    }
    printf("Evaluation Result=%lf\n", res);
}

int main()
{
    Term *one = NULL, *two = NULL, *res_poly = NULL;
    int ch;
    while (1)
    {
        printf("1.Accept\n2.Display\n3.Add\n4.Evaluate\n0.Exit\n5.Enter Choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("1.Polynomial 1\n2.Polynomial 2\nEnter Choice:");
            scanf("%d", &ch);
            if (ch == 1)
                accept(&one);
            if (ch == 2)
                accept(&two);
            break;
        case 2:
            printf("1.Polynomial 1\n2.Polynomial 2\nEnter Choice:");
            scanf("%d", &ch);
            if (ch == 1)
                display(one);
            if (ch == 2)
                display(two);
            break;
        case 3:
            addPoly(&one, &two, &res_poly);
            break;
        case 4:
            printf("1.Polynomial 1\n2.Polynomial 2\nEnter Choice:");
            scanf("%d", &ch);
            if (ch == 1)
                evaluate(one);
            if (ch == 2)
                evaluate(two);
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
    return 0;
}