#include <iostream>
#include <vector>
#include <algorithm>

enum Color
{
	RED,
	GREEN,
	BLUE
};

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<vector<int>> houseVec;

	for (int i = 0; i < N; i++) {
		vector<int> tmpVec(3);
		cin >> tmpVec[RED];
		cin >> tmpVec[GREEN];
		cin >> tmpVec[BLUE];
		houseVec.push_back(tmpVec);
	}

	vector<vector<int>> dp;
	vector<int> tmp_dp(3);
	for (int i = 0; i < N; i++)
		dp.push_back(tmp_dp);

	dp[0][RED]	= houseVec[0][RED];
	dp[0][GREEN]= houseVec[0][GREEN];
	dp[0][BLUE]	= houseVec[0][BLUE];

	for (int i = 1; i < N; i++) {
		dp[i][RED]	= min(dp[i - 1][BLUE], dp[i - 1][GREEN]) + houseVec[i][RED];
		dp[i][GREEN]= min(dp[i - 1][RED], dp[i - 1][BLUE]) + houseVec[i][GREEN];
		dp[i][BLUE]	= min(dp[i - 1][RED], dp[i - 1][GREEN]) + houseVec[i][BLUE];
	}

	cout << *min_element(dp[N - 1].begin(), dp[N - 1].end());

	return 0;
}