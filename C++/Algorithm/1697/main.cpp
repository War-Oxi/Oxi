#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dist[100002];
int cur, target;

int main() {
  cin >> cur >> target;

  fill(dist, dist+100001, -1);

  queue<int> Q;
  dist[cur] = 0;
  Q.push(cur);

  while(!Q.empty()){
    cur = Q.front(); Q.pop();

    for(int next : {cur-1, cur+1, cur*2}){
      if(next < 0 || next > 100000) continue;
      if(dist[next] != -1) continue;

      dist[next] = dist[cur] + 1;
      Q.push(next);
    }
  }

//  for(int i=0; i<=target; i++){
//    cout << dist[i] << " ";
//  }
//  cout << endl;
  cout << dist[target] << endl;

  return 0;
}
