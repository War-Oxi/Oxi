//Class Template
#include <assert.h>
#include <iostream>
/**
 * explicit instantiation
 * @tparam T
 */
template <typename T>

class MyArray
{
private:
    int m_length;
    int *m_data;

public:
    MyArray()
    {
        m_length = 0;
        m_data = nullptr;
    }

    MyArray(int length)
    {
        m_data = new int [length];
        m_length = length;
    }

    void reset()
    {

    }
};

int main() {
    std::cout << std::boolalpha << ("A" > "B") << std::endl;
    return 0;
}
