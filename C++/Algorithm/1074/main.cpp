//#include <iostream>
//using namespace std;
//
//int getPosNum(int n, int row_in, int col_in){
//  if(n == 0) return 0;
//  int half = 1 << (n-1);
//  if(row_in < half && col_in < half) //1사분면
//    return getPosNum(n-1, row_in, col_in);
//  if(row_in < half && col_in >= half) //2사분면
//    return half * half + getPosNum(n-1, row_in, col_in - half);
//  if(row_in >= half && col_in < half) //3사분면
//    return 2 * half * half + getPosNum(n-1, row_in-half, col_in);
//  if(row_in >= half && col_in >= half)
//    return 3 * half * half + getPosNum(n-1, row_in-half, col_in-half);
//  return 0;
//}
//
//int main() {
//  int n, row, col;
//  cin >> n >> row >> col;
//
//  cout << getPosNum(n, row, col);
//  return 0;
//}


#include <iostream>
#include <cmath>
using namespace std;

int getCount(int n, int row_in, int col_in){
  if(n == 0){
    return 0;
  }

  int half = 1 << (n-1);

  if(row_in < half && col_in < half){ //1사분면
    return getCount(n-1, row_in, col_in);
  }
  else if(row_in < half && col_in >= half){ //2사분면
    return half * half + getCount(n-1, row_in, col_in-half);
  }
  else if(row_in >= half && col_in >= half){ //3사분면
    return half * half * 3 + getCount(n-1, row_in-half, col_in-half);
  }
  else{ // 4사분면
    return half * half * 2 + getCount(n-1, row_in-half, col_in);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, row, col;
  cin >> n >> row >> col;

  cout << getCount(n, row, col);
}
