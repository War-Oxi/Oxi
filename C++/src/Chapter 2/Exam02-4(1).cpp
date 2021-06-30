#include <iostream>
#include <cstring>
using std::cout;
using std::endl;

int main()
{
    char *str1 = "Kim";
    char *str2 = "Park";
    char str3[20];

    cout<<strlen(str1)<<endl;
    cout<<strcpy(str3, str1)<<endl;

    cout<<strcat(str3, str2)<<endl;
    
    
    cout<<strcmp(str1, str2)<<endl;

  
    return 0;
}