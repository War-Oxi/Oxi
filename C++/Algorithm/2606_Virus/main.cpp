#include <iostream>
#include <vector>
using namespace std;
std::vector<std::vector<int>> computer_vec;

void connect(int num_of_computer);
void virusChecker(int num, std::vector<bool> &checker_board);

int main() {
    int num_of_computer;
    cin >> num_of_computer;

    std::vector<int> tmp;
    for(int i=0; i<num_of_computer; i++)
        computer_vec.push_back(tmp);

    std::vector<bool> check_board(num_of_computer+1, false);
//    std::vector<std::vector<bool>> check_board(num_of_computer+1, tmp_vec2);

    int num_connected;
    cin >> num_connected;

    connect(num_connected);


//    for(auto ele : computer_vec){
//        count++;
//        cout << count << " ";
//        for(auto ele2 : ele){
//            cout << ele2 << " ";
//        }
//        cout << endl;
//    }
//
    virusChecker(1, check_board);
//
//    for(auto ele : check_board){
//        cout << ele << " ";
//    }
//    cout << endl;

    int count(-1);
    for(auto ele : check_board){
        if(ele) count++;
    }
    cout << count << endl;
    return 0;
}

void connect(int num_connected)
{
    int tmp = num_connected;
    while(tmp){
        int computer1, computer2;
        cin >> computer1 >> computer2;

        computer_vec[computer1].push_back(computer2);
        computer_vec[computer2].push_back(computer1);

        --tmp;
    }
}

void virusChecker(int num, std::vector<bool> &checker_board)
{
    checker_board[num] = true;
    for(auto ele : computer_vec[num]){
        if(!checker_board[ele]){
            virusChecker(ele, checker_board);
        }
    }
}