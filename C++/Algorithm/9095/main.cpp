//#include <iostream>
//using namespace std;
//
//int getNumOfCases(int num_in);
//
//int main() {
//    int N;
//    cin >> N;
//
//    for(int test_case=1; test_case<=N; test_case++){
//        int test_num;
//        cin >> test_num;
//
//        cout << getNumOfCases(test_num) << endl;
//    }
//    return 0;
//}
//
//int getNumOfCases(int num_in) {
//    int count(1);
//    int dp[num_in + 1];
//    dp[0] = 0;
//    dp[1] = 1;
//    dp[2] = 2;
//    dp[3] = 4;
//
//    for(int i=4; i<=num_in; i++){
//        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
//    }
//
//    return dp[num_in];
//}

#include <iostream>
using namespace std;

int count;

void get_num(int sum, int num){
    if(sum == num){
        count++;
        return;
    }

    if(num < sum){
        return;
    }

    for(int i=1; i<=3; i++){
        get_num(sum + i, num);
    }
}

int main(){
    int test_case;
    cin >> test_case;

    for(int i=0; i<test_case; i++){
        int num_in;
        cin >> num_in;
        count = 0;
        get_num(0, num_in);
        cout << count << endl;
    }
}