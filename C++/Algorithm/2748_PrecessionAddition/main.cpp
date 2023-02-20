#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int my_arr[N*2][M];

    for(int i=0; i<N*2; i++){
        for(int j=0; j<M; j++){
            cin >> my_arr[i][j];
        }
    }

    for(int i=N; i<N*2; i++){
        for(int j=0; j<M; j++){
            my_arr[i-N][j]+=my_arr[i][j];
            cout << my_arr[i-N][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
