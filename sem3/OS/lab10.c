#include <stdio.h>
//This C code implements the Shortest Seek Time First (SSTF) disk scheduling algorithm, which is used to optimize the movement of the disk arm in a disk I/O system
int main()
{
    int t[20], d[20], h, i, j, n, temp, k, atr[20], tot, p, sum = 0;
    printf("enter the no of tracks to be traveresed");
    scanf("%d'", &n);
    printf("enter the position of head");
    scanf("%d", &h);
    t[0] = 0;
    t[1] = h;
    printf("enter the tracks");
    for (i = 2; i < n + 2; i++)
        scanf("%d", &t[i]);
    for (i = 0; i < n + 2; i++)
    {
        for (j = 0; j < (n + 2) - i - 1; j++)
        {
            if (t[j] > t[j + 1])
            {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < n + 2; i++)
        if (t[i] == h)
        {
            j = i;
            k = i;
            p = 0;
        }
    
    while (t[j] != 0)
    {
        atr[p] = t[j];//actual track request
        j--;
        p++;
    }
    
    atr[p] = t[j];
    for (p = k + 1; p < n + 2; p++, k++)
        atr[p] = t[k + 1];
    printf("seek sequence is:");
    for (j = 0; j < n + 1; j++)
    {
        if (atr[j] > atr[j + 1])
            d[j] = atr[j] - atr[j + 1];
        else
            d[j] = atr[j + 1] - atr[j];
        sum += d[j];
        printf("\n%d", atr[j]);
    }
    printf("\nTotal head movements:%d", sum);
}

/*
 The code starts by asking the user for the number of tracks to be traversed and the initial position of the disk head.
 Then, it asks for the track numbers in a specific order.
 Next, it sorts these track numbers in ascending order using bubble sort algorithm.
 This is done because SSTF scheduling algorithm works best when tracks are arranged in increasing order.
 Then, it finds the index of initial position (h) in this sorted array and stores it as j and k variables.
 It also initializes an array called atr which will store the actual track requests that need to be serviced.
 Now, starting from j index (initial position), it moves backwards until reaching 0th index while storing each value into atr array.
 Then, starting from k+1 index (initial position + 1), it moves forwards until reaching n+2th index while storing each value into atr array.
 Finally, using a loop, it calculates and prints out the seek sequence by finding absolute difference between consecutive values stored in atr array.
 It also keeps a running total of these differences which represents total head movements required for servicing all requested tracks.
 Some relevant programming concepts used here include: - Arrays: The code uses arrays to store multiple values such as track numbers and actual track requests.
 - Sorting algorithms: Bubble sort algorithm is used to arrange track numbers in ascending order.
 - Looping: For loops are used extensively throughout the code to iterate over arrays or perform certain tasks repeatedly.
 - Conditional statements: If/else statement
 The code implements the Shortest Seek Time First (SSTF) disk scheduling algorithm to optimize the movement of the disk arm in a disk I/O system, by calculating the shortest seek time between tracks and minimizing the total head movements.
 
  The code is used to implement the Shortest Seek Time First (SSTF) disk scheduling algorithm, which is an optimization technique used in a disk I/O system.
 The goal of this algorithm is to minimize the movement of the disk arm and improve overall performance by selecting the next track that is closest to the current position of the head.
 The first part of the code includes necessary header files and initializes variables for tracks, distance, head position, number of tracks, temporary variable for swapping values, actual track request array (atr), total head movements (sum), and two counters i and j.
 Next, we prompt user input for number of tracks to be traversed and initial head position.
 Then we initialize t[0] as 0 since it represents starting point or origin on a graph.
 We also set t[1] equal to h because it represents current position or starting point for our calculations.
 After that, we ask user input for all other tracks using a loop until n+2 where n represents number of tracks entered by user earlier.
 This loop will store all track numbers in array t[].
 Then there's another nested loop which sorts elements in ascending order using bubble sort technique so that they can be easily accessed later during calculation process.
 Next step involves finding index value at which initial head position was stored earlier while sorting elements in ascending order.
 This index value will help us determine how many times we need to iterate through atr[] array when calculating seek sequence later on.
 Now comes one more important concept called Actual Track Request Array (atr).
 It stores actual sequence in which requests were made by users without any regard to their proximity with each other like sorted version does.
 So if you look closely at code inside while loop you'll see that initially j = i; k = i; p=0;.
 Here j & k are initialized with same value as 'i' because they represent indices from where iteration
 The code implements the Shortest Seek Time First (SSTF) disk scheduling algorithm, which optimizes the movement of the disk arm in a disk I/O system by selecting the closest track to the current position of the head and minimizing seek time.
 The code takes in user input for the number of tracks to be traversed, the initial position of the head, and the tracks to be accessed.
 It then calculates and prints out the seek sequence and total head movements required to access all tracks in an optimal manner.*/