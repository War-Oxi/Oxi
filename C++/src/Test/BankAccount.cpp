/*
//*DefalultValue3.cpp

#include <iostream>
int BoxVolume(int length);
int BoxVolume(int length, int width);
int BoxVolume(int length, int width, int height);

int main(void)
{
    std::cout<<"[3, 3, 3] : "<<BoxVolume(3, 3, 3)<<std::endl;
    std::cout<<"[5, 5, D] : "<<BoxVolume(5, 5)<<std::endl;
    std::cout<<"[7, D, D] : "<<BoxVolume(7)<<std::endl;
    //std::cout<<"[D, D, D] : "<<BoxVolume()<<std::endl; //!디폴트 값이 지정되어 있지 않아 컴파일시 에러가 난다.

    return 0;
}

int BoxVolume(int length)
{
    int width = 1;
    int height = 1;
    return length*width*height;
}

int BoxVolume(int length, int width)
{
    int height = 1;
    return length*width*height;
}

int BoxVolume(int length, int width, int height)
{
    return length*width*height;
}
*/

/*
//*InlineFunc.cpp

#include <iostream>

inline int SQUARE(int x)
{
    return x*x;
}

int main(void)
{
    std::cout<<SQUARE(5)<<std::endl;
    std::cout<<SQUARE(5+7)<<std::endl;

    return 0;
}
*/
/*

//*NameSp1.cpp 
#include <iostream>

namespace BestComImp1
{
    void SimpleFunc(void)
    {
        std::cout<<"BestCom이 정의한 함수"<<std::endl;
    }
}

namespace ProgComImp1
{
    void SimpleFunc(void)
    {
        std::cout<<"ProgCom이 정의한 함수"<<std::endl;
    }
}

int main(void)
{
    BestComImp1::SimpleFunc();
    ProgComImp1::SimpleFunc();

    return 0;
}
*/
/*
//*NameSp3.cpp
#include <iostream>

namespace BestComImp1
{
    void SimpleFunc(void);
    void PrettyFunc(void);
}



namespace ProgComImp1
{
    void SimpleFunc(void);
}

int main(void)
{
    BestComImp1::SimpleFunc();
    return 0;
}

void BestComImp1::SimpleFunc(void)
{
    std::cout<<"BestCom이 정의한 함수"<<std::endl;
    PrettyFunc();
    ProgComImp1::SimpleFunc();
}

void BestComImp1::PrettyFunc(void)
{
    std::cout<<"So Pretty!!"<<std::endl;
}

void ProgComImp1::SimpleFunc(void)
{
    std::cout<<"ProgCom이 정의한 함수"<<std::endl;
}
*/

/*
#include <iostream>
using namespace std;

namespace AAA
{
    namespace BBB
    {
        namespace CCC
        {
            int num1;
            int num2;
        }
    }
}

int main(void)
{
    AAA::BBB::CCC::num1=20;
    AAA::BBB::CCC::num2=30;

    namespace ABC=AAA::BBB::CCC;
    cout<<ABC::num1<<endl;
    cout<<ABC::num2<<endl;

    return 0;
}
*/

//*은행계좌 관리 프로그램
//기능 1. 계좌개설
//기능 2. 입 금
//기능 3. 출 금
//기능 4. 전체고객 잔액조회

#include <iostream>
#include <cstring>

const int NAME_LEN=20;
using std::cout;
using std::endl;
using std::cin;

void Add_Account(void);
void ShowMenu(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccInfo(void);

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

typedef struct
{
    int accID;
    int balance;
    char cusName[NAME_LEN];
} Account;

Account accArr[100];
int accNum=0;

int main(void)
{
    int choice;

    while(1)   
    {
        ShowMenu();
        cout<<"선택: ";
        cin>>choice;
        cout<<endl;

        switch(choice)
        {
        case MAKE:
            Add_Account();
            break;
        case DEPOSIT:
            DepositMoney();
            break;
        case WITHDRAW:
            WithdrawMoney();
            break;
        case INQUIRE:
            ShowAllAccInfo();
            break;
        case EXIT:
            return 0;
        default:
            cout<<"Illegal selection.."<<endl;
        }
        
    }
    return 0;
}

void ShowMenu(void)
{
    cout<<"-----Menu------"<<endl;
    cout<<"1. 계좌개설"<<endl;
    cout<<"2. 입 금"<<endl;
    cout<<"3. 출 금"<<endl;
    cout<<"4. 계좌정보 전체 출력"<<endl;
    cout<<"5. 프로그램 종료"<<endl;
}

void Add_Account(void)
{
    int id;
    char name[NAME_LEN];
    int balance;

    cout<<"[계좌개설]"<<endl;
    cout<<"계좌ID: "; cin>>id;
    cout<<"이 름: "; cin>>name;
    cout<<"입금액: "; cin>>balance;
    cout<<endl;

    accArr[accNum].accID=id;
    accArr[accNum].balance=balance;
    strcpy(accArr[accNum].cusName, name);
    accNum++;
}

void DepositMoney(void)
{
    int money;
    int id;
    cout<<"[입   금]"<<endl;
    cout<<"계좌 ID: "; cin>>id;
    cout<<"입금액: "; cin>>money;

    for(int i=0; i<accNum; i++)
    {
        if(accArr[i].accID==id)
        {
            accArr[i].balance+=money;
            cout<<"입금완료"<<endl<<endl;

            return;
        }
    }
    cout<<"유효하지 않은 ID 입니다."<<endl<<endl;
}

void WithdrawMoney(void)
{
    int money;
    int id;
    cout<<"[출   금]"<<endl;
    cout<<"계좌 ID: "; cin>>id;
    cout<<"출금액: "; cin>>money;

    for (int i=0; i<accNum; i++)
    {
        if(accArr[i].accID==id)
        {
            if(accArr[i].balance < money)
            {
                cout<<"잔액 부족"<<endl<<endl;
                return;
            }
            accArr[i].balance-=money;
            cout<<"출금완료"<<endl<<endl;
            return;
        }
    }
     cout<<"유효하지 않은 ID 입니다."<<endl<<endl;
}

void ShowAllAccInfo(void)
{
    for(int i=0; i<accNum; i++)
    {
        cout<<"계좌ID: "<<accArr[i].accID<<endl;
        cout<<"이  름: "<<accArr[i].cusName<<endl;
        cout<<"잔  액: "<<accArr[i].balance<<endl<<endl;
    }
}