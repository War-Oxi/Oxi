#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int test_case, T;
    cin >> T;

    for(test_case=1; test_case<=T; test_case++){
        int test_case_num;
        cin >> test_case_num;
        int score_arr[101]{0, };

        for(int i=1; i<=1000; i++){
            int score_in;
            cin >> score_in;

            score_arr[score_in]++;
        }

        int most_frequent_score;
        int most_frequent_count=0;
        for(int i=0; i<=100; i++){
            if(score_arr[i] >= most_frequent_count){
                most_frequent_count = score_arr[i];
                most_frequent_score = i;
            }
        }

        cout << "#" << test_case_num << " " << most_frequent_score << endl;
    }

    return 0;
}
