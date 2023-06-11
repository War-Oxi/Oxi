#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <utility>
using namespace std;

vector<int> myVec;
int dartBoard[16][16] = {{0,0,0,0,0,0,17,17,17,17,0,0,0,0,0,0},
                         {0,0,0,0,0,4,17,17,17,17,1, 0,0,0,0,0},
                         {0,0,0,7,7,4,4,12,12,1,1,5,5,0,0,0},
                         {0,0,7,7,7,4,4,12,12,1,1,5,5,5,0,0},
                         {0,0,7,7,7,4,4,12,12,1,1,5,5,5,0,0},
                         {0,16,16,16,16,4,4,12,12,1,1,13,13,13,13,0},
                         {19,19,16,16,16,16,4,12,12,1,13,13,13,13,20,20},
                         {19,19,10,10,10,10,10,25,25,9,9,9,9,9,20,20},
                         {19,19,10,10,10,10,10,25,25,9,9,9,9,9,20,20},
                         {19,19,15,15,15,15,3,11,11,2,14,14,14,14,20,20},
                         {0,15,15,15,15,3,3,11,11,2,2,14,14,14,14,0},
                         {0,0,6,6,6,3,3,11,11,2,2,8,8,8,0,0},
                         {0,0,6,6,6,3,3,11,11,2,2,8,8,8,0,0},
                         {0,0,0,6,6,3,3,11,11,2,2,8,8,0,0,0},
                         {0,0,0,0,0,3,18,18,18,18,2,0,0,0,0,0},
                         {0,0,0,0,0,0,18,18,18,18,0,0,0,0,0,0}};
pair<int, int> roundArr[10] = {{0,0},{5,5},{6,6},{7,7},{8,8},{17,18},{9,10}, {11,12}, {19,20},{25,25}};
int solution(vector<int> param) {
  string strIn;
  int score(40);
  cin >> strIn;

  string tmpstr;
  for (auto &ele: strIn) {
    if (ele == ','){
      param.push_back(stoi(tmpstr));
//      param.push_back(int(stoi(tmpstr)));

      tmpstr="";
    }
    else{
      tmpstr.push_back(ele);
    }
  }
  param.push_back(stoi(tmpstr));
  int roundCount(1), pairCount(0);
  int row, col;
  bool pairFlag(false), hitflag(false);
  for (auto ele: param) {
    if (!pairFlag) {
      col = ele;
      pairFlag = !pairFlag;
    } else {
      row = ele;
      pairFlag = !pairFlag;
    }


    if (!pairFlag) {
      pairCount += 1;
      if (dartBoard[row][col] == roundArr[roundCount].first || dartBoard[row][col] == roundArr[roundCount].second) {
        hitflag = true;
        score += dartBoard[row][col];
      }
    }

    if (pairCount != 3) //flag 확인 후, 그대로 false이면 점수 반으로 깎
      continue;

    roundCount += 1;
    pairCount = 0;
    if (hitflag == false) {
      score = score / 2;
    }
    hitflag = false;

  }
//  for(auto & ele : param){
//    cout << ele << " ";
//  }
  cout << score;
  return score;
}

int main(){
  solution(myVec);

  return 0;
}