/*#include <stdio.h>
int main()
{
    int s = 2, mid, l=0, h=9, a[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    mid = (l + h) / 2;
    int c = 0,ind=0;
    while ((mid <= h) && (mid >= l))
    {
        mid = (l + h) / 2;
        if (a[mid] == s)
        {
            c++;ind=mid;break;
        }
        else if (a[mid] < s)
            mid++;
        else
            mid--;
    }
    if (c == 0)
    printf("Value not found\n");
    else
    {
        printf("Value found at %d",ind);
    }
}

#include <stdio.h>
enum COLOR
{
    RED,
    BLACK,
    GREEN
};
typedef enum COLOR CR;
int main()
{
    CR C;
    printf("RED value is %d\n", RED);
    printf("BLACK value is %d\n", BLACK);
    printf("GREEN value is %d\n", GREEN);
    C = RED;
    printf("C variables value is %d\n", C);
    return 0;
}

#include <stdio.h>
//enum {OFF,ON};
const std s={"abc","1rn",35};
int main()
{
    
    //printf("%d",OFF);
}
*/