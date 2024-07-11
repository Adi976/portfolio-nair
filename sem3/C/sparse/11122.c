#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int r, c, v;
} Terms;
void accept(int ***, int);
void display(int **, int);
void displayTerms(Terms *, int);
int countNonZero(int **, int);
void create(Terms[], const int **, const int);
void fastTranspose(Terms *, Terms *);
int main()
{
    int n;
    int **a;
    printf("Enter the size of the 2d array\n");
    scanf("%d", &n);
    a = (int **)malloc(sizeof(int) * (n));
    for (int i = 0; i < n; i++)
    {
        a[i] = (int *)malloc(sizeof(int) * n);
    }
    accept(&a, n);
    display(a, n);
    int c = countNonZero(a, n);
    Terms *ar, *br;
    ar = malloc(sizeof(Terms) * c);
    br = malloc(sizeof(Terms) * c);
    create(ar,a, n);
    fastTranspose(ar, br);
    displayTerms(ar, c);
}
void create(Terms ar[], const int **a, const int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
            {
                ar[i].r = i;
                ar[i].c = j;
                ar[i].v = a[i][j];
            }
        }
    }
}
void fastTranspose(Terms ar[], Terms br[])
{
}
void accept(int ***a, int n)
{
    printf("Enter the elements of the 2-d array\n");
    printf("Kindly note the array should have few non-zero elements\n");
    for (int i = 0; i < n; i++)
    {
        printf("Row %d\n", i + 1);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &(a[i][j]));
        }
    }
}
int countNonZero(int **a, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 0)
            {
                count++;
            }
        }
    }
}
void displayTerms(Terms *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\t%d\t%d\t%d\n", a[i].r, a[i].c, a[i].v);
    }
}
void display(int **a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d", (a[i][j]));
        }
        printf("\n");
    }
}
