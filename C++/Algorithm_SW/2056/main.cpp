#include <iostream>
#include <string>
using namespace std;

int main() {
    int test_case;
    cin >> test_case;
    int mon_day[13] {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::string my_str;

    for (int i=1; i<=test_case; i++){
        bool flag = true;
        cin >> my_str;
        std::string year, month, day;

        for(int y=0; y<4; y++)
            year += my_str[y];

        for(int mon=4; mon<6; mon++)
            month += my_str[mon];

        for(int d=6; d<8; d++)
            day += my_str[d];

        int mon_int, day_int;

        mon_int = stoi(month);
        day_int = stoi(day);

        if(mon_int < 0 || mon_int > 12)
            flag = false;
        else{
            if(day_int < 0 || day_int > mon_day[mon_int])
                flag = false;
        }

        if (flag)
            cout << "#" << i << " " << year << "/" << month << "/" << day << endl;
        else
            cout << "#" << i << " " << "-1" << endl;
    }

    return 0;
}
