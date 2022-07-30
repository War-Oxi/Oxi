/*
 * 백준 2581 [소수]
 * 1. 숫자가 소수인지, 소수가 아닌지 판별하는 함수 생성 (소수가 아니면 0을 리턴)
 * 2. 함수를 사용해 최솟값부터 최댓값까지의 숫자중 소수인 숫자들을 sum 변수에 더해줌
 *    => 소수가 한개 이상 존재하면 false로 초기화된 flag변수를 true로 초기화
 *    => 범위내의 숫자 중 첫 번째로 나오는 숫자는 min_prime_num 변수에 저장
 * 3. 범위 내의 소수들의 합(sum 변수)과 최솟값(min_prime_num) 변수를 출력
 *    => flag변수가 false일 때(범위 내에 소수가 존재하지 않을 때), -1을 출력
 */

#include <iostream>

using namespace std;

int FindPrimeNumber(int number);

int main() {
    int min_num(0), max_num(0), sum(0), min_prime_num(0);
    bool flag(false);
    cin >> min_num >> max_num;
    // 2. 함수를 사용해 최솟값부터 최댓값까지의 숫자중 소수인 숫자들을 sum 변수에 더해줌
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
    //3. 범위 내의 소수들의 합(sum 변수)과 최솟값(min_prime_num) 변수를 출력
    if (flag){
        cout << sum << endl << min_prime_num << endl;
    }
    else{
        cout << -1 << endl;
    }
    return 0;
}
// 1. 숫자가 소수인지, 소수가 아닌지 판별하는 함수 생성 (소수가 아니면 0을 리턴)
int FindPrimeNumber(int number){
    if(number < 2 || number > 10000){
        return 0;
    }
    for(int i = 2; i < number; i++){
        if(number % i == 0){
            return 0;
        }
    }
    return number;
}