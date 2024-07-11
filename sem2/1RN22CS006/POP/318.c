#include <stdio.h>
/*int main()
{
    char str[100];
    int i = 0;
    printf("Enter the string\n");
    gets(str); // enter is the terminator
    while (str[i] != '\0')
        i++;
    printf("Length of string is %d ", i);

int main()
{
    char str[100], upper_str[100];
    int i = 0, j = 0;
    printf("Enter a string\n");
    scanf("%[^\n]", str); // Delimiter is only \n and not <space>
    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            upper_str[j] = str[i] - 32;
        else
            upper_str[j] = str[i];
        i++;
        j++;
    }
    upper_str[j] = '\0';
    printf("Upper case string is: %s\n", upper_str);
    */
int main()
{
    char s1[100], s2[100], s3[100];
    int i = 0, j = 0;
    printf("Enter string s1 and s2\n");
    //scanf("%[^\n] %[^\n]", s1, s2);
    scanf("%[^\n]",s1);
    fflush(stdin);
    scanf("%[^\n]",s2);
    while (s1[i] != '\0')
    {
        s3[i] = s1[i];
        i++;
    }
    s3[i++] = ' ';
    while (s2[j] != '\0')
    {
        s3[i] = s2[j];
        i++;
        j++;
    }
    s3[i] = '\0';
    printf("Concatenated string is : %s\n", s3);
    return 0;
}

