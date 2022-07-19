#include <iostream>
#include "memory.h"
using namespace std;

int main() {
    string exam_string;
    cin >> exam_string;

    for(int i = 0; i < exam_string.length(); i++){
        exam_string[i] = toupper(exam_string[i]);
    }

    if(exam_string.length() > 1000000){
        cout << "input_error" << endl;
        return 0;
    }

    int count[2]; //count[0] = temp,  count[2] = maxValue
    memset(count, 0, sizeof(count));
    count[1] = 1;

    char max_repeat_char;

    for(int i(0); i < exam_string.length(); i++){

        count[0] = 0;
        bool flag = true;

        for(int k(0); k < i-1; k++){
            if (i == 0){
                continue;
            }
            if(exam_string[k] == exam_string[i]){
                flag = false;
                break;
            }
            else{
                flag = true;
            }
        }

        if(!flag){
            continue;
        }

        for(int j(0); j < exam_string.length(); j++){
            if(exam_string[i] == exam_string[j]){
                count[0]++;
            }
        }
        if(count[0] > count[1]){
            count[1] = count[0];
            max_repeat_char = exam_string[i];
        }
        else if (count[0] == count[1]){
            cout << "?" << endl;
            return 0;
        }
    }

    cout << max_repeat_char << endl;

    return 0;
}
