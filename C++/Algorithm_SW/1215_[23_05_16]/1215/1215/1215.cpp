#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

char board[10][10];

int getPalindromeLength(int length, vector<int> &vecIn) {
	int count(0);
	int idx = length / 2;
	if (length % 2 == 0) { // 길이가 짝수일 경우
		while (idx <= 8 - length / 2) {
			bool flag(true);
			for (int i = 0; i < length / 2; i++) {
				if (vecIn[idx - i - 1] != vecIn[idx + i]) { //회문 체크
					flag = false;
					break;
				}
			}
			if (flag) count++;
			idx++;
		}
	}
	else { // 길이가 홀수일 경우
		while (idx < 8 - length / 2) {
			bool flag(true);
			for (int i = 0; i <= length / 2; i++) {
				if (vecIn[idx - i] != vecIn[idx + i]) { //회문 체크
					flag = false;
					break;
				}
			}
			if (flag) count++;
			idx++;
		}
	}

	return count;
}

int main() {
	for (int i = 1; i <= 10; i++) {
		int palindromeLength;
		cin >> palindromeLength;

		int cnt(0);
		
		string tmpString;
		for (int row = 0; row < 8; row++) {
			cin >> tmpString;
			for (int col = 0; col < 8; col++) {
				board[row][col] = tmpString[col];
			}
		}

		for (int row = 0; row < 8; row++) {
			vector<int> tmpVecRow;
			vector<int> tmpVecCol;
			for (int col = 0; col < 8; col++) {
				tmpVecRow.push_back(board[row][col]);
				tmpVecCol.push_back(board[col][row]);
			}
			cnt += getPalindromeLength(palindromeLength, tmpVecRow);
			cnt += getPalindromeLength(palindromeLength, tmpVecCol);
		}
		
		cout << "#" << i << " " << cnt << "\n";
	}

	return 0;
}