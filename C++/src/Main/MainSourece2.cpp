//
// Created by Oxi on 2022-03-09 009.

#include <iostream>
#include "Main_Header2.h"
using namespace std;
/*
bool Rectangle::InitMembers(const Point &ul, const Point &lr)
{
    if(ul.GetX()>lr.GetX() || ul.GetY()>lr.GetY())
    {
        cout<<"Incorrect location information was delivered."<<endl;
        return false;
    }

    upLeft=ul;
    lowRight=lr;
    return true;
}
 */



void Rectangle::ShowRecInfo() const
{
    cout<<"Up Left: "<<'['<<upLeft.GetX()<<", ";
    cout<<upLeft.GetY()<<']'<<endl;
    cout<<"Low Right: "<<'['<<lowRight.GetX()<<", ";
    cout<<lowRight.GetY()<<']'<<endl<<endl;
}
//

