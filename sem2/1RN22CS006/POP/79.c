#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    /*FILE *fp;
    char name[30];
    int rn;
    fp = fopen("student.dat", "r");
    if (fp == NULL)
    {
        printf("File could not be opened\n");
        exit(1);
    }
    // 1st student's information
    printf("Reading name and roll number\n");
    fscanf(fp, "%s%d", name, &rn);

    printf("%s %d\n", name, rn);

    // 2nd student's information
    printf("Reading name and roll number\n");
    fscanf(fp, "%s%d", name, &rn);

    printf("%s %d\n", name, rn);
    fclose(fp);*/

    /*
    FILE *fp;
    char str[90];
    fp = fopen("student.dat", "r");
    if (fp == NULL)
    {
        printf("File could not be opened\n");
        exit(1);
    }

    while (fgets(str, 80, fp) != NULL)
        printf("%s%d\n", str, strlen(str));

    fclose(fp);
    */
    FILE *fp;
    char str[20], ch;
    int bytes_read;
    fp = fopen("student.dat", "r");
    if (fp == NULL)
    {
        printf("File could not be opened\n");
        exit(1);
    }
    bytes_read = fread(str, 1, 10, fp);
    // Into str 10 objects of 1 byte are read from the file pointed by fp

    str[bytes_read] = '\0';
    printf("Bytes read %d\n%s ", bytes_read, str);
    fclose(fp);

    return 0;
}
