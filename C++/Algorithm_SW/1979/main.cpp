#include <iostream>
using namespace std;

int getNumOfPlaceWord(int puzzle_size, int word_size) {
    int puzzle[puzzle_size][puzzle_size];
    for (int i = 0; i < puzzle_size; i++) {
        for (int j = 0; j < puzzle_size; j++) {
            cin >> puzzle[i][j];
        }
    }
    int num_of_place_word(0);
    //row_check
    for (int i = 0; i < puzzle_size; i++) {
        int count(0);
        for (int j = 0; j < puzzle_size; j++) {
            if (puzzle[i][j] == 1) {
                count++;
            }
            if (count == word_size && (puzzle[i][j] != 1 || j == puzzle_size-1)) {
                num_of_place_word++;
                count = 0;
            }
            else if(puzzle[i][j] != 1)
                count = 0;
        }
    }
    //col_check
    for (int i = 0; i < puzzle_size; i++) {
        int count(0);
        for (int j = 0; j < puzzle_size; j++) {
            if (puzzle[j][i] == 1) {
                count++;
            }
            if (count == word_size && (puzzle[j][i] != 1 || j == puzzle_size-1)) {
                num_of_place_word++;
                count=0;
            }
            else if(puzzle[j][i] != 1)
                count = 0;
        }
    }
    return num_of_place_word;
}
int main() {
    int test_case;
    cin >> test_case;

    for(int i=1; i<=test_case; i++){
        int puzzle_size, word_size;
        cin >> puzzle_size >> word_size;
        cout << "#" << i << " " << getNumOfPlaceWord(puzzle_size, word_size) << endl;
    }


    return 0;
}
