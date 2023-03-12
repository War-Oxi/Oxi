#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int getKillNum(vector<vector<int>> table, int table_size, int swatter_size){
    int max_kill_num(0);
    for(int i=0; i<=table_size-swatter_size; i++){
        for(int j=0; j<=table_size-swatter_size; j++){
            int count(0);
            for(int k=0; k<swatter_size; k++){
                for(int l=0; l<swatter_size; l++){
                    count += table[i+k][j+l];
                }
            }
            if (count > max_kill_num)
                max_kill_num = count;
        }
    }

    return max_kill_num;
}

vector<vector<int>> makeFlyTable(int size){
    vector<vector<int>> table_vec;
    vector<int> tmp_vec(size);
    for(int i=0; i<size; ++i)
        table_vec.push_back(tmp_vec);

    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            int tmp;
            cin >> tmp;
            table_vec[i][j] = tmp;
        }
    }
    return table_vec;
}

int main() {
    int test_case;
    cin >> test_case;

    for(int i=1; i<=test_case; i++){
        int table_size, swatter_size, kill_fly_num;
        cin >> table_size >> swatter_size;

        vector<vector<int>> table = makeFlyTable(table_size);
        kill_fly_num = getKillNum(table, table_size, swatter_size);
        cout << "#" << i << " " << kill_fly_num << endl;
    }
    return 0;
}
