#include <iostream>
using std::cout;
using std::endl;

void Swap_Reference(int &ref1, int &ref2)
{
    int temp = ref1;
    ref1 = ref2;
    ref2 = temp;
}

void Swap_Pointer(int *ptr1, int *ptr2)
{
    int temp;
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
int main(void)
{
    int ref1 = 10;
    int ref2 = 20;
    Swap_Reference(ref1, ref2);
    cout<<"ref1 = "<<ref1<<endl;
    cout<<"ref2 = "<<ref2<<endl;
    
    Swap_Pointer(&ref1,&ref2);
    cout<<"========================"<<endl<<"ref1 = "<<ref1<<endl;
    cout<<"ref2 = "<<ref2<<endl;
    return 0;
}