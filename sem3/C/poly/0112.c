#include <stdio.h>
//Poly add uisng automatic
typedef struct
{
    int cf, px;
} term;

int accept(term[], const int);
void display(term [], const int, const int);
void add(term [],int ,int ,int ,int *);
int compare(int ,int );
void attach(term [],int,int,int*);
int main()
{
    term ar[50];
    int sa = 0, fa, sb, fb, sc, fc;
    printf("Enter the 1st polynomial\n");
    fa = accept(ar, 0);
    sb = fa + 1;
    printf("Enter the second polynomial\n");
    fb = accept(ar, sb);
    sc=fb+1;
    printf("The 1st polynomial is ");
    display(ar, sa, fa);
    printf("\nThe 2nd polynomial is ");
    display(ar, sb, fb);
    add(ar,sa,sb,sc,&fc);
    //printf("Value of sc=%d, value of fc=%d",sc,fc);
    printf("\n\nThe resultant polynomial is ");
    display(ar,sc,fc);
}
int accept(term ar[], const int s)
{
    int n,i;
    printf("Enter the number of terms in the polynomial in descending order of their power\n");
    scanf("%d", &n);

    for (i = s; i < s + n; i++)
    {
        printf("Enter the coefficient of term %d:\n",i+1);
        scanf("%d", &ar[i].cf);
        printf("Enter the power of term %d:\n",i+1);
        scanf("%d", &ar[i].px);
    }
    return (i - 1);
}
void add(term ar[],int sa,int sb,int sc,int *fc)
{
    *fc=sc;int fa=sb-1,fb=sc-1;
    while(sa<=fa&&sb<=fb)
    {
        switch(compare(ar[sa].px,ar[sb].px))
        {
            case -1: attach(ar,ar[sb].cf,ar[sb].px,fc);sb++;
                    break;
            case 0:attach(ar,ar[sb].cf+ar[sa].cf,ar[sa].px,fc);sa++;sb++;
                    break;
            case 1:attach(ar,ar[sa].cf,ar[sa].px,fc);sa++;
                    break;
        }
    }
    for(;sa<=fa;sa++)
    attach(ar,ar[sa].cf,ar[sa].px,fc);
    for(;sb<=fb;sb++)
    attach(ar,ar[sb].cf,ar[sb].px,fc);
}
int compare(int i,int j)
{
    if(i>j)
    return 1;
    else if(i==j)
    return 0;
    else
    return -1;
}
void attach(term ar[],int cf,int px,int* fc)
{
    ar[*fc].cf=cf;
    ar[*fc].px=px;
    (*fc)++;
}
void display(term ar[], const int s, const int e)
{
    for (int i = s; i <= e; i++)
    {
        printf("%dX^%d+", ar[i].cf, ar[i].px);
    }
    printf("\b ");
}
