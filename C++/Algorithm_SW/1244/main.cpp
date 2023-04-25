#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_value;

void init(vector<int> &vec_in);
void get_max(vector<int> vec_in, int exchange_num);

int main() {
    int test_case, T;
    cin >> T;

    for(test_case=1; test_case<=T; test_case++){
        vector<int> my_vec;
        init(my_vec);
        max_value = -1;
        get_max(my_vec, 0);


    }

    return 0;
}


void init(vector<int> &vec_in){
    string num;
    cin >> num;


    for(auto & ele : num){
        vec_in.push_back(ele-48);
    }
}

void get_max(vector<int> vec_in, int exchange_num) {
    int max_exchange, exchange_count(0);
    cin >> max_exchange;

    for(int i=0; i<max_exchange; i++){

        }
    }
}