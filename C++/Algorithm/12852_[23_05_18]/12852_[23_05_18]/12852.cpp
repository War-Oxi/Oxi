#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000002];
int dp_arr[1000002];

int main() {
	int num;
	cin >> num;

	dp[0] = 0;
	dp[1] = 0;

	for (int i = 2; i <= num; i++) {
		dp[i] = dp[i - 1] + 1;
		dp_arr[i] = i - 1;
		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
			dp[i] = dp[i / 2] + 1;
			dp_arr[i] = i / 2;
		}
		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
			dp[i] = dp[i / 3] + 1;
			dp_arr[i] = i / 3;
		}
	}

	cout << dp[num] << "\n";

	int cur = num;
	while (true) {
		cout << cur << ' ';
		if (cur == 1) break;
		cur = dp_arr[cur];
	}

	return 0;
}