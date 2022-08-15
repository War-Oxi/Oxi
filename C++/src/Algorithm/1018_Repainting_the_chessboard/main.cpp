#include <iostream>
using namespace std;

int main() {
    int row(0), line(0);
    cin >> row >> line;

    char chess1[8][8];
    char chess2[8][8];
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(i%2==0){
                if(j%2==0){
                    chess1[i][j] = 'W';
                    chess2[i][j] = 'B';
                }
                else{
                    chess1[i][j] = 'B';
                    chess2[i][j] = 'W';
                }
            }
            else{
                if(j%2==0){
                    chess1[i][j] = 'B';
                    chess2[i][j] = 'W';
                }
                else{
                    chess1[i][j] = 'W';
                    chess2[i][j] = 'B';
                }
            }
        }
    }

    char board[row][line];
    for(int i=0; i<row; i++){
        for(int j=0; j<line; j++){
            cin >> board[i][j];
        }
    }
    int max_count(0);
    for(int i=0; i<=line - 8; i++){
        int count(0);
        for(int j=0; j<=row - 8; j++){
            for(int k=i; k <= k+8; k++){
                for(int l=j; l <= l+8; l++){
                    count++;
                }
            }
            max_count = count;
        }
    }

    cout << max_count << endl;

    return 0;
}
