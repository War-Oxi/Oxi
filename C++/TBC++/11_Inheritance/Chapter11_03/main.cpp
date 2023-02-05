#include <iostream>
#include <ostream>

using namespace std;

class Mother
{
protected:
    int m_i;

public:
    Mother(const int & i_in = 0)
        :m_i(i_in)
    {
        cout << "Mother construction " << endl;
    }
};


class Child : public Mother
{
public:
    int m_temp;
    double m_d;

public:
    Child()
        : m_d(1.0), Mother(1024)
    {
        cout << "Child construction " << endl;
    }

    friend std::ostream & operator << (std::ostream & out, Child & child){
        out << child.m_i << " " << child.m_d;
        return out;
    }
};

int main()
{
    Child c1;

    cout << sizeof(Mother) << endl;
    cout << sizeof(Child) << endl;
    cout << sizeof(c1) << endl;
}