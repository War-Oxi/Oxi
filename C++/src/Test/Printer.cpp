#include <iostream>
#include <cstring>
#define MAX_SIZE 50

using std::cout;
using std::endl;

class Printer
{
private:
    char str[MAX_SIZE];
public:
    void SetString(char *s);
    void ShowString();
};

void Printer::SetString(char *s)
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
    pnt.SetString("Hello world!");
    pnt.ShowString();

    pnt.SetString("I Love C++");
    pnt.ShowString();
    
    return 0;
}