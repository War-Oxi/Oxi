#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>

#define X first
#define Y second

using namespace std;

/*
queue<pair<int, int>> Q;
pair<int, int> cur;
*/

char boardRGB[101][101];
bool visit[101][101];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N;
int countRGB(0), countRB(0);

void bfs(int x, int y) {
	queue<pair<int, int>> Q;
	pair<int, int> cur;

	Q.push(make_pair(x, y));
	visit[x][y] = true;
	char color = boardRGB[x][y];

	while (!Q.empty()) {
		cur = Q.front(); Q.pop();

		for (int d = 0; d < 4; d++) {
			int tmpX = cur.X + dx[d];
			int tmpY = cur.Y + dy[d];

			if (tmpX < 0 || tmpX >= N || tmpY < 0 || tmpY >= N) continue;
			if (visit[tmpX][tmpY] == true || boardRGB[tmpX][tmpY] != color) continue;
			
			visit[tmpX][tmpY] = true;
			Q.push(make_pair(tmpX, tmpY));
		}
	}

}


int main() {
	cin >> N;

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++)
			cin >> boardRGB[row][col];
	}

	// 일반인 구하기
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			if (visit[row][col] == true) continue;
			countRGB++;
			bfs(row, col);
	
			/*for (int row = 0; row < N; row++) {
				for (int col = 0; col < N; col++) {
					cout << visit[row][col] << " ";
				}
				cout << endl;
			}
			cout << endl;*/

		}
	}


	// 적록색약 구하기
	for (int i = 0; i < N; i++)
		fill(visit[i], visit[i] + N, false);
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			if (boardRGB[row][col] == 'G')
				boardRGB[row][col] = 'R';
		}
	}

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			if (visit[row][col] == true) continue;
			countRB++;
			bfs(row, col);
		}
	}

	cout << countRGB << " " << countRB;
}

/*
5
RRRBB
GGBBB
BBBRR
BBRRR
RRRRR
*/