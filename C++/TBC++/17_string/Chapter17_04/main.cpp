#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string my_str("abcdefg");

//    try{
//        my_str.at(100) = 'X';
//    }
//    catch(std::exception & e)
//    {
//        cout << e.what() << endl;
//    }

//    cout << my_str.c_str() << endl; //마지막에 null이 들어감

    char buf[20];

    my_str.copy(buf, 5, 1);

    cout << buf << endl;
    char *str = "1234567";
    cout << str << endl;
    return 0;
}
