#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int test_case;
    cin >> test_case;
    std::vector<int> my_vec;

    for (int i=0; i<test_case; i++){
        for(int j=0; j<10; j++){
            int tmp;
            cin >> tmp;
            my_vec.push_back(tmp);
        }
        cout << "#" << i+1 << " " << *std::max_element(my_vec.begin(), my_vec.end()) << endl;
        vector<int>().swap(my_vec);
    }

    return 0;
}
