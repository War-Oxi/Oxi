#include <iostream>

using namespace std;

int main() {
    int nth_num(0); //N번째 영화
    int start_num(666), count(0);

    cin >> nth_num;

    while(true){
        int temp(start_num);

        while(temp>665){
            if(temp % 1000 == 666){
                count++;
                break;
            }
            temp /= 10; //1111666
        }
        if(count == nth_num){
            cout << start_num << endl;
            break;
        }
        start_num++;
    }
    return 0;
}
