#include <iostream>
using namespace std;

int N, M;
bool used[10];
int arr[10];

void getSequence(int cur, int num){
  if(cur == M){
    for(int i=0; i<M; i++){
      cout << arr[i] << " ";
    }
    cout << "\n";
    return;
  }

  for(int i=num; i<=N; i++){
    if(used[i]) continue;

    used[i] = true;
    arr[cur] = i;
    getSequence(cur+1, i+1);
    used[i] = false;
  }
}

int main() {
  cin >> N >> M;

  getSequence(0, 1);

  return 0;
}
