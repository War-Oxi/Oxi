#include <iostream>
using namespace std;

int main() {
    int test_case, T;
    cin >> T;

    for (test_case=1; test_case<=T; test_case++){
        int size;
        cin >> size;

        int arr[size][size];

        int row_min=0, row_max(size-1);
        int col_min=1, col_max(size-1);
        int cur_x(0), cur_y(0);
        int count(0);

        string direction("right");

        while(count < size*size){
            arr[cur_y][cur_x] = ++count;
            if(direction == "right"){
                cur_x++;
                if(cur_x >= row_max){
                    direction = "down";
                    row_max--;
                }
            }
            else if(direction == "down"){
                cur_y++;
                if(cur_y >= col_max){
                    direction = "left";
                    col_max--;
                }
            }
            else if(direction == "left"){
                cur_x--;
                if(cur_x <= row_min){
                    direction = "up";
                    row_min++;
                }
            }
            else if(direction == "up"){
                cur_y--;
                if(cur_y <= col_min){
                    direction = "right";
                    col_min++;
                }
            }
            else{
                cout << "Error Occurred direction => " << direction << endl;
                break;
            }
        }
        //출력
        cout << "#" << test_case << endl;
        for(auto & ele_arr : arr){
            for(auto & ele : ele_arr){
                cout << ele << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
