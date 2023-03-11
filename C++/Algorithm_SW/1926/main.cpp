#include <iostream>
#include <string>

using namespace std;

int main() {
    int num_in;
    cin >> num_in;

    for(auto i=1; i <= num_in; i++){
        int count(0);

        string tmp_str = to_string(i);

        for(auto & e : tmp_str){
            if(e == '3' || e == '6' || e == '9'){
                count++;
            }
        }

        if(count == 0)
            cout << i << " ";
        else{
            for(auto j = 0; j < count; j++)
                cout << "-";
            cout << " ";
        }
    }
    return 0;
}
