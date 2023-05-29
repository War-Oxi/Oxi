//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <utility>
//#include <tuple>
//#include <queue>
//
//using namespace std;
//
//int boxRow, boxCol, boxHeight;
//int dRow[6] = {1 , -1, 0, 0, 0, 0};
//int dCol[6] = {0, 0, -1, 1, 0 ,0};
//int dHeight[6] = {0, 0, 0, 0, 1, -1};
//queue<tuple<int, int, int>> Q;
//
//void bfs(vector<vector<vector<int>>> &wareHouseIn, vector<vector<vector<int>>> &distIn) {
//  /**
//   * 1. cur 움직이기 => tmp
//   * 2. tmp위치의 토마토가 0인지, tmp 위치가 방문한 곳인지 확인
//   * 3. tmp가 창고를 벗어났는지 확인
//   * 4. 모든것이 정상이면 wareHouseIn[h][r][c] => 1로. distIn[h][r][c] => cur + 1로.
//   * 5. tmp Q에 push
//   */
//  while (!Q.empty()) {
//    auto cur = Q.front();
//    Q.pop();
//
//    int curHeight, curRow, curCol;
//    //  curHeight = get<0>(cur);
//    //  curRow = get<1>(cur);
//    //  curCol = get<2>(cur);
//    tie(curHeight, curRow, curCol) = cur;
//
//    for (int i = 0; i < 6; i++) {
//      int tmpHeight(curHeight + dHeight[i]), tmpRow(curRow + dRow[i]), tmpCol(curCol + dCol[i]);
//
//      if (tmpHeight < 0 || tmpHeight >= boxHeight || tmpRow < 0 || tmpRow >= boxRow || tmpCol < 0 || tmpCol >= boxCol) continue;
//      if (wareHouseIn[tmpHeight][tmpRow][tmpCol] != 0 || distIn[tmpHeight][tmpRow][tmpCol] >= 0) continue;
//
////      wareHouseIn[tmpHeight][tmpRow][tmpCol] = 1;
//      distIn[tmpHeight][tmpRow][tmpCol] = distIn[curHeight][curRow][curCol] + 1;
//      Q.push({tmpHeight, tmpRow, tmpCol});
//    }
//  }
//}
//
//int main() {
//  ios::sync_with_stdio(false);
//  cin.tie(nullptr);
//
//  cin >> boxCol >> boxRow >> boxHeight;
//  vector<vector<vector<int>>> wareHouse(boxHeight, vector<vector<int>>(boxRow, vector<int>(boxCol, 0)));
//  vector<vector<vector<int>>> dist(boxHeight, vector<vector<int>>(boxRow, vector<int>(boxCol, 0)));
//
//  for (int height = 0; height < boxHeight; height++) {
//    for (int row = 0; row < boxRow; row++) {
//      for (int col = 0; col < boxCol; col++) {
//        cin >> wareHouse[height][row][col];
//        if (wareHouse[height][row][col] == 1) Q.push({height, row, col});
//        if (wareHouse[height][row][col] == 0) dist[height][row][col] = -1;
//      }
//    }
//  }
////  cout << "\n";
////  for (int height = 0; height < boxHeight; height++) {
////    for (int row = 0; row < boxRow; row++) {
////      for (int col = 0; col < boxCol; col++) {
////        cout << dist[height][row][col] << " ";
////      }
////      cout << "\n";
////    }
////    cout << "\n";
////  }
//  bfs(wareHouse, dist);
//
//  int maxDate(0), flag(0);
//  for (int height = 0; height < boxHeight; height++) {
//    for (int row = 0; row < boxRow; row++) {
//      for (int col = 0; col < boxCol; col++) {
//        maxDate = max(dist[height][row][col], maxDate);
//        if (wareHouse[height][row][col] == 0 && dist[height][row][col] == -1) {
//          flag = -1;
//          break;
//        }
//      }
//      if (flag == -1) break;
//    }
//    if (flag == -1) break;
//  }
//  if (flag == -1) {
//    cout << -1;
//  } else {
//    cout << maxDate;
//  }
//
////  cout << "\n";
////  for (int height = 0; height < boxHeight; height++) {
////    for (int row = 0; row < boxRow; row++) {
////      for (int col = 0; col < boxCol; col++) {
////
////        cout << dist[height][row][col] << " ";
////      }
////      cout << "\n";
////    }
////    cout << "\n";
////  }
//  return 0;
//}

#include <iostream>
#include <algorithm>
#include <tuple>
#include <queue>

using namespace std;

int boxRow, boxCol, boxHeight;
int wareHouse[102][102][102];
int dist[102][102][102];
int dRow[6] = {1 , -1, 0, 0, 0, 0};
int dCol[6] = {0, 0, -1, 1, 0 ,0};
int dHeight[6] = {0, 0, 0, 0, 1, -1};
queue<tuple<int, int, int>> Q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> boxCol >> boxRow >> boxHeight;

  for (int height = 0; height < boxHeight; height++) {
    for (int row = 0; row < boxRow; row++) {
      for (int col = 0; col < boxCol; col++) {
        cin >> wareHouse[height][row][col];
        if (wareHouse[height][row][col] == 1) Q.push({height, row, col});
        if (wareHouse[height][row][col] == 0) dist[height][row][col] = -1;
      }
    }
  }
//  cout << "\n";
//  for (int height = 0; height < boxHeight; height++) {
//    for (int row = 0; row < boxRow; row++) {
//      for (int col = 0; col < boxCol; col++) {
//        cout << dist[height][row][col] << " ";
//      }
//      cout << "\n";
//    }
//    cout << "\n";
//  }
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();

    int curHeight, curRow, curCol;
    //  curHeight = get<0>(cur);
    //  curRow = get<1>(cur);
    //  curCol = get<2>(cur);
    tie(curHeight, curRow, curCol) = cur;

    for (int i = 0; i < 6; i++) {
      int tmpHeight(curHeight + dHeight[i]), tmpRow(curRow + dRow[i]), tmpCol(curCol + dCol[i]);

      if (tmpHeight < 0 || tmpHeight >= boxHeight || tmpRow < 0 || tmpRow >= boxRow || tmpCol < 0 || tmpCol >= boxCol) continue;
      if (wareHouse[tmpHeight][tmpRow][tmpCol] != 0 || dist[tmpHeight][tmpRow][tmpCol] >= 0) continue;

//      wareHouseIn[tmpHeight][tmpRow][tmpCol] = 1;
      dist[tmpHeight][tmpRow][tmpCol] = dist[curHeight][curRow][curCol] + 1;
      Q.push({tmpHeight, tmpRow, tmpCol});
    }
  }

  int maxDate(0), flag(0);
  for (int height = 0; height < boxHeight; height++) {
    for (int row = 0; row < boxRow; row++) {
      for (int col = 0; col < boxCol; col++) {
        maxDate = max(dist[height][row][col], maxDate);
        if (wareHouse[height][row][col] == 0 && dist[height][row][col] == -1) {
          flag = -1;
          break;
        }
      }
      if (flag == -1) break;
    }
    if (flag == -1) break;
  }
  if (flag == -1) {
    cout << -1;
  } else {
    cout << maxDate;
  }

//  cout << "\n";
//  for (int height = 0; height < boxHeight; height++) {
//    for (int row = 0; row < boxRow; row++) {
//      for (int col = 0; col < boxCol; col++) {
//
//        cout << dist[height][row][col] << " ";
//      }
//      cout << "\n";
//    }
//    cout << "\n";
//  }
  return 0;
}
