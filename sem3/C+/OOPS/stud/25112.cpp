#include <iostream>
using namespace std;

class student
{
    public: char* nm,usn;
    int* marks; 
};

student* create(int &n);

int main()
{
    student* p=NULL;int n;
    p=create(n);

}
student* create(int &n)
{
    student* p=NULL;
    cin>>n;
    while(p==NULL)
    p=new student[n];
    static student*p1;
    return p;
}