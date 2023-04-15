#include <iostream>
using namespace std;
long long dp[101];

int main() {
    int test_case;
    cin >> test_case;

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;

    for(int i=5; i<101; i++){
        dp[i] = dp[i-2] + dp[i-3];
    }

    int N;
    for(int i=0; i<test_case; i++){
        cin >> N;
        cout << dp[N] << endl;
    }
    return 0;
}
