#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int test_case, t_num;
    cin >> test_case;

    for(int i=0; i < test_case; i++){
        cin >> t_num;
        vector<int> my_vec;
        my_vec.reserve(t_num);
    }

    /**
     * 1. 가격이 올라가다가 떨어질 때의 가격을 변수 target_price에 기록.
     * 2. target_price보다 높은 가격의 물건은 구매하지 않고, target_price보다 낮은 가격의 물건은 구매. my_vec.push_back()
     * 3. target_price에 도달하면 my_vec의 원소가 빌 때 까지
     */
//    vector<int> my_vec;
//    my_vec.pop_back();
//    for(auto & e : my_vec){
//        cout << e << endl;
//    }

    return 0;
}
