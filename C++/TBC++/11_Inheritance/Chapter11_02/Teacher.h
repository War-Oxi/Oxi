//
// Created by 김태지 on 2023/02/03.
//

#ifndef CHAPTER11_02_TEACHER_H
#define CHAPTER11_02_TEACHER_H

#endif //CHAPTER11_02_TEACHER_H

#include "Person.h"

class Teacher : public Person
{
private:

public:
    Teacher(const std::string & name_in = "No name")
        : Person(name_in)
    {}

    void teach()
    {
        std::cout << getName() << " is teaching " << std::endl;
    }

    friend std::ostream & operator << (std::ostream & out, const Teacher & teacher)
    {
        out << teacher.getName();
        return out;
    }
};

