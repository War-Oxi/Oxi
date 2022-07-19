#include <iostream>
using namespace std;

int main() {
    int e(1), s(1), m(1); // 초기 값
    int E(1), S(1), M(1); // 목표 값

    cin >> E >> S >> M;

    int year(1);

    while(true){
        if(e == E && s == S && m == M){
            break;
        }

        year++;

        e++;
        s++;
        m++;

        if(e==16){
            e=1;
        }
        if(s==29){
            s=1;
        }
        if(m==20){
            m=1;
        }
    }
    cout << year << endl;
    return 0;
}