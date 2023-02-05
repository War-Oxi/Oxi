#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    int Num[N];
    for(int i=0; i<N; i++){
        int tmp;
        cin >> tmp;
        Num[i] = tmp;
    }
    sort(Num, Num+N);

    int M;
    cin >> M;
    int tmp2;
    for(int i=0; i<M; i++){
        cin >> tmp2;
        if (binary_search(Num, Num+N, tmp2)){
            cout << "1\n";
        }
        else {
            cout << "0\n";
        }
    }
    return 0;
}
