#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
    /*char ms[]={"aababbabbaaab"},pat[]={"aab"};
    printf("Enter a string\n");
    scanf("%s",ms);
    printf("Enter the pattern to be searched\n");
    scanf("%s",pat);*/
    char* ms=NULL,*pat=NULL;
    ms=malloc(strlen(argv[1])+1);
    pat=malloc(strlen(argv[2])+1);
    strcpy(ms,argv[1]);strcpy(pat,argv[2]);
    char *ad=NULL;int c=0;
    for(ad=strstr(ms,pat);ad;ad=strstr(ad,pat))
    {
        c++;
        printf("Pattern found at index:%d\n",abs(ms-ad));
        ad+=strlen(pat);
    }
    if(c==0)
    printf("Pattern not found\n");
    return 0;
}