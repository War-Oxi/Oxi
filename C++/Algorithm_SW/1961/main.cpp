#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> rotateMatrix(vector<vector<int>> matrix_in, int matrix_size){
    vector<vector<int>> rotated_matrix;
    for(int i=0; i<matrix_size; i++){
        vector<int> tmp;
        for(int j=matrix_size-1; j>=0; j--){
            tmp.push_back(matrix_in[j][i]);
        }
        rotated_matrix.push_back(tmp);
    }
    /**
    for (auto & ele_vec : rotated_matrix){ //출력부분
        for(auto & ele : ele_vec){
            cout << ele;
        }
        cout << endl;
    }
    */
    return rotated_matrix;
}

int main() {
    int test_case, T;
    cin >> T;

    for (test_case=1; test_case<=T; test_case++){
        int matrix_size;
        cin >> matrix_size;

        vector<vector<vector<int>>> matrix(4);
        for(int i=0; i<matrix_size; i++){
            vector<int> tmp;
            for(int j=0; j<matrix_size; j++){
                int num_in;
                cin >> num_in;
                tmp.push_back(num_in);
            }
            matrix[0].push_back(tmp);
        }

        //회전
        for(int i=1; i<4; i++){
            matrix[i] = rotateMatrix(matrix[i-1], matrix_size);
        }

        //출력
        cout << "#" << test_case << endl;
        for(int row=0; row<matrix_size; row++) {
            for (int i = 1; i < 4; i++) {
                for (int col = 0; col < matrix_size; col++) {
                    cout << matrix[i][row][col];
                }
                cout << " ";
            }
            cout << endl;
        }
    }
    return 0;
}