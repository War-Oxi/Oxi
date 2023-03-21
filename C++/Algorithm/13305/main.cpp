#include <iostream>
#include <queue>
using namespace std;

void input(int &city_num, queue<int> &road_length, queue<int> &oil_price);
long long getMinCost(int &city_num, queue<int> &road_length, queue<int> &oil_price);


int main() {
    int city_num;
    queue<int> road_length;
    queue<int> oil_price;
    input(city_num, road_length, oil_price);


    return 0;
}

void input(int &city_num, queue<int> &road_length, queue<int> &oil_price) {
    cin >> city_num;

    for (int i = 1; i < city_num; i++) {
        int road_length_in;
        cin >> road_length_in;
        road_length.push(road_length_in);
    }

    for (int i = 0; i < city_num; i++) {
        int price_in;
        cin >> price_in;
        oil_price.push(price_in);
    }
}

long long getMinCost(int &city_num, queue<int> &road_length, queue<int> &oil_price) {
    int next_road_length, cur_oil_price;

}
