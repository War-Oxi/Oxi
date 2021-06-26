//!문제1
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main(void)
{
    int Num[10], result;
    for(int i=1; i<=5; i++){
        cout<<i<<"번째 정수 입력: ";
        cin>>Num[i];
    }
    for(int i=1; i<=5; i++){
        result += Num[i];
    }
    cout<<"합계: "<<result<<endl;
}
//!문제2
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main(void)
{
    char Name[10];
    char Phone_NUM[15];

    cout<<"당신의 이름과 전화번호를 입력하세요";
    cin>>Name;
    cin>>Phone_NUM;

    cout<<"이름 : "<<Name<<endl<<"전화번호 : "<<Phone_NUM<<endl;
}
//!문제3
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main(void)
{
    int  Num = 0, result;
    cout<<"What numbers do you want to print out?(9*9)";
    cin>>Num;

    for(int i=1; i<=9; i++){
        cout<<Num<<" * "<<i<<" = "<<Num * i<<endl;
    }
}
//!문제4
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main(void)
{
    int Sales_Amount, Total_Amount;
    while(1){
        cout<<"판매 금액을 만원 단위로 입력(-1 to end): ";
        cin>>Sales_Amount;
        if(Sales_Amount == -1){
            cout<<"프로그램을 종료합니다."<<endl;
            break;
        }
        Total_Amount = 50 + Sales_Amount*0.12;
        cout<<"이번 달 급여: "<<Total_Amount<<"만원"<<endl;
    }
}