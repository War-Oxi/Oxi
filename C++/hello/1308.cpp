#include "iostream"

int totalMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
int DDay(int smallMonth, int bigMonth);
bool LeapYearConfirmation(int year);
int main(){
    int year,month,day;
    int dYear,dMonth,dDay;
    int resultDay = 0;

    int yearGap,monthGap,dayGap;

    std::cin >> year >> month >> day;
    std::cin >> dYear >> dMonth >> dDay;

//    year = 2022;
//    month = 06;
//    day = 23;
//
//    dYear = 2800;
//    dMonth = 12;
//    dDay = 26;

    yearGap = dYear - year;
    monthGap = dMonth - month;
    dayGap = dDay - day;
    if (yearGap>1000 || (yearGap==1000&&monthGap>0) || (yearGap==1000&&monthGap==0&&dayGap>=0)){
        std::cout<<"gg"<<std::endl;
        return 0;
    }

    for(year; year<dYear; year++){
        if(LeapYearConfirmation(year+1)){ //LeapYearConfirmation(year)== true
            resultDay += 366;
        }
        else{
            resultDay += 365;
        }
    }

    if(month > dMonth){
        resultDay -= DDay(dMonth, month);
    }
    else{
        resultDay += DDay(month, dMonth);
    }

    if(day > dDay){
        resultDay -= totalMonth[month-1];
        resultDay += dDay+totalMonth[month-1]-day;
    }
    else{
        resultDay += dDay-day;
    }

    std::cout<<"D-"<<resultDay<<std::endl;
}

int DDay(int smallMonth, int bigMonth){
    int day=0;

    for(smallMonth; smallMonth<bigMonth; smallMonth++){
        day += totalMonth[smallMonth-1];
    }

    return day;
}

bool LeapYearConfirmation(int year){
    if (year % 400 == 0)
        return true;
    else if (year % 100 == 0)
        return false;
    else if (year % 4 == 0)
        return true;
    else
        return false;
}