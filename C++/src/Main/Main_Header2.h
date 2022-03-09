//
// Created by Oxi on 2022-03-09 009.
//

#ifndef MAIN_MAIN_HEADER2_H
#define MAIN_MAIN_HEADER2_H

#include "Main_Header.h"

class Rectangle
{
private:
    Point upLeft;
    Point lowRight;

public:
    bool InitMembers(const Point &ul, const Point &lr);
    void ShowRecInfo() const;
};

#endif //MAIN_MAIN_HEADER2_H
