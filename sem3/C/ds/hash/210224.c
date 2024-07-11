#include <stdio.h>

#define HZ 3
typedef struct
{
    int no;
    float sal;
    char name[10];
} EMP;

typedef struct
{
    int key;      // emp no
    long address; // offset
} Hash;

int hashVal(int num)
{
    int key;
    key = key % HZ;
    return key;
}

void insert(FILE *fp, Hash *table, int n)
{
    EMP a;
    int flag = 0;
    int hash_index, count_index;
    for (int i = 0; i < n; i++, flag = 0)
    {
        printf("Enter\n Employee Number:");
        scanf("%d", &(a.no));
        printf("\nName:");
        scanf("%s", a.name);
        printf("\nSalary:");
        scanf("%f", &(a.sal));
        printf("\n");
        hash_index = hashVal(a.no);
        count_index = hash_index;
        while(table[hash_index].key!=-1)    //checking whether hindex position in h is empty     
        {
            hash_index=(hash_index+1)%HZ;
            flag=1;
            if(hash_index==count_index)
            {
                printf("Entry not possible... \n");
                return;
            }
        }
        table[hash_index].key=a.no;
        fseek(fp,0,SEEK_END);//to make fp to point to the last bit
        table[hash_index].address=ftell(fp);
        fwrite(&a,sizeof(EMP),1,fp);
        fprintf(fp,"%d%s%d\n",a.no,a.name,a.sal);
        printf("Entry Successful\n");
        if(flag)
            printf("Linear Probing used\n");
    }
}

void search(FILE *fp,Hash *table)
{
    EMP a;
    int hash_index,count_index;

    printf("Enter Employee Number to be searched\n");
    scanf("%d",&(a.no));
    hash_index=hashVal(a.no);
    count_index=hash_index;

    while(table[hash_index].key!=a.no)
    {
        hash_index=(hash_index+1)%HZ;
        if(count_index==hash_index)
        {
            printf("Unsuccessful Search\n");
            return;
        }
    }
    printf("Search Successful!\n");
    fseek(fp,table[hash_index].address,SEEK_SET);

    fread(&a,sizeof(EMP),1,fp);
    fsacnf(fp,"%d%s%d",&(a.no),a.name,&(a.sal));
    printf("%d %s %d\n",a.no,a.name,a.sal);
}

void display()
{
}

int main()
{
    Hash table[HZ];
    EMP one;
    FILE *fp;
    int ch, n;
    fp = fopen("emp.txt", "w+");
    for (int i = 0; i < HZ; i++)
    {
        table[i].key = -1;
    }
    while (1)
    {
        printf("\nEnter\n1.Insert\n2.Search\n3.Display\n4.Exit\nChoice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter number of employees\n");
            scanf("%d", &n);
            insert(fp, table, n);
            break;
        case 2:
            search(fp, table);
            break;
        case 3:
            display(fp, table, n);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid Choice\n");
        }
    }
    return 0;
}