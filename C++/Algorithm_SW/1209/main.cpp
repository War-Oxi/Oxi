#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> myVec;
int testCaseArr[101][101];

int dx[2]{1, 1}; //오른쪽 밑 대각선
int dy[2]{1, -1}; //왼쪽 아래 대각선

void rd(int curX, int curY, int sum){
  if(curX < 0 || curX > 100 || curY < 0 || curY > 100){
    myVec.push_back(sum);
    return;
  }

  rd(curX + dx[0], curY + dy[0], sum + testCaseArr[curX][curY]);
}

void ld(int curX, int curY, int sum){
  if(curX < 0 || curX > 100 || curY < 0 || curY > 100){
    myVec.push_back(sum);
    return;
  }

  rd(curX + dx[1], curY + dy[1], sum + testCaseArr[curX][curY]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for(int testCase=1; testCase<=10; testCase++){
    int t;
    cin >> t;

    for(int i = 0; i < 100; i++){
      for (int j = 0; j < 100; j++){
        cin >> testCaseArr[i][j];
      }
    }

    for(int i = 0; i < 100; i++){
      int sumRow(0), sumCol(0);
      for(int j = 0; j < 100; j++){
        sumRow += testCaseArr[i][j];
        sumCol += testCaseArr[j][i];
      }
      myVec.push_back(sumRow);
      myVec.push_back(sumCol);
    }

    for(int i=0; i<100; i++){
      rd(i, 0, 0);
      rd(0, i, 0);
      ld(0, i, 0);
      ld(i, 99, 0);
    }

    cout << "#" << testCase << " " << *max_element(myVec.begin(), myVec.end()) << "\n";

    myVec = vector<int>();
  }
  return 0;
}
