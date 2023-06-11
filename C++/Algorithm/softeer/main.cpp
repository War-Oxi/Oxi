#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>

#define X first
#define Y second

using namespace std;


int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1}; //상 우 하 좌
int N;

int **board;
bool **vis;
vector<int> myVec;
int areaCount(0);

int dfs(pair<int, int> start){
  auto cur = start;
  queue<pair<int, int>> Q;
  if(board[cur.X][cur.Y] != 1 || vis[cur.X][cur.Y] == true) return 0;


  vis[cur.X][cur.Y] = true;
  int size=1;
  Q.push(cur);

  while(!Q.empty()){
    cur = Q.front(); Q.pop();
    for(int i=0; i<4; i++){
      int tmpX = cur.X + dx[i];
      int tmpY = cur.Y + dy[i];

      if(tmpX < 0 || tmpY < 0 || tmpX >= N || tmpY >= N) continue;
      if(board[tmpX][tmpY] != 1 || vis[tmpX][tmpY] == true) continue;

      vis[tmpX][tmpY] = true;
      Q.push(make_pair(tmpX,tmpY));
      size++;
    }
  }
  return size;
}

int main() {
  cin >> N;
  board = new int*[N];
  vis = new bool*[N];

  for(int i=0; i< N; i++){
    board[i] = new int[N];
    vis[i] = new bool[N];
  }

  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      cin >> board[i][j];



  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      int resultAreaSize = dfs(make_pair(i, j));

      if(resultAreaSize != 0){

//        cout << endl;
//        for(int row=0; row<N; row++){
//          for(int col=0; col<N; col++){
//            cout << vis[row][col] << " ";
//          }
//          cout << endl;
//        }
        areaCount++;
        myVec.push_back(resultAreaSize);
      }
    }
  }

  std::sort(myVec.begin(), myVec.end());

  cout << areaCount << "\n";
  for(auto &ele: myVec)
    cout << ele << " ";

  return 0;
}

/*

6
0 1 1 0 0 0
0 1 1 0 1 1
0 0 0 0 1 1
0 0 0 0 1 1
1 1 0 0 1 0
1 1 1 0 0 0
 */