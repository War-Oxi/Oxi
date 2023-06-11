/*
싸피는 중고차를 판매하는데 주차장에 1대의 차만 세워둘 수 있어 어떤 시점에든 보유할 수 있는 차는 최대 1대 뿐이다.

N일 동안 각각 한 명의 손님이 찾아온다.

N일 중 어떤 날은 손님이 금액 X원인 차를 팔러 온다.싸피는 그 차를 받거나 포기할 수 있다.



이미 주차장에 차가 있다면 받을 수 없다.다른 어떤 날은 손님이 금액 Y원인 차를 사러 온다.

싸피가 정확히 그 금액으로 산 차를 가지고 있다면 팔 수 있다.편의상 이익은 Y원이라고 하자.

그리고 싸피는 앞으로 일어날 일을 모두 알고 있다고 한다.싸피가 얻을 수 있는 최대 이익을 구하라.



예를 들어 N = 4이고, 첫날 5원 짜리 차를 팔러, 둘째 날 6원 짜리 차를 팔러, 셋째 날 5원 짜리 차를 사러, 넷째 날 6원 짜리 차를 사러 왔다고 하자.

두 대의 차를 모두 사고 팔 수 있는 방법은 없으므로 첫째 날은 포기하고, 둘째 날 들어온 차를 산 다음, 넷째 날에 파는 것이 가장 큰 이익이다.



[제약사항]

N은 1 이상 500 이하이다. (1 ≤ N ≤ 500)

각 차의 가격은 1 이상 20 이하이다.



[입력]

가장 첫 줄에는 테스트 케이스의 총 수가 주어진다.

그 다음 줄부터 각 테스트 케이스가 주어지며, 각 테스트 케이스는 N + 1 줄로 구성된다.각 테스트 케이스의 첫 줄에는 N이 주어진다.

다음 N개의 줄에, 날짜 순서대로, 손님이 사거나 팔려는 차의 정보가 주어진다.

하루의 기록은 두 개의 정수인데 첫번째 정수가 1인 경우 손님이 팔려고(싸피가 살수 있는) 온 경우이며 두번째 정수는 차의 가격이다.

첫번째 정수가 - 1인 경우 손님이 사러 온 것이다.두번째 정수는 여전히 가격이다.
*/

#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

pair<int, int> day[502];
bool visit[502];
int N;
int startIdx, endIdx;
int sum(0);
int tmpPrice;

bool find(int idx, int status, int price) {
	startIdx = idx;
	for (int i = idx; i <= N; i++) {
		if (day[i].first == -1 && day[i].second == price) {
			tmpPrice = price;
			endIdx = i;
			return true;
		}
	}
	return false;
}

int main() {
	int T;
	cin >> T;

	for (int testCase = 1; testCase <= T; testCase++) {
		cin >> N;

		for (int i = 1; i <= N; i++) {
			int status, price;
			cin >> status >> price;
			day[i] = make_pair(status, price);
		}

		/*
		첫번째 팔 경우, 사는 날, 파는 날 비교
		*/
		for (int i = 1; i <= N; i++) {
			if (find(i, day[i].first, day[i].second)) {
				sum += day[i].second;
				continue;
			}

		}
	}

}