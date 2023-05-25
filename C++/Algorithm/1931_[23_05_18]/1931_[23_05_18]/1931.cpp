#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> arr[100002];

int main() {
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++)
		cin >> arr[i].second >> arr[i].first; //first => [ ≥° ] second [ Ω√¿€ ]

	sort(arr, arr + N);

	int tmp(0), ans(0);

	for (int i = 0; i < N; i++) {
		if (arr[i].second < tmp) continue;
		ans++;
		tmp = arr[i].first;
	}

	cout << ans << "\n";
	return 0;
}