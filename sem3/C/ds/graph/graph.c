#include<stdio.h>
#include<stdlib.h>
#define SIZE 20

void bfs(int n,int source,int amat[][SIZE],int visited[])
{
    int q[SIZE],r=0,f=0,u,v;
    visited[source]=1;
    q[r]=source;
    while(f<=r)
    {
        u=q[f++];
        for(v=0;v<n;v++)
        {
            if((amat[u][v]==1)&&(visited[v]==0))
            {
                q[++r]=v;
                visited[v]=1;
            }
        }
    }
}

int main()
{
    int n,amat[SIZE][SIZE],source,visited[SIZE],i,j;
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",amat[i][j]);
        }
        printf("\n");
    }
    printf("Give the source:\n");
    scanf("%d",&source);
    for(i=0;i<n;i++)
    {
        if(visited[i]==0)
            printf("%d is not reachable\n");
        else
            printf("%d is reachable\n");
    }
    return 0;
}
/*#include <stdio.h>
#include <stdlib.h>

// Using adjacency lists
#define MAX_VERTICES 50

typedef struct node
{
    int vertex;
    struct node *link;
} Node;

#define TRUE 1
#define FALSE 0
int q[MAX_VERTICES];
int f = 0, r = -1;
short int visited[MAX_VERTICES] = {FALSE};
Node *ar[MAX_VERTICES] = {0};
int n;

void createAL()
{
    int no_of_nodes;
    Node *temp, *r;
    printf("Enter number of entries\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter number of nodes:\n");
        scanf("%d", &no_of_nodes);
        r = 0;
        if (no_of_nodes == 0)
            ar[i] = 0; // for leaf nodes graph G2 in page 267
        for (int j = 0; j < no_of_nodes; j++)
        {
            temp = (Node *)malloc(sizeof(Node));
            temp->link = 0;
            printf("Enter Vertex:");
            scanf("%d", &(temp->vertex));
            printf("\n");
            if (ar[i] == 0) // first node
                ar[i] = temp;
            else
                r->link = temp;
            r = temp;
        }
    }
}

void dispAL()
{
    Node *temp=NULL;
    for (int i = 0, temp = ar[i]; i < n; temp = ar[i], i++)
    {
        printf("Vertex %d :", i);
        for (; temp; temp = temp->link)
            printf("%d ", temp->vertex);
        printf("\n");
    }
}
int main()
{

    return 0;
}*/