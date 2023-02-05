#pragma once
#include <iostream>
using namespace std;

void RecursionFunction(int repeat_num);
void InsertIndent(int repeat_num);

int main() {
    int repeat_num(0);
    cin >> repeat_num;
    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << endl;
    RecursionFunction(repeat_num);
    return 0;
}

void RecursionFunction(int repeat_num) {
    static int num(0);
    static bool flag(true);
    if(flag){
        InsertIndent(num);
        cout << "\"재귀함수가 뭔가요?\"" << endl;
        if(num != repeat_num){
            InsertIndent(num);
            cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어." << endl;
            InsertIndent(num);
            cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지." << endl;
            InsertIndent(num);
            cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"" << endl;
            if (num < repeat_num) {
                num++;
                RecursionFunction(repeat_num);
            }
        }
        else{ //num == repeat_num
            InsertIndent(num);
            cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"" << endl;
            flag = false;
            RecursionFunction(repeat_num);
        }
    }
    else{ //flag == false
        if (num >= 0){
            InsertIndent(num);
            cout << "라고 답변하였지." << endl;
            num--;
            RecursionFunction(repeat_num);
        }
    }
}

void InsertIndent(int repeat_num) {
    string indent = "____";
    if(repeat_num >= 1) {
        for (int i = 0; i < repeat_num; i++) {
            cout << indent;
        }
    }
}