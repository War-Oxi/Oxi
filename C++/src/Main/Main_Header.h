//
// Created by Oxi on 2022-03-05 005.
//

#ifndef MAIN_MAIN_HEADER_H
#define MAIN_MAIN_HEADER_H


class Point{
private:
    int x;
    int y;
public:
    bool InitMembers(int xpos, int ypos);
    int GetX() const;
    int GetY() const;
    bool SetX(int xpos);
    bool SetY(int ypos);
};


#endif //MAIN_MAIN_HEADER_H
