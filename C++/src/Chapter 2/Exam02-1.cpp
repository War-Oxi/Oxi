#include <iostream>
using namespace std;

void Plus_fuc(int &num)
{
    num += 1;
}

void Change_sign(int &num)
{
    num *= -1;
}

int main(void)
{
    int num1 = 30;
    cout<<"num1 = "<<num1<<endl;
    Plus_fuc(num1);
    cout<<"after Plus num1 = "<<num1<<endl;
    Change_sign(num1);
    cout<<"after Change num1 = "<<num1<<endl;
    
    return 0;
}
