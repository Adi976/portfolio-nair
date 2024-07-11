#include <iostream>
#include <string.h>
using namespace std;

/*
//1.Program to showcase ambiguity in case of diamond line inheritance
//POWSDM Constructors are not inherited

class parent
{
    int x;
    public:
    void display()
    {
        cout<<"In Parent Display\n";
    }
};

class child1:public parent
{
    int y;
};

class child2:public parent
{
    int z;
};

class grandchild:public child1,public child2
{
    int sum;
};

int main()
{
    grandchild obj;
    //obj.x;            //ambiguous
    //obj.display();    //ambiguous
    cout<<"Size of grandchild:"<<sizeof(obj)<<endl;
    return 0;
}
*/

/*
//2. Static data members and member functions in inheritance

class person
{
    char nm[20];
    long int ad_no;
    public:
    person(){}
    person(const person & p)
    {
        (*this)=p;
    }
    person(char* n,long int a)
    {
        strcpy(nm,n);
        ad_no=a;
    }
    void display()
    {

    }
};

class student:public person
{
    char usn[10];
    float m;
    public:
    student(){}
    //student(person &r,char *u,float m):person(r)
    student(char *n,long int a,char* u,float m):person(n,a)
    {
        strcpy(usn,u);
        this->m=m;
    }
    void display();
};

int main()
{
    //person p;
    student one("adi",9876,"rncs06",45.95);
    //student s(p,"cs06",123);
    one.display();
    return 0;
}
*/

// 3. Virtual classes to do away with ambiguity

class parent
{
    public:
    int x;
};

class child1 : virtual public parent
{
    public:
    int y;
};

class child2 : virtual public parent
{
    public:
    int z;
};

class grandchild : public child1, public child2
{
    public:
    int sum;
};

int main()
{
    grandchild obj;
    cout << "Size=" << sizeof(obj) << endl;
    obj.child1::x=10;
    cout<<"Child 2's x="<<obj.child2::x;
    return 0;
}