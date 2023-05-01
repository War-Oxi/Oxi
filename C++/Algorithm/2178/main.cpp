#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#define X first
#define Y second

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
string board[102];
int dist[102][102];


int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);

  int N, M;
  cin >> N >> M;

  for(int i = 0; i < N; i++){ fill(dist[i], dist[i]+M, -1); } //init => dist[N][M]

  for(int i = 0; i < N; i++){ //init => board[N][M]
    cin >> board[i];
  }

  queue<pair<int, int>> my_queue;
  my_queue.push(make_pair(0,0));
  dist[0][0] = 0;

  while(!my_queue.empty()){
     pair<int, int> cur = my_queue.front();
     my_queue.pop();

     for(int i=0; i<4; i++){
       int x = cur.X + dx[i];
       int y = cur.Y + dy[i];

       if (x < 0 || x >= N || y < 0 || y >= M ) continue;
       if (board[x][y] != '1' || dist[x][y] >= 0) continue;

       dist[x][y] = dist[cur.X][cur.Y] + 1;
       my_queue.push(make_pair(x, y));
     }
  }
  cout << dist[N-1][M-1] + 1;
  return 0;
}
