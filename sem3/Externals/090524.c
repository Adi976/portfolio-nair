#include<stdio.h>
#include<stdlib.h>

struct time
{
    int start;
    int end;
};

typedef struct time Time;

void display(Time list[],int n)
{
      for(int i=0;i<n;i++)
    {
        if(list[i].start!=0&&list[i].end!=0)
        printf("[%d,%d]\n",list[i].start,list[i].end);
    }
}
int main()
{
    /*Time input 
    3
    1 3
    6 9
    2 5
    */ 
    int n;
    scanf("%d",&n);
    Time list[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&list[i].start,&list[i].end);
    }

    //sort

    for(int i=0;i<n;i++)
    {
        if(list[i].start>list[i+1].start)
        {
            Time temp=list[i];
            list[i]=list[i+1];
            list[i+1]=temp;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(list[i].end>list[i+1].start)
        {
            //combine
            list[i].end=list[i+1].end;
            list[i+1].start=list[i+1].end=0;
        }
    }
    display(list,n);
    return 0;
}