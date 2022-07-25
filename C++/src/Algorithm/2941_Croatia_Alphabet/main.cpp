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
