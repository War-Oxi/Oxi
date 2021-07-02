#include <iostream>
using std::cout;
using std::endl;

class Calculator
{
private:
    int NumofAdd;
    int NumofMin;
    int NumofMul;
    int NumofDiv;
public:
    void init();
    double Add(double num1, double num2);
    double Min(double num1, double num2);
    double Mul(double num1, double num2);
    double Div(double num1, double num2);
    void ShowOpCount(); 
};


void Calculator::init()
{
    NumofAdd=0;
    NumofMin=0;
    NumofMul=0;
    NumofDiv=0;
}

double Calculator::Add(double num1, double num2)
{
    NumofAdd++;
    return num1+num2;
}

double Calculator::Min(double num1, double num2)
{
    NumofMin++;
    return num1-num2;
}

double Calculator::Mul(double num1, double num2)
{
    NumofMul++;
    return num1*num2;
}

double Calculator::Div(double num1, double num2)
{
    NumofDiv++;
    return num1/num2;
}

void Calculator::ShowOpCount()
{
    cout<<"Add: "<<NumofAdd<<endl;
    cout<<"Min: "<<NumofMin<<endl;
    cout<<"Mul: "<<NumofMul<<endl;
    cout<<"Div: "<<NumofDiv<<endl;
}

int main(void)
{
    Calculator cal;
    cal.init();
    cout<<"3.2 + 2.4 = "<<cal.Add(3.2, 2.4)<<endl;
    cout<<"3.5 / 1.7 = "<<cal.Div(3.5, 1.7)<<endl;
    cout<<"2.2 - 1.5 = "<<cal.Min(2.2, 1.5)<<endl;
    cout<<"4.9 / 1.2 = "<<cal.Div(4.9, 1.2)<<endl;
    cal.ShowOpCount();
    return 0; 
}