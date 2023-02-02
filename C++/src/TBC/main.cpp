#include <iostream>
#include <initializer_list>
using namespace std;

class IntArray
{
private:
    int m_length = 0;
    int *m_data = nullptr;
public:
    IntArray(const unsigned int &length_in)
        : m_length(length_in)
    {
        m_data = new int[m_length];
    }

    IntArray(const std::initializer_list<int> &list)
        : IntArray(list.size())
    {
        int count = 0;
        for (auto & element : list)
        {
            m_data[count] = element;
            ++count;
        }
    }

    ~IntArray(){
        delete[] m_data;
    }
//    Destructors
//    initialize()
//    void reset();
    IntArray& resize(const int & length_in)
    {
        if (m_length == length_in)
            return *this;
        else if (m_length < length_in)
        {
            int *temp = new int[length_in];
            for (int i = 0; i < m_length; i++)
                temp[i] = m_data[i];
            for (int i = m_length; i < length_in; i++)
                temp[i] = 0;

            m_length = length_in;
            delete[] m_data;
            m_data = temp;
        }
        else
        {
            m_length = length_in;
            int *temp = new int[m_length];
            for(int i = 0; i<m_length; i++)
                temp[i] = m_data[i];

            delete[] m_data;
            m_data = temp;
        }

        return *this;
    }
    IntArray& insertBefore(const int & value, const int & index)
    {
        resize(m_length+ 1 );

        for (int i = m_length-1; i > index; i--)
            m_data[i] = m_data[i - 1];

        m_data[index] = value;

        return *this;
    }
    IntArray& remove(const int & index)
    {
        for (int i = index; i < m_length; i++)
            m_data[i] = m_data[i + 1];
        resize(m_length-1);

        return *this;
    }
    IntArray& push_back(const int& value)
    {
        resize(m_length + 1);
        m_data[m_length - 1] = value;
        return *this;
    }

    friend ostream & operator << (ostream & out, IntArray &arr)
    {
        for(unsigned i = 0; i < arr.m_length; ++i)
            out << arr.m_data[i] << " ";
        out << endl;
    }

    IntArray& operator = (const IntArray& intArray)
    {
        if(this == &intArray) return *this;

        delete[] m_data;

        m_length = intArray.m_length;

        if(intArray.m_data != nullptr)
        {
            m_data = new int[m_length];

            for(int i=0; i<m_length; i++)
                m_data[i] = intArray.m_data[i];
        }
        else
            m_data = nullptr;
    }
};

int main()
{
    IntArray my_arr{ 1, 3, 5, 7, 9 };
    cout << my_arr << endl;

    my_arr.insertBefore(10, 1);//1 10 3 5 7 9
    cout << my_arr << endl;
    my_arr.remove(3);          //1 10 3 7 9
    cout << my_arr << endl;
    my_arr.push_back(13);      //1 10 3 7 9 13
    cout << my_arr << endl;
}