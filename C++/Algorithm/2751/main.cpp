#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//void sort(vector<int>& vec){
//
//}
bool compare(int a, int b){
    return a < b;
}

int main() {
    int T;
    cin >> T;

    vector<int> my_vec;

    my_vec.reserve(T);

    for (int test_case = 0; test_case < T; test_case++){
        int tmp;
        cin >> tmp;
        my_vec.push_back(tmp);
    }

    std::sort(my_vec.begin(), my_vec.end(), compare);

    for (auto & ele : my_vec){
        cout << ele << "\n";
    }

    return 0;
}
