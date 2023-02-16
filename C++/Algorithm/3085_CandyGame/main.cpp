#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void check(vector<vector<char>> vec, int row_col_size, int &maximum);

int main() {
    int N;
    cin >> N;

    vector<vector<char>> my_vec;
    vector<char> tmp_vec;

    for(int i=0; i<N; i++){
        char char_in;
        for(int j=0; j<N; j++){
            cin >> char_in;
            tmp_vec.push_back(char_in);
        }
        my_vec.push_back(tmp_vec);
        vector<char>().swap(tmp_vec);
    }

//    for(int i=0; i<N; i++){
//        for(int j=0; j<N; j++){
//            cout << my_vec[i][j] << " ";
//        }
//        cout << endl;
//    }

    int candy_max(0);
//    check(my_vec, N, candy_max);
//    check(my_vec, N, candy_max);
    for(int i=0; i<N; i++){
        for(int j=0; j<N-1; j++){
            if(my_vec[i][j] != my_vec[i][j+1]) {
                swap(my_vec[i][j], my_vec[i][j + 1]);
                check(my_vec, N, candy_max);
                swap(my_vec[i][j], my_vec[i][j + 1]);
            }
        }
    }
    for(int i=0; i<N-1; i++){
        for(int j=0; j<N; j++){
            if(my_vec[i][j] != my_vec[i+1][j]) {
                swap(my_vec[i][j], my_vec[i + 1][j]);
                check(my_vec, N, candy_max);
                swap(my_vec[i][j], my_vec[i + 1][j]);
            }
        }
    }

    cout << candy_max << endl;

    /**
     * 상근이가 먹을 수 있는 사탕의 최대 개수 구하기
     * 1. 왼쪽 or 오른쪽 => 다른 색 && 다른 한 쪽 => 같은 색
     *      1.왼쪽 다른 색 && 오른쪽 같은 색
     *      2.오른쪽 다른 색 && 왼쪽 같은 색
     * 2. 왼쪽, 오른쪽 모두 다른 색
     *      => 왼쪽 swap,후 위 아래 비교, 오른쪽 swap후 위 아래 비교.
     * 3. 왼쪽, 오른쪽 모두 같은 색
     *      => swap 불필요. 그냥 위 아래 비교.
     *
     *
     */

//    vector<vector<int>> my_vec;
//    vector<int> tmp_vec;
//
//    for(int i=0; i<7; i++)
//        tmp_vec.push_back(i);
//
//    my_vec.push_back(tmp_vec);
//    my_vec.push_back(tmp_vec);
//
//    for (int i = 0; i<7; i++){
//        for(int j = 0; j<7; j++){
//            cout << my_vec[i][j] << " ";
//        }
//        cout << endl;
//    }

    return 0;
}

void check(vector<vector<char>> vec, int row_col_size, int &maximum){
    //row check
    char tmp_char = '1';
    for(int i=0; i<row_col_size; i++){
        int count(0);
        tmp_char = vec[i][0];
        for(int j=0; j<row_col_size; j++){
            if(vec[i][j] == tmp_char){
                count++;
            }
            else{
                if(count > maximum){
                    maximum = count;
                }
                count = 1;
                tmp_char = vec[i][j];
            }
            if(count > maximum){
                maximum = count;
            }
        }
    }

    //col check
    for (int i=0; i<row_col_size; i++){
        int count(0);
        tmp_char = vec[0][i];
        for (int j=0; j<row_col_size; j++){
            if(vec[j][i] == tmp_char){
                count++;
            }
            else{
                if(count > maximum){
                    maximum = count;
                }
                count = 1;
                tmp_char = vec[j][i];
            }
            if(count > maximum){
                maximum = count;
            }
        }
    }
}