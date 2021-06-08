#include <stdio.h>
#include <time.h>

int factiorial_iter(int n) //!팩토리얼 계산
{
    int i, result = 1;
    for (i=1; i<=n; i++)
        result = result * i;
    return(result);
}

int fibo_for(int n)
{
    if (n==0) return 0;
    if (n<=3) return 1;

    int fir=0;
    int sec=1;
    int result = 0;

    for(int i = 3; i<=n; i++){
        result = fir + sec;
        fir = sec;
        sec = result;    
    }
    return result;
}



int fib(int n) //! 피보나치
{
    if (n==0) return 0;
    if (n<=3) return 1;
    
    return (fib(n-1) + fib(n-2));
}

double circle(int n)
{
    if (n==0) return 0;
    if (n==1) return 1;

    return (double)1/n + circle(n-1);
}

int fib_15(int n)
{
    printf("fib(%d) is called\n", n);
    if (n == 0) return 0;
    if (n == 1) return 1;
    return (fib_15(n-1) + fib_15(n-2));
}
void swap(int *px, int *py)             {
    int tmp;
    tmp = *px;
    *px = *py;
    *py = tmp;
}

int main(void)
{
    int a = 1, b = 2;
    printf("swap을 호출하기전 : a=%d, b=%d\n",a,b);
    swap(&a,&b);
    printf("swap을 호출한 후  : a=%d, b=%d\n",a, b);

    return 0;

}





