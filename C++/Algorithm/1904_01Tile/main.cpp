#include <iostream>
using namespace std;

void printTileNum(int num){
    int *arr_tile = new int[num+1];
    arr_tile[0] = 0;
    arr_tile[1] = 1;
    arr_tile[2] = 2;
    arr_tile[3] = 3;

    for(int i=4; i<=num; i++){
        arr_tile[i] = (arr_tile[i-1] + arr_tile[i-2])%15746;
    }

    unsigned int result;
    if (arr_tile[num] % 15746 < 0)
        result = arr_tile[num] % 15746 * -1;
    else
        result = arr_tile[num] % 15746;
    cout << result << endl;

    delete[] arr_tile;
}


int main() {
    int N;
    cin >> N;
    printTileNum(N);

    return 0;
}
