#include <stdio.h>
#include <stdlib.h>
 
typedef struct day
{
	char *name;
	int *date;
	char*desc;
} day;
 
#define MALLOC(p,s)\
	if(!(p=malloc(s))){\
	printf("Insufficient memory");\
	exit(0);}
 
void create(day[]);
void read(day[]);
void display(day[]);
 
int main()
{
	struct day * week;
 
	MALLOC(week,(sizeof(day)*7));
	//printf("DAY %ld\n",sizeof(day));
	create(week);
	read(week);
	display(week);
	return 0;
}
void create(day week[])
{
	for(int i=0;i<7;i++)
	{
		MALLOC(week[i].name,sizeof(char)*20);
		MALLOC(week[i].date,sizeof(int)*1);
		MALLOC(week[i].desc,sizeof(char)*20);
	}
}
void read(day week[])
{
	for(int i=0;i<7;i++)
	{
		printf("Enter the details of day %d\n",(i+1));
 
		printf("Enter the name of the day\n");
		scanf("%s",week[i].name);
 
		printf("Enter the date \n");
		scanf("%d",week[i].date);
 
		printf("Enter the description\n");
		scanf("%s",week[i].desc);
	}
}
void display(day week[])
{
	int option;
	printf("Enter the date\n");
	scanf("%d",&option);
 
	for(int i=0;i<7;i++)
	{
		if(option==*(week[i].date))
		{
			printf("Description %s\n",week[i].desc);
			//printf("Description %s\n",*(week[i].desc));
		}
	}
	free(week);
}
