//2503_숫자야구
#include <iostream>
#include <string>
#include <memory.h>
using namespace std;

int main() {
    bool num_arr[1000];

    memset(num_arr, true, sizeof(num_arr));

    for (int i=123; i<1000; i++){
        string tmp = to_string(i);

        if(tmp[0] == tmp[1] || tmp[1] == tmp[2] || tmp[0] == tmp[2])
            num_arr[i] = false;

        if(tmp[0] == '0' || tmp[1] == '0' || tmp[2] == '0')
            num_arr[i] = false;
    }

    int repeat_num;
    cin >> repeat_num;

    while(repeat_num){
        string num_in;
        int strike_in, ball_in;
        cin >> num_in >> strike_in >> ball_in;
        for (int i=123; i<1000; i++){
            int strike_count(0), ball_count(0);
            string tmp = to_string(i);
            if(num_arr[i]){
                for(int x = 0; x < 3; x++){
                    for(int y = 0; y < 3; y++){
                        if(x==y && num_in[x] == tmp[y])
                            strike_count++;
                        if(x!=y && num_in[x] == tmp[y])
                            ball_count++;
                    }
                }
                if(strike_count != strike_in || ball_count != ball_in)
                    num_arr[i] = false;
            }
        }
        repeat_num--;
    }

    int count(0);

    for(int i=123; i<1000; i++){
        if(num_arr[i])
            count++;
    }

    cout << count << endl;


    return 0;
}
