#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int max_value;
int sortedNum;
int exchange_num;
int min_change;
string num;

void dfs(int cnt){
  int tmp_num = stoi(num);
  if(cnt == exchange_num){
    if(max_value < tmp_num) {
      max_value = tmp_num;
    }
    return;
  }

  if(tmp_num == sortedNum){
    min_change = cnt;
    max_value = tmp_num;
    return;
  }

  for(int i=cnt; i<num.length(); i++){
    for(int j=i+1; j<num.length(); j++){
      swap(num[i], num[j]);
      dfs(cnt+1);
      swap(num[i], num[j]);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int test_case, T;
  cin >> T;

  for(test_case=1; test_case<=T; test_case++){
    cin >> num >> exchange_num;
    string max_num = num;
    sort(max_num.begin(), max_num.end(), greater<>());
    sortedNum = stoi(max_num);
    min_change= 10000000;
    max_value = stoi(num);

    dfs(0);

    if(min_change < exchange_num && abs(min_change - exchange_num) % 2 != 0){
      num = to_string(max_value);
      if(num[0] != num[1])
        swap(num[num.size()-1], num[num.size()-2]);
      max_value = stoi(num);
    }
    cout << "#" << test_case << " " << max_value << "\n";
  }
  return 0;
}


