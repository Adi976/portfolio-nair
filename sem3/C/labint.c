// Polynomial add
#include <stdio.h>
#include <stdlib.h>
/*
typedef struct Term
{
    int xexp,yexp,zexp;
    int coeff;
    struct Term* next;
}Term;

int main()
{
    int ch;
    Term* poly_one=NULL,*poly_two=NULL,*res_poly=NULL;

    printf("Enter\n1.Insert\n2.Add\n3.Evaluate\n4.Display\n0.Exit\nChoice:");
    scanf("%d",&ch);
    printf("\n");
    switch(ch)
    {
        case 1:printf("Enter\n 1. Polynomial 1\n2.Polynomial 2\n");
            scanf("%d",&ch);
            if(ch==1)
                insert(&poly_one);
            else
                insert(&poly_two);
            break;
        case 2:add(&res_poly,&poly_one,&poly_two);
            break;
        case 3:printf("Enter\n1.Polynomial one\n2.Polynomial Two\n3.Resultant Polynomial\nChoice:");
            scanf("%d",&ch);
            if(ch==1)
                evaluate();
            else if(ch==2)
                evaluate();
            else
                evaluate();
            break;
        case 4:printf("Enter\n1.Polynomial one\n2.Polynomial Two\n3.Resultant Polynomial\nChoice:");
            scanf("%d",&ch);
            if(ch==1)
                display(poly_one);
            else if(ch==2)
                display(poly_two);
            else
                display(res_poly);
            break;
        case 0:printf("Simulation Over\n");
            exit(0);
        default:printf("Invalid Choice\n");
    }
    return 0;
}
*/

/*#define SIZE 20

void bfs(int n, int amat[][SIZE], int source, int visited[])
{
    int q[SIZE], f = 0, r = 0, u, v;
    visited[source], q[r] = source;

    while (f <= r)
    {
        u = q[f++];
        for (v = 0; v < n; v++)
        {
            if ((amat[u][v] == 1) & (visited[v] == 0))
            {
                q[++r] = v;
                visited[v] = 1;
            }
        }
    }
}
int main()
{
    int amat[SIZE][SIZE], source, visited[SIZE], n;
    printf("Enter number of vertices\n");
    scanf("%d", &n);
    printf("Enter the adjacency matrix\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &amat[i][j]);
        }
    }
    // print it

    printf("Give the source:\n");
    scanf("%d", &source);
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    bfs(n, amat, source, visited);
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
            printf("%d is not reachable\n", i);
        else
            printf("%d is reachable\n");
    }
    return 0;
}
*/

#define HZ 3

FILE *fp;

typedef struct emp
{
    int sal;
    char name[20];
    int empno;
}EMP;

typedef struct hash
{
    int key;
    long int addr;
}ht;


int hashVal(int num)
{
    int key;
    key=num%HZ;
    return key;
}

void search(FILE* fp,ht* h,int n)
{

}

void insert(FILE* fp,ht h[],int n)
{
    EMP a;int flag=0,hindex,countindex;
    for(int i=0;i<n;i++,flag=0)
    {
        printf("Enter name,empno and salary\n");
        scanf("%s%d%d",a.name,&a.empno,&a.sal);
        hindex=hashVal(a.empno);
        countindex=hindex;
        while(h[hindex].key!=-1)
        {
            hindex=(hindex+1)%HZ;
            flag=1;
            if(hindex==countindex)
            {
                printf("Entry not possible\n");
                return;
            }
        }
        h[hindex].key=a.empno;
        fseek(fp,0,SEEK_END);
        h[hindex].addr=ftell(fp);
        fprintf(fp,"%d%s%d",a.empno,a.name,a.sal);
        printf("Entry Successful\n");
        if(flag)
            printf("Linear Probing is used\n");
    }
}

int main()
{
    ht h[HZ];
    EMP d;
    int n, ch;
    fp = fopen("emp.txt", "w+");
    for (n = 0; n < HZ; n++) // assigning key to -1
        h[n].key = -1;
    for (;;)
    {
        printf("1. Insert\n2. Search\n3. Display\n4. Exit\nEnter choice ");
        scanf("%d", &ch);
        // rewind(fp);
        switch (ch)
        {
        case 1:
            printf("Enter no of employees\n");
            scanf("%d", &n);
            insert(fp, h, n);
            break;
        case 2:
            search(fp, h, n);
            break;
        case 3:
            display(fp, h, n);
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}