#pragma once
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

bool tester(const int cur[2], const int next[2], bool chess[6][6]);

int main()
{
    bool chess[6][6]; //6*6 크기의 체스판 생성
    int start[2], cur[2], next[2]; //start[0] = x좌표 start[1] = y좌표
    string coordinate;

    cin >> coordinate; //입력 A2

    memset(chess, true, sizeof(chess));
 // x 0~5  y 0~5
    start[0] = coordinate[0] - 'A';
    start[1] = coordinate[1] - '1';

    cur[0] = start[0];
    cur[1] = start[1];

    int error(0);

    for (int i = 0; i < 35; i++){
        cin >> coordinate;

        next[0] = coordinate[0] - 'A';
        next[1] = coordinate[1] - '1';

        if (tester(cur, next, chess)){
            cur[0] = next[0];
            cur[1] = next[1];
            chess[cur[0]][cur[1]] = false;
        }
        else {
            error++;
        }
    }

    if(!tester(cur, start, chess)){
        error++;
    }

    if(error == 0) {
        cout << "Valid" << endl;
    }
    else{
        cout << "Invalid" << endl;
    }

    return 0;
}

bool tester(const int cur[2], const int next[2], bool chess[6][6]){

    int x_movement = cur[0] - next[0];
    int y_movement = cur[1] - next[1];

    if(abs(x_movement) == 1 && abs(y_movement) == 2 && chess[next[0]][next[1]]){
        return true;
    }
    else if (abs(x_movement) == 2 && abs(y_movement) == 1 && chess[next[0]][next[1]]){
        return true;
    }
    else{
        return false;
    }
}