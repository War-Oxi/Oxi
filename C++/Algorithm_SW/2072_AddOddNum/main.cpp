#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    int my_arr[10];

    for(int i=0; i<T; ++i){
        int add_result(0);
        for(int j=0; j<10; j++){
            int tmp;
            cin >> tmp;
            if(tmp % 2 != 0)
                add_result += tmp;
        }
        cout << "#" << i+1 << " " << add_result << endl;
    }

    return 0;
}
