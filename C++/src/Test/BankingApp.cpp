#include <iostream>
using namespace std;
const int NAME_LENGTH = 20;

void ShowMenu(void);
void MakeAccount(void);
void Deposit(void);
void Withdraw(void);
void ShowAllAccountInfo(void);

enum {MAKE=1, DEPOSIT, WITHDRAW, SHOW, EXIT};

typedef struct{
    int account_Number; //계좌 번호
    int balance; //계좌 잔액
    char custName[NAME_LENGTH]; //고객 이름
}Client_info;

Client_info account_array[100];
int account_num=0;

int main(void){
    int choice;
    while(1){
        ShowMenu();
        cout<<"선택: "; cin>>choice;
        cout<<endl;
        switch (choice){
        case MAKE:
            MakeAccount();
            break;
        case DEPOSIT:
            Deposit();
            break;
        case WITHDRAW:
            Withdraw();
            break;
        case SHOW:
            ShowAllAccountInfo();
            break;
        case EXIT:
            return 0;
        default:
            cout<<"Illegal selection... please input again";
        }
    }
    return 0;
}


void ShowMenu(void){
    cout<<"----Menu-----"<<endl;
    cout<<"1. 계좌개설"<<endl;
    cout<<"2. 입 금"<<endl;
    cout<<"3. 출 금"<<endl;
    cout<<"4. 계좌정보 전체 출력"<<endl;
    cout<<"5. 프록그램 종료"<<endl;
}

void MakeAccount(void){
    int id;
    int balance;
    char name[NAME_LENGTH];

    cout<<"[계좌개설]"<<endl;
    cout<<"계좌 번호: "; cin>>id;
    cout<<"고객 이름: "; cin>>name;
    cout<<"입금액: "; cin>>balance;

    account_array[account_num].account_Number=id;
    account_array[account_num].balance=balance;
    strcpy(account_array[account_num].custName, name);
    account_num++;
}

void Deposit(void){
    int money;
    int account_id;
    cout<<"[입 금]"<<endl;
    cout<<"계좌 번호: "; cin>>account_id;
    cout<<"입금액: "; cin>>money;

    for(int i=0; i<account_num; i++){
        if(account_array[i].account_Number==account_id){
            account_array[i].balance+=money;
            cout<<"입금완료"<<endl;
            return;
        }
    }
    cout<<"유효하지 않은 ID 입니다."<<endl<<endl;
}

void Withdraw(void){
    int money;
    int account_id;

    cout<<"[출 금]"<<endl;
    cout<<"계좌 번호: "; cin>>account_id;
    cout<<"출금액: "; cin>>money;

    for(int i=0; i<account_num; i++){
        if(account_array[i].account_Number==account_id){
            if(account_array[i].balance<money){
                cout<<"잔액이 부족합니다"<<endl<<endl;
                return;
            }
            account_array[i].balance-=money;
            cout<<"출금완료"<<endl;
            return;
        }
    }
    cout<<"유효하지 않은 ID 입니다."<<endl<<endl;
}

void ShowAllAccountInfo(void){
    for(int i=0; i<account_num; i++){
        cout<<"계좌번호: "<<account_array[i].account_Number<<endl;
        cout<<"이 름: "<<account_array[i].custName<<endl;
        cout<<"잔 액: "<<account_array[i].balance<<endl;
    }
}