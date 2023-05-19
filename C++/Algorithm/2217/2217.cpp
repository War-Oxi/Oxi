#include <iostream>
#include <algorithm>
using namespace std;

int rope[100002];

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) 
		cin >> rope[i];

	sort(rope, rope + N);
	int ans(0);
	for (int i = 1; i <= N; i++)
		ans = max(ans, rope[N - i] * i);

	cout << ans;

	return 0;
}