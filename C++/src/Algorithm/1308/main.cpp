#include <iostream>

using namespace std;
/**
 * 1. 배열을 사용해서 Month 만들기
 * 2. Year 차이를 없애주기
 *  2.1 Year < 1일 때, Year > 1 일 때 (차이가)
 * 3. Month 차이를 없애주기
 *  3.1 Month < 1일 때, Month > 1 일 떄 (차이가)
 * 4. Day 차이를 없애주기
 *  4.1 Day < 1일 때, Day > 1 일 때 (차이가)
 * 5. 윤년 계산하기
 *  5.1 윤년일 떄
 *  5.2 윤년일 때 (start_month가 2보다 클 때)
 *  5.3 윤년일 떄 (end_month가 2보다 작을 때)
 * @return
 */

int g_month[] = {31, 28, 31, 30, 31, 30,
                 31, 31, 30, 31, 30, 31};

int YearCalculator(int start_year, int start_month, int start_day, int end_year, int end_month, int end_day);
bool CheckLeapYear (int year);

int main()
{
    int start_year(0), start_month(0), start_day(0);
    int end_year(0), end_month(0), end_day(0);

    cin >> start_year >> start_month >> start_day;
    cin >> end_year >> end_month >> end_day;

    int diff_year(end_year - start_year);
    int diff_month(end_month - start_month);
    int diff_day(end_day - start_day);

    if(diff_year < 1000 || (diff_year == 1000 && diff_month < 0) || (diff_year == 1000 && diff_month == 0 && diff_day < 0)) {
        cout << "D-" << YearCalculator(start_year, start_month, start_day, end_year, end_month, end_day) << endl;
    }
    else {
        cout << "gg" << endl;
    }

    return 0;
}

int YearCalculator(int start_year, int start_month, int start_day, int end_year, int end_month, int end_day) {

    int count(0);

    if (start_day > end_day) {
        count += g_month[start_month - 1] - start_day;
        count += end_day;
    } else //start_day<=end_day
    {
        count += end_day - start_day;
    }

    /**
     * 년도가 다르고 start_month가 end_month보다 클 때
     * 년도가 다르고 start_month가 end_month보다 작을 때
     * 년도가 같을 때
     */
    if (start_year != end_year) {
        for (int i(start_year); i < end_year; i++) {
            if (CheckLeapYear(i)) {
                count++;
            }
        }
        if ((CheckLeapYear(start_year) && start_month > 2) && (CheckLeapYear(end_year) && end_month < 2)) {
            count -= 2; // start_month > 2 end_month < 2
        }
        else if ((CheckLeapYear(start_year) && start_month > 2) || (CheckLeapYear(end_year) && end_month < 2)) {
            count -= 1;
        }
        // 년도, 월 차이
        if (start_month < end_month) {
            for (; start_year < end_year; start_year++) {
                count += 365;
            }
            if (start_day > end_day) {
                for (; start_month + 1 < end_month; start_month++) {
                    count += g_month[start_month];
                }
            }
            else {
                for (; start_month < end_month; start_month++) {
                    count += g_month[start_month - 1];
                }
            }
        }
        else if (start_month >= end_month) { // = else
            for (; start_year < end_year; start_year++) {
                count += 365;
            }
            if (start_day > end_day) {
                for (; start_month + 1 > end_month; start_month--) {
                    count -= g_month[start_month - 1];
                }
            }
            else {
                for (; start_month > end_month; start_month--) {
                    count -= g_month[start_month - 2];
                }
            }
        }
    }
    else //start_year == end_year
    {
        if (CheckLeapYear(start_year) && start_month < 3 && end_month >= 3) {
            count++;
        }
        if (start_day > end_day) {
            for (; start_month + 1 < end_month; start_month++) {
                count += g_month[start_month];
            }
        }
        else {
            for (; start_month < end_month; start_month++) {
                count += g_month[start_month - 1];
            }
        }
    }
    return count;
}

bool CheckLeapYear (int year) {
    if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) {
        return true;
    }
    else {
        return false;
    }
}