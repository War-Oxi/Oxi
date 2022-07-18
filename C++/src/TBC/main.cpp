#include <iostream>

using namespace std;

int main()
{
    int a = 1, b = 10;
    int z;

    z = (a, a++ + b++);

    cout << z << endl;
    cout << a << endl;
    cout << b << endl;

    return 0;
}