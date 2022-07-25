#include <iostream>

using namespace std;

int FindPrimeNumber(int number);

int main() {
    int min_num(0), max_num(0), sum(0), min_prime_num(0);
    bool flag(false);
    cin >> min_num >> max_num;

    for(min_num; min_num <= max_num; min_num++){
        if(FindPrimeNumber(min_num) != 0){
            flag = true;
            min_prime_num = min_num;
            sum += min_num;
            min_num++;
            break;
        }
    }

    for(min_num; min_num <= max_num; min_num++){
        if(FindPrimeNumber(min_num) != 0){
            flag = true;
            sum += min_num;
        }
    }

    if (flag){
        cout << sum << endl << min_prime_num << endl;
    }
    else{
        cout << -1 << endl;
    }

    return 0;
}

int FindPrimeNumber(int number){
    if(number < 2 || number > 10000){
        return 0;
    }
    bool flag = true;
    for(int i = 2; i < number; i++){
        if(number % i == 0){
            return 0;
        }
    }
    return number;
}