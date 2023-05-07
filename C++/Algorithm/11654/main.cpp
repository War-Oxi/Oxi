#include <iostream>
#include <algorithm>
using namespace std;

int arr[10];
int num[10];
bool unused[10];
int N, M;


bool compare(int a, int b);
void input();
void func(int cur);

int main() {
  cin >> N >> M;
  input();
  sort(arr, arr+N, compare);
  func(0);

  return 0;
}

void input(){
  for(int i=0; i<N; i++)
    cin >> arr[i];
}

bool compare(int a, int b){
  return a < b;
}

void func(int cur){
  if(cur == M){
    for(int i=0; i<M; i++)
      cout << num[i] << " ";
    cout << "\n";
    cur = 0;
    return;
  }

  for(int i=0; i<N; i++){
    if(unused[i]) continue;

    unused[i] = true;
    num[cur] = arr[i];
    func(cur+1);
    unused[i] = false;
  }
}