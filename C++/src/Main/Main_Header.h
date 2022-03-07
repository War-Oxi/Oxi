//
// Created by Oxi on 2022-03-05 005.
//

#ifndef MAIN_MAIN_HEADER_H
#define MAIN_MAIN_HEADER_H

using namespace std;
#include <iostream>

class FruitSeller{
private:
    int numOfApples;
    int myMoney;

public:
    void InitMembers(int price, int num, int money);
    int SaleApples(int money);
    void ShowSalesResult() const;

    int apple_Price;
};

class FruitBuyer{
private:
    int myMoney;
    int numOfApples;

public:
    void InitMembers(int money);
    void BuyApples(FruitSeller &seller, int money);
    void ShowBuyResult() const;
};

#endif //MAIN_MAIN_HEADER_H
