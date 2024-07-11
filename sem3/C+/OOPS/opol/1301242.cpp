// Program to overload new and delete

#include <iostream>
#include <stdlib.h>

using namespace std;

void *operator new(size_t size)
{
    void *temp = NULL;
    while (temp == NULL)
        temp = malloc(size);
    return temp;
}
void operator delete(void *p)
{
    if (p != NULL)
        free(p);
}

int main()
{
    int *s = NULL;
    cout << "Pre-new" << s;
    s = new int;
    cout << "\nPost-new" << s;
    return 0;
}
