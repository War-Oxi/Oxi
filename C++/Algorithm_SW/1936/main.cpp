#include <iostream>
// 1 => 가위
// 2 => 바위
// 3 => 보

using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    if(A == 1){
        if(B == 2)
            cout << "B";
        else if(B == 3)
            cout << "A";
    }else if(A == 2){
        if(B == 1)
            cout << "A";
        else if(B == 3)
            cout << "B";
    }else{
        if(B == 1){
            cout << "B";
        }
        else if(B == 2){
            cout << "A";
        }
    }

    return 0;
}
