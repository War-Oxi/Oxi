#include <iostream>
using namespace std;

double powpow(int num1, int num2) {
    double result = 0;
    if(num2 > 0){
        result = num1;
        for(int i=1; i<num2; i++) {
            result *= num1;
        }
    }
    else if(num2 < 0 ){
        result = 1.0 / num1;
        for(int i=-1; i>num2; i--){
            result /= num1;
        }
    }
    else{
        return 1;
    }
    return result;
}

int main() {
    cout << powpow(2, 0) << endl;

    return 0;

}