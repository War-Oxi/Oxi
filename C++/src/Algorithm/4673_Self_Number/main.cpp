#include <iostream>
#include <memory.h>

using namespace std;

int selfNumber(int param_num);

int main() {
    bool self_numbers[10001];
    memset(self_numbers, true, sizeof(self_numbers));
    int param_num(0);

//    while(selfNumber(param_num) < 10000){
//        self_numbers[selfNumber(param_num)] = false;
//        param_num++;
//    }

    while(param_num <= 10000){
        if(selfNumber(param_num)<=10000)
            self_numbers[selfNumber(param_num)] = false;
        param_num++;
    }

    int cnt(0);
    while(cnt <= 10000){
        if(self_numbers[cnt]){
            cout << cnt << endl;
        }
        cnt++;
    }

    return 0;
}

int selfNumber(int param_num){
    int self_num(param_num);

    while(param_num > 0) {
        self_num += param_num % 10;
        param_num /= 10;
    }

    return self_num;
}