#include <iostream>
using namespace std;

double sum_grade(0), sum_credit(0);

void calculatorAvgGrade(){
    std::string name_subject, grade;
    double credit;

    cin >> name_subject >> credit >> grade;

    if(grade == "P")
        return;
    else if(grade == "A+"){
        sum_credit += credit;
        sum_grade += credit * 4.5;
    }
    else if(grade == "A0"){
        sum_credit += credit;
        sum_grade += credit * 4.0;
    }
    else if(grade == "B+"){
        sum_credit += credit;
        sum_grade += credit * 3.5;
    }
    else if(grade == "B0"){
        sum_credit += credit;
        sum_grade += credit * 3.0;
    }
    else if(grade == "C+"){
        sum_credit += credit;
        sum_grade += credit * 2.5;
    }
    else if(grade == "C0"){
        sum_credit += credit;
        sum_grade += credit * 2.0;
    }
    else if(grade == "D+"){
        sum_credit += credit;
        sum_grade += credit * 1.5;
    }
    else if(grade == "D0"){
        sum_credit += credit;
        sum_grade += credit * 1.0;
    }
    else if(grade == "F"){
        sum_credit += credit;
        sum_grade += credit * 0;
    }
};

int main() {
    for(int i=0; i<20; i++){
        calculatorAvgGrade();
    }
    cout << sum_grade/sum_credit;
    return 0;
}
