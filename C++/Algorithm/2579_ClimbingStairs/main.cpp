#include <iostream>
//#include <algorithm>

using namespace std;

void climbingStair(int num_stairs){
    int *stairs_arr = new int[num_stairs+1];
    for(int i=1; i<=num_stairs+1; i++){
        cin >> stairs_arr[i];
    }

    int *max_score_arr = new int[num_stairs+1];

    max_score_arr[1] = stairs_arr[1];
    max_score_arr[2] = stairs_arr[1] + stairs_arr[2];
    max_score_arr[3] = max(stairs_arr[1], stairs_arr[2]) + stairs_arr[3];

    for (int i=4; i<=num_stairs; i++) {
        max_score_arr[i] = std::max(max_score_arr[i-2], max_score_arr[i-3] + stairs_arr[i-1]) + stairs_arr[i];
    }

    cout << max_score_arr[num_stairs] << "\n";

    delete[] max_score_arr;
    delete[] stairs_arr;
}

int main() {
    int num_of_stair;
    cin >> num_of_stair;

    climbingStair(num_of_stair);
    return 0;
}
