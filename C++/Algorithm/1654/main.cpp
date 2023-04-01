#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long getMaxLength(long long need_cable_num, const vector<long long>& cable_vec);

int main() {
    long long cable_num_in, need_cable_num;
    cin >> cable_num_in >> need_cable_num;

    vector<long long> cable_vec(cable_num_in);
    for(long long i=0; i<cable_num_in; ++i)
        cin >> cable_vec[i];

    cout << getMaxLength(need_cable_num, cable_vec) << "\n";

    return 0;
}

long long getMaxLength(long long need_cable_num, const vector<long long> &cable_vec) {
    long long max_cable_length = *max_element(cable_vec.begin(), cable_vec.end());
    long long min_cable_length = 1;
    long long cable_length, ans(0);

    while(min_cable_length <= max_cable_length){
        long long cable_num(0);
        cable_length = (max_cable_length + min_cable_length)/2;

        for(auto & ele : cable_vec)
            cable_num += ele / cable_length;

        if(cable_num >= need_cable_num){
            min_cable_length = cable_length+1;
            ans = max(ans, cable_length);
        }
        else{
            max_cable_length = cable_length-1;
        }
    }
    return ans;
}