#include <iostream>
#include "memory.h"
using namespace std;

int main() {
    string exam_string;
    cin >> exam_string;

    for(int i(0); i < exam_string.length(); i++){
        exam_string[i] = toupper(exam_string[i]);
    }

    if(exam_string.length() > 1000000){
        cout << "input_error" << endl;
        return 0;
    }

    int count(0);
    int max_count[2];
    memset(max_count, 0, sizeof(max_count));
    bool flag;

    char most_frequency_alphabet;

    for(int i(0); i < exam_string.length(); i++){
        int counter(0);

        if(most_frequency_alphabet == exam_string[i]){
            continue;
        }

        for(int j(0); j < exam_string.length(); j++){
            if(exam_string[i] == exam_string[j]){
                counter++;
            }
        }

        if(counter >= count){
            count = counter;
            if(flag){
                flag = !flag;
                max_count[0] = count;
            }
            else{
                flag = !flag;
                max_count[1] = count;
            }
            most_frequency_alphabet = exam_string[i];
        }
    }

    if(max_count[0] != max_count[1]){
        cout << most_frequency_alphabet << endl;
    }
    else{
        cout << "?" << endl;
    }

    return 0;
}
