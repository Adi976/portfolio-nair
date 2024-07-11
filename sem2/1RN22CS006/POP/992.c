
/*10. Implement structures to read, write, and compute average- marks and the students
scoringabove and below the average marks for a class of N students

#include<stdio.h>
struct student{
    char name[20];
    char usn[10];
    int marks;
};
typedef struct student std;
int main()
{
    int n,c=0,m=0,avg=0,ab=0,bb=0;
    printf("Enter the number of students\n");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        std s;c++;
        printf("Enter the name of the student\n");
        scanf("%s",&(s.name));
        printf("Ent usn\n");
        scanf("%s",&(s.usn));
        printf("Enter marks\n");
        scanf("%d",&(s.marks));
        m+=s.marks;
        if(s.marks>avg)
        {
            ab++;
        }
        else
        {
            bb++;
        }
        avg=m/c;
    }
    printf("Ab avg:%d\n",ab);
    printf("Bel avg:%d\n",bb);
}*/

/*
Develop a program using pointers to compute the sum, mean and standard deviation of all
elements stored in an array of N real numbers
Find the mean (average) of the 10 numbers using the method described above.
For each number, subtract the mean from that number to find the "deviation" of each number from the mean.
Square each of these deviations.
Find the mean (average) of the squared deviations.
Take the square root of this mean to find the standard deviation.*/

#include<stdio.h>
#include<math.h>
int main()
{
    int a[10];
    int n,sum=0,mean=0,d=0,md=0,sd=0,std=0;
    printf("Enter array size\n");
    scanf("%d",&n);
    printf("Enter the elements of the array\n");
    for(int i=0;i<n;i++)
    {
        printf("Enter the element %d\n",i+1);
        scanf("%d",&(a[i]));
    }
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        mean=sum/(i+1);
        d=a[i]-mean;
        d*=d;
        sd+=d;
        sd=sqrt(sd/n);
    }
    printf("Sum:%d",sum);
    printf("Mean:%d",mean);
    printf("Standard deviation:%d",sd);
}