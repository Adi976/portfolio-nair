// PROGRAM: b) LRU
#include <stdio.h>
int main()
{
    int i, j, k, min, rs[25], m[10], count[10], flag[25], n, f,
        pf = 0, next = 1;
    printf("Enter the length of reference string -- ");
    scanf("%d", &n);
    printf("Enter the reference string -- ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &rs[i]);
        flag[i] = 0;
    }
    printf("Enter the number of frames -- ");
    scanf("%d", &f);
    for (i = 0; i < f; i++)
    {
        count[i] = 0;
        m[i] = -1;
    }
    printf("\nThe Page Replacement process is -- \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < f; j++)
        {
            if (m[j] == rs[i])
            {
                flag[i] = 1;
                count[j] = next;
                next++;
            }
        }
        if (flag[i] == 0)
        {
            if (i < f)
            {
                m[i] = rs[i];
                count[i] = next;
                next++;
            }
            else
            {
                min = 0;
                for (j = 1; j < f; j++)
                    if (count[min] > count[j])
                        min = j;

                m[min] = rs[i];
                count[min] = next;
                next++;
            }
            pf++;
        }
        for (j = 0; j < f; j++)
            printf("%d\t", m[j]);
        if (flag[i] == 0)
            printf("PF No. -- %d", pf);
        printf("\n");
    }
    printf("\nThe number of page faults using LRU are %d", pf);
}
/*
 The code starts with the declaration of variables and arrays.
 The first for loop is used to initialize the flag array to 0, which will be used later to check if a page has been referenced before or not.
 Then, the user is prompted to enter the length of reference string and then asked to input each element of the reference string.
 Next, we ask for the number of frames that are available in memory.
 This represents how many pages can be stored in memory at once.
 The main part of this code is inside a nested for loop.
 The outer loop iterates through each element in the reference string while the inner loop checks if that particular page already exists in one of our frames (stored in array m).
 If it does exist, then we set its corresponding flag value as 1 and update its count value with next++.
 Next++ simply increments next by 1 every time it's called.
 If a page doesn't exist in any frame (flag[i] == 0), then we have a page fault (PF) and need to replace an existing page with this new one.
 We use another nested for loop here where we iterate through all our frames and find out which frame has been least recently used based on their count values.
 Once found, we replace that frame's content with our new page from rs[i].
 Finally, we increment PF by 1 since there was indeed a replacement made.
 After each iteration through both loops, we print out all current contents of our frames along with their respective counts using printf().
 If there was no replacement made during this iteration (flag[i] == 0), then PF No.-- <number> is also printed indicating how many total replacements were made so far.
 Once all iterations are complete, i.e., when i reaches n-1 where n = length_of_reference_string ,we exit both loops and print out "The number of faults using LRU are %
 The code is used to simulate the LRU (Least Recently Used) page replacement algorithm and outputs the number of page faults that occur during the process.*/