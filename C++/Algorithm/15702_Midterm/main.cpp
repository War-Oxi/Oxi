#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int exam_score[N];
    for(int i=0; i<N; i++){
        cin >> exam_score[i];
    }

    string student_info[M][N+1];

    for(int i=0; i<M; i++){
        for(int j=0; j<N+1; j++){
            cin >> student_info[i][j];
        }
    }

    int max_score(-1), student_num(-1);
    for(int i=0; i<M; i++){
        int tmp_score(0), tmp_num(std::stoi(student_info[i][0]));
        for(int j=1; j<N+1; j++){
            if(student_info[i][j] == "O"){
                tmp_score += exam_score[j-1];
            }
        }
        if(max_score <= tmp_score){
            if(max_score == tmp_score && student_num < tmp_num)
                continue;
            max_score = tmp_score;
            student_num = tmp_num;
        }
    }

    cout << student_num << " " << max_score;

    return 0;
}
