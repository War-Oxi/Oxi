#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr1[102], arr2[102];

bool compare(int a, int b) {
	return a > b;
}

void solve() {
	cin >> N;

	for (int i = 0; i < N; i++) cin >> arr1[i];
	for (int i = 0; i < N; i++) cin >> arr2[i];

	sort(arr1, arr1 + N, compare);
	sort(arr2, arr2 + N);

	/*for (int i = 0; i < N; i++) cout << arr1[i];
	cout << endl;
	for (int i = 0; i < N; i++) cout << arr2[i];
	cout << endl;*/


	int result(0);
	for (int i = 0; i < N; i++) result += arr1[i] * arr2[i];

	cout << result;
}

int main() {
	solve();
}