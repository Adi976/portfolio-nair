#include<iostream>
#include<string.h>
using namespace std;
class str
{
    char ar[20];
    public:void accept();
    void display();
    void concat(const str,const str);
};
int main()
{
    str s1,s2,s3;
    cout<<"Enter string 1\n";
    s1.accept();
    cout<<"Enter string 2\n";
    s2.accept();
    s3.concat(s1,s2);
    cout<<"The concated string is ";
    s3.display();
}
void str::accept()
{
    cin>>ar;
}
void str::concat(const str s1,const str s2)
{
    strcpy(this->ar,s1.ar);
    strcpy(this->ar+strlen(s1.ar),s2.ar);
}
void str::display()
{
    cout<<ar<<endl;
}