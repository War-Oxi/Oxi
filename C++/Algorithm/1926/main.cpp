#include <iostream>
#include <stack>
#include <utility>
#include <algorithm>
#include <queue>

#define X first
#define Y second
#define endl "\n"

using namespace std;

//상 하 좌 우
int dx[4] = { 1, -1, 0 ,0 };
int dy[4] = { 0, 0, -1, 1 };

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int row, col;
  cin >> row >> col;

  int board[row][col];
  bool visit[row][col];


  for(int i=0; i<row; i++){
    fill(visit[i], visit[i]+col, false);
  }

  int tmp;
  for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
      cin >> tmp;
      board[i][j] = tmp;
    }
  }

  queue<pair<int, int>> Q;

  int max_area = 0;
  int pic_count = 0;

  for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
      int count(1);

      if(board[i][j] != 1)
        continue;

      if(!visit[i][j]){
        pic_count++;
      }

      visit[i][j] = 1;
      Q.push({i,j});

      while(!Q.empty()){
        pair<int, int> cur = Q.front();
        Q.pop();

//        cout << '(' << cur.X << ", " << cur.Y << ") -> ";

        for(int dir = 0; dir < 4; dir++){
          int cur_x = cur.X + dx[dir];
          int cur_y = cur.Y + dy[dir];
          if(cur_x < 0 || cur_y < 0 || cur_x >= row || cur_y >= col)
            continue;
          if(visit[cur_x][cur_y] || board[cur_x][cur_y] != 1)
            continue;
          count++;
          visit[cur_x][cur_y] = true;
          Q.push({cur_x, cur_y});
        }
      }
      if(count > max_area){
        max_area = count;
      }
    }
  }

//  cout << endl << endl;
//  for(int i = 0; i < row; i++){
//    for(int j = 0; j < col; j++){
//      cout << visit[i][j] << " ";
//    }
//    cout << endl;
//  }
  cout << pic_count << endl << max_area;

  return 0;
}
