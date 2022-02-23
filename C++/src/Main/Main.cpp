#include <iostream>
#include "cstring"
using namespace std;

int main(){
    char *name1 = "i am happy";
    char *name2 = ". kukuruppingppong";
    char name3[50];

    cout<<name1<<endl<<"문자열의 길이는? "<<strlen(name1)<<endl;

    strcat(name3, name1);
    cout<<name3<<endl;
    strcpy(name3,name2);
    cout<<name3<<endl;

    if (strcmp(name1, name2)==0){
        cout<<"문자열이 같다."<<endl;
    }
    else{
        cout<<"문자열이 다르다."<<endl;
    }

    char name5[50];
    const char *name4;
    name4 = "123123456";
    name5[1] = 1;

    cout<<name4<<name5<<endl;


    return 0;
}