#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#define X first
#define Y second

using namespace std;

int board[502][502];
bool visitBoard[502][502];
//좌 하 우 상
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int rowSize, colSize;
int maxNum(0), pictureNum(0);
void init();

void bfs(int y_pos, int x_pos){
  if(visitBoard[y_pos][x_pos] || board[y_pos][x_pos] == 0) return;
  pictureNum++;
  int cnt = 1;
  pair<int, int> cur;
  queue<pair<int, int>> Q;

  cur = make_pair(x_pos, y_pos);
  visitBoard[cur.Y][cur.X] = true;
  Q.push(cur);
  /**
   * 1. cur 에 시작 위치 저장.
   * 2. q에 cur위치 push
   * 3. while(!Q.empty())  ( BFS시작 )
   * 3.1
   */
   while(!Q.empty()){
     cur = Q.front(); Q.pop();

     for(int i=0; i<4; i++){
       int tmpX = cur.X + dx[i];
       int tmpY = cur.Y + dy[i];

       if(tmpX < 0 || tmpX >= colSize || tmpY < 0 || tmpY >= rowSize) continue;
       if(visitBoard[tmpY][tmpX] || board[tmpY][tmpX] == 0) continue;

       visitBoard[tmpY][tmpX] = true;
       Q.push(make_pair(tmpX, tmpY));
       cnt++;
     }
   }
  maxNum = max(maxNum, cnt);
}

int main() {
  cin >> rowSize >> colSize;

  init();
  for(int i=0; i<rowSize; i++)
    for(int j=0; j<colSize; j++)
      bfs(i, j);

//  cout << "\n";
//  for(int i=0; i<rowSize; i++){
//    for(int j=0; j<colSize; j++){
//      cout << visitBoard[i][j] << " ";
//    }
//    cout << "\n";
//  }
  cout << pictureNum << "\n" << maxNum;

  return 0;
}

void init(){
  for(int i=0; i<rowSize; i++){
    for(int j=0; j<colSize; j++){
      cin >> board[i][j];
    }
  }
}
