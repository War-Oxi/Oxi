// 11047_동전 0
#include <iostream>
#include <malloc.h>
using namespace std;

int Min_Coin_Calculator(const int *array, int array_size, int goal_money);

int main() {
    int coin_num(0), goal_money(0);
    cin >> coin_num >> goal_money;

    if(!(1 <= coin_num && coin_num <= 10)){
        cout << -1 << endl;
        return -1;
    }
    if(!(1 <= goal_money && goal_money <= 100000000)){
        cout << -2 << endl;
        return -2;
    }

    int *array = new int[coin_num];
    for(int i=0; i<coin_num; i++){
        cin >> array[i];
    }

    cout << Min_Coin_Calculator(array, coin_num ,goal_money) << endl;

    delete [] array;
    return 0;
}

int Min_Coin_Calculator(const int *array, const int array_size, int goal_money){
    int coin_count(0);
    int biggest_coin_index(-1);
    for(int i=array_size-1; i>=0; i--){
        if(array[i] <= goal_money){
            biggest_coin_index = i;
            break;
        }
    }

    while(goal_money != 0){
        if(goal_money >= array[biggest_coin_index]){
            coin_count += goal_money / array[biggest_coin_index];
            goal_money %= array[biggest_coin_index];
        }
        biggest_coin_index--;
    }

    return coin_count;
}
