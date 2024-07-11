#include<stdio.h>
void acc(std[],int );
void display(std[],int );
 struct dob
 {
    int day,month,year;
 };
 struct student{
    char nm[20],usn[20];
    struct dob db;
    int marks;
 };
 typedef struct student std;
 int main()
 {
    std s[4];
    printf("Input the values\n");
    acc(s,4);
    display(s,4);
 }
 void acc(std s[],int n)
 {
    for(int i=0;i<3;i++)
    {
        printf("Enter name,usn,dob and marks respectively\n");
        scanf("%s",s[i].nm);
        scanf("%s",s[i].usn);
        scanf("%d%d%d",&(s[i].db.day),&(s[i].db.month),&(s[i].db.year));
        scanf("%d",&s[i].marks);
    }
 }
 void display(std s[],int n)
 {
    for(int i=0;i<2;i++)
    {
        printf("Name:%s\n USN:%s\n",s[i].nm,s[i].usn);
        printf("%d-%d-%d\n",s[i].db.day,s[i].db.month,s[i].db.year);
        printf("%d\n",s[i].marks);
    }
 }

