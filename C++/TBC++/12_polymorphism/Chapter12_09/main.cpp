#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Base
{
public:
    int m_i = 0;

    virtual void print()
    {
        cout << "I'm Base" << endl;
    }
};

class Derived : public Base
{
public:
    int m_j = 1;

    virtual void print() override
    {
        cout << "I'm Derived" << endl;
    }
};

void doSomething(Base &b)
{
    b.print();
}

int main() {
    Derived d;
    Base b;

    std::vector<Base*> my_vec;
    my_vec.push_back(&b);
    my_vec.push_back(&d);

    for (auto & ele: my_vec)
        ele->print(); //객체 잘림 현상이 일어남

    std::vector<std::reference_wrapper<Base>> my_vec2;
    my_vec2.push_back(b);
    my_vec2.push_back(d);

    for (auto & ele : my_vec2)
        ele.get().print();

    return 0;
    return 0;
}
