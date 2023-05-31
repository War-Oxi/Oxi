#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;
#define X first
#define Y second
/*
1. queue, dx, dy	!!
2. boardArr[N][N]	!!
3. 
*/

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int board[52][52];
int testCase, row, col, k;
queue<pair<int, int>> Q;
pair<int, int> cur;

void bfs(int x, int y) { //출발점
	board[x][y] = -1;
	Q.push(make_pair(x, y));
	while (!Q.empty()) {
		cur = Q.front();
		Q.pop();

		for (int i = 0; i < 4; i++) { // bfs 하우상좌 이동
			int tmpX, tmpY;
			tmpX = cur.X + dx[i];
			tmpY = cur.Y + dy[i];

			if (board[tmpX][tmpY] == 1) {
				board[tmpX][tmpY] = -1;
				Q.push(make_pair(tmpX, tmpY));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> testCase;

	for (int test = 0; test < testCase; test++) {
		int count(0);

		cin >> col >> row >> k;

		for (int i = 0; i < row; i++)
			fill(board[i], board[i] + col, 0);

		int xpos, ypos;

		for (int i = 0; i < k; i++) {
			cin >> xpos >> ypos;
			board[ypos][xpos] = 1;
		}
		
		
		for (int tmpRow = 0; tmpRow < row; tmpRow++) {
			for (int tmpCol = 0; tmpCol < col; tmpCol++) {
				if (board[tmpRow][tmpCol] != 1) continue;
				count++;
				bfs(tmpRow, tmpCol);
			}
		}

		cout << count << endl;
	}
}