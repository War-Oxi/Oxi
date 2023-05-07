#include <iostream>
using namespace std;

int N, M;
int arr[10];

void func(int cur, int idx){
  if(cur == M){
    for(int i=0; i<M; i++){
      cout << arr[i] << " ";
    }
    cout << "\n";
    return;
  }

  for(int i=idx; i<=N; i++){
    arr[cur] = i;
    func(cur+1, arr[cur]);
  }
}

int main() {
  cin >> N >> M;
  func(0, 1);
  return 0;
}
