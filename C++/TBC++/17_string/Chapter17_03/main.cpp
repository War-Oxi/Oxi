#include <iostream>
#include <string>

using namespace std;

int main() {
    string my_str("012345678910111213141516"); //std::string은 null을 보관하지 않는다.
    my_str.resize(10);
    my_str.reserve(1000);
    cout << my_str << endl;
//    my_str.reserve(10);
//    my_str.resize(5);
//    cout << std::boolalpha;
    cout << my_str << endl;
    cout << my_str.size() << endl;
    cout << my_str.length() << endl;
    cout << my_str.capacity() << endl; //default capacity => 15.
    cout << my_str.empty() << endl;
    cout << my_str.max_size() << endl;
    return 0;
}
