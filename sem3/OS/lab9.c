#include <stdio.h>
#include <stdlib.h>
//This C code simulates the allocation of blocks in a file system using the first-fit allocation technique. 
int main()
{
    int f[50], p, i, st, len, j, c, k, a, fn = 0;
    for (i = 0; i < 50; i++)
        f[i] = 0;
    /* printf("Enter how many blocks already allocated: ");
     scanf("%d", &p);
     printf("Enter blocks already allocated: ");
     for (i = 0; i < p; i++) {
         scanf("%d", &a);
         f[a] = 1;
     }*/
x:
    fn = fn + 1;
    printf("Enter index starting block and length: ");
    scanf("%d%d", &st, &len);
    k = len;
    if (f[st] == 0)
    {
        for (j = st; j < (st + k); j++)
        {
            if (f[j] == 0)
            {
                f[j] = fn;
                printf("%d-------->%d\n", j, f[j]);
            }
            else
            {
                printf("%d Block is already allocated \n", j);
                k++;
            }
        }
    }
    else
        printf("%d starting block is already allocated \n", st);
    printf("Do you want to enter more file(Yes - 1/No - 0)");
    scanf("%d", &c);
    if (c == 1)
        goto x;
    else
        exit(0);
    return 0;
}

/*
 The code starts by declaring an array of 50 elements called "f" which will be used to represent the blocks in the file system.
 Each element in this array represents a block, and its value will indicate whether that block is allocated or not.
 Next, the program asks for user input on how many blocks are already allocated and then prompts the user to enter those blocks.
 This information is stored in the first part of the array "f", with a value of 1 indicating that it is already allocated.
 Then, using a loop labeled as "x", the program continues to ask for user input on starting index and length until all desired files have been entered.
 The variable "fn" keeps track of which file number we are currently allocating blocks for.
 Inside this loop, if statement checks if the starting block (st) is available (has a value of 0).
 If it is available, another loop runs from st to st+k-1 (where k = len), checking each element in f along this range.
 If any element has a value other than 0, it means that particular block is already allocated so we increment k by one to account for this and continue checking until all required blocks are found.
 If there are no conflicts with existing allocations within our desired range, then we allocate these blocks by setting their values equal to fn (the current file number).
 After each allocation process finishes successfully or encounters an error due to conflicting allocations, there's an option given at line 35
 The code simulates the allocation of blocks in a file system using the first-fit allocation technique, where the user can input the starting block and length of a file and the code will allocate those blocks in the file system

  The code is used to simulate the allocation of blocks in a file system using the first-fit allocation technique.
 The code starts by declaring an array f[50] which will be used to store information about allocated and unallocated blocks.
 This array has 50 elements, each representing a block in the file system.
 Next, we initialize all elements of the array to 0 using a for loop.
 This indicates that all blocks are currently unallocated.
 The user is then prompted to enter how many blocks have already been allocated and their respective indices.
 These values are stored in variables p and a respectively.
 We then use another for loop to mark these allocated blocks as 1 in our f[] array.
 This means that these particular blocks are now marked as being occupied or unavailable for further allocation.
 Next, we move on to the main part of our code where we allocate new files using the first-fit technique.
 We start by incrementing fn (file number) by 1 since this is a new file being added.
 The user is prompted to enter the starting index and length of this new file they want to add into the system.
 These values are stored in variables st and len respectively.
 We check if there is any existing data at this starting index st by checking its corresponding element in our f[] array.
 If it's equal to 0, it means that this block is available for allocation so we proceed with allocating k (length) number of consecutive blocks starting from st.
 If however, there exists some data at index st (f[st] != 0), it means that this block has already been allocated so we need to find another available block before proceeding with allocating k more consecutive ones.
 To do this, we use another nested for loop which checks every subsequent element after st until k consecutive free spaces have been found.
 Once these free spaces have been found, they are marked as occupied or unavailable by assigning
 The code simulates the allocation of blocks in a file system using the first-fit allocation technique, where the user can enter the starting block and length of a file and the code will allocate blocks for that file until it reaches its desired length
 */