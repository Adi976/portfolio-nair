#include<stdio.h>
#include<string.h>
/*struct student
{
    char nm[20];
    char usn[20];
    int m[3];
};
typedef struct student std;
int main()
{
    std s1;
    printf("Enter name and usn\n");
    scanf("%s%s",s1.nm,s1.usn);

    for(int i=0;i<3;i++)
    scanf("%d",&(s1.m[i]));

    printf("Name %s\n",s1.nm);
    printf("USN %s\n",s1.usn);

    for(int i=0;i<3;i++)
    printf("%d\n",s1.m[i]);

}*/
int main()
{
    char s1[]={"Aa"};
    char s2[]={"aaa"};
    printf("%d",strcmp(s1,s2));
}