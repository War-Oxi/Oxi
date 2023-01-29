#include <iostream>
using namespace std;


int main() {
    int switchNum;
    cin >> switchNum;

    int arrSwitch[switchNum+1];
    for(int i=1; i<=switchNum; i++){
        cin >> arrSwitch[i];
    }

    int studentNum;
    cin >> studentNum;


    for(int i=0; i<studentNum; i++){
        int option[2];
        cin >> option[0] >> option[1];

        if(option[0] == 1){ //남자일 때
            for (int i = option[1]; i <= switchNum; i += option[1]) {
                arrSwitch[i] = !arrSwitch[i];
            }
        }
        else{//option[0] != 1 //여자일 때
            int left = option[1] - 1;
            int right = option[1] + 1;
            arrSwitch[option[1]] = !arrSwitch[option[1]];
            while (left >= 1 && right <= switchNum) {
                if (arrSwitch[left] != arrSwitch[right]) {
                    break;
                }
                arrSwitch[left] = !arrSwitch[left];
                arrSwitch[right] = !arrSwitch[right];
                left--;
                right++;
            }
        }
    }

    for (int i = 1; i <= switchNum; i++) {
        cout << arrSwitch[i] << " ";
        if (i % 20 == 0) cout << "\n";
    }

    return 0;
}
