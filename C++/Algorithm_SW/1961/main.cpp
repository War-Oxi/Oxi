#include <iostream>
#include <vector>

using namespace std;

void rotateMatrix(vector<vector<int>> matrix_in, int matrix_size){
    for(int i=0; i<matrix_size; i++){

    }
}

int main() {
    int test_case, T;
    cin >> T;

    for (test_case=1; test_case<=T; test_case++){
        int matrix_size;
        cin >> matrix_size;

        vector<vector<int>> matrix;
        for(int i=0; i<matrix_size; i++){
            vector<int> tmp;
            for(int j=0; j<matrix_size; j++){
                int num_in;
                cin >> num_in;
                tmp.push_back(num_in);
            }
            matrix.push_back(tmp);
        }
        rotateMatrix(matrix, matrix_size);
    }
    return 0;
}