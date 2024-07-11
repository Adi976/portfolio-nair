#include <iostream>
#include <stdlib.h>
using namespace std;
 
class student
{
	char name[20];
	char usn[10];
	int marks[3];
	public: void accept()
	{
		cout<<endl<<"Enter details of student "<<endl;
		cout<<"Enter name:"<<endl;
		cin>>name;
		cout<<"Enter usn:"<<endl;
		cin>>usn;
		cout<<"Enter marks:"<<endl;
		for(int i=0;i<3;i++)
		{
			cout<<"Subject"<<i+1<<":"<<endl;
			cin>>marks[i];
		}
	}
	void display()
	{
		cout<<"Name: "<<name<<endl;
		cout<<"USN: "<<usn<<endl;
		for(int i=0;i<3;i++)
		cout<<marks[i]<<endl;
	}
};
 
int main()
{
	student s[20];
	for(int i=0;i<3;i++)
		s[i].accept();
 
	for(int i=0;i<3;i++)
		s[i].display();
 
}
