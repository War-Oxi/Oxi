#include <iostream>
using namespace std;

int arr[100002];
int dp[100002];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	
	dp[1] = arr[1];
	dp[2] = dp[1] + arr[2];
	//cout << "\n" << dp[1] << "\n" << dp[2] << "\n" << "\n";
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + arr[i];
	}

	for (int testCase = 0; testCase < M; testCase++) {

		int i, j;
		cin >> i >> j;

		int sum(0);

		cout << dp[j] - dp[i-1] << "\n";
	}
}