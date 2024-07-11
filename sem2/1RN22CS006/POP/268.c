#include <stdio.h>
#include <string.h>
struct student
{
    char nm[20];
    char usn[20];
    int marks;
    struct student *ptr;
};
typedef struct student std;
const std s={"abc","1rn",35};
void accept(std[],int *);
void arrange_marks(std[], int *);
void arrange_name(std[] , int *);
void srch(std[],int*);
void display(std[],int *);
int main()
{
    //freopen("input.txt", "r", stdin);
    std s[50];int n;
    //printf("%d\n",sizeof(p));
    //printf("%d",sizeof(std));
    accept(s,&n);int ch=0;
    printf("Enter '0' for searching a particular USN, '1' for arranging wrt marks and '2' for arranging wrt names\n");
    printf("Enter choice:");
    scanf("%d",&ch);
    if(ch==1)
    {
    arrange_marks(s,&n);
    display(s,&n);
    }
    else if(ch==2)
    {
    arrange_name(s,&n);
    display(s,&n);
    }
    else
    {
        srch(s,&n);
        //display(s,&n);
    }
}
void accept(std s[],int *n)
{
    printf("Enter size of the array\n");
    scanf("%d",n);
    for(int i=0;i<*n;i++)
    {
        printf("\nSet:%d\n",(i+1));
        printf("Enter name:");
        scanf("%s",s[i].nm);
        printf("\nEnter usn:\n");
        scanf("%s",s[i].usn);
        printf("\nEnter marks:\n");
        scanf("%d",&s[i].marks);
    }
}
void arrange_marks(std s[], int *n)
{
    for(int i=0;i<*n;i++)
    {
        for(int j=0;j<*n-1;j++)
        {
            if (s[j].marks>s[j+1].marks)
            {
                int t=s[j].marks;
                s[j].marks=s[j+1].marks;
                s[j+1].marks=t;
            }
        }
    }
}
void arrange_name(std s[], int *n)
{
    for(int i=0;i<*n;i++)
    {
        for(int j=0;j<*n-1;j++)
        {
            if (strcmp(s[j].nm,s[j+1].nm)>0)
            {
                std t=s[j];
                s[j]=s[j+1];
                s[j+1]=t;

            }
        }
    }
}
void srch(std s[],int *n)
{
    printf("Enter the USN to be searched\n");
    char u[20];
    scanf("%s",&u);
    for(int i=0;i<=*n;i++)
    {
        if(strcmp(s[i].usn,u)==0)
        {
            printf("USN found at position %d",i);
            return;
        }
    }
    printf("USN not found\n");
}
void display(std s[],int *n)
{
    printf("\nName\n");
    for(int i=0;i<*n;i++)
    {
        printf("%s\n",s[i].nm);
    }
    printf("\nUSN\n");
    for(int i=0;i<*n;i++)
    {
        printf("%s\n",s[i].usn);
    }
    printf("\nMarks\n");
    for(int i=0;i<*n;i++)
    {
        printf("%d\n",s[i].marks);
    }
}

/*
#include <stdio.h>
void accept(int *, int *, int[][5]);
int main()
{
    int a[5][5], m, n, i, j;
    accept(&m, &n, a);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++) // 1
            printf("%d ", a[i][j]);
        printf("\n"); // 2
    }
    return 0;
}
void accept(int *m, int *n, int a[][5])
{
    int i, j;
    printf("Enter row-size and col-size \n");
    scanf("%d%d", m, n);
    printf("Enter %d X %d values for 2D array\n", *m, *n);
    for (i = 0; i < *m; i++)
        for (j = 0; j < *n; j++)
            scanf("%d", &a[i][j]);
}
/*
#include <stdio.h>
union point
{
    int x, y;
};
typedef union point pt;
int main()
{
    pt a = {1,2};
    pt b, c;
    printf("a= %d %d\n", a.x, a.y);
    b.x = 10;
    b.y = 20;
    printf("%d\n",sizeof(a));
    printf("%d\n",sizeof(b));
    printf("b= %d %d\n", b.x, b.y);
    scanf("%d%d", &(c.x), &(c.y));
    printf("c= %d %d\n", c.x, c.y);
    return 0;
}
*/