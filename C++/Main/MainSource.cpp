//
// Created by Oxi on 2022-03-05 005.
//

#include <iostream>
#include "Main_Header.h"
using namespace std;
/*
bool Point::InitMembers(int xpos, int ypos) {
    if(xpos<0 || ypos<0){
        cout<<"Out of range value"<<endl;
        return false;
    }

    x=xpos;
    y=ypos;
    return true;
}
 */


int Point::GetX() const {
    return x;
}

int Point::GetY() const {
    return y;
}

bool Point::SetX(int xpos) {
    if(0>xpos || xpos>100){
        cout<<"Out of range value"<<endl;
        return false;
    }
    x=xpos;
    return true;
}
bool Point::SetY(int ypos) {
    if(0>ypos || ypos>100){
        cout<<"Out of range value"<<endl;
        return false;
    }
    y=ypos;
    return true;
}

Point::Point() {}