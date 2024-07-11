#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent a max priority queue
typedef struct
{
    int elements[MAX_SIZE]; // Array to store elements
    int size;               // Current size of the priority queue
} MaxPriorityQueue;

// Function to swap two elements in the priority queue
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain the max heap property after inserting a new element
void heapifyUp(MaxPriorityQueue *pq, int index)
{
    int parent = (index - 1) / 2;
    while (parent >= 0 && pq->elements[parent] < pq->elements[index])
    {
        swap(&pq->elements[parent], &pq->elements[index]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

// Function to insert a new element into the max priority queue
void insert(MaxPriorityQueue *pq, int value)
{
    if (pq->size >= MAX_SIZE)
    {
        printf("Priority queue overflow!\n");
        return;
    }
    pq->elements[pq->size++] = value;
    heapifyUp(pq, pq->size - 1);
}

// Function to maintain the max heap property after deleting the root element
void heapifyDown(MaxPriorityQueue *pq, int index)
{
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int largest = index;

    if (leftChild < pq->size && pq->elements[leftChild] > pq->elements[largest])
    {
        largest = leftChild;
    }
    if (rightChild < pq->size && pq->elements[rightChild] > pq->elements[largest])
    {
        largest = rightChild;
    }
    if (largest != index)
    {
        swap(&pq->elements[index], &pq->elements[largest]);
        heapifyDown(pq, largest);
    }
}

// Function to delete and return the maximum element from the max priority queue
int deleteMax(MaxPriorityQueue *pq)
{
    if (pq->size == 0)
    {
        printf("Priority queue is empty!\n");
        return -1; // Return a sentinel value indicating an empty queue
    }
    int maxElement = pq->elements[0];
    pq->elements[0] = pq->elements[pq->size - 1];
    pq->size--;
    heapifyDown(pq, 0);
    return maxElement;
}

// Function to display the elements of the max priority queue
void display(MaxPriorityQueue *pq)
{
    printf("Max Priority Queue: ");
    for (int i = 0; i < pq->size; i++)
    {
        printf("%d ", pq->elements[i]);
    }
    printf("\n");
}

int main()
{
    MaxPriorityQueue pq = {{}, 0}; // Initialize an empty max priority queue

    // Insert elements into the max priority queue
    insert(&pq, 20);
    insert(&pq, 10);
    insert(&pq, 30);
    insert(&pq, 40);

    // Display the max priority queue
    display(&pq); // Output: Max Priority Queue: 40 30 10 20

    // Delete the maximum element from the max priority queue
    int maxElement = deleteMax(&pq);
    printf("Deleted Max Element: %d\n", maxElement); // Output: Deleted Max Element: 40

    // Display the max priority queue after deletion
    display(&pq); // Output: Max Priority Queue: 30 20 10

    return 0;
}
