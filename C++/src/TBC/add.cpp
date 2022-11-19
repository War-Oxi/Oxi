#include <iostream>

using namespace std;

struct S{
    int a, b, c, d;
};

S getStruct(){
    S my_s{1, 2, 3, 4};
    return my_s;
}

int main(){
    S my_s = getStruct();
    cout << my_s.c << endl;

    return 0;
}