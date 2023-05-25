#include <iostream>
#include <deque>
using namespace std;

void generatePassword(deque<int>& deque_in) {
	int num = 1;
	while (true) {
		int tmp;
		if (deque_in.front() > 0) {
			deque_in[0] -= num++;
			tmp = deque_in.front();

			if (tmp <= 0) {
				deque_in.pop_front();
				deque_in.push_back(0);
				return;
			}

			deque_in.pop_front();
			deque_in.push_back(tmp);

			if (num == 6)
				num = 1;
		}
		else return;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int tmp;
	for (int i = 1; i <= 10; i++) {

		deque<int> my_deque;
		int N;
		cin >> N;
		for (int i = 0; i < 8; i++) {
			cin >> tmp;
			my_deque.push_back(tmp);
		}

		generatePassword(my_deque);

		cout << "#" << N << " ";
		for (auto & ele : my_deque)
			cout << ele << " ";
		cout << "\n";
	}

	return 0;
}