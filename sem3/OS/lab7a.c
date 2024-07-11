// PROGRAM: a) FIFO
#include <stdio.h>
void main()
{
    int i, j, k, f, pf = 0, count = 0, rs[25], m[10], n;//m for memory
    printf("\n Enter the length of reference string -- ");
    scanf("%d", &n);
    printf("\n Enter the reference string -- ");
    for (i = 0; i < n; i++)
        scanf("%d", &rs[i]);
    printf("\n Enter no. of frames -- ");
    scanf("%d", &f);
    for (i = 0; i < f; i++)
        m[i] = -1;
    printf("\n The Page Replacement Process is -- \n");
    for (i = 0; i < n; i++)
    {
        for (k = 0; k < f; k++)
        {
            if (m[k] == rs[i])
                break;
        }
        if (k == f)
        {
            m[count++] = rs[i];
            pf++;
        }
        for (j = 0; j < f; j++)
            printf("\t%d", m[j]);
        if (k == f)
            printf("\tPF No. %d", pf);
        printf("\n");
        if (count == f)
            count = 0;
    }
    printf("\n The number of Page Faults using FIFO are %d", pf);
}

/*
 The code starts by asking the user for the length of a reference string and then reads in each element of that string.
 It also asks for the number of frames, which is essentially how many pages can be stored in memory at once.
 Next, it initializes an array called "m" with -1 values.
 This will represent the frames in memory, and -1 indicates that they are currently empty.
 Then, it enters a loop to go through each element of the reference string.
 Within this loop, there is another loop to check if the current page being referenced is already present in one of the frames (represented by comparing its value to m[k]).
 If it is not found (k == f), then that means there was a page fault and we need to replace one of the existing pages with this new one.
 To do so, we use a counter variable "count" to keep track of which frame should be replaced next.
 We add 1 to count after every replacement so that it cycles through all available frames before starting over again from 0.
 After replacing or keeping all existing pages as necessary, we print out each frame's contents along with any relevant information such as whether or not there was a page fault on this iteration.
 Finally, outside both loops we print out how many total page faults occurred during this process using FIFO logic.
 The code is used to implement the first-in-first-out (FIFO) page replacement algorithm and calculate the number of page faults.
 
  The code is used to simulate the FIFO (First In First Out) page replacement algorithm.
 The program takes in a reference string, which represents the pages that are requested by the CPU.
 It also takes in the number of frames available for storing these pages.
 The first part of the code declares and initializes variables such as i, j, k, f, pf (page faults), count and rs (reference string).
 Then it prompts the user to enter the length of reference string and reads it into variable n using scanf().
 Next, it asks for each element of reference string from user and stores them in an array called rs[] using another scanf() function.
 Then it prompts for number of frames available and stores this value in variable f using scanf().
 After that a loop is started with i=0; i<n; i++ where n is length of reference string entered by user earlier.
 Inside this loop there's another loop with k=0; k<f; k++.
 This inner loop checks if current page referenced by CPU already exists inside frame or not.
 If yes then break out from inner loop otherwise continue checking next frame until all frames have been checked.
*/
