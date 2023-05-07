#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

void hanoi(int start, int target, int num){
  if(num == 1){
    cout << start << " " << target << "\n";
    return;
  }
  int way_point = 6 - start - target;
  hanoi(start, way_point, num-1);
  cout << start << " " << target << "\n";
  hanoi(way_point, target, num-1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  cout << (int)pow(2, N) -1 << "\n";
  hanoi(1, 3, N);

  return 0;
}
