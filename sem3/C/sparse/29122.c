/*#include<stdio.h>
typedef struct term
{
    int r,c,v;
}T;
int main()
{
    T a[50];
    accept(a);
    display(a)
}*/
#include<stdio.h>
#include<time.h>

typedef struct {

    int row,col,value;
} T;
void accept(T*);
void accept(T*a)
{
    scanf("%d %d %d", &a[0].row, &a[0].col, &a[0].value);
    for(int i=1;i<=a[0].value;i++)
    {
        scanf("%d %d %d",&(a[i].row), &(a[i].col), &(a[i].value));
    }
}

void display(T * a)
{
    printf("\tRow\tColumn\tValue\n");
    for(int i=1;i<=a[0].value;i++)
    {
        printf("\t%d\t%d\t%d\n",a[i].row,a[i].col,a[i].value);
    }
    printf("\n");
}

/*void transpose(T * a, T * b)
{
    int added=1;

    b[0]=a[0];

    for(int j=0;j<a[0].col;j++)
    {
        for(int i=1; i<=a[0].value;i++)
        {
            if(a[i].col == j)
            {
                b[added].col=a[i].row;
                b[added].row=a[i].col;
                b[added].value=a[i].value;
                added++;
            }
        }
    }
}*/
void fastTranspose(T a[],T b[])
{
    int rowTerms[20]={0};
    int startingPos[20]={0};
    int i,j,numCols=a[0].col,numTerms=a[0].value;
    b[0].row=numCols;b[0].col=a[0].row;
    b[0].value=numTerms;

    if(numTerms>0)
    {
        for(i=1;i<=numTerms;i++)
        {
            rowTerms[a[i].col]++;
            startingPos[0]=1;
            for(i=1;i<numCols;i++)
            {
                startingPos[i]=startingPos[i-1]+rowTerms[i-1];

                for(i=1;i<numTerms;i++)
                {
                    j=startingPos[a[i].col]++;
                    b[j].row=a[j].col;
                    b[j].col=a[i].row;
                    b[j].value=a[i].value;
                }
            }
        }
    }
}
int main()
{
    T a[50], b[50];

    accept(a);
    display(a);
    display(b);

    return 0;
}