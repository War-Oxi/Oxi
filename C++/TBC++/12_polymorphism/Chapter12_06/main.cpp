#include <iostream>
using namespace std;

class Base
{
private:
public:
    virtual void fun1() {};
    void fun2() {};
};

class Der : public Base
{
private:
    int a, b, c;

public:
    void fun1() {};
    void fun3() {};
};

int main() {
    cout << sizeof(Base) << endl;
    cout << sizeof(Der) << endl;
    return 0;
}
