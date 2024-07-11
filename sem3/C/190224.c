#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

struct node
{
    int vertex;
    struct node *link;
};
typedef struct node nd;

/*
 8
 2
 1 2
 3
 0 3 4
 3
 0 5 6
 2
 1 7
 2
 1 7
 2
 2 7
 2
 2 7
 4
 3 4 5 6
*/

#define FALSE 0
#define TRUE 1
int q[MAX_VERTICES];
int f = 0, r = -1;
short int visited[MAX_VERTICES] = {FALSE};
nd *a[MAX_VERTICES] = {0};
int n;
void Create_AL()
{
    FILE *fp;
    int no_of_nodes, i, j;
    nd *t, *r;
    fp = fopen("graph.txt", "r");
    fscanf(fp, "%d", &n);
    for (i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &no_of_nodes);
        r = 0;
        if (no_of_nodes == 0)
            a[i] = 0; // for leaf nodes graph G2 in page 267
        for (j = 0; j < no_of_nodes; j++)
        {
            t = (nd *)malloc(sizeof(nd));
            t->link = 0;
            fscanf(fp, "%d", &(t->vertex));
            if (a[i] == 0) // first node
                a[i] = t;
            else
                r->link = t;
            r = t;
        }
    }
}
void Disp_AL()
{
    int i;
    nd *t;
    for (i = 0, t = a[i]; i < n; i++, t = a[i])
    {
        printf("Vertex %d :", i);
        for (; t; t = t->link)
            printf("%d ", t->vertex);
        printf("\n");
    }
}
void DFS(int v)
{

    nd *w;
    visited[v] = TRUE;
    printf("%d ", v);
    for (w = a[v]; w; w = w->link)
        if (!visited[w->vertex])
            DFS(w->vertex);
}

void addq(int v)
{
    q[++r] = v;
}
int deleteq()
{
    return q[f++];
}

void BFS(int v)
{
    nd *w;//could be named curNode
    int i;
    for (i = 0; i < MAX_VERTICES; i++)
        visited[i] = FALSE;             //incase dfs set it to 1
    printf("%d ", v);
    visited[v] = TRUE;//the node from which the value has to be printed
    addq(v);//add it to the queue after it has been printed
    while (r >= f)
    {
        v = deleteq();//pop out the elements
        for (w = a[v]; w; w = w->link)//for terminates when next is NULL
            if (!visited[w->vertex])//visit check
            {
                printf("%d ", w->vertex);
                addq(w->vertex);
                visited[w->vertex] = TRUE;
            }
    }
}
int main()
{
    Create_AL();
    Disp_AL();
    printf("DEPTH FIRST SEARCH\n");
    printf("******************\n");
    DFS(0);
    printf("\nBREADTH FIRST SEARCH\n");
    printf("********************\n");
    BFS(0);
    return 0;
}
