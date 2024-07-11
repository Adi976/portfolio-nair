#include<stdio.h>
#include<stdlib.h>

typedef struct student
{
    char* nm;
    char *usn;
    int* m;

}stud;

int main()
{
    stud* p[3];

    for(int i=0;i<3;i++)
    {
        p[i]=malloc(sizeof(stud)*3);
    }

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            p[i][j].nm=malloc(sizeof(char)*20);
            p[i][j].usn=malloc(sizeof(char)*10);
            p[i][j].m=malloc(sizeof(int)*3);
        }
    }
    int c=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            c++;
            printf("Enter details of student %d\n",c);
            printf("Enter name\n");
            scanf("%s",p[i][j].nm);

            printf("Enter usn\n");
            scanf("%s",p[i][j].usn);
            
            printf("Enter marks of three subjects\n");
            for(int k=0;k<3;k++)
            {
                printf("Subject %d\n",k+1);
                scanf("%d",&(p[i][j].m[k]));
            }
        }
    }

    c=0;
    printf("\nThe entered details are as follows:\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            c++;
            printf("Details of student %d\n",c);
            printf("\tName \n",p[i][j].nm);
            printf("\tUSN \n",p[i][j].usn);
            for(int k=0;k<3;k++)
            {
                printf("Subject %d: %d",k+1,(p[i][j].m[k]));
            }
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            free(p[i][j].nm);
            free(p[i][j].usn);
            free(p[i][j].m);
        }
        free(p[i]);
    }
}