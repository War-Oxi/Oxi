#include <iostream>
using namespace std;

template<class T>
class A
{
private:
    T m_value;

public:
    A(const T & input)
            :m_value(input)
    {}
    template<typename TT>
    void doSomeThing()
    {
        cout << typeid(T).name() << " " << typeid(TT).name() << endl;
    }
    void print()
    {
        cout << m_value << endl;
    }
};

//template<class T>

int main() {
    A<char> a_char('a');
    a_char.print();

    a_char.doSomeThing<int>();
//    a_int.doSomeThing<float>(123.4);
//    int temp = 456;
//
//    A<int*> a_int_ptr(&temp);
//    a_int_ptr.print();
//
//    double temp_d = 3.141592;
//    A<double*> a_double_ptr(&temp_d);
//    a_double_ptr.print();

    return 0;
}
