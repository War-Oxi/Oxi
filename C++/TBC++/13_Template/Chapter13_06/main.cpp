#include <iostream>
#include <string.h>
//#ifdef __STDC_LIB_EXT1__
//constexpr bool can_have_strcpy_s = true;
//#else
//constexpr bool can_have_strcpy_s = false;
//#endif
using namespace std;

template <class T, int size>
class StaticArray_Base{
private:
    T m_array[size];
public:
    T * getArray() { return m_array; }

    T& operator[](int index){
        return m_array[index];
    }

    void print(){
        for(int i=0; i<size; i++){
            cout << (*this)[i] << " ";
        }
        cout << endl;
    }
};

template <class T, int size>
class StaticArray : public StaticArray_Base<T, size>
{};

template <int size>
class StaticArray<char, size> : public StaticArray_Base<char, size>
{
public:
    void print(){
        for(int i=0; i<size; i++){
            cout << (*this)[i];
        }
        cout << endl;
    }
};
int main() {
    StaticArray<int, 4> my_arr;
    my_arr[0] = 1;
    my_arr[1] = 2;
    my_arr[2] = 3;
    my_arr[3] = 4;
    my_arr.print();

    StaticArray<char, 14> char_arr;
//    std::strcpy(char_arr.getArray(), "Hello, World~~");
    strncpy(char_arr.getArray(), "Hello, World~~", 14);
    char_arr.print();

    return 0;
}
