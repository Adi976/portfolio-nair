void bfs(int source, int visited[], int amat[][20], int n)
{
    int q[n], f = 0, r = 0, u, v;
    visited[source] = 1;
    q[++r] = source;
    while (f < r)
    {
        u = q[f++];
        for (v = 0; v < n; v++)
        {
            if (amat[u][v] == 1 && visited[v] == 0)
            {
                visited[v] = 1;
                q[r++] = v;
            }
        }
    }
}
void dfs(int visited[], int source, int amat[][20], int n)
{
    visited[source] = 1;
    printf("%d ", source);
    for (int i = 0; i < n; i++)
    {
        if (amat[source][i] == 1 && visited[i] == 0)
        {
            dfs(visited, i, amat, n);
        }
    }
}
int main()
{
    int n;
    printf("Enter Number of vertices\n");
    scanf("%d", &n);
    int amat[n][n], source, visited[n];
    printf("Enter the Adjacency Matrix\n");
    for (int i = 0; i < n; i++)
    {
        printf("Row %d:", i + 1);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &amat[i][j]);
        }
        printf("\n");
    }
    printf("The Adjacency Matrix is\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", amat[i][j]);
        printf("\n");
    }
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    printf("Enter Source:");
    scanf("%d", &source);
    bfs(source, visited, amat, n);
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 1)
            printf("%d is visited\n");
        else
            printf("%d is not visited\n");
    }
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    dfs(visited, source, amat, n);
    return 0;
}