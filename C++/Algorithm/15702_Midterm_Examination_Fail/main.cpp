#include <iostream>

using namespace std;

int main() {
    int num_of_questions(0), num_of_applicant(0);
    cin >> num_of_questions >> num_of_applicant;
    if(num_of_questions<0 || num_of_questions>100 || num_of_applicant<0 || num_of_applicant>100){
        return 0;
    }
    int questions_allocation[num_of_questions];

    for (int i = 0; i<num_of_questions; i++){
        cin >> questions_allocation[i];
    }

    int best_applicant;
    int max_total_point(0);
    for (int j = 0; j<num_of_applicant; j++){
        int applicant_total_point(0);
        int applicant_num(0);
        string applicant_result[num_of_questions];
        for (int k = 0; k<num_of_questions+1; k++){
            if(k==0){
                cin >> applicant_num;
                if(applicant_num > 100000){
                    return 0;
                }
            }
            else{
                cin >> applicant_result[k-1];
                if(applicant_result[k-1] == "O")
                    applicant_total_point += questions_allocation[k-1];
            }
        }
        if(applicant_total_point == max_total_point && best_applicant > applicant_num){
            best_applicant = applicant_num;
        }
        if(applicant_total_point > max_total_point){
            best_applicant = applicant_num;
            max_total_point = applicant_total_point;
        }
    }

    cout << best_applicant << " " << max_total_point << endl;

    return 0;
}
