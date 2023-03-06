#include <iostream>
//#include <string>
#include <vector>
/**
std::string operator + (std::string str1, std::string str2){
    std::string tmp;

    for(int i=0; i<str1.size(); i++){
        tmp.push_back(str1[i]);
    }
    for(int i=0; i<str2.size(); i++){
        tmp.push_back(str2[i]);
    }

    return tmp;
}

using namespace std;

int main() {
    std::string str1="Hello", str2=" World";

    std::cout << str1+str2 << std::endl;

//    std::vector<std::string> v;
//
//    v.push_back(str1);
//
//    cout << str1 << endl;
//    cout << v[0] << endl;
//
//    v.push_back(std::move(str1));
//
//    cout << str1 << endl;
//    cout << v[0] << " " << v[1] << endl;

    int *a = new int[1000000];
    int *b = std::move(a);
//    cout << &b << " " << &a;


    delete[] a;

    return 0;
}
*/
template<typename T>
auto adder(T num1, T num2){
    return num1 + num2;
}

int main(){
    std::cout << typeid(adder(4, 4)).name() << std::endl;
    std::cout << typeid(adder(4.5, 5.5)).name() << std::endl;

}