#include<iostream>
using namespace std;
#include<cstring>
 
class student
{
	char name[20];
	char usn[10];
	int marks[3];
 
	public: void accept();
	int sort(const student&)const;
	void display();
};
 
int main()
{
	student* ar=NULL,temp;int n;
	cout<<"Enter the number of students"<<endl;
	cin>>n;
 
	while(ar==NULL)
	ar=new student[n];
 
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter details of student "<<i+1<<endl;
		ar[i].accept();
	}
 
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n-1;j++)
		{
			if(ar[j].sort(ar[j+1])>0)
			{
				temp=ar[j];
				ar[j]=ar[j+1];
				ar[j+1]=temp;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<"\nStudent "<<i+1<<":"<<endl;
		ar[i].display();
	}
 
 
}
void student::accept()
{
	cout<<"Enter name:"<<endl;
	cin>>name;
	cout<<"Enter USN:"<<endl;
	cin>>usn;
	for(int i=0;i<3;i++)
	{
		cout<<"Subject "<<i+1<<":"<<endl;	
		cin>>marks[i];
	}
}
int student::sort(const student& s)const
{
	return(strcmp(name,s.name));
}
 
void student::display()
{
	cout<<"\tName:"<<name<<endl;
	cout<<"\tUSN:"<<usn<<endl;
	for(int i=0;i<3;i++)
	{
		cout<<"\tSubject "<<i+1<<": "<<marks[i]<<endl;	
	}
}