//
// Created by Oxi on 2023-01-27 027.
//

#ifndef TBC_MONSTER_H
#define TBC_MONSTER_H

#endif //TBC_MONSTER_H

#include <string>
#include "Position2D.h"

class Monster
{
private:
    std::string m_name;
    Position2D  m_location;

public:
    Monster(const std::string name_in, const Position2D & pos_in)
        : m_name(name_in), m_location(pos_in)
    {}

    void moveTo(const Position2D & pos_target)
    {
        m_location.set(pos_target);
    }

    friend std::ostream & operator << (std::ostream & out, const Monster & monster)
    {
        out << monster.m_name << " " << monster.m_location;
    }
};