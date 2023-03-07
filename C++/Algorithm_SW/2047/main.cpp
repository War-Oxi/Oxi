#include <iostream>
#include <string>

using namespace std;

int main() {
    std::string my_str;
    cin >> my_str;

    for(auto & ele : my_str){
        ele = toupper(ele);
    }

    for(auto & ele : my_str)
        cout << ele;

    return 0;
}
