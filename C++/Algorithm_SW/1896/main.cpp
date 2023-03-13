#include <iostream>
using namespace std;

int zigzag(int N){
    int return_value(0);
    for(int i=1; i<=N; i++){
        if(i % 2 == 0)
            return_value -= i;
        else
            return_value += i;
    }
    return return_value;
}

int main() {
    int test_case;
    cin >> test_case;

    for(int i=1; i<=test_case; i++){
        int num_in, result;
        cin >> num_in;

        result = zigzag(num_in);
        cout << "#" << i << " " << result << endl;
    }
    return 0;
}
