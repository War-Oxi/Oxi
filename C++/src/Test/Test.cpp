#include <iostream>
using namespace std;

int main(){
    int value = 4;
    int value3 = 6;
    int *const ptr = &value;
//    value = 8;
//    ptr = &value3;
//    *ptr = 6;

    cout << value << endl;
    cout << *ptr << endl;
    cout << endl;

    int value2 = 6;
    const int *ptr2 = &value2;
    value2 = 8;
//    *ptr2 = *value3;
    ptr2 = &value;
    cout << value2 << endl;
    cout << *ptr2 << endl;

    return 0;
}