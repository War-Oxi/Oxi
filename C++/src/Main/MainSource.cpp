//
// Created by Oxi on 2022-03-05 005.
//

#include "Main_Header.h"

void FruitSeller::InitMembers(int price, int num, int money){
    apple_Price = price;
    numOfApples = num;
    myMoney = money;
}
int FruitSeller::SaleApples(int money) {
    int num = money/apple_Price;
    numOfApples -= num;
    myMoney += money;
    myMoney -= money%apple_Price;
    return num;
}
void FruitSeller::ShowSalesResult() const {
    cout<<"The remaining apples: "<<numOfApples<<endl;
    cout<<"Profit from sales: "<<myMoney<<endl<<endl;
}

void FruitBuyer::InitMembers(int money) {
    myMoney = money;
    numOfApples = 0;
}
void FruitBuyer::BuyApples(FruitSeller &seller, int money) {
    int num = seller.SaleApples(money);
    numOfApples += num;
    myMoney -= num * seller.apple_Price;
}
void FruitBuyer::ShowBuyResult() const {
    cout<<"The number of apples: "<<numOfApples<<endl;
    cout<<"Current balance: "<<myMoney<<endl<<endl;
}
