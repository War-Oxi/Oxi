#include <iostream>
#include <vector>

using namespace std;

int N;
//int startRow, startCol;
int cnt[3];

bool check(const vector<vector<int>>& tableIn, int startRowIn, int startColIn, int numIn){
  for(int row=startRowIn; row<startRowIn+numIn; row++)
    for(int col=startColIn; col<startColIn+numIn; col++)
      if(tableIn[row][col] != tableIn[startRowIn][startColIn])
        return false;
  return true;
}

void divide(const vector<vector<int>>& tableIn, int startRow, int startCol, int num){
  if(check(tableIn, startRow, startCol, num)){
    cnt[tableIn[startRow][startCol]+1] += 1;
    return;
  }

  int nextNum = num / 3;
  for(int row=0; row<3; row++){
    for(int col=0; col<3; col++){
      divide(tableIn, startRow+row*nextNum, startCol+col*nextNum, nextNum);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  vector<vector<int>> table(N, vector<int>(N, 0));

  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      cin >> table[i][j];

//  for(auto ele: table){
//    for(auto ele2: ele){
//      cout << ele2 << " ";
//    }
//    cout << "\n";
//  }

  divide(table, 0, 0, N);

  for(int i : cnt)
    cout << i << "\n";


  return 0;
}
