#include <iostream>
using namespace std;

class Base
{
public:
    int m_public;
protected:
    int m_protected;
private:
    int m_private;
};

class Derived : protected Base
{
public:
    Derived()
    {
        Base::m_public; //this->m_public; == m_public;
        Base::m_protected;
//        Base::m_private;
    }
};

class GrandChild : public Derived
{
public:
    GrandChild()
    {
        Base::m_public;
        Base::m_protected;
    }
};


int main() {
    Derived derived;

//    derived.m_public = 1024;
//    derived.m_protected;
//    derived.m_private;

    return 0;
}
