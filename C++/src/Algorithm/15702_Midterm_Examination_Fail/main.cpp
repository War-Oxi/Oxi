//! 15702 중간고사 채점
#include <iostream>

using namespace std;

int main() {
    int num_of_questions(0), num_of_applicant(0);
    cin >> num_of_questions >> num_of_applicant;

    if(!(1 <= num_of_questions && num_of_questions <= 100 && 1 <= num_of_applicant && num_of_applicant <= 100)){
        return 0;
    }

    int questions_allocation[num_of_questions];

    for (int i = 0; i<num_of_questions; i++){
        cin >> questions_allocation[i];
        if (questions_allocation[i] < 100)
            continue;
        else
            break;
    }

    string best_applicant("-1");
    int max_total_point(0);

    for (int j = 0; j<num_of_applicant; j++){
        int applicant_total_point(0);
        string applicant_result[num_of_questions+1];
        for (int k = 0; k<num_of_questions+1; k++){
            cin >> applicant_result[k];
            if(k == 0 && stoi(applicant_result[k]) > 100000)
                return 0;

            if (k > 0 && applicant_result[k] == "O")
                    applicant_total_point += questions_allocation[k - 1];
        }
        if(applicant_total_point > max_total_point){
            best_applicant = applicant_result[0];
            max_total_point = applicant_total_point;
        }
        else if((applicant_total_point == max_total_point) && (stoi(best_applicant) > stoi(applicant_result[0]))){
            best_applicant = applicant_result[0];
        }
    }

    cout << best_applicant << " " << max_total_point << endl;
    return 0;
}