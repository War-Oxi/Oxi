#include <iostream>
#include <vector>
using namespace std;

int month_date[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    int test_case, T;
    cin >> T;

    for(test_case=1; test_case<=T; test_case++){
        int first_month, first_day, second_month, second_day;
        cin >> first_month >> first_day >> second_month >> second_day;

        int day(1);
        if(first_month != second_month){
            day += month_date[first_month]-first_day;
            for(int i=first_month+1; i<second_month; i++){
                day += month_date[i];
            }

            day += second_day;
        }
        else{
            day += second_day - first_day;
        }

        cout << "#" << test_case << " " << day << endl;
    }

    return 0;
}
