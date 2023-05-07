#include <iostream>
#include <algorithm>
using namespace std;

int N;
bool col_check[40], right_down_check[40], right_up_check[40];
int cnt = 0;

void backTracking(int row) {
  if (row == N) {
    cnt++;
    return;
  }

  for (int i = 0; i < N; i++) {
    if (col_check[i] || right_down_check[row - i + N] || right_up_check[row + i])
      continue;
    col_check[i] = true;
    right_down_check[row - i + N] = true;
    right_up_check[row + i] = true;
    backTracking(row + 1);
    col_check[i] = false;
    right_down_check[row - i + N] = false;
    right_up_check[row + i] = false;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N;

  backTracking(0);

  cout << cnt;

  return 0;
}
