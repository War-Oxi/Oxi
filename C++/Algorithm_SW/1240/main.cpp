#include <iostream>
using namespace std;

int encryptionCode[51][101];
int row, col;
int password[10][8] {{0,0,0,1,1,0,1},
                     {0,0,1,1,0,0,1},
                     {0,0,1,0,0,1,1},
                     {0,1,1,1,1,0,1},
                     {0,1,0,0,0,1,1},
                     {0,1,1,0,0,0,1},
                     {0,1,0,1,1,1,1},
                     {0,1,1,1,0,1,1},
                     {0,1,1,0,1,1,1},
                     {0,0,0,1,0,1,1}};
int result[9];

bool getPassword();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int testCase, T;
  cin >> T;

  for(testCase = 1; testCase <= T; testCase++){
    cin >> row >> col;

    string tmpStr;
    for(int i=0; i<row; i++){
      cin >> tmpStr;
      for(int j=0; j<col; j++){
        encryptionCode[i][j] = tmpStr[j] - '0';
      }
    }

    if(getPassword()){
      int decryptedPassword(0);
      for(int i=1; i<=8; i++){
        decryptedPassword += result[i];
      }
      cout << "#" << testCase <<" " << decryptedPassword << endl;
    }
    else{
      cout << "#" << testCase <<" " << 0 << endl;
    }
  }
  return 0;
}

bool getPassword() {
  pair<int, int> posStart;
  bool flag(false);
  for(int i = 0; i < row; i++){
    for(int j = col; j >= 0; j--){
      if(encryptionCode[i][j] == 1){
        flag = true;
        posStart = {i, j-55};
      }
      if(flag)
        break;
    }
    if(flag)
      break;
  }

  int oddNum(0), evenNum(0), cnt(1);
  for(int i = posStart.second; i <= posStart.second+55; i += 7){
    int arr[8];
    for(int j = i; j < i+8; j++){
      arr[j-i] = encryptionCode[posStart.first][j];
    }

    for(int cmp=0; cmp<10; cmp++){
      bool flag2;
      for(int j=0; j<8; j++){
        if(arr[j] == password[cmp][j]){
          flag2 = true;
        }
        else{
          flag2 = false;
          break;
        }
      }

      if(flag2){
        result[cnt] = cmp;
        cnt++;
        if(flag){
          oddNum += cmp;
          flag = false;
        }
        else{
          evenNum += cmp;
          flag = true;
        }
        break;
      }
    }
  }
  if((oddNum * 3 + evenNum) % 10 == 0)
    return true;
  else
    return false;
}
