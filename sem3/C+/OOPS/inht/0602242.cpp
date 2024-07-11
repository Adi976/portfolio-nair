
#include<iostream>
using namespace std;


/*

//Program to simulate arithmetic operation on two numbers
class num1
{
    int x;
    public:
    num1()
    {}
    num1(int x1)
    {
        x=x1;
    }
    int getNum1()
    {
        return x;
    }
};

class num2
{
    int y;
    public:
    num2()
    {}
    num2(int y1)
    {
        y=y1;
    }
    int getNum2()
    {
        return y;
    }
};

class num3:public num1,public num2
{
    public:
    num3(int a,int b):num1(a),num2(b)
    {
    }
    void add()
    {
        cout<<"Sum="<<getNum1()+getNum2()<<endl;
    }
};

int main()
{
    int n1,n2;
    cout<<"Enter two numbers\n";
    cin>>n1>>n2;
    num3 one(n1,n2);
    one.add();
    return 0;
}
*/


//Same but using generic classes

//Program to simulate arithmetic operation on two numbers

#include<iostream>
using namespace std;

class num1
{
    int x;
    public:
    num1()
    {}
    num1(int x1)
    {
        x=x1;
    }
    int getNum1()
    {
        return x;
    }
};

class num2
{
    int y;
    public:
    num2()
    {}
    num2(int y1)
    {
        y=y1;
    }
    int getNum2()
    {
        return y;
    }
};

class num3:public num1,public num2
{
    public:
    num3(int a,int b):num1(a),num2(b)
    {
    }
    void add()
    {
        cout<<"Sum="<<getNum1()+getNum2()<<endl;
    }
};

int main()
{
    int n1,n2;
    cout<<"Enter two numbers\n";
    cin>>n1>>n2;
    num3 one(n1,n2);
    one.add();
    return 0;
}