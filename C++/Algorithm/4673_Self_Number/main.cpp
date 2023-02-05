/*
 * 백준 4673 - 셀프 넘버
 * 1. 인자의 값에 인자의 값의 각 자리수를 더하는 함수를 만든다 (셀프 넘버가 아닌 숫자를 찾는데 사용)
 * 2. true로 초기화 된 boolean형 배열에 셀프 넘버가 아닌 숫자에 해당하는 인덱스를 false로 초기화 해준다.
 * 3. 반복문을 활용해 boolean형 배열의 값이 true에 해당 하는 값만 출력시킨다.
 */
#include <iostream>
#include <memory.h>

using namespace std;

int selfNumber(int param_num);

int main() {
    bool self_numbers[10001];
    memset(self_numbers, true, sizeof(self_numbers));
    int param_num(0);
    // 2. true로 초기화 된 boolean형 배열에 셀프 넘버가 아닌 숫자에 해당하는 인덱스를 false로 초기화 해준다.
    while(param_num <= 10000){
        if(selfNumber(param_num)<=10000)
            self_numbers[selfNumber(param_num)] = false;
        param_num++;
    }
    // 3. 반복문을 활용해 boolean형 배열의 값이 true에 해당 하는 값만 출력시킨다.
    int cnt(0);
    while(cnt <= 10000){
        if(self_numbers[cnt]){
            cout << cnt << endl;
        }
        cnt++;
    }
    return 0;
}
// 1. 인자의 값에 인자의 값의 각 자리수를 더하는 함수 (셀프 넘버가 아닌 숫자)
int selfNumber(int param_num){
    int self_num(param_num);

    while(param_num > 0) {
        self_num += param_num % 10;
        param_num /= 10;
    }
    return self_num;
}