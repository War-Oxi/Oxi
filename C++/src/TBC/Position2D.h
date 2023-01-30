<<<<<<< HEAD
#pragma once
=======
//
// Created by Oxi on 2023-01-27 027.
//

#ifndef TBC_POSITION2D_H
#define TBC_POSITION2D_H

#endif //TBC_POSITION2D_H

#include <iostream>
>>>>>>> 0d237e5f087aba07936aeae20b10fd0b7f9d7e06

class Position2D
{
private:
    int m_x;
    int m_y;

public:
<<<<<<< HEAD
    Position2D(const int & x_in, const int & y_in)
=======
    Position2D(const int & x_in, const int y_in)
>>>>>>> 0d237e5f087aba07936aeae20b10fd0b7f9d7e06
        :m_x(x_in), m_y(y_in)
    {}

    void set(const int & x_target, const int & y_target)
    {
        m_x = x_target;
        m_y = y_target;
    }

<<<<<<< HEAD
    void set(const Position2D & pos_target)
=======
    void set(const Position2D pos_target)
>>>>>>> 0d237e5f087aba07936aeae20b10fd0b7f9d7e06
    {
        set(pos_target.m_x, pos_target.m_y);
    }

    friend std::ostream & operator << (std::ostream & out, const Position2D & pos2d)
    {
<<<<<<< HEAD
        out << pos2d.m_x << " " << pos2d.m_y
=======
        out << pos2d.m_x << " " << pos2d.m_y;
>>>>>>> 0d237e5f087aba07936aeae20b10fd0b7f9d7e06
        return out;
    }
};