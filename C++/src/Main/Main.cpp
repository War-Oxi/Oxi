#include<iostream>
#include "Main_Header.h"
#include "Main_Header2.h"
using namespace std;

int main(void)
{
    Point pos1;
    if(!pos1.InitMembers(-2, 4))
        cout<<"Initialization failed."<<endl;
    if(!pos1.InitMembers(2, 4))
        cout<<"Initialization failed."<<endl;

    Point pos2;
    if(!pos2.InitMembers(5, 9))
        cout<<"Initialization failed."<<endl;

    Rectangle rec;
    if(rec.InitMembers(pos2, pos1))
        cout<<"Rectangle Initialization failed."<<endl;

    if(rec.InitMembers(pos1, pos2))
        cout<<"Rectangle Initialization failed."<<endl;

    rec.ShowRecInfo();
    return 0;
}
