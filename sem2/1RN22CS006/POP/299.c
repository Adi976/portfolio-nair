#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* Develop a C program to concatenate 2 strings without using built-in function
void accept(char[], char[]);
void concat(char[], char[], char[]);
void display(char[]);
int main()
{
    char s1[10], s2[10], s[20];
    accept(s1, s2);
    concat(s1, s2, s);
    display(s);
}
void accept(char s1[], char s2[])
{
    printf("Enter two strings\n");
    printf("Enter 1st string\n");
    scanf("%s", s1);
    printf("Enter 2nd string\n");
    scanf("%s", s2);
}
void concat(char s1[], char s2[], char s[])
{
    int k = 0;
    for (int i = 0; i < strlen(s1); i++)
    {
        s[k++] = s1[i];
    }
    for (int i = 0; i < strlen(s2); i++)
    {
        s[k++] = s2[i];
    }
    s[k] = '\0';
}
void display(char s[])
{
    for (int i = 0; i < strlen(s); i++)
    {
        printf("%c", s[i]);
    }
    printf("2md method\n");
    printf("Using s %s", s);
}*/

// Write a C program to find the product of two given matrix
