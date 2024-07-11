/*#include <iostream>
using namespace std;

int main()
{
    // Create a stream
    cout << "Example 1:\n";

    // Original flags
    cout << "Original flags: " << cout.flags() << endl;

    // Set flags for scientific notation and fixed precision
    cout.setf(ios::scientific, ios::floatfield);
    cout.setf(ios::fixed, ios::floatfield);

    // New flags
    cout << "New flags: " << cout.flags() << endl;

    return 0;
}*/

#include <iostream>
using namespace std;

int main() {
    // Create a stream
    cout << "Example 2:\n";

    // Original flags
    cout << "Original flags: " << cout.flags() << endl;

    // Set flags for hex and uppercase
    cout.setf(ios::hex, ios::basefield);
    cout.setf(ios::uppercase, ios::uppercase);

    // New flags
    cout << "New flags: " << cout.flags() << endl;

    return 0;
}

