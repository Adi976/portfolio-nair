#include <stdio.h>
#include <string.h>
void concat(char* s,char* s1);
int main()
{
    char s[30],s1[30];int n;
    printf("enter two strings\n");
    scanf("%s",s);
    scanf("%s",s1);
    printf("Choose the operation to be performed from the options given below:\n");
    printf("1.concat\n 2.substring\n 3.To uppercase\n");
    scanf("%d",&n);
    if(n==1)
    {
        concat(s,s1);
    }
    /*else if(n==2)
    {substring(s);}
    else if(n==3)
    {toup(s);}*/
}
void concat(char* s,char* s1)
{
    //int sl=strlen(s);
    char c[60];int i=0,j=0;
    while(s[i]!='\0')
    {
        c[j++]=s[i];
        i++;
    }
    c[j++]=' ';
    i=0;
    while(s1[i]!='\0')
    {
        c[j++]=s1[i];
        i++;
    }
    c[j++]='\0';
    printf("%s",c);
}
