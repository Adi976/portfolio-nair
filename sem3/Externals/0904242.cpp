// Program to find the sum and product of two matrices and store it in the third

#include <iostream>
using namespace std;

#define MAX 10

void accept(int **ar, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Column " << i + 1 << ":\n";
        for (int j = 0; j < n; j++)
        {
            cin >> ar[i][j];
        }
    }
}

void add(int **a, int **b, int **c, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void mul(int **a, int **b, int **c, int n)
{
    // Condition: mxn & nxp => mxp
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void display(int **ar, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ar[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int n;
    cout << "Enter Array Size:";
    cin >> n;
    int **a, **b, **c;
    a = new int *[n];
    b = new int *[n];
    c = new int *[n];
    for (int i = 0; i < n; ++i)
        a[i] = new int[n];
    for (int i = 0; i < n; ++i)
        b[i] = new int[n];
    for (int i = 0; i < n; ++i)
        c[i] = new int[n];
    cout << "Enter Array 1:\n";
    accept(a, n);
    cout << "Array A:\n";
    display(a, n);
    cout << "Enter Array 2:\n";
    accept(b, n);
    cout << "Array B:\n";
    display(b, n);
    cout << "Adding A&B:\n";
    add(a, b, c, n);
    display(c, n);
    cout << "Multiplying A&B:\n";
    mul(a, b, c, n);
    display(c, n);
    return 0;
}
