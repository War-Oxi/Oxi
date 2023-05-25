#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
#include <string>
#include <functional>
#define X first
#define Y second

using namespace std;

int boardSize;
int board[51][51];
bool visit[51][51];
int dy[2] = { -1, 1 };

void input();

int bfs(int x, int y, int num) {
	queue<pair<int, int>> Q;
	pair<int, int> cur;
	int sum(0), cnt(0);

	visit[x][y] = true;
	sum += board[x][y];
	cnt++;
	Q.push({ x, y });

	while (!Q.empty()) {
		if (cnt >= num) break;
		cur = Q.front(); Q.pop();
		for (int i = 0; i <= 1; i++) {
			int tmpX = cur.X;
			int tmpY = cur.Y + dy[i];

			if (tmpY < 0 || tmpY > boardSize) continue;
			if (visit[tmpX][tmpY] == true) continue;

			visit[tmpX][tmpY] = true;
			sum += board[tmpX][tmpY];
			cnt++;
			Q.push(make_pair(tmpX, tmpY));
		}
	}
	return sum;
}

void solve() {
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;

	for (int testCase = 1; testCase <= T; testCase++) {
		cin >> boardSize;
		input();

		int row;
		int start = (boardSize + 1) / 2;
		int num(1), sum(0);
	
		for (row = 1; row <= boardSize; row++) {
			if (row <= start) {
				sum += bfs(row, start, num);
				if (row == start) continue;
				num += 2;
			}
			else {
				num -= 2;
				sum += bfs(row, start, num);
			}
		}

		cout << "#" << testCase << " " << sum << "\n";

		for (int i = 1; i <= boardSize; i++) {
			for (int j = 1; j <= boardSize; j++) {
				cout << board[i][j] << " ";
			}
			cout << "\n";
		}

		cout << "\n";
		for (int i = 1; i <= boardSize; i++) {
			for (int j = 1; j <= boardSize; j++) {
				cout << visit[i][j] << " ";
			}
			cout << "\n";
		}

	}
}


void input() {
	for (int i = 1; i <= boardSize; i++) {
		string tmpStr;
		cin >> tmpStr;
		for (int j = 1; j <= boardSize; j++) {
			board[i][j] = tmpStr[j-1] - '0';
			fill(visit[i], visit[i] + boardSize+1, false);
		}
	}
}