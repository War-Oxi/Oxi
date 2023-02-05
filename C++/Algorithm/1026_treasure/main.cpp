//1026_보물
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int array_num(0);
    cin >> array_num;
    if(array_num > 50 || array_num < 0){ //예외 처리
        return 0;
    }
    int array_a[array_num], array_b[array_num];
    for(int i=0; i<array_num; i++){
        cin >> array_a[i];
        if(array_a[i] > 100 || array_a[i] < 0){ //예외 처리
            return 0;
        }
    }
    for(int i=0; i<array_num; i++){
        cin >> array_b[i];
        if(array_b[i] > 100 || array_b[i] < 0){ //예외 처리
            return 0;
        }
    }

    sort(array_a, array_a+array_num);

    int temp_array_b[array_num]; //배열array_b의 해당 인덱스의 값이 몇 번째로 큰 값인지 나열
    int temp2_array_b[array_num]; //배열temp_array_b를 구할 때 사용. 사용된 값은 -200으로 바꿈
    for(int i=0; i<=array_num-1; i++){
        temp2_array_b[i] = array_b[i];
    }

    int before_max_num(200);
    for(int i=0; i<=array_num-1; i++){
        int index(-1);
        int max_num(-1);
        for(int j=0; j<=array_num-1; j++){
            if(temp2_array_b[j] == -200){
                continue;
            }
            if(temp2_array_b[j] > max_num){
                max_num = temp2_array_b[j];
                index = j;
            }
        }
        before_max_num = max_num;
        temp_array_b[i] = index;
        temp2_array_b[index] = -200;
    }


    int temp_array_a[array_num];//array_a를 정렬할 때 사용
    for(int i=0; i<=array_num-1; i++){
        temp_array_a[temp_array_b[i]] = array_a[i];
    }
    for(int i=0; i<=array_num-1; i++){
        array_a[i] = temp_array_a[i];
    }

    int sum(0);
    for(int i=0; i<=array_num-1; i++){
        sum += array_b[i] * temp_array_a[i];
    }
    cout << sum << endl;

    return 0;
}
