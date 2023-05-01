#include <iostream>
#include <algorithm>
#include <queue>

#define x first
#define y second

using namespace std;

int board[1002][1002];
int dist[1002][1002];

int dx[4] = {1,-1,0, 0};
int dy[4] = {0,0, -1,1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int col, row;
  cin >> col >> row;

//  for(int i=0; i<row; i++) // dist 초기화
//    fill(dist[i], dist[i]+col, -1);

  queue<pair<int, int>> my_Q;

  for(int i=0; i<row; i++){ // board 초기화
    for(int j=0; j<col; j++){
      cin >> board[i][j];
      if(board[i][j] == 1)
        my_Q.push(make_pair(i,j));

      if(board[i][j] == 0)
        dist[i][j] = -1;
    }
  }
//  cout << my_Q.front().x << " " << my_Q.front().y;

  while(!my_Q.empty()){
    auto cur = my_Q.front();
    my_Q.pop();

    for(int i=0; i<4; i++){
      int tmp_x = cur.x + dx[i];
      int tmp_y = cur.y + dy[i];

      if(tmp_x < 0 || tmp_x >= row || tmp_y < 0 || tmp_y >= col)
        continue;
      if(dist[tmp_x][tmp_y] != -1)
        continue;

      dist[tmp_x][tmp_y] = dist[cur.x][cur.y] + 1;
      my_Q.push(make_pair(tmp_x, tmp_y));
    }
  }

  /**
   * check 저장될 때부터 토마토가 모두 익은 상태 => 0
   * 토마토가 모두 익지 못하는 상태 => -1
   * else => 최대 일수
   */

  int max_dist(0);

  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      if(board[i][j] == 0 && dist[i][j] == -1){ // 토마토가 모두 익지 못하는 상태
        cout << -1;
        return 0;
      }
      else{
        max_dist = max(max_dist, dist[i][j]);
      }
    }
  }

  cout << max_dist;

  return 0;
}
