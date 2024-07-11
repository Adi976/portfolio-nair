#include<iostream>
using namespace std;

//WAP to overload << >> 
//Write a C++ program to find the sum of two numbers using friend
//Function.  Assume two variables are present in two different class.

// write a program in C++ to swap two variables of type complex and display the values before and
//s after swapping

class Base {
public:
    Base() {
        cout << "Base constructor called" << endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Derived constructor called" << endl;
    }
};

int main() {
    Derived obj;
    return 0;
}
