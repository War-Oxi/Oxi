#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void showMenu();
void makeAccount();
void deposit();
void withdraw();
void showAllAccount();

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

class Account{
private:
    int accountID=-1;
    int balance;
    std::string customerName;
public:
    Account(int input_accountID, int input_balance, std::string input_customerName)
        :accountID(input_accountID), balance(input_balance), customerName(std::move(input_customerName))
    {
        cout << "===========계좌 생성 완료============" << endl;
        cout << "계좌번호 : " << accountID << "\n이름 "<< customerName << "\n잔액 : " << balance << endl;
//        cout << "==================================" << endl;
    }

    [[nodiscard]] int getAccountID() const { return accountID; }

    void deposit(int money){
        this->balance += money;
        cout << money << "원 입금 완료 \n남은 잔액 : " << this->balance << endl;
        cout << "==================================" << endl;

    }

    void withdraw(int money){
        if(money > balance){
            cout << "계좌에 잔고가 부족합니다. [출금 실패]" << endl;
            cout << "현재 잔고 : " << this->balance << endl;
            cout << "==================================" << endl;
        }
        else{
            this->balance -= money;
            cout << money << "원을 출금 했습니다." << endl;
            cout << "현재 잔고 : " << this->balance << endl;
            cout << "==================================" << endl;
        }
    }

    void showAccountInfo(){
        cout << "계좌번호 : " << this->accountID << "\n이름 "<< this->customerName << "\n잔액 : " << this->balance << endl;
        cout << "==================================" << endl;
    }
};

std::vector<Account> account;

int main(){
    account.reserve(100);
    int option = -1;
    while(1){
        showMenu();
        cout << "option => ";
        cin >> option;
        cout << "==================================" << endl;

        switch(option){
            case MAKE:
                makeAccount();
                break;
            case DEPOSIT:
                deposit();
                break;
            case WITHDRAW:
                withdraw();
                break;
            case INQUIRE:
                if (account.size() == 0){
                    cout << "현재 만들어진 계좌가 없습니다" << endl;
                }
                showAllAccount();
                break;
            case EXIT:
                cout << "프로그램을 종료합니다." << endl;
                return 0;
            default:
                cout << "[Warning] 다시 입력해주세요." << endl;
        }
    }
}
void showMenu(){
    cout << "===============Menu===============" << endl;
    cout << "===========1. 계좌개설 =============" << endl;
    cout << "===========2. 입  금  =============" << endl;
    cout << "===========3. 출  금  =============" << endl;
    cout << "===========4. 계좌정보 전체 출력======" << endl;
    cout << "===========5. 프로그램 종료 =============" << endl;
}

Account &findAccount (int accID){
    for (auto&temp: account){
        if (temp.getAccountID() == accID)
            return temp;
    }
    cout << "없는 계좌입니다." << endl;
}

void makeAccount(){
    static int id = 1;
//    int id=1234;
    int money=10000;
    string name = "Kim Tae Ji";

    account.emplace_back(id, money, name);
    id++;
}

void deposit(){
    int accID;
    int money;
    cout << "계좌번호 : "; cin >> accID;
    Account &acc = findAccount(accID);
    if (acc.getAccountID() == 0){
        cout << "없는 계좌입니다." << endl;
        return;
    }
    cout << "금액 : "; cin >> money;
    acc.deposit(money);
}

void withdraw(){
    int accID;
    int money;
    cout << "계좌번호 : "; cin >> accID;
    Account &acc = findAccount(accID);
    if (acc.getAccountID() == 0){
        cout << "없는 계좌입니다." << endl;
        return;
    }
    cout << "금액 : "; cin >> money;
    acc.withdraw(money);
}

void showAllAccount(){
    for(auto&tmpAcc: account){
        tmpAcc.showAccountInfo();
    }
}