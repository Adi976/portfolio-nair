#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
void bfs(int, int, int[][SIZE], int[]);
int main()
{
    int n, amat[SIZE][SIZE], source, visited[SIZE], i, j;
    printf("Enter number of vertices:\n");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &amat[i][j]);
    printf("The adjacency matrix is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d\t", amat[i][j]);
        printf("\n");
    }
    printf("Give the source:\n");
    scanf("%d", &source);
    for (i = 0; i < n; i++)
        visited[i] = 0;
    bfs(n, source, amat, visited);
    for (i = 0; i < n; i++)
        if (visited[i] == 0)
            printf("%d is not reachable\n", i);
        else
            printf("%d is reachable\n", i);
    return 0;
}
void bfs(int n, int source, int amat[][SIZE], int visited[])
{
    int q[SIZE], r = 0, f = 0, u, v;
    visited[source] = 1;
    q[r] = source;
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
/*
The code is for implementing the Breadth First Search (BFS) algorithm on a given graph represented by an adjacency matrix.
 The BFS algorithm is used to traverse or search a graph in a systematic manner, starting from a given source vertex and visiting all its adjacent vertices before moving on to the next level of vertices.
 The first part of the code takes input from the user - number of vertices and the adjacency matrix representing the graph.
 It then prints out the adjacency matrix for reference.
 Next, it asks for the source vertex from where we want to start our BFS traversal.
 This will be used as an argument in calling the bfs() function.
 The bfs() function takes four arguments - n (number of vertices), source (starting vertex), amat (adjacency matrix) and visited array which keeps track of visited vertices.
 Initially, all elements in this array are set to 0 indicating that no vertex has been visited yet.
 Inside bfs(), we first mark our starting vertex as visited by setting its corresponding element in visited array to 1.
 Then, we use a queue data structure implemented using an array q[] with two variables r and f pointing to rear and front respectively.
 We enqueue our starting vertex into this queue.
 In each iteration, we dequeue one element from front end using f++ operation and assign it to variable u which represents current node being processed.
 We then check if any unvisited adjacent nodes exist for u by traversing through row u in adjacency matrix amat[][].
 If there exists such
 The code attempts to perform a breadth-first search on an adjacency matrix, starting from a given source vertex, and determine which vertices are reachable
 
  The code is used to implement the Breadth First Search (BFS) algorithm on a given graph represented by an adjacency matrix.
 The BFS algorithm is used to traverse or search through a graph in a systematic manner, starting from a given source vertex and visiting all its adjacent vertices before moving on to the next level of vertices.
 The first few lines of code are used for including necessary header files and defining constants such as SIZE which represents the maximum size of the adjacency matrix.
 Then, we have the function declaration for bfs() which takes in parameters such as number of vertices (n), source vertex (source), adjacency matrix (amat) and an array to keep track of visited vertices (visited).
 Moving on to main(), we start by taking user input for number of vertices and then creating an empty n x n adjacency matrix amat.
 We then take user input for each element in this matrix using nested loops.
 After printing out the entered values, we ask for user input again - this time asking them to specify the source vertex from where they want BFS traversal to begin.
 Next, we initialize another array called visited with all elements set to 0 indicating that no vertex has been visited yet.
 This array will be updated during execution of bfs() function.
 Inside bfs(), we start by marking our initial/source vertex as visited and adding it into a queue data structure q[].
 A queue works on FIFO principle i.e., first-in-first-out meaning that elements added first will also be removed first when dequeued later.
 We use two variables r and f representing rear end index and front end index respectively, both initialized at 0 initially since there's only one element in our queue currently - our source vertex.
 While loop runs until front end index becomes greater than rear end index indicating that there are no more unvisited adjacent nodes left.
 Inside while loop, variable u stores value at current front-end-index position inside q[] which gets incremented

 */
