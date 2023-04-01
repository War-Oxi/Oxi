#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void input(long long &city_num, vector<long long> &road_length, vector<long long> &oil_price);
long long getMinCost(long long &city_num, vector<long long> &road_length_vec, vector<long long> &oil_price_vec);


int main() {
    long long city_num;
    vector<long long> road_length;
    vector<long long> oil_price;
    input(city_num, road_length, oil_price);
    cout << getMinCost(city_num, road_length, oil_price);

    return 0;
}

void input(long long &city_num, vector<long long> &road_length, vector<long long> &oil_price) {
    cin >> city_num;

    for (long long i = 1; i < city_num; i++) {
        long long road_length_in;
        cin >> road_length_in;
        road_length.push_back(road_length_in);
    }

    for (long long i = 0; i < city_num; i++) {
        long long price_in;
        cin >> price_in;
        oil_price.push_back(price_in);
    }
}

long long getMinCost(long long &city_num, vector<long long> &road_length_vec, vector<long long> &oil_price_vec) {
    long long price = road_length_vec[0] * oil_price_vec[0], min_oil_price(oil_price_vec[0]);

    for(long long i=1; i<road_length_vec.size(); i++) {
        if(oil_price_vec[i] < min_oil_price)
            min_oil_price = oil_price_vec[i];
        price += min_oil_price * road_length_vec[i];
    }

    return price;
}
