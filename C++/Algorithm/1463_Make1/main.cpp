//1463_1로 만들기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void makeOne(int num){
    vector <int> vec;
    vec.reserve(num+1);
    vec[0] = 0;
    vec[1] = 0;
    vec[2] = 1;
    vec[3] = 1;

    for(int i = 4; i <= num; i++){
        vec[i] = vec[i-1] + 1;
        if(!(i % 3))
            vec[i] = min(vec[i], vec[i/3] + 1);
        if (!(i % 2))
            vec[i] = min(vec[i], vec[i/2] + 1);
    }

    cout << vec[num] << endl;
}

int main() {
    int Num;
    cin >> Num;
    makeOne(Num);
    return 0;
}
