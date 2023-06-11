#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int rowSize, colSize, numOfSticker;
int board[42][42];

int stickerRowSize, stickerColSize;
int sticker[12][12];

void rotate(){
  int tmp[12][12];

  for(int row=0; row<stickerRowSize; row++)
    for(int col=0; col<stickerColSize; col++)
      tmp[row][col] = sticker[row][col];

  for(int row=0; row<stickerRowSize; row++)
    for(int col=0; col<stickerColSize; col++)
      sticker[row][col] = tmp[stickerColSize - 1 - col][row];

  for(int row = 0; row < stickerColSize; row++)
    for(int col = 0; col < stickerRowSize; col++)
      sticker[row][col] = tmp[stickerRowSize - 1 - col][row];

  swap(stickerRowSize, stickerColSize);

//  cout << "\n";
//  for(int row=0; row<stickerRowSize; row++){
//    for(int col=0; col<stickerColSize; col++){
//      cout << sticker[row][col] << " ";
//    }
//    cout << "\n";
//  }

}

bool attachable(int x, int y) {
  for (int row = 0; row < stickerRowSize; row++) {
    for (int col = 0; col < stickerColSize; col++) {
      if (board[row + x][col + y] == 1 && sticker[row][col] == 1)
        return false;
    }
  }

  for (int row = 0; row < stickerRowSize; row++) {
    for (int col = 0; col < stickerColSize; col++) {
      if (sticker[row][col] == 1)
        board[row + x][col + y] = 1;
    }
  }
  return true;
}

int main() {
  cin >> rowSize >> colSize >> numOfSticker;

  for (int i = 0; i < rowSize; i++)
    fill(board[i], board[i] + colSize, 0);

  for (int i = 0; i < numOfSticker; i++) {
    cin >> stickerRowSize >> stickerColSize;
    for (int r = 0; r < stickerRowSize; r++)
      for (int c = 0; c < stickerColSize; c++)
        cin >> sticker[r][c];

    //스티커 붙이기
    for (int rotation = 0; rotation < 4; rotation++) {
      bool attached = false;
      for (int row = 0; row <= rowSize - stickerRowSize; row++) {
        if(attached) break;
        for (int col = 0; col <= colSize - stickerColSize; col++) {
          if(attachable(row, col)){
            attached = true;
            break;
          }
        }
      }
      if(attached) break;
      rotate();
    }
  }

  int count(0);
  for(int row=0; row<rowSize; row++){
    for(int col=0; col<colSize; col++){
      if(board[row][col]) count += 1;
    }
  }

//  cout << "\n";
//  for(int row=0; row<rowSize; row++){
//    for(int col=0; col<colSize; col++){
//      cout << board[row][col] << " ";
//    }
//    cout << "\n";
//  }

  cout << count;

  return 0;
}
