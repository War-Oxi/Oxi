//3085_캔디게임 [상근이 돼지]
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


    int candy_max(0);

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