#include <iostream>
#include <string>
using namespace std;

//A = 65 B = 66 ... Z = 90
int main() {

    std::string my_str;
    cin >> my_str;

    for(char i : my_str){
        cout << i - 64 << " ";
    }

    return 0;
}
