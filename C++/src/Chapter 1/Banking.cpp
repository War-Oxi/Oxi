#include <iostream>
#include <string>
#include <cstring>
using std::cout;
using std::cin;
using std::endl;
using std::string;

const int Name_Len=20;

void ShowMenu(void);
void Account_init(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllMoney(void);

enum {Make=1, Deposit, Withdraw, Inquire, Exit};

typedef struct Account{
    char Name[Name_Len];
    char Account_Num[Name_Len];
    int Balance;
} Account;

Account accArr[100];
int accNum=0;

int main(void)
{
    int choice;

    while(1)
    {
        ShowMenu();
        cout<<"선택 : ";
        cin>>choice;
        cout<<endl;

        switch(choice)
        {
        case Make:
            Account_init();
            break;
        case Deposit:
            DepositMoney();
            break;
        case Withdraw:
            WithdrawMoney();
            break;
        case Inquire:
            ShowAllMoney();
            break;
        case Exit:
            return 0;
        default:
            cout<<"wrong selection.."<<endl;
        }
    }
    return 0;
}

void ShowMenu(void)
{
    cout<<"-----------------Menu----------------"<<endl;
    cout<<"1. Make"<<endl<<"2. Deposit"<<endl
    <<"3. Withdraw"<<endl<<"4. ShowAll"<<endl<<"5. Exit"<<endl;
}

void Account_init(void)
{
    string Name, id;

    int Balance;
    
    cout<<"input Name : "; getline(cin, Name);
    cout<<"input Account Number: "; getline(cin>> id);
    cout<<"input Balance: "; cin>>Balance;
    cout<<endl;

    accArr[accNum].Name = Name;
    accArr[accNum].Account_Num = id;
    accArr[accNum].Balance=Balance;

    accNum++;
}

void DepositMoney(void)
{
    int money;
    char id[Name_Len];
    cout<<"[ Deposit ]"<<endl;
    cout<<"input Account Num : "; cin>>id;
    cout<<"How much deposit money? : "; cin>>money;

    for(int i=0; i<accNum; i++)
    {
        if(strcmp(accArr[i].Account_Num,id)){
            accArr[i].Balance+=money;
            cout<<"Deposit Complete"<<endl<<endl;
            return;
        }
    }
    cout<<"wrong ID."<<endl<<endl;
}

void WithdrawMoney(void)
{
    int money;
    char id[Name_Len];
    cout<<"[ Withdraw ]"<<endl;
    cout<<"input Account Num : "; cin>>id;
    cout<<"How much Withdraw money? : "; cin>>money;

    for(int i=0; i<accNum; i++){
        if(strcmp(accArr[i].Account_Num,id)){
            accArr[i].Balance -= money;
            cout<<"Withdraw Complete"<<endl<<endl;
            return;
        }
    }
    cout<<"wrong ID."<<endl<<endl;
}

void ShowAllMoney(void)
{
    for(int i=0; i<accNum; i++){
        cout<<"Name : "<<accArr[i].Name<<endl;
        cout<<"Account Num: "<<accArr[i].Account_Num<<endl;
        cout<<"Balance : "<<accArr[i].Balance<<endl;
    }
}