#include <iostream>
using namespace std;

int getNumOfCases(int num_in);

int main() {
    int N;
    cin >> N;

    for(int test_case=1; test_case<=N; test_case++){
        int test_num;
        cin >> test_num;

        cout << getNumOfCases(test_num);
    }
    return 0;
}

int getNumOfCases(int num_in) {
    int count(1);
    if(num_in % 2 == 0) count++;
    int min_num_of_num;
    if(num_in % 3 == 0)
        min_num_of_num = num_in / 3;
    else
        min_num_of_num = num_in / 3 + 1;


    for (int i = num_in-1; i >= min_num_of_num; i--) {
        count += i;
        if(i == num_in-1) continue;
        for (int j = 1; j < i-1; j++) {
            count += j;
        }
    }

    return count;
}
