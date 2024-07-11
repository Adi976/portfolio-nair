// Program to create namespaces
// Exception Handling
// Finding c++ version
#include <iostream>
#include <cstring>
using namespace std;

// Program to show that an object created in the try block is deallocated automatically once it exits the block
/*
class str1
{
public:
    str1()
    {
    }
    ~str1()
    {
        cout << "Destructor Called\n";
    }
};
int main()
{
    try
    {
        str1 obj;
        throw 100;
    }
    catch (int i)
    {
        cout << "In Catch Block" << '\n';
    }
}
*/

// Program to show that the throw statement can be called from a function called in the try block

/*
void callThrow()
{
    throw 100;
}
int main()
{
    try
    {
        callThrow();
    }
    catch(int i)
    {
        cout<<"In Catch Block" << '\n';
    }

    return 0;
}

*/

// Program to use classes that give detailed report about the exception being raised

/*
//Creating a class type exception, provides the programmer facility to create an object
// that well describes the error that has occurred. This information can be used by the
// exception handler to process the error.


class MyException
{
public:
    char str_what[80];
    int what;
    MyException() : what(0)
    {
        str_what[0] = 0;
    }
    MyException(char *s, int e) : what(e)
    {
        strcpy(str_what, s);
    }
};
int main()
{
    int i;
    char s[] = {"Not Positive"};
    try
    {
        cout << "Enter a positive number: ";
        cin >> i;
        if (i < 0)
            throw MyException(s, i);
    }
    catch (MyException e)
    {
        // catch an error
        cout << e.str_what << ": ";
        cout << e.what << "\n";
    }
    return 0;
}
*/

// Program to catch all exceptions

/*
// Here, the ellipsis matches any type of data.
#include <iostream>
using namespace std;
void Xhandler(int test)
{
    try
    {
        if (test == 0)
            throw test; // throw int
        if (test == 1)
            throw 'a'; // throw char
        if (test == 2)
            throw 123.23; // throw double
    }
    catch (...) // catch all exceptions
    {
        cout << "Caught One!\n";
    }
}
int main()
{
    cout << "Start\n";
    Xhandler(0);
    Xhandler(1);
    Xhandler(2);
    cout << "End";
    return 0;
}

*/

// Program to rethrow exceptions
/*
void xHandler()
{
    try
    {
        throw "Error";
    }
    catch (const char *desc)
    {
        cout << desc << '\n';
        throw "Error returns";
    }
}
int main()
{
    try
    {
        xHandler();
    }
    catch (const char *desc)
    {
        cout << desc << '\n';
    }
    return 0;
}
*/

// Finding out c++ version
/*
int main()
{
    if (__cplusplus == 202101L)
        std::cout << "C++23";
    else if (__cplusplus == 202002L)
        std::cout << "C++20";
    else if (__cplusplus == 201703L)
        std::cout << "C++17";
    else if (__cplusplus == 201402L)
        std::cout << "C++14";
    else if (__cplusplus == 201103L)
        std::cout << "C++11";
    else if (__cplusplus == 199711L)
        std::cout << "C++98";
    else
        std::cout << "pre-standard C++." << __cplusplus;
    std::cout << "\n";
}
*/

// Program to create namespaces

namespace mynamespace
{
    int i;
}
namespace mysecondnamespace
{
    int i;
}

int main()
{
    mynamespace::i = 1;
    mysecondnamespace::i = 2;
    cout << mynamespace::i;
    cout << "\nSecond:" << mysecondnamespace::i;
    return 0;
}