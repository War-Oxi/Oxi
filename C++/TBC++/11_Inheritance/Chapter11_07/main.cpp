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

    friend ostream & operator << (std::ostream & out, const Base &b)
    {
        out << "This is base output";
        return out;
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

    friend ostream & operator << (std::ostream & out, const Derived &d)
    {
        cout << static_cast<Base>(d) << endl;
        out << "This is derived output";
        return out;
    }
};

int main() {
    Base base(5);
    cout << base << endl;

    Derived derived(7);
    cout << derived << endl;

    return 0;
}