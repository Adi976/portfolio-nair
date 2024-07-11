#include<iostream>
using namespace std;

class A {
    int a, b;

public:
    void accept() {
        cin >> a >> b;
    }

    void display() {
        cout << a << b;
    }

    friend class B; // Declaring class B as a friend of class A
};

class B {
public:
    void accept(A &obj) { // Accepting object of class A as argument
        cin >> obj.a >> obj.b;
    }

    void display(A &obj) { // Displaying contents of object of class A
        cout << obj.a << obj.b;
    }
};

int main() {
    A objA;
    B objB;
    objB.accept(objA); // Calling accept function of class B with object of class A
    objB.display(objA); // Calling display function of class B with object of class A
    return 0;
}
