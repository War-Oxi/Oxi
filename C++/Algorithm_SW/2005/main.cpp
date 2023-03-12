#include <iostream>
#include <vector>

using namespace std;

void drawTriangle(int row_size){
    std::vector<int> my_vec;
    my_vec.push_back(1);
    for(int i=1; i<=row_size; i++){
        std::vector<int> tmp_vec(i);
        tmp_vec[0] = 1;
        tmp_vec[i-1] = 1;
        if(i >= 2){
            for(int j=1; j<i; j++){
                tmp_vec[j] = my_vec[j-1] + my_vec[j];
            }
            swap(my_vec, tmp_vec);
        }
        for(auto & e : my_vec)
            cout << e << " ";
        cout << endl;
    }
}

int main() {
    int T;
    cin >> T;
    for(int i=1; i<=T; i++){
        int test_data;
        cin >> test_data;
        cout << "#" << i << endl;
        drawTriangle(test_data);
    }

    return 0;
}


/**
*                  1
 *              1     1
 *           1     2     1
 *        1     3     3     1
 *     1     4     5     4     1
 *  1     5     9     9     5     1
 *
 *  triangle size => rowsize
 *  [0][0] = 1
 *  [1][0] = 1 [1][1] = 1
 *  [2][0] = 1 [2][1] = [1][0] + [1][1] [2][2] = 1
 *  [3][0] = 1 [3][1] = [2][0] + [2][1]
*/