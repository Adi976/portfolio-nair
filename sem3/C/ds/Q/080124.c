#include<stdio.h>
#include<stdlib.h>
#define MS 4
typedef struct 
{
   int Q[MS];
   int r,f;
}Queue;
void insert(Queue* );
void delete(Queue *);
void display(const Queue *);
int main()
{
    Queue p={.r=-1,.f=0};
    insert(&p);
    delete(&p);
    display(&p);
    return 0;
}
void insert(Queue* p)
{
    if(p->r==MS-1)
    {
        printf("Queue Overflow\n");
        exit(0);
    }
    (p->r)++;
    printf("Enter an element\n");
    scanf("%d",&p->Q[p->r]);
}
void delete(Queue *p)
{
        if(p->f>p->r)
        {
            printf("Queue Underflow\n");
            exit(0);
        }
        (p->f)++;
}
void display(const Queue *p)
{
    for(int i=p->f;p->f<p->r;i++)
    printf("%d",p->Q[i]);
}
