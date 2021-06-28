/*#include <iostream>

using namespace std;

bool IsPositive(int num)
{
    if(num<=0)
        return false;
    else
        return true;
}

int main(void)
{
    bool isPos;
    int num;
    cout<<"Input number: "; cin>>num;

    isPos=IsPositive(num);
    if(isPos)
        cout<<"Positive number"<<endl;
    else
        cout<<"Negative number"<<endl;

    return 0;
}
*/
/*
#include <iostream>
using namespace std;

int main(void)
{
    int num=12;
    int *ptr=&num;
    int **dptr=&ptr;

    int &ref=num;
    int *(&pref)=ptr;
    int **(&dpref)=dptr;

    cout<<ref<<endl;
    cout<<*pref<<endl;
    cout<<**dpref<<endl;

    return 0;
}
*/
/*                        
//!Call-By-Value, Call-By-Ref
#include <iostream>
using std::cout;
using std::endl;

void SwapByValue(int num1, int num2)
{
    int temp=num1;
    num1=num2;
    num2=temp;
}

void SwapByRef(int *ptr1, int * ptr2)
{
    int temp=*ptr1;
    *ptr1=*ptr2;
    *ptr2=temp;
}

int main(void)
{
    int val1=10;
    int val2=20;
    SwapByValue(val1, val2);
    cout<<"val1: "<<val1<<endl;
    cout<<"val2: "<<val2<<endl;
    SwapByRef(&val1, &val2);
    cout<<"val1: "<<val1<<endl;
    cout<<"val2: "<<val2<<endl;


    return 0;
}*/
/*
//*RefSwap.cpp
#include <iostream>
using namespace std;

void SwapByRef2(int &ref1, int &ref2)
{
    int temp = ref1;
    ref1 = ref2;
    ref2 = temp;
}

int main(void)
{
    int val1=10;
    int val2=20;

    SwapByRef2(val1, val2);
    cout<<"val1: "<<val1<<endl;
    cout<<"val2: "<<val2<<endl;

    return 0;
}*/
/* //!80page
#include <iostream>
using namespace std;

void SwapPointer(int *(&pref1),int *(&pref2))
{
    int *ptr=pref1;
    pref1=pref2;
    pref2=ptr;
}
int main(void)
{
    int num1=5;
    int *ptr1=&num1;
    int num2=10;
    int *ptr2=&num2;

    cout<<*ptr1<<endl;
    cout<<*ptr2<<endl;

    SwapPointer(ptr1, ptr2);

    cout<<*ptr1<<endl;
    cout<<*ptr2<<endl;


    return 0;
}
*/
/*//!83 RefReturnOne.cpp
#include <iostream>
using namespace std;

int& RefRetFuncOne(int &ref)
{
    ref++;
    return ref;
}

int main(void)
{
    int num1=1;
    int &num2=RefRetFuncOne(num1);

    num1++;
    num2++;
    cout<<"num1: "<<num1<<endl;
    cout<<"num2: "<<num2<<endl;

    return 0;
}
*/
/*//! RefReturnTwo.cpp
#include <iostream>
using namespace std;

int& RefRetFuncOne(int &ref)
{
    ref++;
    return ref;
}

int main(void)
{
    int num1=1;
    int num2=RefRetFuncOne(num1);

    num1+=1;
    num2+=100;
    cout<<"num1: "<<num1<<endl;
    cout<<"num2: "<<num2<<endl;

    return 0;
}
*/
/*
#include <iostream>
using namespace std;

int RefRetFuncTwo(int &ref)
{
    ref++;
    return ref;
}

int main(void)
{
    int num1=1;
    int num2=RefRetFuncTwo(num1);

    num1+=1;
    num2+=100;
    cout<<"num1 ="<<num1<<endl;
    cout<<"num2 ="<<num2<<endl;

    return 0;
}
*/
/*//*90page 문제02-2
//!1.포인터 변수를 선언해서 위 변수를 가리키게 한다.
//!2.포인터 변수를 참조하는 참조자를 하나 선언한다.
//!3.포인터 변수와 참조자를 이욯해서 num에 저장된 값을 출력하는 예제를 완성한다.

#include <iostream>
using namespace std;

int main(void)
{
    const int num=12;
    const int *ptr = &num;
    const int *(&ref)=ptr;

    cout<<*ptr<<endl;
    cout<<*ref<<endl;

    return 0; 
}*/
/*//! 91page MemMalFree.cpp
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

char * MakeStrAdr(int len)
{
    char * str=(char*)malloc(sizeof(char)*len);
    return str;
}

int main(void)
{
    char * str=MakeStrAdr(20);
    strcpy(str, "I am so happy~");
    cout<<str<<endl;
    free(str);

    return 0;
}*/
/*#include <iostream>
#include <string.h>
using namespace std;

char * MakeStrAdr(int len)
{
    //! char * str = (char*)malloc(sizeof(char)*len);  에서
    char * str = new char[len];
    return str;
}

int main(void)
{
    char * str=MakeStrAdr(20);
    strcpy(str, "I'm so happy~");
    cout<<str<<endl;
    //!free(str); 에서
    delete []str;  //*이렇게 하면 된다.

    return 0;
}*/
/*//!2-3***************************************************
#include <iostream>
using std::cout;
using std::endl;

typedef struct __Point
{
    int xpos;
    int ypos;
} Point;

Point& PntAdder(const Point &p1, const Point &p2)
{
    Point * pptr=new Point;
    pptr -> xpos=p1.xpos+p2.xpos;
    pptr -> ypos=p1.ypos+p2.ypos;
    
    return *pptr;
}

int main(void)
{
    Point *pptr1=new Point;
    pptr1 -> xpos=3;
    pptr1 -> ypos=30;

    Point *pptr2=new Point;
    pptr2 -> xpos=70;
    pptr2 -> ypos=7;

    Point &pref=PntAdder(*pptr1,*pptr2);
    cout<<"["<<pref.xpos<<", "<<pref.ypos<<"]"<<endl;

    delete pptr1;
    delete pptr2;
    delete &pref;
    return 0;
}*/
/*//!2-4
#include <cstring>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main(void)
{
    char *str1="ABC 123";
    char *str2="DEF 456";
    char str3[50];

    cout<<strlen(str1)<<endl;
    cout<<strlen(str2)<<endl;

    cout<<"strcpy(str3, str2) => "<<strcpy(str3, str2)<<endl; //!문자열 복사하기
    cout<<"strcat(str3, str1) => "<<strcat(str3, str1)<<endl; //!문자열 뒤에 덧 붙이기
    cout<<"strcmp(str1, str2) => "<<strcmp(str1, str3)<<endl; //!문자열 비교하기

    return 0;
}*/
#include <iostream>
#include <tchar.h>
#include <windows.h>
using namespace std;
char* ReverseString(const char* src, int len)
{
//char reverse[100];
char* reverse=new char[len+1];

for(int i=0;i<len;++i)
	reverse[i]=src[len-i-1];
reverse[len]=NULL;
return reverse;
}

int _tmain(int argc, _TCHAR* argv[])
{
char original[]="NEMODRI";
char* copy=ReverseString(original, 8);

cout<<original<<"\n";
//cout<<copy<<"\n";

for(int i=0;i<8;i++)
     cout<<copy[i];
cout<<"\n";

delete[] copy;
copy=NULL;

return 0;
}

