#include <iostream>
#include <algorithm>
using namespace std;

int row, col;
int board[10][10]; // CCTV와 벽의 위치를 위한 보드
int check_board[10][10]; // 사각지대의 숫자를 구하기 위한 보드
int min_value(0), cctv_num(0); // 최소값, cctv의 개수

int dx[4] = {-1, 0, 1, 0}; // ↓ → ↑ ←
int dy[4] = {0, 1, 0, -1};

void input(vector<pair<int, int>> &my_vec);
bool outChecker(int row_in, int col_in);
void observe(int row, int col, int dir);

int main() {
  cin >> row >> col;
  vector<pair<int, int>> cctv;
  input(cctv); // 보드 판 초기화

  for(int tmp = 0; tmp < (1 << (2*cctv.size())); tmp++){
    for(int i=0; i<row; i++){
      for(int j=0; j<col; j++){
        check_board[i][j] = board[i][j];
      }
    }

    int brute = tmp;
    for(int i=0; i<cctv.size(); i++){
      int dir = brute % 4;
      brute /= 4;

      int x = cctv[i].first;
      int y = cctv[i].second;

      if(board[x][y] == 1){
        observe(x, y, dir);
      }
      else if(board[x][y] == 2){
        observe(x, y, dir);
        observe(x, y, dir+2);
      }
      else if(board[x][y] == 3){
        observe(x, y, dir);
        observe(x, y, dir+1);
      }
      else if(board[x][y] == 4){
        observe(x, y, dir);
        observe(x, y, dir+1);
        observe(x, y, dir+2);
      }
      else if(board[x][y] == 5){
        observe(x, y, dir);
        observe(x, y, dir+1);
        observe(x, y, dir+2);
        observe(x, y, dir+3);
      }
    }
    int val = 0;
    for(int i=0; i<row; i++){
      for(int j=0; j<col; j++){
        if(check_board[i][j] == 0)
          val++;
      }
    }
    min_value = min(val, min_value);
  }

  cout << min_value;
  return 0;
}

void input(vector<pair<int, int>> &my_vec){
  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      cin >> board[i][j];
      if(board[i][j] == 1 || board[i][j] == 2 || board[i][j] == 3 || board[i][j] == 4 || board[i][j] == 5){
        my_vec.push_back(make_pair(i, j));
        cctv_num++;
      }
      else if(board[i][j]==0)
        min_value++;
    }
  }
}

bool outChecker(int row_in, int col_in){
  if(row_in < 0 || row_in >= row || col_in < 0 || col_in >= col || board[row_in][col_in] == 6)
    return false;
  else
    return true;
}

void observe(int row_in, int col_in, int dir){
  dir %= 4;
  while(true){
    row_in += dx[dir];
    col_in += dy[dir];
    if(!outChecker(row_in, col_in) || board[row_in][col_in] == 6) return;
    if(board[row_in][col_in] != 0) continue;
    check_board[row_in][col_in] = 7;
  }
}

/**
   * 1. BFS사용.
   *    -> if CCTV개수
   * 2. CCTV의 개수만큼 for문?
   * 3. if (cnt == CCTV개수) 현재 최소 사각지대 크기 비교. min_value = min(cnt, min_value)
   */
/**
 * 1. CCTV의 좌표, 번호, 방향을 저장
 *    Queue에 CCTV 하나씩 넣기 방향은 0~3
 * 2. dfs(x_pos, y_pos, direction)
 *    => 만약 현재 위치가 벽이거나 표의 바깥으로 나갈경우 멈춤. outChecker()사용
 * 3.
*/