// Program to implement CQ using DMA
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 3

// Function prototypes
int *insertQ(int *, int *, int *, int *);
void deleteQ(int *, int *, int *);
void displayQ(int *, int, int);

int main()
{
    int *Queue = NULL;
    int ch, rear = -1, front = 0, count = 0;

    // Allocate memory for the queue
    Queue = (int *)malloc(sizeof(int) * INITIAL_SIZE);
    if (Queue == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("Simulation Begins!!\n");
    while (1)
    {
        printf("Enter\n'1' for Insert\n'2' for Delete\n'3' for Display\n'4' for Exit Simulation\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            Queue = insertQ(Queue, &rear, &front, &count);
            break;
        case 2:
            deleteQ(Queue, &front, &count);
            break;
        case 3:
            displayQ(Queue, front, count);
            break;
        case 4:
            printf("Simulation Over!!\n");
            exit(0);
        default:
            printf("Enter valid choice\n");
        }
    }
    return 0;
}

int *insertQ(int *Queue, int *rear, int *front, int *count)
{
    int ele;

    // Check for queue overflow
    if (*count == INITIAL_SIZE)
    {
        printf("Queue Overflow...\n");
        return Queue;
    }

    printf("Enter the element: ");
    scanf("%d", &ele);

    *rear = (*rear + 1) % INITIAL_SIZE;
    Queue[*rear] = ele;
    (*count)++;

    return Queue;
}

void deleteQ(int *Queue, int *front, int *count)
{
    // Check for queue underflow
    if (*count == 0)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Element deleted from circular queue is %d\n", Queue[*front]);
    *front = (*front + 1) % INITIAL_SIZE;
    (*count)--;
}

void displayQ(int *Queue, int front, int count)
{
    int i, j;

    if (count == 0)
    {
        printf("Circular Queue is empty\n");
        return;
    }

    printf("Circular Queue contents are\n");
    for (i = front, j = 0; j < count; j++)
    {
        printf("%d : %d\n", i, Queue[i]);
        i = (i + 1) % INITIAL_SIZE;
    }
}
