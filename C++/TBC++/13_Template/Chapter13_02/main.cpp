//Class Template
#include <assert.h>
#include <iostream>

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
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
