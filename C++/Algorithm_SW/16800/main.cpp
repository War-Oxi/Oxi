#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

long long getMinMoveNum(long long num_in){
    long long x_pos(1), y_pos(1);
    long long x_target, y_target;
    long long num_sqrt = (int)sqrt(num_in);

    while(true){
        if(num_in % num_sqrt == 0){
            x_target = num_sqrt;
            y_target = num_in / num_sqrt;
            break;
        }
        num_sqrt--;
    }

    return (x_target-x_pos)+(y_target-y_pos);
}

int main() {
    int TC;
    cin >> TC;

    for(int test_case=1; test_case<=TC; test_case++){
        long long num_in;
        cin >> num_in;

        long long min_move_num = getMinMoveNum(num_in);

        cout << "#" << test_case << " " << min_move_num << endl;
    }

    return 0;
}
