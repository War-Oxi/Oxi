#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> my_vec(N+1);
	for (int i = 1; i <= N; i++) {
		cin >> my_vec[i];
	}

	int dp[302];

	dp[1] = my_vec[1];
	dp[2] = my_vec[2] + my_vec[1];
	dp[3] = max(my_vec[1], my_vec[2]) + my_vec[3];

	for (int i = 3; i <= N; i++) {
		dp[i] = max(dp[i - 3] + my_vec[i - 1], dp[i - 2]) + my_vec[i];
	}

	cout << dp[N];

	return 0;
}