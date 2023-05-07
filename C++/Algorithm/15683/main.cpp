#include <iostream>
#include <algorithm>
using namespace std;

int row, col;
int board[10][10]; // CCTV와 벽의 위치를 위한 보드
bool check_board[10][10]; // 사각지대의 숫자를 구하기 위한 보드
bool observe_board[10][10]; // 백트래킹을 위한 보드
int min_value(0), cctv_num(0);
/**
 * 0 -> 상
 * 1 -> 하
 * 2 -> 좌
 * 3 -> 우
 */
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input();
void observe();

int main() {
  cin >> row >> col;
  input(); // 보드 판 초기화

  return 0;
}

void input(){
  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      cin >> board[i][j];
      if(board[i][j] == 1 || board[i][j] == 2 || board[i][j] == 3 || board[i][j] == 4 || board[i][j] == 5){
        observe_board[i][j] = true;
        cctv_num++;
      }
    }
  }
}

void observe(){
  /**
   *
   */
}