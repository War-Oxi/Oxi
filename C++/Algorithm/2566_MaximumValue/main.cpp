#include <iostream>
#include <vector>
using namespace std;

int main() {
    std::vector<std::vector<int>> my_vec(10);
    std::vector<int> tmp_vec(10);

    for(int i=1; i<10; i++){
        for(int j=1; j<10; j++){
            int tmp;
            cin >> tmp;
            tmp_vec[j] = tmp;
        }
        my_vec[i] = tmp_vec;
    }

    int row_index(0), col_index(0), max_value(-1);
    for(int i=1; i<10; i++){
        for(int j=1; j<10; j++){
            if(my_vec[i][j] > max_value){
                max_value = my_vec[i][j];
                row_index = i;
                col_index = j;
            }
        }
    }

    cout << max_value << "\n" << row_index << " " << col_index << endl;

    return 0;
}
