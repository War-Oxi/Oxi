#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int test_case, T;
    cin >> T;

    for(test_case=1; test_case<=T; test_case++){
        int N;
        cin >> N;

        vector<int> record(N);
        for(int i=0; i<N; i++){
            int input_num;
            cin >> input_num;
            record[i] = abs(input_num);
        }

        int min_closed_distance = *std::min_element(record.begin(), record.end());
        int count(0);
        for (auto & ele : record){
            if(ele == min_closed_distance)
                count++;
        }

        cout << "#" << test_case << " " << min_closed_distance << " " << count << endl;
    }
    return 0;
}
