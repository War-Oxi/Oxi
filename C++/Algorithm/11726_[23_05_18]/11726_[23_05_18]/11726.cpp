#include <iostream>
using namespace std;

int dp[1002];

int main() {
	int N;
	cin >> N;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 5;

	for (int i = 5; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}

	cout << dp[N]<< "\n";

	return 0;
}