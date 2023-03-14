#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(int a, int b){
    return a > b;
}

string getDegree(int num_of_student, int num){
    double percentage = double(num) / num_of_student * 10;
    if(percentage <= 1)
        return "A+";
    else if(percentage <= 2)
        return "A0";
    else if(percentage <= 3)
        return "A-";
    else if(percentage <= 4)
        return "B+";
    else if(percentage <= 5)
        return "B0";
    else if(percentage <= 6)
        return "B-";
    else if(percentage <= 7)
        return "C+";
    else if(percentage <= 8)
        return "C0";
    else if(percentage <= 9)
        return "C-";
    else if(percentage <= 10)
        return "D0";

}

int main() {
    int test_case;
    cin >> test_case;


    for(int i=1; i<=test_case; i++){
        vector<int> my_vec;
        int num_of_student, find_student, find_score;
        cin >> num_of_student >> find_student;

        for(int j=0; j<num_of_student; j++){
            int middle_test_score, final_test_score, work_score;
            cin >> middle_test_score >> final_test_score >> work_score;

            middle_test_score *= middle_test_score*35/100;
            final_test_score *= final_test_score*45/100;
            work_score *= work_score*20/100;

            int total_score = middle_test_score + final_test_score + work_score;
            if(j == find_student - 1)
                find_score = total_score;

            my_vec.push_back(total_score);
        }
        std::sort(my_vec.begin(), my_vec.end(), compare);
        int idx = std::find(my_vec.begin(), my_vec.end(), find_score) - my_vec.begin() + 1;
//        cout << idx << endl;
        cout << "#" << i << " " << getDegree(num_of_student, idx) << endl;
    }

    return 0;
}
