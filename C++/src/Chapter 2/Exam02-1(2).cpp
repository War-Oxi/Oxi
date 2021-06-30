#include <iostream>
using std::cout;
using std::endl;

int main()
{
    const int num=12;
    const int *ptr1 = &num;
    const int *(&ref1) = ptr1;
    cout<<*ref1<<endl;
    cout<<*ptr1<<endl;
}
