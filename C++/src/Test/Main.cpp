#include <iostream>
using namespace std;
//!급여계산
void swap(int *num_1, int *num_2){
    int temp = *num_1;
    *num_1 = *num_2;
    *num_2 = temp;
}
void swap(char *a,char *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void swap(double *a, double *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void){
    int num1=20, num2=30;
    swap(&num1, &num2);
    std::cout<<num1<<' '<<num2<<std::endl;
    
    char ch1='A', ch2='Z';
    swap(&ch1, &ch2);
    std::cout<<ch1<<' '<<ch2<<std::endl;

    double db11=1.111, db12=5.555;
    swap(&db11, &db12);
    std::cout << db11 << ' ' << db12 << std::endl;
    
}
