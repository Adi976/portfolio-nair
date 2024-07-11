#include <stdio.h>
#include <string.h>
#define max 20
void search(char[][20], int, char[]);
void main()
{
    char string[max][20], t[20], word[20];
    int i, j, n;
    printf("Enter the number of words: \n");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter word:%d \n",i+1);
        scanf("%s", string[i]);
    }
    printf("Input words \n");
    for (i = 0; i < n; i++)
    {
        printf("%s\n", string[i]);
    }

    for (i =0; i < n; i++)
    {
        for (j = 0; j < n-1; j++)
        {
            if (strcmp(string[j], string[j+1]) > 0)
            {
                strcpy(t, string[j]);
                strcpy(string[j], string[j+1]);
                strcpy(string[j+1], t);
            }
        }
    }
    printf("Enter the element to be searched: \n");
    scanf("%s", word);
    search(string, n, word);
}
/* Binary searching begins */
void search(char string[][20], int n, char word[])
{
    int lb, mid, ub;
    lb = 0;
    ub = n;
    do
    {
        mid = (lb + ub) / 2;
        if ((strcmp(word, string[mid])) < 0)
            ub = mid - 1;
        else if ((strcmp(word, string[mid])) > 0)
            lb = mid + 1;
    } while ((strcmp(word, string[mid]) != 0) && lb <= ub);
    if ((strcmp(word, string[mid])) == 0)
        printf("SEARCH SUCCESSFUL \n");
    else
        printf("SEARCH FAILED \n");
}