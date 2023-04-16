#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int test_case;
    cin >> test_case;

    for(int i=1; i<=test_case; i++){
        int arr_size;
        cin >> arr_size;

        vector<int> arr(arr_size);
        for(int j=0; j<arr_size; j++){
            cin >> arr[j];
        }

        sort(arr.begin(), arr.end());
        cout << "#" << i << " ";
        for (auto & ele : arr)
            cout << ele << " ";
        cout << endl;
    }
    return 0;
}
