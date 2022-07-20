#include <iostream>

using namespace std;

int main(){
    cout << ((true && true ) || false) << endl;
    cout << true << endl;
    cout << ((false && true) || true) << endl;
    cout << true << endl;
    cout << ((false && true) || false || true) << endl;
    cout << true << endl;
    cout << ((14 > 13 || 2 > 1) && (9 > 1)) << endl;
    cout << true << endl;
    cout << (!(2314123 > 2 || 123123 > 2387)) << endl;
    cout << false << endl;

    return 0;
}