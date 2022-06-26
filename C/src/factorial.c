//!팩토리얼 계산해보기

#include <stdio.h>
#include <time.h>

int factorial_sum(int n)
{
    int result = 1;
    double time;
    int start,stop;

    start = clock();
    if (n == 0) return 1;

    for(int i=n; i>=1; i--){
        result = result * i;
    }
    
    for(int p=0; p<=1000000000; p++);

    stop = clock();
    time = (double)(stop - start)/CLOCKS_PER_SEC;

    printf("함수 구동 시간 : %lf초\n", time);

    return result;
}

int main(void)
{
    int factorial_Num,start,stop;
    double time;

    
    
    printf("팩토리얼을 구할 정수를 입력하세요 : ");
    scanf("%d", &factorial_Num);
    
    
    

    printf("%d 팩토리얼은 %d 입니다", factorial_Num, factorial_sum(factorial_Num));
    


    return 0;
}