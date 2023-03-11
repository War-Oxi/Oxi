#include <iostream>
#include <vector>
#include <queue> // queue를 써야할 것 같음
#include <algorithm>

using namespace std;

/**
 * 입력을 받으면서  max_element의 위치를 찾는다. vector 사용 max_idx;
 * vec.begin 부터 max_idx까지 이익을 계산한다.
 *
 * max_idx부터 반복문을 다시 실행 하여 다음 max_idx를 찾는다.
 */
 
long long getProfit(int vec_size)
{
    std::vector<int> my_vec;
    my_vec.reserve(vec_size);

    //입력
    for(int i=0; i<vec_size; i++){
        int tmp;
        cin >> tmp;
        my_vec.push_back(tmp);
    }

    vector<int>::reverse_iterator r_itr;

    //값 계산
    int max_value(*my_vec.rend());
    long long profit(0);
    for(r_itr = my_vec.rbegin(); r_itr != my_vec.rend(); r_itr++){
        if(*r_itr > max_value)
            max_value = *r_itr;
        else
            profit += max_value - *r_itr;
    }

    return profit;
//    cout << "#" profit;
}

int main() {
    int test_case, t_num;
    cin >> test_case;

    for(int i=0; i < test_case; i++){
        cin >> t_num;
        long long profit(getProfit(t_num));

        cout << "#" << i+1 << " " << profit << endl;
    }

    return 0;
}
