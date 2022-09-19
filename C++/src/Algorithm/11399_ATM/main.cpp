//11399_ATM
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int num_of_people(0), min_time(0), waiting_time(0);
    cin >> num_of_people;
    int *arr_withdrawal_speed = new int [num_of_people];

    for(int i=0; i<num_of_people; i++){
        cin >> arr_withdrawal_speed[i];
    }
    sort(arr_withdrawal_speed, arr_withdrawal_speed+num_of_people);

    for(int i=0; i<num_of_people; i++){
        if(i == 0){
            min_time += arr_withdrawal_speed[i];
        }
        else{
            waiting_time += arr_withdrawal_speed[i-1];
            min_time += waiting_time + arr_withdrawal_speed[i];
        }
    }

    cout << min_time;
    return 0;
}
