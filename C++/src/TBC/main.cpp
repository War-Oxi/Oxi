#include <iostream>
using namespace std;

class Fraction{
private:
    int m_numerator; //분자
    int m_denominator; //분모

public:
    Fraction(int num_in = 1,int denom_in = 1){
        m_numerator = num_in;
        m_denominator = denom_in;
    }
    void print() const{
        cout << m_numerator << " " << m_denominator << endl;
    }
};


int main(){
    Fraction frac{1, 2};
    frac.print();

    return 0;
}