#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int r, c, v;
} Triplet;

void printTriplet(Triplet a[])
{
    printf("r c v\n");
    for (int i = 0; i <= a[0].v; i++)
    {
        printf("%d %d %d\n", a[i].r, a[i].c, a[i].v);
    }
}

void fastTranspose(Triplet a[], Triplet b[], int n)
{
    int numTerms = a[0].v, numColumns = a[0].c;
    int startingPos[n], rowTerms[n];
    b[0].r = a[0].c;
    b[0].c = a[0].r;
    b[0].v = a[0].v;

    // Initializing arrays
    for (int i = 0; i < n; i++)
        rowTerms[i] = 0;

    // Calculating rowTerms
    for (int i = 1; i <= numTerms; i++)
        rowTerms[a[i].c]++;

    // Calculating startingPos
    startingPos[0] = 1;
    for (int i = 1; i < numColumns; i++)
        startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];

    // Transposing
    for (int i = 1; i <= numTerms; i++)
    {
        int j = startingPos[a[i].c]++;
        b[j].r = a[i].c;
        b[j].c = a[i].r;
        b[j].v = a[i].v;
    }
}

int main()
{
    int n;
    printf("Enter value of n:");
    scanf("%d", &n);
    int ar[n][n];
    printf("Enter the Array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Column %d :\n", i + 1);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &ar[i][j]);
        }
    }
    printf("\nThe Array you entered:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", ar[i][j]);
        }
        printf("\n");
    }

    // Forming the triplets
    Triplet *a = malloc(sizeof(Triplet) * 10);
    int k = 1;
    a[0].r = a[0].c = n;
    a[0].v = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ar[i][j] != 0)
            {
                a[k].r = i;
                a[k].c = j;
                a[k].v = ar[i][j];
                a[0].v++;
                k++;
            }
        }
    }
    printf("\nThe Triplets:\n");
    printTriplet(a);
    Triplet *b = malloc(sizeof(Triplet) * 10);
    printf("Post-Transpose\n");
    fastTranspose(a, b, n);
    printTriplet(b);
    return 0;
}
