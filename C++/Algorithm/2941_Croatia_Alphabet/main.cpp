/*
 * 백준 2941 [크로아티아 알파벳]
 * 1. string변수에 문자열을 입력받고 해당 문자열에 크로아티아 알파벳에 해당하는 문자가 등장하면 해당 글자 수에 따라 반복문의 i값을 정상보다 더 더해줌
 * 2. cnt 변수 출력
 */
#pragma once
#include <iostream>

using namespace std;

int main() {
    string croatia_word;
    cin >> croatia_word;

    if(croatia_word.length() > 100){
        return 0;
    }

    int cnt(0);

    for(int i=0; i<croatia_word.length(); i++) {
        cnt++;
        if (croatia_word[i] == 'c') {
            if (croatia_word[i + 1] == '=' || croatia_word[i + 1] == '-') {
                i++;
            }
        }
        else if (croatia_word[i] == 'd') {
            if (croatia_word[i + 1] == 'z' && croatia_word[i+2] == '='){
                i += 2;
            }
            else if(croatia_word[i + 1] == '-'){
                i++;
            }
        }
        else if (croatia_word[i] == 'l' && croatia_word[i+1] == 'j'){
            i++;
        }
        else if (croatia_word[i] == 'n' && croatia_word[i+1] == 'j'){
            i++;
        }
        else if (croatia_word[i] == 's' && croatia_word[i+1] == '='){
            i++;
        }
        else if (croatia_word[i] == 'z' && croatia_word[i+1] == '='){
            i++;
        }
    }

    cout << cnt << endl;
    return 0;
}
