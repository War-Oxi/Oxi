#include <iostream>
#include <string.h>
using std::cout;
using std::endl;
using std::cin;

class Printer
{
private:
    char str[30];
public:
    void SetString(char* s);
    void ShowString();
};

void Printer::SetString(char* s)
{
    strcpy(str, s);
}

void Printer::ShowString()
{
    cout<<str<<endl;
}

int main(void)
{
    Printer pnt;
    pnt.SetString("Hello World");
    pnt.ShowString();

    pnt.SetString("42++ Gang Will win");
    pnt.ShowString();
    return 0;
}