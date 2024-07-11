#include <stdio.h>
#include <string.h>
/*int main()
{
char a[100];
gets(a); // abcd p q
printf("%s\n",a); // abcd p q
return 0;
}*/
int main()
{
    char a[100], ch;
    int i = 0;
    ch = getchar();
    while (ch != '\n')
    {
        a[i] = ch;
        i++;
        ch = getchar();
    }
    a[i] = '\0';
    printf("%s\n", a);
    return 0;
}
