#include <iostream>
#include <string>
using namespace std;

class DynamicArray
{
public:
    DynamicArray(int arraySize);
    ~DynamicArray();

    void SetAt(int index, int value);
    int GetAt(int index) const;
    int GetSize() const;

protected:
    int* arr;
    int size;
};

class MyException
{
public:
    const void* sender;
    const char* description;
    int info;

    MyException(const void* sender, const char* description, int info)
    {
        this->sender = sender;
        this->description = description;
        this->info = info;
    }
};

DynamicArray::DynamicArray(int arraySize)
{
    arr = new int [arraySize];
    size = arraySize;
}
DynamicArray::~DynamicArray()
{
    delete[] arr;
    arr = 0;
}
void DynamicArray::SetAt(int index, int value)
{
    if(index<0 || index >= GetSize())
        throw MyException(this, "Out of Range", index);
    arr[index] = value;
}
int DynamicArray::GetAt(int index) const
{
    if(index < 0 || index >= GetSize())
        throw MyException(this, "Out of Range", index);
    return arr[index];
}
int DynamicArray::GetSize() const
{
    return size;
}

void UseArray(DynamicArray& arr1, DynamicArray& arr2);

int main()
{
    DynamicArray arr1(10);
    DynamicArray arr2(8);

    UseArray(arr1, arr2);
    char a;
    a=getchar();
    
    return 0;
}

void UseArray(DynamicArray& arr1, DynamicArray& arr2)
{
    try{
        arr1.SetAt(5,100);
        arr2.SetAt(5,100);
        arr1.SetAt(8,100);
        arr2.SetAt(8,100);
        arr1.SetAt(10,100);
        arr2.SetAt(10,100);
    }
    catch(MyException& ex){
        cout<<"&arr1="<<&arr1<<"\n&arr2="<<&arr2<<endl;
        cout<<"예외를 던진 객체의 주소 = "<<ex.sender<<endl;
        cout<<"예외에 대한 설명 ="<<ex.description<<endl;
        cout<<"부가정보 = "<<ex.info<<endl;
    }
}
