#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int getAverage(vector<int> vec_in){
    std::sort(vec_in.begin(), vec_in.end());

    std::vector<int>::iterator itr;

    double sum_value(0);
    for(itr = vec_in.begin()+1; itr != vec_in.end()-1; itr++){
        sum_value += *itr;
    }
    double avg = round((sum_value/(vec_in.size()-2)));
    return avg;
}

int main() {
    int test_case;
    cin >> test_case;


    vector<int> my_vec(10);
    for(int i=1; i<=test_case; i++){
        for(int j=0; j<10; j++){
            int tmp_in;
            cin >> tmp_in;
            my_vec[j] = tmp_in;
        }
        int average = getAverage(my_vec);

        cout << "#" << i << " " << average << endl;
    }
    return 0;
}
