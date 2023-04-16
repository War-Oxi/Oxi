#include <iostream>
#include <vector>
using namespace std;

void getChange(int money_in){
    vector<int> money_type {50000, 10000, 5000, 1000, 500, 100, 50, 10};

    for(auto & ele : money_type){
        cout << money_in / ele << " ";
        money_in %= ele;
    }
}

int main() {
    int test_case;
    cin >> test_case;

    for(int i=1; i<=test_case; i++) {
        int money_in;
        cin >> money_in;
        cout << "#" << i << endl;
        getChange(money_in);
        cout << endl;
    }
    return 0;
}
