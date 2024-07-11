//Sparse matrix in c!!
#include <stdio.h>
#include <stdlib.h>

#define MAX_COL 100

typedef struct
{
    int row;
    int col;
    int value;
} term;

int acceptArray(int **ar, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter Row %d: \n", i + 1);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &ar[i][j]);
            printf("\t");
        }
        printf("\n");
    }
}

void createTriplet(term *a, int **ar, int n)
{
    int ind = 1;
    a[0].row = n;
    a[0].col = n;
    a[0].value = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ar[i][j] != 0)
            {
                a[ind].row = i;
                a[ind].col = j;
                a[ind].value = ar[i][j];
                ind++;
                a[0].value++;
            }
        }
    }
}

void fastTranspose(term a[], term b[])
{
    int rowTerms[MAX_COL], startingPos[MAX_COL];
    int i, j, numCols = a[0].col, numTerms = a[0].value;
    b[0].row = numCols;
    b[0].col = a[0].row;
    b[0].value = numTerms;

    if (numTerms > 0)
    {
        for (i = 0; i < numCols; i++)
            rowTerms[i] = 0;

        for (i = 1; i <= numTerms; i++)
            rowTerms[a[i].col]++;

        startingPos[0] = 1;

        for (i = 1; i < numCols; i++)
            startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];

        for (i = 1; i <= numTerms; i++)
        {
            j = startingPos[a[i].col]++;
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].value = a[i].value;
        }
    }
}

void displayMatrix(int **ar, int n)
{
    printf("Original Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", ar[i][j]);
        }
        printf("\n");
    }
}

void displayTriplets(term ar[])
{
    printf("Triplets:\n");
    for (int i = 0; i <= ar[0].value; i++)
    {
        printf("(%d, %d, %d)\n", ar[i].row, ar[i].col, ar[i].value);
    }
}

int main()
{
    int **ar = NULL, n;
    term *a = NULL;
    term b[MAX_COL];

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Memory allocation for 2D array
    ar = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
        ar[i] = (int *)malloc(sizeof(int) * n);

    // Memory allocation for triplets array
    a = (term *)malloc(sizeof(term) * (n * n));

    printf("Enter a %dx%d matrix:\n", n, n);
    acceptArray(ar, n);

    printf("Creating Triplets\n");
    createTriplet(a, ar, n);

    fastTranspose(a, b);

    displayMatrix(ar, n);
    displayTriplets(a);

    printf("\nFast Transposed Matrix:\n");
    displayTriplets(b);

    // Free allocated memory
    for (int i = 0; i < n; i++)
        free(ar[i]);
    free(ar);
    free(a);

    return 0;
}
