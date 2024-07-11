/*#include<stdio.h>
union sample
{
    int a;float b;char c;
};
typedef union sample sp;
int main()
{
    sp s;
    printf("Address a %x\n",&(s.a));
    printf("Address b %x\n",&(s.b));
    printf("Address c %x\n",&(s.c));
}*/

/*
#include <stdio.h>
struct a
{
    int marks;
    char name[20];
};
typedef struct a A;
struct b
{
    int marks;
    int roll_no;
};
typedef struct b B;
 union student
{
    A s1;
    B s2;
};
typedef union student st;
int main()
{
    st s;
    char ch;
    printf("Name or roll_no (N/R)\n");
    scanf("%c", &ch);
    if (ch == 'N')
    {
        printf("Enter name\n");
        scanf("%s", s.s1.name);
        printf("Enter marks\n");
        scanf("%d", &(s.s1.marks));
    }
    else
    {
        printf("Enter roll_no\n");
        scanf("%d", &(s.s2.roll_no));
        printf("Enter marks\n");
        scanf("%d", &(s.s2.marks));
    }
}
*/
#include <stdio.h>
struct student
{
    union nmro
    {
        char name[20];
        int roll_no;
    };
    union nmro nr;
    int marks;
};
typedef struct student std;
int main()
{
    std s;
    printf("Enter name\n");
    scanf("%s", s.nr.name);
    printf("Enter marks\n");
    scanf("%d", &(s.marks));
    printf("Name : %s\n", s.nr.name);
    printf("Marks : %d\n", s.marks);
    return 0;
}