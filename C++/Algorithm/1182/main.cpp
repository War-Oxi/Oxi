#include <iostream>
using namespace std;

int arr[20];
int N, S;
int cnt(0);

void getNum(int cur, int sum){
  if(cur == N){
    if(sum == S)
      cnt++;
    return;
  }

  getNum(cur+1, sum);
  getNum(cur+1, sum + arr[cur]);
}

int main(){
  cin >> N >> S;
  for(int i = 0; i < N; i++){
    cin >> arr[i];
  }

  getNum(0, 0);

  if(S == 0) cnt--;

  cout << cnt;
}



/**
#include <iostream>
using namespace std;

int arr[20];
int num, target_value(0);
int cnt(0);

void getCount(int num_of_ele, int sum){
  if(num_of_ele == num){
    if(sum == target_value){
      cnt++;
    }
    return;
  }

  getCount(num_of_ele + 1, sum);
  getCount(num_of_ele + 1, sum+arr[num_of_ele]);
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> num >> target_value;
  for(int i=0; i<num; i++){
    cin >> arr[i];
  }

  getCount(0, 0);

  if(target_value == 0) cnt--;
  cout << cnt;

  return 0;
}
*/