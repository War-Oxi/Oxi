#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1("one");
    string str2("two");

    str1.append("three");
    //str1.push_back("123213"); X
    str1 += "three";


    str1 = str2 + "four";

    str1.insert(3, "bbb");

    cout << str1 << endl;

    return 0;
}
