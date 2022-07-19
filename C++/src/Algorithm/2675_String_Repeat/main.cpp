#include <iostream>
using namespace std;

int main() {
    int t(0);

    cin >> t;

    string s[t]; // S = 반복할 문자열
    int r[t]; // T = 테스트의 개수, R = 반복 횟수

    for(int i(0); i < t; i++){
        cin >> r[i] >> s[i];
    }

    for(int j(0); j < t; j++){
        int string_size = s[j].length();

        for(int l(0); l < string_size; l++){
            for (int k(0); k < r[j]; k++){
                cout<<s[j][l];
            }
        }

        cout<<endl;
    }

    return 0;
}
