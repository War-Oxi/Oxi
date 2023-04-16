#include <iostream>
#include <vector>
using namespace std;


void inputSudoku(vector<vector<int>> &sudoku_in) {
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> sudoku_in[i][j];
        }
    }
}

bool checkerSudoku(const vector<vector<int>> &sudoku_in) {
    for(int i=1; i<=9; i++){
        bool checker_row[10] = {false, };
        bool checker_col[10] = {false, };
        bool checker_square[10] {false, };
        for(int j=1; j<=9; j++){
            checker_row[sudoku_in[i][j]] = true;
            checker_col[sudoku_in[j][i]] = true;

            if(i % 3 == 1 && j % 3 == 1){
                for(int row=i; row<i+3; row++){
                    for(int col=j; col<j+3; col++){
                        checker_square[sudoku_in[row][col]] = true;
                    }
                }
                for(int test=1; test<=9; test++){
                    if(!checker_square[test])
                        return false;
                }
            }
        }

        for(int test=1; test<=9; test++){
            if(!checker_row[test] || !checker_col[test])
                return false;
        }
    }

    return true;
}

int main() {
    int test_case;
    cin >> test_case;

    for (int i = 1; i <= test_case; i++) {
        vector<vector<int>> sudoku(10, vector<int>(10));
        inputSudoku(sudoku);
        cout << "#" << i << " " << checkerSudoku(sudoku) << endl;
    }
}