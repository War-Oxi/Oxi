#include <iostream>
#include <vector>
using namespace std;

std::vector<std::vector<bool>> chessBoard;
std::vector<std::vector<bool>> beforeChessBoard;

int chessBoardSize;
int numOfCase(0);

void addQueen(int y, int x){
  for(int i=0; i< chessBoardSize; i++){ // 가로,세로
//    chessBoard[x][i] = true;
    chessBoard[i][y] = true;
  }
  for(int i=0; i<chessBoardSize; i++){ // 대각
    if(y+i >= chessBoardSize || x+i >= chessBoardSize)
      break;
    chessBoard[x+i][y+i] = true; //오른쪽 아래 대각
  }

  for(int i=0; i<chessBoardSize; i++){ // 대각
    if(y-i < 0 || x+i >= chessBoardSize )
      break;
    chessBoard[x+i][y-i] = true; //왼쪽 아래 대각
  }
}

void removeQueen(int y, int x){
  for(int i=0; i< chessBoardSize; i++){ // 세로
//    chessBoard[x][i] = false;
    chessBoard[i][y] = false;
  }
  for(int i=0; i<chessBoardSize; i++){ // 대각
    if(y+i >= chessBoardSize || x+i >= chessBoardSize)
      break;
    if(beforeChessBoard[x+i][y+i] == false)
      chessBoard[x+i][y+i] = false; //오른쪽 아래 대각
  }

  for(int i=0; i<chessBoardSize; i++){ // 대각
    if(y-i < 0 || x+i >= chessBoardSize)
      break;
    if(beforeChessBoard[x+i][y+i] == false)
      chessBoard[x+i][y-i] = false; //왼쪽 아래 대각
  }
}

void solve(int cnt){
  if(cnt == chessBoardSize){
    numOfCase++;
    return;
  }

  for(int i=0; i<chessBoardSize; i++){
    if(chessBoard[cnt][i] == false){
      beforeChessBoard = chessBoard;
      addQueen(i, cnt);
      solve(cnt+1);
//      for(const auto& ele: chessBoard){
//        for(auto ele2 : ele){
//          cout << ele2 << " ";
//        }
//        cout << "\n";
//      }
//      cout << "\n";
      removeQueen(i, cnt);
//      for(const auto& ele: beforeChessBoard){
//        for(auto ele2 : ele){
//          cout << ele2 << " ";
//        }
//        cout << "\n";
//      }
//      cout << "\n";
    }
  }
}

int main() {
  cin >> chessBoardSize;

  chessBoard.resize(chessBoardSize);
  beforeChessBoard.resize(chessBoardSize);
  for(int i=0; i<chessBoardSize; i++){
    chessBoard[i].resize(chessBoardSize, false);
    beforeChessBoard[i].resize(chessBoardSize);
  }

//  addQueen(5, 5);
//  removeQueen(2, 0);
//  for(const auto& ele: chessBoard){
//    for(auto ele2 : ele){
//      cout << ele2 << " ";
//    }
//    cout << "\n";
//  }
  solve(0);
  cout << numOfCase << endl;

  return 0;
}
