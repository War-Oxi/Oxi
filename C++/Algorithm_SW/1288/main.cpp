#include <iostream>
using namespace std;

bool checker_board[10] = {false, };


bool checkComplete();
void checker(int num_in);

int main() {
    int test_case, T;
    cin >> T;

    for(test_case=1; test_case<=T; test_case++){
        int first_num, count(1), cur_value;
        cin >> first_num;

        while(true){
            cur_value = first_num * count;
            checker(cur_value);
            if(checkComplete())
                break;

            count++;
        }

        cout << "#" << test_case << " " << cur_value << endl;
        for(auto & ele : checker_board)
            ele = false;
    }
    return 0;
}


bool checkComplete(){
    for(int i=0; i<=9; i++){
        if(!checker_board[i])
            return false;
    }
    return true;
}

void checker(int num_in){
    string tmp_str = to_string(num_in);
    for(char i : tmp_str){
        checker_board[i-48] = true;
    }
}
