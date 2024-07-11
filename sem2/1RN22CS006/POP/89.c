/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    /*FILE *fp;
    int i;
    char name[20];
    float salary;
    fp = fopen("Student.dat", "w");
    if (fp == NULL)
    {
        printf("File could not be created");
        exit(1);
    }
    for (i = 0; i < 2; i++)
    {
        fprintf(stdout, "Enter name\n");
        scanf(" %[^\n]s", name);
        fprintf(stdout, "Enter salary\n");
        scanf("%f", &salary);
        fprintf(fp, " (%d) NAME: %10s \t SALARY %5.2f\n", i, name, salary);
    }
    fclose(fp);*/

/*FILE *fp;
char f[200];
int count;
fp = fopen("contents.txt", "w");
if (fp == NULL)
{
    printf("\n file could not be opened\n");
    exit(1);
}
printf("Enter a sentence\n");
scanf("%[^\n]", f);
count = fwrite(f, 1, strlen(f), fp);
printf("\n %d bytes were written to the file", count);
fclose(fp);*/

/*FILE *fp;	char c;	int i;
fp=fopen("student.dat","r");
if (fp==NULL)
{ printf("\n file could not be opened\n");
exit(1);
}
while(1)
{
    c = fgetc(fp);
    if (c==EOF)
    break;
    printf("%c",c);
}
fclose(fp);*/

/*FILE *fp;
char s[100];
int i;
fp = fopen("student.dat", "r");
if (fp == NULL)
{
    printf("\n file could not be opened\n");
    exit(1);
}
while (1)
{
    fgets(s, 80, fp);
    printf("%s", s);
    if (feof(fp))
    {
        printf("\nEnd of file reached...\n");
        break;
    }
}
fclose(fp);*/
/*
FILE *fp;
int i, j;
fp = fopen("data.txt", "w");
// writing
printf("Enter an integer value\n");
scanf("%d", &i);
fwrite(&i, sizeof(int), 1, fp);
fclose(fp);
// reading
fp = fopen("data.txt", "r");
fread(&j, sizeof(int), 1, fp);
printf("Read value from bin file is %d\n", j);
fseek(fp, 0, SEEK_END);
int size=ftell(student.dat);
printf("Size:%d",size);
fclose(fp);*/
/*
FILE *fp;
int ar[20], n, i, b[20];
fp = fopen("student.txt", "w");

// Writing
printf("Enter value for n\n");
scanf("%d", &n);
printf("Enter %d values for array\n", n);
for (i = 0; i < n; i++)
    scanf("%d", &ar[i]);

fwrite(ar, sizeof(int), n, fp);
fclose(fp);

// Reading
fp = fopen("student.txt", "r");
fread(b, sizeof(int), n, fp);

printf("Array values are\n");
for (i = 0; i < n; i++)
    printf("%d\n", b[i]);
fclose(fp);

// Finding the file size
long file_size;
fp = fopen("student.txt", "rb"); // Open the file in binary read mode
if (fp == NULL)
{
    perror("Error opening the file");
    return 1;
}

fseek(fp, 0, SEEK_END); // Seek to the end of the file
file_size = ftell(fp);  // Get the current position, which is the file size
fclose(fp);

printf("File size: %ld bytes\n", file_size);
*/
#include <stdio.h>
#include <stdlib.h>
struct student
{
    char nm[20], usn[20];
    int m[3];
};
typedef struct student std;
int main()
{
    FILE *fp;
    int i, n;
    std ar[30], b[30];
    fp = fopen("data.txt", "w");
    // writing
    printf("Enter value for n\n");
    scanf("%d", &n);
    printf("Enter %d values for student array\n", n);
    printf("The format being s,s,d,d,d\n");
    for (i = 0; i < n; i++)
    {
        printf("Iteration: %d\n", i + 1);
        scanf("%s%s%d%d%d", ar[i].nm, ar[i].usn, &(ar[i].m[0]), &(ar[i].m[1]), &(ar[i].m[2]));
    }
    fwrite(ar, sizeof(std), n, fp);
    fclose(fp);
    // reading
    fp = fopen("data.txt", "r");
    fread(b, sizeof(std), n, fp);

    printf("Array values are\n");
    for (i = 0; i < n; i++)
    {
        printf("%s %s %d %d %d\n", ar[i].nm, ar[i].usn, ar[i].m[0], ar[i].m[1], ar[i].m[2]);
    }
    fclose(fp);
    long file_size = 0;
    fseek(fp, 0, SEEK_END); // Seek to the end of the file
    file_size = ftell(fp);  // Get the current position, which is the file size
    fclose(fp);

    printf("File size: %ld bytes\n", file_size);

    return 0;
}
