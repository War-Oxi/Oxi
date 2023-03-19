#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int getLightHouseNum(int num_of_house) {
    vector<int> house_height_vec(num_of_house);
    for (int i = 0; i < num_of_house; ++i) {
        cin >> house_height_vec[i];
    }

//    int count(0);
//    for (auto & ele : house_height_vec){
//        count++;
//        cout << ele << " ";
//        if(count % 10 == 0)
//            cout << endl;
//    }
    int house_num(0);

    for (int i = 0; i < num_of_house; i++) {
        //i가 0, 1, num_of_house-1, num_of_house 일 경우 Algorithm 구현필요
        if(i == 0){
            if( house_height_vec[i] > house_height_vec[i + 1] &&
                house_height_vec[i] > house_height_vec[i + 2]  ){
                int tmp = house_height_vec[i];
                house_height_vec[i] = 0;
                house_num += tmp - *max_element(house_height_vec.begin()+i, house_height_vec.begin()+i+2);
                house_height_vec[i] = tmp;
            }
        }
        else if(i == 1){
            if( house_height_vec[i - 1] < house_height_vec[i] &&
                house_height_vec[i] > house_height_vec[i + 1] &&
                house_height_vec[i] > house_height_vec[i + 2]  ){
                int tmp = house_height_vec[i];
                house_height_vec[i] = 0;
                house_num += tmp - *max_element(house_height_vec.begin()+i-1, house_height_vec.begin()+i+3);
                house_height_vec[i] = tmp;
            }
        }
        else if(i == num_of_house-2){
            if( house_height_vec[i - 2] < house_height_vec[i] &&
                house_height_vec[i - 1] < house_height_vec[i] &&
                house_height_vec[i] > house_height_vec[i + 1]) {
                int tmp = house_height_vec[i];
                house_height_vec[i] = 0;
                house_num += tmp - *max_element(house_height_vec.begin()+i-2, house_height_vec.end());
                house_height_vec[i] = tmp;
            }
        }
        else if(i == num_of_house-1){
            if( house_height_vec[i - 2] < house_height_vec[i] &&
                house_height_vec[i - 1] < house_height_vec[i]){
                int tmp = house_height_vec[i];
                house_height_vec[i] = 0;
                house_num += tmp - *max_element(house_height_vec.begin()+i-2, house_height_vec.end());
                house_height_vec[i] = tmp;
            }
        }
        else {
            if( house_height_vec[i - 2] < house_height_vec[i] &&
                house_height_vec[i - 1] < house_height_vec[i] &&
                house_height_vec[i] > house_height_vec[i + 1] &&
                house_height_vec[i] > house_height_vec[i + 2]  ){
                int tmp = house_height_vec[i];
                house_height_vec[i] = 0;
                house_num += tmp - *max_element(house_height_vec.begin()+i-2, house_height_vec.begin()+i+3);
                house_height_vec[i] = tmp;
            }
        }
    }
    return house_num;
}

int main() {
    int test_case(10);

    for(int i=1; i<=test_case; ++i){
        int house_num(0);
        cin >> house_num;
        cout << "#" << i << " " << getLightHouseNum(house_num) << endl;
    }

    return 0;
}
