#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N, M;
    cin >> N;

    vector<int> in_hand_card;  // 갖고 있는 카드
    in_hand_card.reserve(N);

    for (int i=0; i<N; i++){
        int tmp;
        cin >> tmp;
        in_hand_card.push_back(tmp);
    }

    std::sort(in_hand_card.begin(), in_hand_card.end());

    cin >> M;

    vector<int> find_card; // 찾는 카드
    find_card.reserve(M);
    for (int i=0; i<M; i++){
        int tmp;
        cin >> tmp;
        find_card.push_back(tmp);
    }

    for (auto & ele : find_card){
        cout << upper_bound(in_hand_card.begin(), in_hand_card.end(), ele)
        - lower_bound(in_hand_card.begin(), in_hand_card.end(), ele) << " ";
    }

}
//int main() {
//    int N, M;
//    cin >> N;
//
//    vector<int> have_card_arr;
//    for(int i = 1; i <= N; i++){
//        int tmp;
//        cin >> tmp;
//        have_card_arr.push_back(tmp);
//    }
//
//    cin >> M;
//
//    vector<int> find_card_arr;
//    for(int i = 1; i <= M; i++){
//        int tmp;
//        cin >> tmp;
//        find_card_arr.push_back(tmp);
//    }
//
//    for(auto & ele : find_card_arr){
//        int count(0);
//        auto idx = find_card_arr.begin();
//        while (std::find(have_card_arr.begin(), have_card_arr.end(), ele) != have_card_arr.end()){
//            auto idx = std::find(have_card_arr.begin(), have_card_arr.end(), ele) - have_card_arr.begin();
////            cout <<idx << endl;
//            have_card_arr[idx] = -1;
//            count++;
//        }
//        cout << count << " " ;
//    }
//
//    return 0;
//}
