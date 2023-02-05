#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int repeat_num(0);
    cin >> repeat_num;

    vector<int> cog;
    for(int i = 0; i<repeat_num; i++){
        int temp_num(-1);
        cin >> temp_num;
        if(temp_num == 0){
            cog.pop_back();
        }
        else{
            cog.push_back(temp_num);
        }
    }

    int sum(0);
    for(auto &num : cog){
        sum += num;
    }
    cout << sum;

    return 0;
}
