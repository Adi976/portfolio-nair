#include <stdio.h>
#include <string.h>
struct std
{
    char nm[3];
    char usn[3];
    int marks[3];
};
typedef struct std s;
int main()
{
    s o;
    char t[20];
    scanf("%s", o.nm);
    scanf("%s", o.usn);
    int k;
    k=sprintf(t,"%s",o.nm);
    k+=sprintf(t+k,"%s",o.usn);
    for (int i = 0; i < 3; i++)
    {
        //char g[3];
        scanf("%d",&(o.marks[i]));
        k+=sprintf(t+k,"%d",o.marks[i]);
        //printf("%d",i);
    }
    //sprintf(t,"%s%s%d%d%d",o.nm,o.usn,o.marks[0],o.marks[1],o.marks[2]);
    printf("%s",t);
    // char a[100] = {"C language"};
    /*printf("|%s|\n", a);
    printf("|%20s|\n", a);         // right justified
    printf("|%-20s|\n", a);        // left justified
    printf("|%.4s|\n", a);         // only 4 characters from begining
    printf("|%20.4s|\n", a);       // right justified with 4 char's from begining
    printf("|%-20.4s|\n", a);      // left justified with 4 char's from begining
    printf("|%*.*s|\n", 20, 4, a); // right justified with 4 char's from begining
    // First ‘*’ indicates width and second ‘*’ indicates precision.
    printf("%d",puts(a));
    int c=puts(a);

    int i = 0;
    printf("Number of characters printed %d\n\n", puts(a));
    printf("Printing string using putchar( )\n");
    while (a[i] != '\0')
    {
        putchar(a[i]);
        i++;
    }
    int i = 230;
    sprintf(a, "value of i is %d", i);
    printf("String in a which is %s\n", a);
    //printf("%d\n", k);
    //printf("%d",strcmp("adia","adi"));

/*
struct student
{
    char nm[20];
    char usn[20];
    int m[3];
};
typedef struct student std;
int main()
{
    /*char a[20];
    scanf("%4[a-z,A-Z]", a);
    printf("%s", a);
    char a[20] = {"12 45 60"};
    int i, j,k;
    sscanf(a, "%d%d%d", &i, &j,&k);
    printf("%d %d %d", i, j,k);
    
    char a[20] = {"abc 123 45 56 67"};
    std s;
    sscanf(a, "%s%s%d%d%d", s.nm, s.usn, &(s.m[0]), &(s.m[1]), &(s.m[2]));
    printf("%s %s %d %d %d", s.nm, s.usn, s.m[0], s.m[1], s.m[2]);
*/
    return 0;
}