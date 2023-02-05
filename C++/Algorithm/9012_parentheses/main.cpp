// [9012] 괄호

#include <iostream>
using namespace std;

void tester();

int main() {
    int repeat_num(0);
    cin >> repeat_num;
    while(repeat_num > 0){
        tester();
        repeat_num--;
    }

    return 0;
}

void tester(){
    string test_str;
    cin >> test_str;
    bool flag(true);
    int left_counter(0), right_counter(0);
    for(int i=0; i < test_str.length(); i++){
        if (test_str[i] == '(')
            right_counter++;
        else if (test_str[i] == ')')
            left_counter++;
        else
            continue;

        if(left_counter > right_counter) {
            flag = false;
        }
    }

    if(right_counter == left_counter && flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}