//
// Created by 김태지 on 2023/02/03.
//

#ifndef CHAPTER11_02_PERSON_H
#define CHAPTER11_02_PERSON_H

#endif //CHAPTER11_02_PERSON_H

#pragma once

#include <string>
#include <iostream>

class Person
{
private:
    std::string m_name;
public:
    Person(const std::string & name_in = "No Name")
        :m_name(name_in)
    {}

    void setName(const std::string & name_in)
    {
        m_name = name_in;
    }

    std::string getName() const
    {
        return m_name;
    }

    void doNothing() const
    {
        std::cout << m_name << " is doing nothing " << std::endl;
    }
};