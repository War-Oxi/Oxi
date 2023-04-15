#include <iostream>
#include <vector>
using namespace std;


void inputSudoku(vector<vector<int>> &sudoku_in) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku_in[i][j];
        }
    }
}

bool checkerSudoku(const vector<vector<int>> &sudoku_in) {
    for(int i=0; i<9; i++){
        bool checker_row[10];
        bool checker_col[10];
        bool checker_square[10];
        for(int j=0; j<9; j++){
            if(sudoku_in[i][j]){

            }
        }
    }

    return true;
}

int main() {
    int test_case;
    cin >> test_case;

    for (int i = 1; i <= test_case; i++) {
        vector<vector<int>> sudoku(9, vector<int>(9));
        inputSudoku(sudoku);
        cout << "#" << i << " " << checkerSudoku(sudoku) << endl;
    }
}