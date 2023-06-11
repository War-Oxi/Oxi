#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<bool> used;
vector<int> vec;

void solve(int cnt){
  if(cnt == M){
    for(int i=0; i<M; i++)
      cout << vec[i] << " ";
    cout << "\n";
    return;
  }

  for(int i=1; i<=N; i++){
    if(used[i] == false){
      vec[cnt] = i;
      used[i] = true;
      solve(cnt+1);
      used[i] = false;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;
  used.resize(N + 1, false);
  vec.resize(N + 1);

  solve(0);

  return 0;
}
