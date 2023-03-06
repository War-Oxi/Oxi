#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int N;
    cin >> N;

    string num = to_string(N);

    int result(0);
    for(int i=0; i<num.size(); i++){
        result += int(num[i]) - '0';
    }

    cout << result << endl;

    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}