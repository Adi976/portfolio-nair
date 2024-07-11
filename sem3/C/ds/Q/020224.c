// Dynamic CQ
// balanced brackets
#include <stdio.h>
#include <stdlib.h>

int max = 4, cnt = 0;

void insertCQ(int **CQ, int *front, int *rear)
{
    if ((cnt) == max)
    {
        // Allocating twice the memory
        max = max * 2;
        (*CQ) = (int *)realloc((*CQ), sizeof(int) * max);
    }
    if (*front > *rear)
    {
        // rearrange the elements
        int *temp_ar = (int *)malloc(sizeof(int) * (cnt - (*front)));
        (*CQ) = (int *)realloc((*CQ) + (*front), sizeof(int) * max);
        // memcpy              //0 1 2  3  4 5 6
        int j = cnt - *front; // 5 6 1x 2x 3 4 5
        // front=3 rear=1
        for (int i = 0; i <= *rear; i++)
        {
            // rearranging
            (*CQ)[j++] = temp_ar[i];
        }
        *front = 0;
        *rear = cnt;
    }
    (*rear) = ((*rear) + 1) % max;
    printf("Enter Element:\n");
    scanf("%d", &(*CQ)[*rear]);
    cnt++;
}

void deleteCQ(int **CQ, int *front, int *rear)
{
    if (cnt == 0)
    {
        printf("C Queue is empty\n");
        return;
    }
    printf("Element deleted from circular queue is %d\n", (*CQ)[(*front)]);
    (*front) = ((*front) + 1) % max;
    cnt--;
}

void displayCQ(const int *CQ, const int front)
{
    int i, j;
    if (cnt == 0)
    {
        printf("Circular Queue is empty\n");
        return;
    }
    printf("Circular Queue contents are\n");
    for (i = front, j = 0; j < cnt; j++)
    {
        printf("%d : %d\n", i, CQ[i]);
        i = (i + 1) % max;
    }
}

int main()
{
    int *CQ = NULL, ch, front = 0, rear = -1;
    while (CQ == NULL)
        CQ = (int *)malloc(sizeof(int) * max);

    while (1)
    {
        printf("Enter\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertCQ(&CQ, &front, &rear);
            break;
        case 2:
            deleteCQ(&CQ, &front,rear);
            break;
        case 3:
            displayCQ(CQ, front);
            break;
        case 4:
            printf("CQ Simulation Over!!\n");
            exit(0);
            break;
        default:
            printf("Invalid Choice\n");
        }
    }
    return 0;
}