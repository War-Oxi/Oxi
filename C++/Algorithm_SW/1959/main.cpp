#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int test_case, T;
    cin >> T;

    for(test_case = 1; test_case <= T; test_case++){
        int first, second;
        cin >> first >> second;

        vector<int> first_vec, second_vec;
        if(first > second){
            first_vec.resize(first);
            second_vec.resize(first);
        }
        else{
            first_vec.resize(first);
            second_vec.resize(second);
        }

        // input_vec
        for(int i=0; i < first; i++){
            cin >> first_vec[i];
        }

        for(int i=0; i<second; i++){
            cin >> second_vec[i];
        }

        if(first > second){
            swap(first_vec, second_vec);
            swap(first, second);
        }

        int max_num(0);
        for(int i=0; i<=second-first; i++){
            int sum(0);
            for(int j=i; j<i+first; j++){
                sum += first_vec[j-i] * second_vec[j];
            }
//            cout << sum << " ";
            if(sum > max_num)
                max_num = sum;
        }

//        cout << endl;
        cout << "#" << test_case << " " << max_num << endl;
    }

    return 0;
}
