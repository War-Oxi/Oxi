#include <iostream>
using namespace std;

void getTime(int &hour1, int &hour2, int &min1, int &min2, int &hour, int &min){
    min += min1 + min2;
    if(min > 60){
        hour += min / 60;
        min %= 60;
    }

    hour += hour1 + hour2;

    if(hour > 12){
        hour = hour % 12;
        if(hour == 0)
            hour = 12;
    }
    cout << hour << " " << min << endl;
}


int main() {
    int test_case;
    cin >> test_case;

    for(int i=1; i<=test_case; i++){
        int hourArr[2], minArr[2], hour(0), min(0);
        cin >> hourArr[0] >> minArr[0] >> hourArr[1] >> minArr[1];
        cout << "#" << i << " ";
        getTime(hourArr[0], hourArr[1], minArr[0], minArr[1], hour, min);
    }
    return 0;
}
