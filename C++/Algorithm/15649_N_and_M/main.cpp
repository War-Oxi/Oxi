#include <iostream>
using namespace std;

int n, m;
int arr[10];
bool used_num[10] {false, };

void func(int count){
  if(count == m){
    for(int i=0; i<m; i++){
      cout << arr[i] << " ";
    }
    cout << "\n";
    return;
  }

  for(int i=1; i<=n; i++){
    if(!used_num[i]){
      arr[count] = i;
      used_num[i] = true;
      func(count+1);
      used_num[i] = false;
    }
  }
}

int main(){
  cin >> n >> m;
  func(0);
}


/**
#include <iostream>
#include <vector>
#define MAX 9
using namespace std;

std::vector<int> my_vec;
std::vector<bool> check_vec(MAX, false);

void solve(int N, int M, int cur_depth);

int main() {
    int N, M;
    cin >> N >> M;

    solve(N, M, 0);

    return 0;
}

void solve(const int N, const int M, int cur_depth){
    if(cur_depth >= M){
        for (auto &ele: my_vec){
            cout << ele << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=1; i<=N; i++){
        if(check_vec[i]) continue;
        check_vec[i] = true;
        my_vec.push_back(i);
        solve(N, M, cur_depth+1);
        check_vec[i] = false;
        my_vec.pop_back();
    }
}
*/

