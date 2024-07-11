#include <iostream>
#include <stdlib.h>
using namespace std;
 
struct student
{
	char* name;
	char* usn;
	int* marks;
};
 
void accept(student []);
void display(const student []);
void create(student []);
 
int main()
{
	student *s;
	s=(student*)malloc(sizeof(student)*3);
	create(s);
	accept(s);
	display(s);
}
 
void create(student s[])
{
	for(int i=0;i<3;i++)
	{
		s[i].name=(char*)malloc(20*sizeof(char));
		s[i].usn=(char*)malloc(10*sizeof(char));
		s[i].marks=(int*)malloc(3*sizeof(int));
	}
}
 
void accept(student s[])
{
	cout<<"Enter the below mentioned details of three students"<<endl;
 
	for(int i=0;i<3;i++)
	{
		cout<<endl<<"Enter details of student "<<i+1<<endl;
		cout<<"Enter name"<<endl;
		cin>>s[i].name;
		cout<<"Enter usn"<<endl;
		cin>>s[i].usn;
	}
}
void display(const student s[])
{
	for(int i=0;i<3;i++)
	{
		cout<<endl<<"Student "<<i+1<<endl;
		cout<<"Name: "<<s[i].name<<endl;
		cout<<"USN: "<<s[i].usn<<endl;
	}
}
