//Program to implement CQ using DMA
//incmp
#include <stdio.h>
#include <stdlib.h>
int QS = 3;
int *insertQ(int *, int *, int *, int *);
void displayQ(int[], int, int);
void deleteQ(int[], int *, int *);
int main()
{
    int *Queue = NULL;
    int ch, rear = -1, front = 0;
    while (Queue == NULL)
        Queue = malloc(sizeof(int) * 3);
    printf("Simulation Begins!!\n");
    while (1)
    {
        printf("Enter\n'1' for Insert\n'2' for Delete\n'3' for Display\n'4' for Exit Simulation\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            Queue = insertQ(Queue, &rear, &front, &QS);
            break;
        case 2:
            deleteQ(Queue, &front, &QS);
            break;
        case 3:
            displayQ(Queue, front, QS);
            break;
        case 4:
            printf("Simulation Over!!\n");
            exit(0);
        default:
            printf("Enter valid choice\n");
        }
    }
}
int *insertQ(int *Queue, int *rear, int *front, int *n)
{
    int ele;
    int *p = Queue, i, j;
    if ((*n) == QS)
    {
        printf("Queue Overflow...\n");
        p = (int *)malloc(sizeof(int) * (*n) * 2);
        if (*rear > *front)
            p = realloc(Queue, sizeof(int) * 2);
        else
        {
            printf("Empty space at beginning of the queue\n");
            Queue = realloc(Queue + 1, sizeof(int) * 2);
            (*front) = 0;
            (*rear) = QS - 1;
            printf("After doubling and rearranging\n");
            for (i = 0; i < QS; i++)
                printf("%d ", Queue[i]);
            QS *= 2;
            p = Queue;
        }
    }
    (*rear) = ((*rear) + 1) % QS;
    printf("enter the ele\n");
    scanf("%d", &ele);
    Queue[*rear] = ele;
    (*n)++;
    return p;
}
void deleteQ(int q[], int *f, int *cnt)
{
    if ((*cnt) == 0)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Element deleted from circular queue is%d\n", q[(*f)]);
    (*f) = ((*f) + 1) % QS;
    (*cnt)--;
}
void displayQ(int q[], int f, int cnt)
{
    int i, j;
    if (cnt == 0)
    {
        printf("Circular Queue is empty\n");
        return;
    }
    printf("Circular Queue contents are\n");
    for (i = f, j = 0; j < cnt; j++)
    {
        printf("%d : %d\n", i, q[i]);
        i = (i + 1) % QS;
    }
}
