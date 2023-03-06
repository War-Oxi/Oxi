#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    int add_num=6;
    int move_distance(1);
    int i=1;

    while (i < N) {
        i += add_num;
        add_num += 6;
        move_distance++;
        cout << i << endl;
    }

    cout << move_distance << endl;
    return 0;
}
