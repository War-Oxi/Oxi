#include <iostream>
#include <vector>
using namespace std;

void primeFactorization(int num_in){
    vector<int> num_vec {2, 3, 5, 7, 11};
    vector<int> count_vec(13);

    while(true){
        if(num_in == 1) break;

        for(auto & ele : num_vec){
            while(true){
                if(num_in % ele !=0)
                    break;
                count_vec[ele]++;
                num_in /= ele;
            }
        }
    }

    for(auto & ele : num_vec){
        cout << count_vec[ele] << " ";
    }
    cout << endl;
};


int main() {
    int test_case, T;
    cin >> T;

    int num_in;
    for(test_case=1; test_case<=T; test_case++){
        cin >> num_in;

        cout << "#" << test_case << " ";
        primeFactorization(num_in);

    }
    return 0;
}
