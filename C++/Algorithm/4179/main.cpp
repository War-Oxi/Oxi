#include <iostream>
#include <queue>
#include <algorithm>
#define X first
#define Y second
using namespace std;

// 불이난 곳이 한 곳이 아닐 수도 있음.
string board[1002];
int dist_ji_hun[1002][1002];
int dist_fire[1002][1002];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int row, col;
  cin >> row >> col;
  cin.ignore();

  for(int i=0; i<row; i++){ // 지훈, 불 init
    fill(dist_ji_hun[i], dist_ji_hun[i]+col, -1);
    fill(dist_fire[i], dist_fire[i]+col, -1);
  }

  for(int i=0; i<row; i++){ //board 초기화
    getline(cin, board[i]);
  }

  queue<pair<int, int>> Q;

  //불의 dist 먼저 구하기
  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      if(board[i][j] == 'F'){
        dist_fire[i][j] = 0;
        Q.push(make_pair(i, j));
      }
    }
  }

  while(!Q.empty()){
    auto cur = Q.front(); Q.pop();

    int tmp_x, tmp_y;
    for(int i=0; i<4; i++){
      tmp_x = cur.X + dx[i];
      tmp_y = cur.Y + dy[i];

      if(tmp_x < 0 || tmp_x >= row || tmp_y < 0 || tmp_y >= col) continue;
      if(board[tmp_x][tmp_y] == '#' || dist_fire[tmp_x][tmp_y] != -1)continue;

      dist_fire[tmp_x][tmp_y] = dist_fire[cur.X][cur.Y] + 1;
      Q.push(make_pair(tmp_x, tmp_y));
    }
  }

  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      if(board[i][j] == 'J'){
        dist_ji_hun[i][j] = 0;
        Q.push(make_pair(i, j));
        break;
      }
    }
  }

  //지훈 dist 구하기
  while(!Q.empty()){
    auto cur = Q.front(); Q.pop();

    int tmp_x, tmp_y;
    for(int i=0; i<4; i++){
      tmp_x = cur.X + dx[i];
      tmp_y = cur.Y + dy[i];

      if(tmp_x < 0 || tmp_x >= row || tmp_y < 0 || tmp_y >= col){
        cout << dist_ji_hun[cur.X][cur.Y] + 1;
        return 0;
      }

      if(board[tmp_x][tmp_y] == '#' || dist_ji_hun[tmp_x][tmp_y] != -1)continue;
      if(dist_fire[tmp_x][tmp_y] <= dist_ji_hun[cur.X][cur.Y] + 1 && dist_fire[tmp_x][tmp_y] != -1){
        continue;
      }
      dist_ji_hun[tmp_x][tmp_y] = dist_ji_hun[cur.X][cur.Y] + 1;
      Q.push(make_pair(tmp_x, tmp_y));
    }
  }

  cout << "IMPOSSIBLE";

//  cout << endl;
//  for(int i=0; i<row; i++){
//    for(int j=0; j<col; j++){
//      cout << dist_ji_hun[i][j] << " ";
//    }
//    cout << endl;
//  }


  return 0;
}
