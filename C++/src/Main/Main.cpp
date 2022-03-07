#include "Main_Header.h";

int main(){
    FruitSeller seller;
    seller.InitMembers(1000,20,0);
    FruitBuyer buyer;
    buyer.InitMembers(5000);
    buyer.BuyApples(seller, 2000);

    cout<<"The status of fruit sellers"<<endl;
    seller.ShowSalesResult();
    cout<<"The status of fruit buyers"<<endl;
    buyer.ShowBuyResult();

    return 0;
}