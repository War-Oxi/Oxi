#include <iostream>
#include <map>
using namespace std;

int main() {

    int test_case, T;
    cin >> T;

    for (test_case=1; test_case<=T; test_case++){
        map<string, int> map_in;
        int num_of_pair;

        cin >> num_of_pair;

        for(int i=0; i<num_of_pair; i++){
            string alphabet;
            int num;
            cin >> alphabet >> num;
            map_in.insert({alphabet, num});
        }

        int count(0);
        cout << "#" << test_case << endl;
        for(auto & ele : map_in){
            for(int i=0; i<ele.second; i++){
                cout << ele.first;
                count++;
                if(count == 10){
                    cout << endl;
                    count = 0;
                }
            }
        }
        cout << endl;
    }
    return 0;
}
