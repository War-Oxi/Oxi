#include <iostream>
#include <algorithm>
using namespace std;

int boardSize, M;
int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int blackCount, whiteCount;

void show(int board_in[][10]) {
	for (int i = 1; i <= boardSize; i++) {
		for (int j = 1; j <= boardSize; j++) {
			cout << board_in[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void numCheck(int board_in[][10]);
bool testCheck(int board_in[][10]);
void init(int board_in[][10]);
void play(int board_in[][10]);

int main() {
	int testCase;
	cin >> testCase;

	for (int test = 1; test <= testCase; test++) {
		int board[10][10];
		
		init(board);
		play(board);

		cout << "#" << test << " " << blackCount << " " << whiteCount << "\n";
	}
}



void numCheck(int board_in[][10]) {
	blackCount = 0;
	whiteCount = 0;

	for (int i = 1; i <= boardSize; i++) {
		for (int j = 1; j <= boardSize; j++) {
			if (board_in[i][j] == 1)
				blackCount++;
			else if (board_in[i][j] == 2)
				whiteCount++;
		}
	}
}

bool testCheck(int board_in[][10]) {
	if (blackCount == 0 || whiteCount == 0)
		return false;
	return true;
}

void init(int board_in[][10]) {
	cin >> boardSize >> M;

	for (int i = 0; i <= boardSize; i++)
		fill(board_in[i], board_in[i] + 10, 0);

	board_in[boardSize / 2][boardSize / 2] = 2; //1 �浹 2 �鵹
	board_in[boardSize / 2][boardSize / 2 + 1] = 1;
	board_in[boardSize / 2 + 1][boardSize / 2] = 1;
	board_in[boardSize / 2 + 1][boardSize / 2 + 1] = 2;
}

void play(int board_in[][10]) {
	/*
	1. count���� 0���� �ʱ�ȭ [�Ϸ�]
	2. whlie(count != M) ���� �÷���
		2.1 x, y, color ��ǥ �Է¹ޱ� [�Ϸ�]
		2.2 for(int i=0; i<4; i++) //0(��) 1(��) 2(��) 3(��) [�Ϸ�]
		2.2.1 x, y ��ǥ�� �������� �������θ� �� ���鼭 �� ���⿡ color�� �Ȱ��� ���� �ִ��� Ȯ��(�̵��Ÿ� Ȯ�� int distance �ʿ�)
		2.2.2 �̵��Ÿ��� 2�̻��̰� color�� �Ȱ��� ���� ���� ��, ���̿� �ִ� �� ��� ��ü
	*/
	int count = 0;

	while (count != M) {
		int col, row, color;
		cin >> col >> row >> color;
		board_in[row][col] = color;

		for (int i = 0; i < 8; i++) {
			bool flag = false;
			int distance(0);
			int tmpCol = col;
			int tmpRow = row;

			while (true) {
				tmpCol = tmpCol + dy[i];
				tmpRow = tmpRow + dx[i];

				if (tmpCol < 1 || tmpCol > boardSize || tmpRow < 1 || tmpRow > boardSize) //tmpCol, tmpRow�� ���� ���� ���̸� ���߱�
					break;

				if (board_in[tmpRow][tmpCol] == 0) //
					break;
				if (board_in[tmpRow][tmpCol] == color && distance < 1)
					break;

				distance++;

				if (board_in[tmpRow][tmpCol] == color && distance > 1) {
					flag = true;
					break;
				}

			}

			if (flag) {
				while (distance--) {
					board_in[tmpRow][tmpCol] = color;
					tmpCol = tmpCol - dy[i];
					tmpRow = tmpRow - dx[i];
				}
			}
		}
		numCheck(board_in);
		if (!testCheck(board_in)) break;

		count++;
	}
}