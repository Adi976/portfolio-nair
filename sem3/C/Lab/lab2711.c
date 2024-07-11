#include <stdio.h>
#include<stdlib.h>
 
typedef struct student
{
	char* nm;
	char* usn;
	int* m;
}stud;
 
void create(stud**);
void read(stud**);
void sort_avgmarks(stud**);
void display(stud**);
 
int main()
{
	stud* p[2];
	//p=malloc(sizeof(stud*)*2);
	for(int i=0;i<2;i++)
	p[i]=malloc(sizeof(stud)*2);
 
	create(p);
	read(p);
	sort_avgmarks(p);
	/*sort_lexigo(p);
	free_func(p);*/
}
void create(stud** p)
{
 	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			p[i][j].nm=malloc(sizeof(char)*20);
			p[i][j].usn=malloc(sizeof(char)*10);
			p[i][j].m=malloc(sizeof(int)*1);
		}
	}
}
void read(stud** p)
{
	int c=0;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			c++;
			printf("Enter details of student %d\n", c);
			printf("Enter name:\n");
			scanf("%s",p[i][j].nm);
 
			printf("Enter USN\n");
			scanf("%s",p[i][j].usn);
 
			printf("Enter the marks of three subjects\n");
			for(int k=0;k<1;k++)
			{
				printf("Subject %d:",k+1);
				scanf("%d",&(p[i][j].m[k]));
				printf("\n");
			}
		}
	}
	printf("Pre-sorting the details are\n");
	display(p);
}
void sort_avgmarks(stud** p)
{
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<1;j++)
		{
			int m1=p[i][j].m[0];
			int m2=p[i][j+1].m[0];
			if(m1>m2)
			{
				char* tn;char* tusn;int tm[3];
				tn=(p[i][j].nm);
				tusn=(p[i][j].usn);
				for(int k=0;k<3;k++)
				tm[k]=p[i][j].m[k];
 
				//swapping p[i][j] with p[i][j+1]
				p[i][j].nm=p[i][j+1].nm;
				p[i][j].usn=p[i][j+1].usn;
				for(int k=0;k<3;k++)
				p[i][j].m[k]=p[i][j+1].m[k];
 
				//swapping p[i][j+1] with temp variables
				p[i][j+1].nm=tn;
				p[i][j+1].usn=tusn;
				for(int k=0;k<3;k++)
				p[i][j+1].m[k]=tm[k];
 
				char* t;
				t=(p[i][j].nm);
				(p[i][j].nm)=(p[i][j+1].nm);
				(p[i][j+1].nm)=t;
 
				/*printf("Address of p[%d][%d]=%x",i,j,&p[i][j]);
				printf("Address of p[%d][%d]=%x",i,j,&p[i][j+1]);
				stud* m1=&p[i][j];
				stud* m2=&p[i][j+1];
				stud*t=NULL;
 
				t=m1;
				m1=m2;
				m2=t;*/
			}
		}
	}
	printf("\nAfter sorting\n");
	display(p);
}
void display(stud** p)
{
	int c=0;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			c++;
			printf("\nStudent %d:\n",c);
			printf("\tName: %s\n",p[i][j].nm);
			printf("\tUSN: %s\n",p[i][j].usn);
			for(int k=0;k<1;k++)
			{
				printf("\tSubject %d: %d\n",k+1,(p[i][j].m[k]));
			}
		}
	}
}
/*int s1,s2;
			s1=(p[i][j].m[0]+p[i][j].m[1]+p[i][j].m[2])/3;
			s2=(p[i][j+1].m[0]+p[i][j+1].m[1]+p[i][j+1].m[2])/3;
			if(p[i][j+1].m[0]>p[i][j].m[0])
			{
 
				char* tn;char* tusn;int tm[3];
				tn=(p[i][j].nm);
				tusn=(p[i][j].usn);
				for(int k=0;k<3;k++)
				tm[k]=p[i][j].m[k];
 
				//swapping p[i][j] with p[i][j+1]
				p[i][j].nm=p[i][j+1].nm;
				p[i][j].usn=p[i][j+1].usn;
				for(int k=0;k<3;k++)
				p[i][j].m[k]=p[i][j+1].m[k];
 
				//swapping p[i][j+1] with temp variables
				p[i][j+1].nm=tn;
				p[i][j+1].usn=tusn;
				for(int k=0;k<3;k++)
				p[i][j+1].m[k]=tm[k];
 
				char* t;
				t=(p[i][j].nm);
				(p[i][j].nm)=(p[i][j+1].nm);
				(p[i][j+1].nm)=t;
			}
		}
		*/