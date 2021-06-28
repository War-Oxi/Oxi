#include <iostream>
#include "tchar.h"
using namespace std;

struct RetValue
{
int retValue1;
int retValue2;
};
RetValue PlusMinus(int a, int b)
{
RetValue ret;
ret.retValue1=a+b;
ret.retValue2=a-b;
return ret;
}
int _tmain(int argc, _TCHAR* argv[])
{
RetValue result;
result=PlusMinus(3,5);

cout<<result.retValue1<<"\n";
cout<<result.retValue2<<"\n";
return 0;
}
