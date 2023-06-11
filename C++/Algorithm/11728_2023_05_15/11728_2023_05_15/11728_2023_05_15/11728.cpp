/*
����)
���ĵǾ��ִ� �� �迭 A�� B�� �־�����. �� �迭�� ��ģ ���� �����ؼ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�)
ù° �ٿ� �迭 A�� ũ�� N, �迭 B�� ũ�� M�� �־�����. (1 �� N, M �� 1,000,000)

��° �ٿ��� �迭 A�� ������, ��° �ٿ��� �迭 B�� ������ �־�����. �迭�� ����ִ� ���� ������ 109���� �۰ų� ���� �����̴�.
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