#include <iostream>
using std::cout;
using std::endl;

void swap(int *Num1, int *Num2)
{
    int Temp;
    Temp = *Num1;
    *Num1 = *Num2;
    *Num2 = Temp;
}
void swap(char *A, char *B)
{
    char Temp;
    Temp = *A;
    *A = *B;
    *B = Temp;
}
void swap(double *Num1, double *Num2)
{
    double Temp;
    Temp = *Num1;
    *Num1 = *Num2;
    *Num2 = Temp;
}

int main(void)
{
    int num1=20, num2=30;
    swap(&num1, &num2);
    cout<<num1<<' '<<num2<<endl;

    char ch1='A', ch2='Z';
    swap(&ch1, &ch2);
    cout<<ch1<<' '<<ch2<<endl;

    double dbl1 = 1.111, dbl2 = 5.555;
    swap(&dbl1, &dbl2);
    cout<<dbl1<<' '<<dbl2<<endl;
    return 0;
}