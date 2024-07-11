#include <stdio.h>
#include <string.h>
/*char *strcpy1(char *, const char *);
int main()
{
    char p[] = {"abc"};
    char *q = NULL;
    printf("working\n");
    q = strcpy1(q, p);
    printf("Q=%s\n", q);
    if (strcmp(p, q) == 0)
    printf("Equal\n");
    else
    printf("Not Equal\n");

    printf("Result=%x",":");
    printf("Result=%x","RNSIT");
}
char *strcpy1(char *dest, const char *src)
{
    int i = 0;

    for (; src[i] != '\0'; i++)
    {
        //printf("src[i]=%c",str[i]);
        dest[i] = src[i];
    }
    dest[i] = src[i];
    printf("In strcpy1 dest=%s\n", dest);
    return dest;
}*/
int main()
{
    /*char a[] = {"https://www.google.com"};//strtok makes substring of first occurence of delimiter from the beginning index
    printf("%s\n", a); // "//www.google.com"
    printf("%s\n", strtok(a,":")); // https
    printf("%s\n", strtok(NULL,".")); // //www
    printf("%s\n", strtok(NULL,".")); // google
    printf("%s\n", strtok(NULL,".")); // com*/

    /*Printing words of a sentence
    char a[]={"This is a sentence"};
    char* sub=NULL;int len=0;
    sub=strtok(a," ");
    printf("%s",sub);
    for(int i=0;i<strlen(a);i++)
    {
        sub=strtok(NULL," ");
        len+=strlen(sub);
        printf("%s",sub);
    }*/

    /*char a[] = {"https://www.google.com"}; // strtok makes substring of first occurence of delimiter from the beginning index
    int l=strlen(a);
    printf("%x\n", a);                     // "//www.google.com"
    printf("%x\n", strtok(a, ":"));        // https
    printf("%x\n", strtok(NULL, "."));     // //www
    printf("%x\n", strtok(NULL, "."));     // google
    printf("%x\n", strtok(NULL, "."));     // com
    printf("%s\n", a);
    for(int i=0;i<l;i++)
    printf("%c",a[i]);*/

    char *s="RNSIT";
    s[0]='r';
    
    printf("%s",s);
}