/*
N개의 레이저 발사기가 있다.

이들 중 i번째 발사기는 수직선(x축)의 X[i]에 위치하고 강도 F[i]를 가진다.

X[i]에 위치한 발사기가 레이저를 발사하면 X[i]에서 X[i]+F[i]까지 위치한 발사기가 모두 파괴된다. 자기 자신도 파괴됨에 주의하라.

전체에서 몇 개의 발사기를 수동으로 동작시켜 모든 발사기를 파괴하고 싶다

발사되는 레이저를 선택할 때는 반드시 X[i]가 작은 것을 먼저 작동시켜야 하며, 파괴된 발사기는 동작할 수 없다

발사 가능한 최소의 개수를 구하라.



예를 들어, N = 3이고 발사기들의 좌표가 각각 2, 4, 6, 발사 거리가 모두 2라고 하자.

이 경우 제일 왼쪽 2에 위치한 발사기를 동작시키면, 2와 4에 위치한 두 개의 발사기가 파괴된다. 그리고 6에 위치한 발사기를 동작시키면 모든 발사기가 파괴된 것이고 이 경우의 답은 2가 된다

[제약사항]



발사기의 수 N은 1 이상 500 이하이다. (1 ≤ N ≤ 500)

발사기의 좌표는 1 이상 10,000 이하의 정수이다.

발사기들의 좌표는 모두 다르다.

발사기의 강도는 1 이상 4,000 이하의 정수이다.



[입력]

가장 첫 줄에는 테스트 케이스의 총 수가 주어진다.

그 다음 줄부터 각 테스트 케이스가 주어지며, 각 테스트 케이스는 N+1 줄로 구성된다. 각 테스트 케이스의 첫 줄에는 N이 주어진다.

다음 N개의 줄 각각에 각 발사기의 좌표와 강도가 주어진다.

발사기는 좌표 값이 작은 것부터 큰 것의 순서로 주어진다.



[출력]

출력의 각 줄은 ‘#x’로 시작하고, 공백을 한 칸 둔 다음 동작시켜야 하는 발사기의 최소 개수를 출력한다. 단, x는 테스트 케이스의 번호이다.



[입력 예]

3                         // 테스트 케이스의 수

1                         // N = 1, 테스트 케이스 #1

8 2

3                         // N = 3, 테스트 케이스 #2

2 2

4 2

6 2

3                         // N = 3, 테스트 케이스 #3

2 2

50 2

98 4





[출력 예]

#1 1

#2 2

#3 3
*/

#include <iostream>
#include <algorithm>
#include <utility>
bool board[15001];

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, N;
	cin >> T;

	for(int testCase = 1; testCase <= T; testCase++){
		int cnt(0);
		pair<int, int> raser[502]; //first 위치 second 강도
		cin >> N;
		fill(board, board + 15002, false);

		for (int i = 1; i <= N; i++) {
			int pos, power;
			cin >> pos >> power;
			raser[i] = make_pair(pos, power);
		}

		for (int i = 1; i <= N; i++) {
			if (board[raser[i].first] == false) { //폭발하지 않은 발사기일 경우
				int start = raser[i].first - raser[i].second;
				if (start < 1) start = 1;
				int end = raser[i].first + raser[i].second;
				if (end > 10000) end = 10000;
				for (int cur = start; cur <= end; cur++) { //폭파
					if (cur < 1) cur = 1;
					board[cur] = true;
				}
				cnt++;
			}
		}
		
		cout << "#" << testCase << " " << cnt << "\n";
	}

	return 0;
}
/*
1
3
2 2
4 2
6 2


3
1
8 2
3
2 2
4 2
6 2
3
2 2
50 2
98 4
*/