/*
문제)
정렬되어있는 두 배열 A와 B가 주어진다. 두 배열을 합친 다음 정렬해서 출력하는 프로그램을 작성하시오.

입력)
첫째 줄에 배열 A의 크기 N, 배열 B의 크기 M이 주어진다. (1 ≤ N, M ≤ 1,000,000)

둘째 줄에는 배열 A의 내용이, 셋째 줄에는 배열 B의 내용이 주어진다. 배열에 들어있는 수는 절댓값이 109보다 작거나 같은 정수이다.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int arrA[1000002];
int arrB[1000002];
int arrResult[1000002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int aArrSize, bArrSize;
	cin >> aArrSize >> bArrSize;

	for (int i = 0; i < aArrSize; i++) // arrA initialization
		cin >> arrA[i];

	for (int i = 0; i < bArrSize; i++) // arrB initialization
		cin >> arrB[i];

	int aIdx(0), bIdx(0);

	for (int i = 0; i < aArrSize + bArrSize; i++) {
		if (aIdx == aArrSize)
			arrResult[i] = arrB[bIdx++];
		else if (bIdx == bArrSize)
			arrResult[i] = arrA[aIdx++];
		else if (arrA[aIdx] < arrB[bIdx])
			arrResult[i] = arrA[aIdx++];
		else
			arrResult[i] = arrB[bIdx++];
	}

	for (int i = 0; i < aArrSize + bArrSize; i++)
		cout << arrResult[i] << " ";

	//cout << "\n";
	//sort(arrResult, arrResult + aArrSize + bArrSize, greater<>());
	//for (int i = 0; i < aArrSize + bArrSize; i++)
	//	cout << arrResult[i] << " ";
	return 0;
}