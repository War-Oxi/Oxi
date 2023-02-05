#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main(){
    std::array<int, 5> my_arr = {1, 2, 3, 4, 5};
    my_arr = {0,1,2,3,4};
//    my_arr = {0,1,2};

    cout << my_arr[5] << endl;
    cout << my_arr.at(2) << endl;
    cout << my_arr.size() << endl << endl;

    std::sort(my_arr.begin(), my_arr.end());
    for (auto &element : my_arr)
        cout << element << " ";
    cout << endl;

    std::sort(my_arr.rbegin(), my_arr.rend());
    for (auto &element : my_arr)
        cout << element << " ";
    cout << endl;

    return 0;
}