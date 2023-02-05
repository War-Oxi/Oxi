/**
 * [1018]체스판 다시칠하기
 */
#include <iostream>

using namespace std;

int main(){
    char chess_board_1[8][8], chess_board_2[8][8];
    for(int i=0; i<8; i++){ //체스판 초기화 (시작이 W인 체스판이 chess_board_1 else chess_board_2)
        for(int j=0; j<8; j++){
            if(i%2==1){
                if(j%2==1){
                    chess_board_1[i][j] = 'W';
                    chess_board_2[i][j] = 'B';
                }
                else{
                    chess_board_1[i][j] = 'B';
                    chess_board_2[i][j] = 'W';
                }
            }
            else{
                if(j%2==1){
                    chess_board_1[i][j] = 'B';
                    chess_board_2[i][j] = 'W';
                }
                else{
                    chess_board_1[i][j] = 'W';
                    chess_board_2[i][j] = 'B';
                }
            }
        }
    }

    int row, column;
    cin >> row >> column;
    char input_chess_board[row][column];
    for(int i=0; i<row; i++){ //주어진 보드판 초기화
        for(int j=0; j<column; j++){
            cin >> input_chess_board[i][j];
        }
    }

    int min_count(222222);
    for(int i=0; i<=row-8; i++){ //다시 칠해야 하는 정사각형의 최소 개수 구하기
        for(int j=0; j<=column-8; j++){
        int count1(0), count2(0);
            for(int q=i; q<i+8; q++){
                for(int k=j; k<j+8; k++){
                    if(input_chess_board[q][k] != chess_board_1[q-i][k-j]){
                        count1++;
                    }
                    if(input_chess_board[q][k] != chess_board_2[q-i][k-j]){
                        count2++;
                    }
                }
            }
//            cout << count1 << " " << count2 << endl;
            if(count1 > count2)
                count1 = count2;
            if(count1 < min_count)
                min_count = count1;
        }
    }
    cout << min_count << endl;

    return 0;
}