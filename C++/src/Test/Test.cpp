#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>


using namespace std;

int main(){
//    int arr_1[] = {1,2,3,4,5,6,7,8,10,200,7,11,2,22,33};
    vector<int> arr_1 = {1,2,3,4,5,6,7,8,10,200,7,11,2,22,33};

    int max_num = std::numeric_limits<int>::lowest();

    for(const auto &num: arr_1){
        max_num = std::max(num, max_num);
    }

    cout << max_num << endl;


}