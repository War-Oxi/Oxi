/**
 * [1065] 한수
 * 어떤 양의 정수 X의 각 자리가 등차수열을 이룬다면, 그 수를 한수라고 한다.
 * 등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다. N이 주어졌을 때, 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오.
 * @return
 */
#include <iostream>

int Han_Num_Checker(int Num){
    int num1 = Num % 10;  //1의 자리 숫자
    int num2 = Num % 100 / 10;  //2의 자리 숫자
    int num3 = Num / 100; //3의 자리 숫자

    if(Num < 100)
        return 1;
    else if(num3 - num2 == num2 - num1)
        return 1;
    else
        return 0;
}

int main() {
    int input_number(0), han_num_count(0);
    std::cin >> input_number;
    while(input_number>0){
        han_num_count += Han_Num_Checker(input_number);
        input_number--;
    }
    std::cout << han_num_count;
    return 0;
}
