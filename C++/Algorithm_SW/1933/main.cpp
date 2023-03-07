#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void sort(vector<int> &vec_in){
    vector<int>::iterator itr;

    for(auto itr = vec_in.begin(); itr != vec_in.end(); itr++){
        iter_swap(itr, min_element(itr, vec_in.end()));
    }
}

void factor(int a, vector<int> &vec_in) {
    if (a <= 0) {
        return;
    }

    for (int i = 1; i * i <= a; i++) {

        if (i * i == a) {
//            cout << i << "는 " << a << "의 중복되는 제곱수 " << endl;
            vec_in.push_back(i);
            vec_in.push_back(a);
        }else if (a % i == 0) {
            vec_in.push_back(i);
            vec_in.push_back(a);
//            cout << a << "의 약수 : " << i << ", "<< a / i << endl;
        }
    }
}

int main() {
    int N, i(1);
    cin >> N;
    bool flag;

    vector<int> my_vec;
    my_vec.reserve(N);
    factor(N, my_vec);

    sort(my_vec);
//    while(i<=N){
//        int tmp = N;
//        if(tmp % i == 0){
//            my_vec.push_back(i);
//        }
//        i++;
//    }
//
//    sort(my_vec);
//
    for (auto & ele : my_vec)
        cout << ele << " ";
    return 0;
}
