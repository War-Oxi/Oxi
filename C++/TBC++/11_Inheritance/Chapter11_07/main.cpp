#include <iostream>
using namespace std;

class Base {
protected:
    int m_i;
public:
    Base(int value)
        : m_i(value)
    {}

    void print()
    {
        cout << "I'm base" << endl;
    }
};

class Derived : public Base
{
private:
    double m_d;
public:
    Derived(int value)
        : Base(value)
    {}

    void print()
    {
//        Base::print();
        cout << "I'm derived " << endl;
    }
};

int main() {
    Base base(5);
    base.print();

    Derived derived(7);
    derived.print();

    return 0;
}