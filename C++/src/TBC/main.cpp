#include <iostream>
using namespace std;

class IntArray{
private:
    int *m_arr = nullptr;
    int m_arrSize = 0;

public:
    explicit IntArray(const int sizeIn){
        m_arrSize = sizeIn;
        m_arr = new int[m_arrSize];

        cout << "Constructor called" << endl;
    }

    ~IntArray(){
        if (m_arr != nullptr){
            delete m_arr;
            cout << "Destructor called" << endl;
        }
        else
            cout << "Destructor not called" << endl;
    }
};

int main(){
    for (int i =0; i<100; i++){
        IntArray(1000);
    }

    return 0;
}