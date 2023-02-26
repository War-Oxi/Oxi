#include <iostream>
#include <vector>
using namespace std;

bool primeNumChecker(int num){
    if(num == 1) return false;
    int half_num = num/2;
    for(int i=2; i<=half_num; i++){
        if(!(num % i))
            return false;
    }
    return true;
}

int main() {
//    cout << 10/2 << endl;
//    cout << 10%5 << endl;
    int N;
    cin >> N;
    vector<int> my_vec;
    for(int i=0; i<N; i++){
        int tmp;
        cin >>tmp;
        my_vec.push_back(tmp);
    }

    vector<int>::iterator iter;
    int count(0);
    for(iter = my_vec.begin(); my_vec.end() != iter; iter++){
        if(primeNumChecker(*iter)){
//            cout << *iter << " ";
            count++;
        }
    }
//    cout << endl;

    cout << count << endl;

    return 0;
}
